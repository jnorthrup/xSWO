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




 	 int test_sparql() {

#if 1
	   sparql_parser sparql; // Our parser
 string str(                " BASE <BtC> PREFIX r8DNA: <b%k> PREFIX EjBBa: <3)M> PREFIX YX6xO: <t~r> SELECT DISTINCT ?9iVy $9dcp FROM <-Rv> FROM NAMED ioANU:EAj3M FROM <0ZQ> WHERE { ?aJKL $z5l6 TqZ.q: , ( ?xJqk [ a 'P\\\\,' @ho-jj-wV-Zi , ( ) , $KGBc ; <=$d> [ a 21 , ( ?eZ6t [ $8LsO true , ( ) , ?EESP ; ; a [ z18px:N8rKT _:fdQ0P , ( $ggWm [ a ( ) , ( ) , ?86TQ ] [ $FZ8C <a> , ( ?ANtz ) , [ a \"g\\r4\" ^^ yFSOt: , ( $Qvc3 [ </dP> +13 ; ; a ( ) , ?fXeV , [ $e6C0 false , ( ?gInH [ a [ ] ; ] ) , ( $fsyx [ ZP5G2:TVKWV ( ) , ( ) , ?L5E9 ; a [ $SC1y <umG> , ( ?yghH [ a ''''R'\\\"'P''' @QD-nc-GB-YN , ( ) , $UXuw ; ; jOurI: [ a -97 , ( ?2t_N [ $JE77 true , ( ) , ?pfDb ] [ a _:MeHdb , ( $Uuoe ) , [ <01a> ( ) , ( ?aYFc [ a Z22h3:29MC3 ; ; $eIkV ( ) , ?1Vyu , [ a \"\"\"\"t\"\"\" ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) } "
				);
	 
parse_info<> info = parse(str.c_str(), sparql, space_p);
       cout << (info.full ? "+" : "-")<< endl;

#else
	 
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
#endif
   return 0;
 }
