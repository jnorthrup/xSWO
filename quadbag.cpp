#include "quadbag.hpp"
#include "hat_set.h"

using namespace xModel;
using namespace stx;
#include<fstream>											 
#include<iostream>
int main(int argc,const char**argv){ 
  hat_trie<std::string>keys;
  typedef hat_trie<string>::_node_pointer  hat_tag;
  quad<string>::log_quad_context log;

  vector<string>row;

  
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]); 
  {


      for(int i=0;i<args.size();i++)      {
	
 	std::cerr << args[i] <<'\n'; 
	std::ifstream infile((args[i]).c_str());  

	string line;
	vector <string> row;	

	while(infile >>  line  ){
 	  {
	    string c( line[0]=='<' ? line.substr(1,line.find_last_not_of('>')):  (line)); 

	      keys.insert(c);
	      row.push_back(c);
	     
	    
	    if(c=="."){	       
	      	      if(row.size()>3)	
	      log.push_back(quad<string>(row[0],row[1],row[2],row[3]));  
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
