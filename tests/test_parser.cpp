


#include "sparql.h"

#include <iostream>

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
	
	
/*
	cout << "/////////////////////////////////////////////////////////\n\n";
	cout << "  Expression parser...\n\n";
	cout << "/////////////////////////////////////////////////////////\n\n";
	cout << "Type an expression...or [q or Q] to quit\n\n";
	sparql_parser sparql; // Our parser
	
	string str;
	
	char ** corpi{
                               " ",
 }
while (getline(cin, str))
{
parse_info<> info = parse(str.c_str(), sparql, space_p);
cout << (info.full ? "+" : "-");
}
*/
//
//cout << "Bye... :-) \n\n";

vector<const string&> s;
);s.push_back(string()+
                "     BASE <hok>    PREFIX  DOf-v: <z.\u007F>   PREFIX  XV2TB: <yy_>   PREFIX  XmToU: <HLG>   SELECT    DISTINCT   ?t3kz $Gv8N     FROM <yNO>   FROM   NAMED c1Wqi:d3AXh   FROM <4pD>     WHERE    {     ?kXve  $2SLN   FjXp6:    ,   (   ?FwR8   [    a    'Z\\\\\u001E'  @KJ-BL-DN-36    ,   (    )   , $Caaz    ;   <G_@>    [    a   89    ,   (   ?zPbW   [   $gAWm    true    ,   (    )   , ?tbOS    ;    ;    a    [   HBR.9:zMS3J   _:olIXY    ,   (   $ifB2   [    a   ( \n" +
                        "\t)    ,   (    )   , ?IDo2   ]   [   $q3p2   <e&@>    ,   (   ?P3SX  )   ,   [    a    \"4\\nE\"    ^^ XZKSq:    ,   (   $0Tmp   [   <9d6>   +85     ;    ;    a    (    )    , ?mPwg   ,   [   $Xan4    false    ,   (   ?lrtu   [    a   [\t\n" +
                        "\t]     ;   ]  )   ,   (   $_TX4   [   J5h2k:R8qmx   (\n" +
                        "  )    ,   (    )   , ?_h_W    ;    a    [   $0Wh5   <TZG>    ,   (   ?ah24   [    a    ''''c'\\n'4'''  @Bl-kO-xt-yd    ,   (    )   , $hBuN    ;    ;   lyqfD:    [    a   -08    ,   (   ?6sRu   [   $XpKy    true    ,   (    )   , ?FWFA   ]   [    a   _:ay61-    ,   (   $zlkg  )   ,   [   <\u007FlB>   (\n" +
                        " \n" +
                        ")    ,   (   ?LIWx   [    a   akJtm:0_ZpP     ;    ;   $kdRg    (    )    , ?O343   ,   [    a    \"\"\"\"3\"\\n\"\u001E\"\"\"    ^^ <yb5>    ,   (   $OQ_r   [   u6.Vc:   61.134     ;   ]  )   ,   (   ?TVxv   [    a    false    ,   (    )   , $9mv5    ;   ?PsWf    [    a   [ \t\t]    ,   (   $t_AA   [   <36$>   (\n" +
                        "\t\n" +
                        ")    ,   (    )   , ?dG3e    ;    ;    a    [   $eItF   Jaav7:Ftzec    ,   (   ?_JgF   [    a    '\\'#\\n'  @zY-2r-zC-Wg    ,   (    )   , $FsrA   ]   [   <&5V>   +.54    ,   (   ?SkiK  )   ,   [    a    true    ,   (   $oCkH   [   ?sYX7   _:8Q2l3     ;    ;    a    (    )    , $HRvK   ,   [   uiFcV:   (\t  )    ,   (   ?jM20   [    a   <[J+>     ;   ]  )   ,   (   $sMvP   [   ?7959    \"\\\\\u000F\\\\\"    ^^ dOPIM:DDekK    ,   (    )   , $IGYY    ;    a    [   <0%S>   -07.143    ,   (   ?dJ8P   [    a    false    ,   (    )   , $5SHL    ;    ;   ?SFFI    [    a   [\t\t\t]    ,   (   $rcwn   [   ztn_i:   (\n" +
                        "\n" +
                        ")    ,   (    )   , ?MHaY   ]   [    a   <L+N>    ,   (   $llpa  )   ,   [   ?OOxo    ''''\\t'C'\\b'''  @jl-99-Es-uf    ,   (   $2YhI   [    a   99.529e-08     ;    ;   s4YoI:oYU1K    (    )    , ?7vHc   ,   [    a    true    ,   (   $rr1A   [   ?GnsF   _:nXURp     ;   ]  )   ,   (   $Kqvh   [    a   (  \n" +
                        ")    ,   (    )   , ?ka9Q    ;   <E_Z>    [    a   WyZWf:    ,   (   $hnEr   [   ?ug5W    \"\"\"\"\\\\\"B\"\\n\"\"\"    ^^ <GlA>    ,   (    )   , $a6Oe    ;    ;    a    [   zGezS:5_.Rz   +.12E+56    ,   (   ?MeTq   [    a    false    ,   (    )   , $hFQ3   ]   [   ?W9ut   [\n" +
                        "  ]    ,   (   $36fG  )   ,   [    a   (\t\n" +
                        "\t)    ,   (   ?mK9n   [   <ZZl>   ofeRj:     ;    ;    a    (    )    , $cjtc   ,   [   ?44v3    '.\\n\u001F'  @Uu-Km-8g-9f    ,   (   $lb5W   [    a   -1E    ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )      }    ",
                 );s.push_back(string()+   

                "     BASE <hok>    PREFIX  DOf-v: <z.\u007F>   PREFIX  XV2TB: <yy_>   PREFIX  XmToU: <HLG>   SELECT    DISTINCT   ?t3kz $Gv8N     FROM <yNO>   FROM   NAMED c1Wqi:d3AXh   FROM <4pD>     WHERE    {     ?kXve  $2SLN   FjXp6:    ,   (   ?FwR8   [    a    'Z\\\u001E'  @KJ-BL-DN-36    ,   (    )   , $Caaz    ;   <G_@>    [    a   89    ,   (   ?zPbW   [   $gAWm    true    ,   (    )   , ?tbOS    ;    ;    a    [   HBR.9:zMS3J   _:olIXY    ,   (   $ifB2   [    a   ( \n" +
                        "\t)    ,   (    )   , ?IDo2   ]   [   $q3p2   <e&@>    ,   (   ?P3SX  )   ,   [    a    \"4\n" +
                        "E\"    ^^ XZKSq:    ,   (   $0Tmp   [   <9d6>   +85     ;    ;    a    (    )    , ?mPwg   ,   [   $Xan4    false    ,   (   ?lrtu   [    a   [\t\n" +
                        "\t]     ;   ]  )   ,   (   $_TX4   [   J5h2k:R8qmx   (\n" +
                        "  )    ,   (    )   , ?_h_W    ;    a    [   $0Wh5   <TZG>    ,   (   ?ah24   [    a    ''''c'\n" +
                        "'4'''  @Bl-kO-xt-yd    ,   (    )   , $hBuN    ;    ;   lyqfD:    [    a   -08    ,   (   ?6sRu   [   $XpKy    true    ,   (    )   , ?FWFA   ]   [    a   _:ay61-    ,   (   $zlkg  )   ,   [   <\u007FlB>   (\n" +
                        " \n" +
                        ")    ,   (   ?LIWx   [    a   akJtm:0_ZpP     ;    ;   $kdRg    (    )    , ?O343   ,   [    a    \"\"\"\"3\"\n" +
                        "\"\u001E\"\"\"    ^^ <yb5>    ,   (   $OQ_r   [   u6.Vc:   61.134     ;   ]  )   ,   (   ?TVxv   [    a    false    ,   (    )   , $9mv5    ;   ?PsWf    [    a   [ \t\t]    ,   (   $t_AA   [   <36$>   (\n" +
                        "\t\n" +
                        ")    ,   (    )   , ?dG3e    ;    ;    a    [   $eItF   Jaav7:Ftzec    ,   (   ?_JgF   [    a    ''#\n" +
                        "'  @zY-2r-zC-Wg    ,   (    )   , $FsrA   ]   [   <&5V>   +.54    ,   (   ?SkiK  )   ,   [    a    true    ,   (   $oCkH   [   ?sYX7   _:8Q2l3     ;    ;    a    (    )    , $HRvK   ,   [   uiFcV:   (\t  )    ,   (   ?jM20   [    a   <[J+>     ;   ]  )   ,   (   $sMvP   [   ?7959    \"\\\u000F\\\"    ^^ dOPIM:DDekK    ,   (    )   , $IGYY    ;    a    [   <0%S>   -07.143    ,   (   ?dJ8P   [    a    false    ,   (    )   , $5SHL    ;    ;   ?SFFI    [    a   [\t\t\t]    ,   (   $rcwn   [   ztn_i:   (\n" +
                        "\n" +
                        ")    ,   (    )   , ?MHaY   ]   [    a   <L+N>    ,   (   $llpa  )   ,   [   ?OOxo    ''''\t'C'\b'''  @jl-99-Es-uf    ,   (   $2YhI   [    a   99.529e-08     ;    ;   s4YoI:oYU1K    (    )    , ?7vHc   ,   [    a    true    ,   (   $rr1A   [   ?GnsF   _:nXURp     ;   ]  )   ,   (   $Kqvh   [    a   (  \n" +
                        ")    ,   (    )   , ?ka9Q    ;   <E_Z>    [    a   WyZWf:    ,   (   $hnEr   [   ?ug5W    \"\"\"\"\\\"B\"\n" +
                        "\"\"\"    ^^ <GlA>    ,   (    )   , $a6Oe    ;    ;    a    [   zGezS:5_.Rz   +.12E+56    ,   (   ?MeTq   [    a    false    ,   (    )   , $hFQ3   ]   [   ?W9ut   [\n" +
                        "  ]    ,   (   $36fG  )   ,   [    a   (\t\n" +
                        "\t)    ,   (   ?mK9n   [   <ZZl>   ofeRj:     ;    ;    a    (    )    , $cjtc   ,   [   ?44v3    '.\n" +
                        "\u001F'  @Uu-Km-8g-9f    ,   (   $lb5W   [    a   -1E    ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )      }    "
);s.push_back(string()+
                "     BASE <BtC>    PREFIX  r8DNA: <b%k>   PREFIX  EjBBa: <3)M>   PREFIX  YX6xO: <t~r>   SELECT    DISTINCT   ?9iVy $9dcp     FROM <-Rv>   FROM   NAMED ioANU:EAj3M   FROM <0ZQ>     WHERE    {     ?aJKL  $z5l6   TqZ.q:    ,   (   ?xJqk   [    a    'P\\\\,'  @ho-jj-wV-Zi    ,   (    )   , $KGBc    ;   <=$d>    [    a   21    ,   (   ?eZ6t   [   $8LsO    true    ,   (    )   , ?EESP    ;    ;    a    [   z18px:N8rKT   _:fdQ0P    ,   (   $ggWm   [    a   (\t\t\t)    ,   (    )   , ?86TQ   ]   [   $FZ8C   <h\u007Fa>    ,   (   ?ANtz  )   ,   [    a    \"g\\r4\"    ^^ yFSOt:    ,   (   $Qvc3   [   </dP>   +13     ;    ;    a    (    )    , ?fXeV   ,   [   $e6C0    false    ,   (   ?gInH   [    a   [\n" +
                        "\n" +
                        " ]     ;   ]  )   ,   (   $fsyx   [   ZP5G2:TVKWV   (\n" +
                        "\t\n" +
                        ")    ,   (    )   , ?L5E9    ;    a    [   $SC1y   <umG>    ,   (   ?yghH   [    a    ''''R'\\\"'P'''  @QD-nc-GB-YN    ,   (    )   , $UXuw    ;    ;   jOurI:    [    a   -97    ,   (   ?2t_N   [   $JE77    true    ,   (    )   , ?pfDb   ]   [    a   _:MeHdb    ,   (   $Uuoe  )   ,   [   <01a>   (  \n" +
                        ")    ,   (   ?aYFc   [    a   Z22h3:29MC3     ;    ;   $eIkV    (    )    , ?1Vyu   ,   [    a    \"\"\"\"t\"\\\\\"x\"\"\"    ^^ <#4N>    ,   (   $un4a   [   Y63f7:   23.984     ;   ]  )   ,   (   ?gUMv   [    a    false    ,   (    )   , $Myqw    ;   ?wePP    [    a   [ \t\n" +
                        "]    ,   (   $WSny   [   <n#->   (\n" +
                        "\t\t)    ,   (    )   , ?ixx4    ;    ;    a    [   $HTHd   upDlX:_IH9Q    ,   (   ?roFZ   [    a    '\\ns\\''  @wi-0l-Yn-lz    ,   (    )   , $Av8j   ]   [   <%5q>   +.85    ,   (   ?rK3j  )   ,   [    a    true    ,   (   $JwRx   [   ?54nC   _:8LKcI     ;    ;    a    (    )    , $Dd4N   ,   [   oMsHZ:   (\n" +
                        "\t\t)    ,   (   ?jc7W   [    a   <sL$>     ;   ]  )   ,   (   $vq2U   [   ?J_nG    \"\\t{\\f\"    ^^ ILyM7:NbY3k    ,   (    )   , $RLhE    ;    a    [   <pg]>   -14.703    ,   (   ?ovbJ   [    a    false    ,   (    )   , $csyD    ;    ;   ?0kOm    [    a   [\n" +
                        "\n" +
                        "]    ,   (   $k0mJ   [   Am_YJ:   ( \n" +
                        "\n" +
                        ")    ,   (    )   , ?lFXf   ]   [    a   <aMM>    ,   (   $6n6Z  )   ,   [   ?ST5R    ''''\\\"'\u0013'\\f'''  @GC-pG-uh-p7    ,   (   $Q3xr   [    a   72.897e+27     ;    ;   oWEX5:OOQT_    (    )    , ?xBPw   ,   [    a    true    ,   (   $FinS   [   ?wQKb   _:ZT3NB     ;   ]  )   ,   (   $DPPy   [    a   ( \n" +
                        " )    ,   (    )   , ?u0Us    ;   <FM]>    [    a   tuyaZ:    ,   (   $EbR7   [   ?dzF1    \"\"\"\"\\r\"\u0017\"\\'\"\"\"    ^^ <iQ&>    ,   (    )   , $IFaY    ;    ;    a    [   Roki6:WyMvx   +.1E    ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )      }    "
);s.push_back(string()+
                "     BASE <BtC>    PREFIX  r8DNA: <b%k>   PREFIX  EjBBa: <3)M>   PREFIX  YX6xO: <t~r>   SELECT    DISTINCT   ?9iVy $9dcp     FROM <-Rv>   FROM   NAMED ioANU:EAj3M   FROM <0ZQ>     WHERE    {     ?aJKL  $z5l6   TqZ.q:    ,   (   ?xJqk   [    a    'P\\\\,'  @ho-jj-wV-Zi    ,   (    )   , $KGBc    ;   <=$d>    [    a       ]   ]  )      }    "
                 );s.push_back(string()+

                "     BASE <BtC>    PREFIX  r8DNA: <b%k>   PREFIX  EjBBa: <3)M>   PREFIX  YX6xO: <t~r>   SELECT    DISTINCT   ?9iVy $9dcp     FROM <-Rv>   FROM   NAMED ioANU:EAj3M   FROM <0ZQ>     WHERE    {     ?aJKL  $z5l6   TqZ.q:    ,   (   ?xJqk   [    a    'P\\\\,'  @ho-jj-wV-Zi    ,   (    )   , $KGBc    ;   <=$d>    [    a   21    ,   (   ?eZ6t   [   $8LsO    true    ,   (    )   , ?EESP    ;    ;    a    [   z18px:N8rKT   _:fdQ0P    ,   (   $ggWm   [    a   (\t\t\t)    ,   (    )   , ?86TQ   ]   [   $FZ8C   <h\u007Fa>    ,   (   ?ANtz  )   ,   [    a    \"g\\r4\"    ^^ yFSOt:    ,   (   $Qvc3   [   </dP>   +13     ;    ;    a    (    )    , ?fXeV   ,   [   $e6C0    false    ,   (   ?gInH   [    a   [\n" +
                        "\n" +
                        " ]     ;   ]  )   ,   (   $fsyx   [   ZP5G2:TVKWV   (\n" +
                        "\t\n" +
                        ")    ,   (    )   , ?L5E9    ;    a    [   $SC1y   <umG>    ,   (   ?yghH   [    a    ''''R'\\\"'P'''  @QD-nc-GB-YN    ,   (    )   , $UXuw    ;    ;   jOurI:    [    a   -97    ,   (   ?2t_N   [   $JE77    true    ,   (    )   , ?pfDb   ]   [    a   _:MeHdb    ,   (   $Uuoe  )   ,   [   <01a>   (  \n" +
                        ")    ,   (   ?aYFc   [    a   Z22h3:29MC3     ;    ;   $eIkV    (    )    , ?1Vyu   ,   [    a    \"\"\"\"t\"\"\"     ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )   ]  ]  )   ]   ]  )   ]   ]  )   ]   ]  )      }    "

                        ,
                        );
        };

return 0;

} 


