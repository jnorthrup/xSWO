/*
 * Copyright 2010-2011 Chris Vaszauskas and Tyler Richard
 *
 * This file is part of a HAT-trie implementation following the paper
 * entitled "HAT-trie: A Cache-concious Trie-based Data Structure for
 * Strings" by Nikolas Askitis and Ranjan Sinha.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// TODO backwards iteration

#ifndef ARRAY_HASH_H
#define ARRAY_HASH_H

#include <cstring>
#include <stdint.h>
#include <utility>
#include <iterator>

namespace stx {

/**
 * Provides a way to tune the performance characteristics of an
 * array hash table.
 *
 * \subsection Usage
 * \code
 * array_hash_traits traits;
 * traits.burst_threshold = 8192;
 * hat_set<string> rawr(traits);
 * rawr.insert(...);
 * ...
 * \endcode
 */
class array_hash_traits {

  public:
    array_hash_traits() {
        slot_count = 512;
        allocation_chunk_size = 32;
    }

    /**
     * Number of slots in the hash table. Higher values use more
     * memory but may show faster access times.
     *
     * Default 512. Must be positive.
     */
    int slot_count;

    /**
     * This value only affects the speed of the insert() operation.  When a
     * slot in the array hash is allocated, it is allocated in blocks of this
     * size until there is enough space for a word.  In general, higher values
     * use more memory but require fewer memory copy operations.  Try to guess
     * how many average characters your strings will use, then multiply that
     * by (hat_trie__traits.burst_threshold / array_hash_traits::slot_count) to
     * get a good estimate for this value.
     *
     * If you want memory allocations to be exactly as big as they need to
     * be (rather than in block chunks), set this value to 0. This may be
     * your best option in memory-tight situations. Insertion speed is still
     * impressive even with abundant memory copy operations.
     *
     * Default 32. Must be non-negative.
     */
    int allocation_chunk_size;

};

/*
array-hash public interface:
class array_hash {

  public:
    array_hash();
    ~array_hash();

    // accessors
    bool exists(const char *str) const;
    iterator find(const char *str) const;
    size_t size() const;

    // modifiers
    bool insert(const char *str);
    void erase(const char *str);
    void erase(iterator);

    iterator begin() const;
    iterator end() const;

    class iterator {

      public:
        iterator();
        iterator(const iterator& rhs);

        iterator& operator++();
        iterator& operator--();

        const char *operator*() const;
        bool operator==(const iterator& rhs);
        bool operator!=(const iterator& rhs);

    };
};
*/

template <class T>
class array_hash { };

/**
 * Hash table container for unsorted strings.
 */
template <>
class array_hash<std::string> {

  private:
    typedef uint16_t length_type;
    typedef uint32_t size_type;

  public:
    class iterator;

    /**
     * Default constructor.
     *
     * @param traits  array hash customization traits
     */
    array_hash(const array_hash_traits &traits = array_hash_traits()) :
            _traits(traits) {
        _data = new char *[_traits.slot_count];
        for (int i = 0; i < _traits.slot_count; ++i) {
            _data[i] = NULL;
        }
        _size = 0;
    }

    /**
     * Standard destructor.
     */
    ~array_hash() {
        for (int i = 0; i < _traits.slot_count; ++i) {
            delete [] _data[i];
        }
        delete [] _data;
    }

    /**
     * Determines whether @a str is in the table.
     *
     * @param str  string to search for
     * @return  true iff @a str is in the table
     */
    bool exists(const char *str) const {
        // Determine which slot in the table should contain str.
        length_type length;
        char *p = _data[_hash(str, length)];

        // Return true if p is in that slot.
        if (p == NULL) {
            return false;
        }
        size_type s;
        return _search(str, p, length, s) != NULL;
    }

    /**
     * Gets the number of elements in the table.
     */
    size_t size() const {
        return _size;
    }

    /**
     * Gets the traits associated with this array hash.
     */
    const array_hash_traits &traits() const {
        return _traits;
    }

    /**
     * Inserts @a str into the table.
     *
     * @param str  string to insert
     * @return  true if @a str is successfully inserted, false if @a str
     *          already appears in the table
     */
    bool insert(const char *str) {
        length_type length;
        int slot = _hash(str, length);
        char *p = _data[slot];
        if (p) {
            size_type occupied;
            if (_search(str, p, length, occupied) != NULL) {
                // str is already in the table. Nothing needs to be done.
                return false;
            }

            // Resize the slot if it doesn't have enough space.
            size_type current = *((size_type *)(p));
            size_type required = occupied + sizeof(length_type) + length;
            if (required > current) {
                _grow_slot(slot, current, required);
            }

            // Position for writing to the slot.
            p = _data[slot] + occupied - sizeof(length_type);

        } else {
            // Make a new slot for this string.
            size_type required =
                sizeof(size_type) + 2 * sizeof(length_type) + length;
            _grow_slot(slot, 0, required);

            // Position for writing to the slot.
            p = _data[slot] + sizeof(size_type);
        }

        // Write str into the slot.
        _append_string(str, p, length);
        ++_size;
        return true;
    }

    /**
     * Erases a string from the hash table.
     *
     * @param str  string to erase
     */
    void erase(const char *str) {
        length_type length;
        int slot = _hash(str, length);
        char *p = _data[slot];
        if (p) {
            size_type occupied;
            if ((p = _search(str, p, length, occupied)) != NULL) {
                _erase_word(p, slot);
            }
        }
    }

    /**
     * Erases a string from the hash table.
     *
     * @param pos  iterator to the string to erase
     */
    void erase(const iterator &pos) {
        _erase_word(pos._p, pos._slot);
    }

    /**
     * Gets an iterator to the first element in the table.
     */
    iterator begin() const {
        iterator result;
        if (size() == 0) {
            result = end();
        } else {
            result._data = _data;
            while (result._data[result._slot] == NULL) {
                ++result._slot;
            }
            result._p = result._data[result._slot] + sizeof(size_type);
        }
        result._slot_count = _traits.slot_count;
        return result;
    }

    /**
     * Gets an iterator to one past the last element in the hash table.
     */
    iterator end() const {
        return iterator(_traits.slot_count, NULL, _data, _traits.slot_count);
    }

    /**
     * Searches for @a str in the table.
     *
     * @param str  string to search for
     * @return  iterator to @a str in the table, or @a end() if @a str
     *          is not in the table
     */
    iterator find(const char *str) const {
        // Determine which slot in the table should contain str.
        length_type length;
        int slot = _hash(str, length);
        char *p = _data[slot];

        // Search for str in that slot.
        if (p == NULL) {
            return end();
        }
        size_type s;
        p = _search(str, p, length, s);
        return iterator(slot, p, _data, _traits.slot_count);
    }

    class iterator : std::iterator<std::bidirectional_iterator_tag,
                                   const char *> {
        friend class array_hash;

      public:
        iterator() : _slot(0), _p(NULL), _data(NULL) { }

        /**
         * Move this iterator forward to the next element in the table.
         *
         * @return  self-reference
         */
        iterator& operator++() {
            // Move p to the next string in this slot.
            if (_p) {
                _p += *((length_type *) _p) + sizeof(length_type);
                if (*((length_type *) _p) == 0) {
                    // Move down to the next slot.
                    ++_slot;
                    while (_slot < _slot_count && _data[_slot] == NULL) {
                        ++_slot;
                    }

                    if (_slot == _slot_count) {
                        // We are at the end. Make this an end iterator
                        _p = NULL;
                    } else {
                        // Move to the first element in this slot.
                        _p = _data[_slot] + sizeof(size_type);
                    }
                }
            }
            return *this;
        }

        /**
         * Move this iterator backward to the previous element in the table.
         *
         * @return  self-reference
         */
        iterator& operator--() {
            return *this;
        }

        /**
         * Iterator dereference operator.
         *
         * @return  character pointer to the string this iterator points to
         */
        const char *operator*() const {
            if (_p) {
                return _p + sizeof(length_type);
            }
            return NULL;
        }

        /**
         * Standard equality operator.
         */
        bool operator==(const iterator& rhs) {
            return _p == rhs._p;
        }

        /**
         * Standard inequality operator.
         */
        bool operator!=(const iterator& rhs) {
            return !operator==(rhs);
        }

      private:
        int _slot;
        char *_p;
        char **_data;
        int _slot_count;

        iterator(int slot, char *p, char **data, int slot_count) :
                 _slot(slot), _p(p), _data(data),
                 _slot_count(slot_count) { }
    };

  private:
    array_hash_traits _traits;
    size_t _size;
    char **_data;

    /**
     * Hashes @a str to an integer, its slot in the hash table.
     *
     * @param str     string to hash
     * @param length  length of @a str. Calculated as this function runs
     * @param seed    seed for the hash function
     *
     * @return  hashed value of @a str, its slot in the table
     */
    int _hash(const char *str, length_type &length, int seed = 23) const {
        int h = seed;
        length = 0;
        while (str[length]) {
            // Hash this character.
            h = h ^ ((h << 5) + (h >> 2) + str[length]);
            ++length;
        }

        ++length;  // include space for the NULL terminator
        return h & (_traits.slot_count - 1);  // same as h %
                                              // _traits.slot_count if
                                              // _traits.slot_count is a
                                              // power of 2
    }

    /**
     * Searches for @a str in the table.
     *
     * @param str       string to search for
     * @param length    length of @a str
     * @param p         slot in @a data that @a str goes into
     * @param occupied  number of bytes in the slot that are currently in use.
     *                  This value is only meaningful when this function
     *                  doesn't find @a str
     *
     * @return  If @a str is found in the table, returns a pointer to
     *          the string and its corresponding length. If not, returns NULL.
     */
    char *_search(
            const char *str,
            char *p,
            length_type length,
            size_type &occupied) const {
        occupied = -1;
        char *start = p;

        // Search for str in the slot p points to.
        p += sizeof(size_type);  // skip past size at beginning of slot
        length_type w = *((length_type *) p);
        while (w != 0) {
            p += sizeof(length_type);
            if (w == length) {
                // The string being scanned is the same length as str.
                // Make sure they aren't the same string.
                if (strncmp(str, p, length) == 0) {
                    // Found str.
                    return p - sizeof(length_type);
                }
            }
            p += w;
            w = *((length_type *) p);
        }
        occupied = p - start + sizeof(length_type);
        return NULL;
    }

    /**
     * Increases the capacity of a slot to be >= required.
     *
     * @param slot      slot to change
     * @param current   current size of the slot
     * @param required  required size of the slot
     */
    void _grow_slot(int slot, size_type current, size_type required) {
        // Determine how much space the new slot needs.
        size_type new_size = current;
        while (new_size < required) {
            new_size += _traits.allocation_chunk_size;
        }

        // Make a new slot and copy all the data over.
        char *p = _data[slot];
        _data[slot] = new char[new_size];
        if (p != NULL) {
            memcpy(_data[slot], p, current);
            delete [] p;
        }
        *((size_type *)(_data[slot])) = new_size;
    }

    /**
     * Appends a string to a list of strings in a slot.
     *
     * @param str     string to append
     * @param p       pointer to the location in the slot this string
     *                should occupy
     * @param length  length of @a str
     */
    void _append_string(const char *str, char *p, length_type length) {
        // Write the length of the string, the string itself, the NULL
        // terminator, and a 0 after all of that (for the length of the
        // next string).
        memcpy(p, &length, sizeof(length_type));
        p += sizeof(length_type);
        memcpy(p, str, length);
        p += length;
        length = 0;
        memcpy(p, &length, sizeof(length_type));
    }

    /**
     * Erases a word from a slot in the table.
     *
     * @param p     word to erase
     * @param slot  slot @a p is in
     */
    void _erase_word(char *p, int slot) {
        int length = *(length_type *)(p);
        size_type size = *((size_type *)_data[slot]);

        // Erase the word by overwriting it.
        int n = size - (p - _data[slot]);
        memcpy(p, p + sizeof(length_type) + length, n);

        // If that made the slot empty, erase the slot.
        if (*((length_type *)(_data[slot] + sizeof(size_type))) == 0) {
            delete [] _data[slot];
            _data[slot] = NULL;
        }
        --_size;
    }

};

}  // namespace stx

#endif  // ARRAY_HASH_H

