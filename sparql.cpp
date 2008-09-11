/*
 *  sparql.cpp
 *  xSWO
 *
 *  Created by jim on 9/9/08.
 *  Copyright 2008 Glamdring Inc. Enterprises. All rights reserved.
 *
 */

#include "sparql.h"

////////////////////////////////////////////////////////////////////////////
//
// Main program
//
////////////////////////////////////////////////////////////////////////////



 int
 test_sparql()
 {


   cout << "/////////////////////////////////////////////////////////\n\n";
   cout << "  Expression parser...\n\n";
   cout << "/////////////////////////////////////////////////////////\n\n";
   cout << "Type an expression...or [q or Q] to quit\n\n";
   sparql_parser sparql; // Our parser
 
   string str;

   while (getline(cin, str))
     {
       parse_info<> info = parse(str.c_str(), sparql, space_p);
       cout << (info.full ? "+" : "-");
     }

   cout << "Bye... :-) \n\n";

   return 0;

 }
