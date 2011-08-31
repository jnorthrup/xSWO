#include "quadbag.hpp"

#include<boost/tokenizer.hpp>
#include "hat_set.h"

using namespace xModel;
using namespace stx;
       														 
int main(int argc,const char**argv){
  string ws= " <>";
  int ctr=0;
  hat_set <std::string>keys;

  quad<pair<long,unsigned char> >:: normalized_quad_context  qc();
 
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]);


  
  { 
    for(int i=0;i<args.size();i++)
      {

	string iter(args[i]);
	std::cout << iter <<'\n'; 
	std::ifstream infile((iter).c_str()); 


	string line;
	while(infile >>  line  ){
 	  {
	    string c;bool b;
	    if(line[0]=='<')
	      c=line.substr(1,line.find_last_not_of('>'));
	    else
	      c=(line);
	    b=keys.insert(c);
	    if(b){
	      cerr << c << endl;
	      ctr++;
	    }
	    
	  }
	}
	infile.close();
     
      } 
  }
  
}
