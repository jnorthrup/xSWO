 
#include <fstream>
#include <ios>

 #include <vector>
 #include <string>
#include "hat_set.h" 

using namespace stx;
using namespace std;
       														 
int main(int argc,const char**argv){  
  hat_set <std::string>keys;
 
 
  std::vector<std::string>args(argc);
  for (int c=1;c<argc;++c)
    args.push_back(argv[c]);
 

  { 
#pragma omp parallel  for 
    for(int i=0;i<args.size();i++)
      {

	string iter(args[i]);
	std::cerr << iter <<'\n'; 
	std::ifstream infile((iter).c_str());  

	string line;
	while(infile >>  line  ){
 	  {
	    string c;bool b;
	    if(line[0]=='<')
	      c=line.substr(1,line.find_last_not_of('>'));
	    else
	      c=(line);

#pragma omp critical(keyupdate) 
	    {	    b=keys.insert(c); }
	    
	    
	   
	    
	    
	  }
	}
	infile.close();
     
      } 
  }
  for(hat_set<std::string>::iterator iter=keys.begin();iter!=keys.end();++iter){
    cout << *iter << endl ; 
  }
  
}
