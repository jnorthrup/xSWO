#include "quadbag.hpp"
#include "hat_set.h"
#include <fstream>
#include <ios>
#include <vector>
#include<fstream>
#include<iostream>
#include <string>

using namespace xModel;
using namespace stx;
using namespace std;
int main(int argc,
const char **argv){
   hat_trie <string>keys;

 
  vector<string>args(argc);
  for(int c=1;c<argc;++c)args.push_back(argv[c]);
 

  { 
//#pragma omp parallel  for 
    for(int i=0;i<args.size();i++){

	string iter(args[i]);
	cerr << iter <<'\n'; 
	ifstream infile((iter).c_str());  

	string line;
	while(infile >>  line  ){
 	  {
	    string c;bool b;
	    if(line[0]=='<')
	      c=line.substr(1,line.find_last_not_of('>'));
	    else
	      c=(line);

//#pragma omp critical(keyupdate) 
	    {	    b=keys.insert(c); }
	  }
	}
	infile.close();
     
    }
  }

    typedef hat_trie<string>::_node_pointer  hat_tag;
    quad< const hat_tag* >::log_quad_context log;




      {
      for(int i=0;i<args.size();i++){

 	cerr << args[i] <<'\n';
	ifstream infile((args[i]).c_str());  

	string line;
	vector <hat_tag> row;

	while(infile >> line  ){
 	  {
	    string c( line[0]=='<' ? line.substr(1,line.find_last_not_of('>')):  (line)); 

	    hat_tag tag(keys._locate(c.c_str()));
	    row.push_back(tag);
	    
	    if(c=="."){
	      if(row.size()>3)	
		log.push_back(quad<  const hat_tag* >(&row[0],&row[1],&row[2],&row[3]));
	      row.clear();
	    }
	  }
	}
	infile.close(); 
 
      } 
    }


 
/*
  for(hat_set<string>::iterator iter=keys.begin();iter!=keys.end();++iter){
    cout << *iter << endl ; 
  }
*/
}
