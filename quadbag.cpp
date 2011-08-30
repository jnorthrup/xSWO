#include "quadbag.hpp"

using namespace xModel;
															 
int main(int argc,const char**argv){
  string ws= " <>";

  quad<pair<long,unsigned char> >:: normalized_quad_context  qc();
 
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]);

  for(std::vector<std::string>::iterator iter=args.begin();iter!=args.end();++iter){   
    std::cout << *iter <<'\n'; 
    std::ifstream infile((*iter).c_str());
    while(infile.good()){char buf[2024];

      infile.     getline (buf,2024);
      string line(buf);
    }
    infile.close();
  }
  
  

}
