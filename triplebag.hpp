#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include <cstdio> // remove

#if defined(BOOST_NO_STDC_NAMESPACE)
namespace std{ 
	using ::remove;
}
#endif

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/version.hpp>
#include <boost/array.hpp>
#include <boost/functional/hash/hash.hpp> 
#include <boost/multi_index/hashed_index.hpp> 
#include <boost/multi_index/key_extractors.hpp> 
#include <boost/multi_index/member.hpp> 
#include <boost/multi_index/ordered_index.hpp> 
#include <boost/multi_index/sequenced_index.hpp> 
#include <boost/multi_index_container.hpp>  
#include <boost/shared_array.hpp> 
#include <boost/shared_ptr.hpp> 
#include <boost/tokenizer.hpp> 
#include <boost/tuple/tuple_comparison.hpp> 
#include <boost/tuple/tuple_io.hpp>
#include <boost/tuple/tuple_io.hpp> 

#include <algorithm>
#include <functional>
#include <iomanip> 
#include <iostream>
#include <iostream> 
#include <iterator>
#include <map> 
#include <set> 
#include <sstream> 
#include <string> 
#include <utility> 

#pragma warning(   once : 4561  )

using namespace boost::serialization;//multi_index;
using namespace boost::multi_index;
using namespace boost::tuples; 
using namespace boost; 
using namespace std; 
namespace xSWO{ 

	/**
	Intelligent Object Handler.  
	this provides the communciation layer to generically and efficiently send object notifications by reference around the localized runtime objects in a consumer provider model.

	Unlike a "Framework" level of communication abstractions, the "subscribers" are merely callbacks, wrapped in STL names.
	*/
	namespace xIO{

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
		> 		
		struct publisher:container_t	 ,unary_function< event_t&, event_t& > {

			event_t& operator ()( event_t &x){
				for(typename container_t ::iterator iter= begin();iter!= end();++iter)
					**iter(x);
				return x;
			};
		};
	};

	namespace IOP{

		typedef string 	resource; 
		typedef resource literal;
		typedef resource /*shared_ptr <resource>*/  uri;

		struct node
		{
			friend class boost::serialization::access;  
		public:
			string subject;
			set<pair<string,string> >arcs;
			node()
				:subject(""){
			}
			node(const resource &s_,const resource &p,const resource &o):
			subject(s_==""?),arcs()
			{
				arcs.insert(make_pair(p,o) ) ;

			};		
			template <typename Archive>

			void serialize(Archive & ar, const unsigned int file_version )
			{
				//ar.template register_type<bus_stop_corner>();
				ar.register_type(static_cast<pair<string,string> *>(NULL));
				//ar.template register_type<bus_stop_destination>();
				ar.register_type(static_cast<pair<string,string> *>(NULL));
				// serialization of stl collections is already defined
				// in the header
				ar & BOOST_SERIALIZATION_NVP(arcs);
			};

		};

		typedef node triple;
		typedef set<node > graph;
		typedef xSWO::xIO::publisher<graph> event_context;
		typedef set<graph> model;
		typedef set <model> model_storage;


#if 0 

		/**

		Javadoc .  Javadoc Comment placed here.

		Here too.


*/
		template <typename T> 
		struct store: 
			multi_index_container< 
			T, 
			hashed_unique<const_mem_fun<id,&T::get< 0 > > > 
			>  //,    hashed_non_unique <const_mem_fun <objecttype,&triple::get< 4> > > 
	  >  ; 

		//typedef store<triple> triples_s; 
		typedef store<resource> resources_s; 
		typedef store<ns> nss_s; 
		typedef store<literal> literals_s; 
		typedef store<model> models_s; 
#endif
	} ;
}  
