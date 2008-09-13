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
    sparql_parser sparql;
	
#if 1
    std::string const str = " BASE <BtC> PREFIX r8DNA: <b%k> PREFIX EjBBa: <3)M> PREFIX YX6xO: <t~r> SELECT DISTINCT ?9iVy $9dcp FROM <-Rv> FROM NAMED ioANU:EAj3M FROM <0ZQ> WHERE { ?aJKL $z5l6 TqZ.q: , ( ?xJqk [ a 'P\\\\,' @ho-jj-wV-Zi , ( ) , $KGBc ; <=$d> [ a 21 , ( ?eZ6t [ $8LsO true , ( ) , ?EESP ; ; a [ z18px:N8rKT _:fdQ0P , ( $ggWm [ a ( ) , ( ) , ?86TQ ] [ $FZ8C <a> , ( ?ANtz ) , [ a \"g\\r4\" ^^ yFSOt: , ( $Qvc3 [ </dP> +13 ; ; a ( ) , ?fXeV , [ $e6C0 false , ( ?gInH [ a [ ] ; ] ) , ( $fsyx [ ZP5G2:TVKWV ( ) , ( ) , ?L5E9 ; a [ $SC1y <umG> , ( ?yghH [ a ''''R'\\\"'P''' @QD-nc-GB-YN , ( ) , $UXuw ; ; jOurI: [ a -97 , ( ?2t_N [ $JE77 true , ( ) , ?pfDb ] [ a _:MeHdb , ( $Uuoe ) , [ <01a> ( ) , ( ?aYFc [ a Z22h3:29MC3 ; ; $eIkV ( ) , ?1Vyu , [ a \"\"\"\"t\"\"\" ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) ] ] ) } ";
#else
    std::string const str = " BASE <0l5>    PREFIX  fzmrW: <p3?>   PREFIX  nh.W0: <tnB>   PREFIX  H6acq: <gsL>   SELECT    DISTINCT   ?Rwse $3jSw     FROM <kQe>   FROM   NAMED b950C:qnB2z   FROM <-#z>     WHERE    {     ?EanT  $btmG   LdyeK:    ,   (   ?4jKt   [    a    '\fG'  @HU-8b-uY-pX    ,   (    )   , $UJsD    ;   <o,,>    [    a   91    ,   (   ?uWj_   [   $cCLQ    true    ,   (    )   , ?IvKM    ;    ;    a    [   nI3tL:s3LHC   _:vxakc    ,   (   $tLHf   [    a   (     )    ,   (    )   , ?6iTg   ]   [   $pRGx   <zuE>    ,   (   ?jmGQ  )   ,   [    a    \"g\"     ]   ]  )   ]   ]  )   ]   ]  )      }    ";
#endif
	
    parse_info<> info = parse(str.c_str(), sparql, space_p);
    std::cout << (info.full ? '+' : '-') << std::endl;
#else
    std::cout << "/////////////////////////////////////////////////////////\n\n"
	<< "  Expression parser...\n\n"
	<< "/////////////////////////////////////////////////////////\n\n"
	<< "Type an expression...or [q or Q] to quit\n\n";
    sparql_parser sparql;
	
    std::string str;
	
    while (std::getline(std::cin, str))
    {
        parse_info<> info = parse(str.c_str(), sparql, space_p);
        std::cout << (info.full ? '+' : '-');
    }
	
    std::cout << "Bye... :-)\n" << std::endl;
#endif
    return 0;
}