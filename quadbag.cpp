#include "quadbag.hpp"
#include "hat_set.h"

using namespace xModel;
using namespace stx;
       														 
int main(int argc,const char**argv){ 
  hat_set <std::string>keys;
  typedef  hat_set <std::string>::iterator hat_tag;
  quad<  string >:: normalized_quad_context  qc();
 
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]); 
  {
#pragma omp parallel for

      for(int i=0;i<args.size();i++)      {
	
	vector< string>qr ;
	string iter(args[i]);
	std::cerr << iter <<'\n'; 
	std::ifstream infile((iter).c_str());  

	string line;
	while(infile >>  line  ){
 	  {
	    string c( line[0]=='<' ? line.substr(1,line.find_last_not_of('>')):  (line)); 
	    qr.push_back( c);
	    if(c=="."){	       
	      int ctr=0;
	      for(vector<string>::iterator iter=qr.begin();qr.end()!=iter;++iter){
#pragma omp critical 
		{ 
		  keys.insert(*iter);  
		};
		
		qc.insert(&	quad<string>(qr[0],qr[1],qr[2],qr[3]));
	      }
	      qr.clear();
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
