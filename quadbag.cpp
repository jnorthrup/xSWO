#include "quadbag.hpp"

using namespace xModel;
															 
int main(int argc,const char**argv){
  string ws= " <>";

  quad<pair<long,unsigned char> >:: normalized_quad_context  qc();
 
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]);


#pragma omp parallel num_threads(3)
  {
   
#pragma omp for
    for(int i=0;i<args.size();i++)
      {

	string iter(args[i]);
      std::cout << iter <<'\n'; 
      std::ifstream infile((iter).c_str());
      char       buf[2048];
      while(infile.good())
	infile.getline(buf,2048);
      
      infile.close();
     
    } 
  }
  
}
