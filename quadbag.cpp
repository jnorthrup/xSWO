#include "quadbag.hpp"

#include<boost/tokenizer.hpp>

using namespace xModel;
															 
int main(int argc,const char**argv){
  string ws= " <>";

  quad<pair<long,unsigned char> >:: normalized_quad_context  qc();
 
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]);


  
   {
#pragma omp parrallel  for schedule(static,12)
     for(int i=0;i<args.size();i++)
      {

	string iter(args[i]);
	std::cout << iter <<'\n'; 
	std::ifstream infile((iter).c_str()); 


	    string line;
	while(infile >> line){
 	  {

    std::cout << "[" <<  line << "] ";
 	    
	  }
	}
	infile.close();
     
      } 
  }
  
}
