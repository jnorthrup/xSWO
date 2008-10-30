/*
 *  sql2003.cpp
 *  xSWO
 *
 *  Created by jim on 9/9/08.
 *  Copyright 2008 Glamdring Inc. Enterprises. All rights reserved.
 *
 */

#include "sql2003.hpp"

////////////////////////////////////////////////////////////////////////////
//
// Main program
//
////////////////////////////////////////////////////////////////////////////




int test_sql2003() {
#if 1
    sql2003_parser sql2003;

#if 1
    std::string const str = " SELECT * FROM  users WHERE id IS NOT NULL;" ;
#else
    std::string const str = " BASE <0l5>    PREFIX  fzmrW: <p3?>   PREFIX  nh.W0: <tnB>   PREFIX  H6acq: <gsL>   SELECT    DISTINCT   ?Rwse $3jSw     FROM <kQe>   FROM   NAMED b950C:qnB2z   FROM <-#z>     WHERE    {     ?EanT  $btmG   LdyeK:    ,   (   ?4jKt   [    a    '\fG'  @HU-8b-uY-pX    ,   (    )   , $UJsD    ;   <o,,>    [    a   91    ,   (   ?uWj_   [   $cCLQ    true    ,   (    )   , ?IvKM    ;    ;    a    [   nI3tL:s3LHC   _:vxakc    ,   (   $tLHf   [    a   (     )    ,   (    )   , ?6iTg   ]   [   $pRGx   <zuE>    ,   (   ?jmGQ  )   ,   [    a    \"g\"     ]   ]  )   ]   ]  )   ]   ]  )      }    ";
#endif

    parse_info<> info = parse(str.c_str(), sql2003, space_p);
    std::cout << (info.full ? '+' : '-') << std::endl;
#else
    std::cout << "/////////////////////////////////////////////////////////\n\n"
	<< "  Expression parser...\n\n"
	<< "/////////////////////////////////////////////////////////\n\n"
	<< "Type an expression...or [q or Q] to quit\n\n";
    sql2003_parser sql2003;

    std::string str;

    while (std::getline(std::cin, str))
    {
        parse_info<> info = parse(str.c_str(), sql2003, space_p);
        std::cout << (info.full ? '+' : '-');
    }

    std::cout << "Bye... :-)\n" << std::endl;
#endif
    return 0;
}
