#include "quadbag.hpp"
#include "hat_set.h"

using namespace xModel;
using namespace stx;
       														 
int main(int argc,const char**argv){ 
  hat_set <std::string>keys;
  typedef hat_set <std::string>::iterator hat_tag;
  typedef quad<hat_tag>   hat_quad ; 
  
  hat_quad::log_quad_context log;
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]); 
  {
#pragma omp parallel for

      for(int i=0;i<args.size();i++)      {
	
 	std::cerr << args[i] <<'\n'; 
	std::ifstream infile((args[i]).c_str());  

	string line;
	vector <hat_tag> row;
	while(infile >>  line  ){
 	  {
	    string c( line[0]=='<' ? line.substr(1,line.find_last_not_of('>')):  (line)); 

	    //first million insert-always.
	    //todo: monotonic performing pair<iterator,bool> insert(key)
	    //todo: (implement or verify) global cached cursor for the trie 

	      hat_tag t (keys.size()<1000000 ? keys.end():keys.find(c)); 
	    if(t==keys.end()){
	      keys.insert(c);  
	      t=keys.find(c);
	    }
	    row.push_back(t);
	    
	    if(c=="."){	       
	      hat_quad hq(row[0],row[1],row[2],row[3]);
	      log.push_back(hq);	      
	      row.clear();
	    }
	  }
	}
	infile.close(); 
 
      } 
  }
 
    for(hat_set<std::string>::iterator iter=keys.begin();iter!=keys.end();++iter){
      cout << *iter << endl ; 
    }

}
