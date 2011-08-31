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
	    
	    string c;
	    int a=line.find_first_not_of('<');
		   int b=line.find_last_not_of('>');
		   c.assign(   (const string&)line,a,b-a);
	    b=keys.insert(c);
	    ctr++;
	    if(b)cerr << c << endl;
	    
	  }
	}
	infile.close();
     
      } 
  }
  
}
