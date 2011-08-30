#include "quadbag.hpp"

using namespace xModel;
															 
int main(int argc,const char**argv){

  quad<>::  normalized_quad_context  qc();
  int c=0;
  std::vector<std::string>args(argc);
  for (int c=0;c<argc;++c)args.push_back(argv[c]);
  for(std::vector<std::string>::iterator iter=args.begin();iter!=	args.end();++iter)     std::cout << *iter ; 
}
