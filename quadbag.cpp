#include "quadbag.hpp"

using namespace xModel;
															 
int main(int argc,const char**argv){

  quad<pair<long,unsigned char> >:: normalized_quad_context  qc();
  int c=0;
  std::vector<std::string>args(argc);
  for (int c=0;c<argc;++c)
    args.push_back(argv[c]);

  for(std::vector<std::string>::iterator iter=args.begin();iter!=args.end();++iter){   
    std::cout << *iter <<'\n'; 
    std::ifstream infile((*iter).c_str());
    while(infile.good()){char buf[1024];

      infile.     getline (buf,1024);
      string line(buf);
      cout << line << '\n';
    }
    infile.close();
  }
  
  

}
