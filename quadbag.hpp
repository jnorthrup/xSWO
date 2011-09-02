#pragma once
 
#include <boost/multi_index/hashed_index.hpp> 
#include <boost/multi_index/key_extractors.hpp> 
#include <boost/multi_index/member.hpp> 
#include <boost/multi_index/ordered_index.hpp> 
#include <boost/multi_index/sequenced_index.hpp> 
#include <boost/multi_index_container.hpp>   
  

#pragma warning(   once : 4561  )

#pragma once

using namespace boost::serialization;//multi_index;
using namespace boost::multi_index;
using namespace boost::tuples; 
using namespace boost; 
using namespace std; 
namespace xModel{ 
  template <typename Literal=std::string>
  struct quad{
    /**   literals definition. 	 
     */
	
    Literal s,  p ,  o,c;
	
	
    quad(const Literal &s2 ,const Literal &p2 ,const Literal & o2 ,const Literal &c2 ):s(s2),p(p2),o(o2),c(c2){};
	
    const Literal &subject  () const  {return s;};
    const Literal &predicate() const  {return p;};
    const Literal &object()    const  {return o;} ;
    const Literal &context()   const  {return c;} ;
	
    const bool operator < ( const quad&t2) const {
      return (s!=t2.s)?(s<t2.s):
	(p!=t2.p)?(p<t2.p):
	(o!=t2.o)?(o<t2.o):
	(c<t2.c);
    }; 
    /** a set-like context for quads.  performs sorting and folding.				
     */
    typedef multi_index_container
    < quad,
      indexed_by<
      ordered_unique< identity< quad > >,
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, subject) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, subject) >,
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, predicate) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, predicate) >,
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, object) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, object) >,				
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, context) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, context) >						> > normalized_quad_context;
    /**
       a log-like bag of quads without sorting or node removal.
    */
    typedef multi_index_container
    < quad,
      indexed_by<
      sequenced<>,
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, subject) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, subject) >,
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, predicate) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, predicate) >,
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, object) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, object) >,
      hashed_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, context) >,
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, context) >
    > > log_quad_context;
  }; 
};
