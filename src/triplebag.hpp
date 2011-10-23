#pragma once

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/set.hpp> 
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>  
#include <boost/multi_index/hashed_index.hpp> 
#include <boost/multi_index/key_extractors.hpp> 
#include <boost/multi_index/member.hpp> 
#include <boost/multi_index/ordered_index.hpp> 
#include <boost/multi_index/sequenced_index.hpp> 
#include <boost/multi_index_container.hpp>   

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // remove
#include <algorithm>
#include <functional>
#include <iomanip> 
#include <iterator>
#include <map> 
#include <set> 
#include <sstream> 
#include <string> 
#include <utility> 

#pragma warning(   once : 4561  )

#pragma once

using namespace boost::serialization;//multi_index;
using namespace boost::multi_index;
using namespace boost::tuples; 
using namespace boost; 
using namespace std; 
namespace xModel{ 
	
	/**
	 Intelligent Object Handler.  
	 this provides the communciation layer to generically and efficiently send object notifications by reference around the localized runtime objects in a consumer provider model.
	 
	 Unlike a "Framework" level of communication abstractions, the "subscribers" are merely callbacks, wrapped in STL names.
	 */
	namespace xEvent{
		
		/**
		 the source of events.  
		 A Publisher provides events to a collection of subscribers (callback functions).
		 This implementation uses mutliple inheritance to provide "IsA" container 
		 for add/remove of shared_ptrs to subscribers.  
		 
		 */
		template < typename event_t,
		typename container_t=std::set< 
		shared_ptr < 
		unary_function< event_t&, event_t & > 
		>			 >
		>struct publisher:container_t,unary_function< event_t&, event_t& > {
		event_t& operator ()( event_t &x){
		for(typename container_t ::iterator iter= begin();iter!= end();++iter)
		**iter(x);
		return x;
	};
};
};

namespace xPersist{
	template <typename Literal=std::string>
	struct triple{
	/**
	 literals definition. 
	 
	 intended as boost::fusion ultimately
	 
	 */
	
	Literal s,  p ,  o;
	
	
	triple(const string &s2=T(),const string &p2=T(),const string &o2=T()):s(s2),p(p2),o(o2){};
	
	const Literal &subject  () const {return s;};
	const Literal &predicate() const  {return p;};
	const Literal &object()   const  {return o;} ;
	
	const bool operator < ( const triple&t2) const {
		return (s!=t2.s)?(s<t2.s):
		(p!=t2.p)?(p<t2.p):				
		(o<t2.o);
	};
	friend class boost::serialization::access;
	/**
	 serialization using boost xml serialization name-value pairs.
	 @param version defaults a subversion changeset in which the routine was first committed.  
	 */
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version=0)	{
		ar & make_nvp("s", s);
		ar & make_nvp("p", p);
		ar & make_nvp("o", o);
	};
	/** a set-like context for triples.  performs sorting and folding.				
	 */
	typedef multi_index_container
		< triple,
		indexed_by<
		ordered_unique< identity< triple > >,
		hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, subject) >,
		ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, subject) >,
		hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, predicate) >,
		ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, predicate) >,
		hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, object) >,
		ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, object) >				
		>  > normalized_triple_context;
	
	/**
	 a log-like bag of triples without sorting or node removal.
	 */
	typedef multi_index_container
		< triple,
		indexed_by<
		sequenced<>,
		hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, subject) >,
		ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, subject) >,
		hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, predicate) >,
		ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, predicate) >,
		hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, object) >,
		ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( triple, const Literal&, object) >
		>  > log_triple_context;
	
}; 
} ;
};