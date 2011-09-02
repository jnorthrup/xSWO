 
 

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
 
#include<vector>
using namespace std; 

using namespace boost::serialization;//multi_index;
using namespace boost::multi_index;
using namespace boost::tuples; 
using namespace boost;  
namespace xModel{ 
  template <typename Literal=std::string>
  struct quad{
    /**   literals definition. 	 
     */
	
    Literal s,  p ,  o,c;
	
	
    quad( const  Literal &s2=Literal(),const  Literal &p2=Literal(),const Literal   &o2=Literal(),const Literal   &c2=Literal()):s(s2),p(p2),o(o2),c(c2){};
	
    const Literal &subject  () const  {return s;};
    const Literal &predicate() const  {return p;};
    const Literal &object()    const  {return o;};
    const Literal &context()   const  {return c;};
	
    const bool operator < ( const quad&t2) const {
      return (s!=t2.s)?(s<t2.s):
	(p!=t2.p)?(p<t2.p):	
	(o!=t2.o)?(o<t2.o):						
	(c<t2.c);
    };
//     friend class boost::serialization::access;
//     /**
//        serialization using boost xml serialization name-value pairs.
//        @param version defaults a subversion changeset in which the routine was first committed.  
//     */
//     template<class Archive>
//     void serialize(Archive & ar, const unsigned int version=0)	{
//       ar & make_nvp("s", s);
//       ar & make_nvp("p", p);
//       ar & make_nvp("o", o);	
//       ar & make_nvp("c", c);

//     };
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
      ordered_non_unique< BOOST_MULTI_INDEX_CONST_MEM_FUN( quad, const Literal&, context) > > > normalized_quad_context;
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
}

using namespace xModel; 

int main(int argc, char** argv){

  quad<string> q("a","b","c","d");
  			 
   vector<quad<string> > v  ;
   v.push_back(q);	 

//   quad<string>::normalized_quad_context n ;										 
  quad<string>::log_quad_context l ;		
  
//   l.insert(n.end(),v.begin(),v.end());
  l.push_back(q);

											  
}
