/**
 *  sparql.h
 *  xSWO
 *
 *  Created by jim on 9/9/08.
 *  Copyright 2008 Glamdring Inc. Enterprises. All rights reserved.
 *  @ see http://www.w3.org/2005/01/yacker/uploads/SPARUL_EGP/bnf?markup=html
 ; *[1]     Query     =       Prologue
 ( SelectQuery | ConstructQuery | DescribeQuery | AskQuery | Replace | Update | Manage )
 ; [2]          Update    =     Insert | Delete | Load | Clear
 ; [3]          Replace   =     'REPLACE' WhereClause 'WITH' GraphTemplate
 ; [4]          Delete    =     'DELETE' GraphTemplate WhereClause?
 ; [5]          Insert    =     'INSERT' GraphTemplate WhereClause?
 ; [6]          GraphIRI          =     'GRAPH' IRIref
 ; [7]          Load      =     'LOAD' IRIref+ ( 'INTO' IRIref )?
 ; [8]          Clear     =     'CLEAR' GraphIRI?
 ; [9]          Manage    =     Create | Drop
 ; [10]         Create    =     'CREATE' 'SILENT'? GraphIRI
 ; [11]         Drop      =     'DROP' 'SILENT'? GraphIRI

 ; [2]     Prologue      =       BaseDecl? PrefixDecl*
 ; [3]     BaseDecl      =       'BASE' IRI_REF
 ; [4]     PrefixDecl    =       'PREFIX' PNAME_NS IRI_REF
 ; [5]     SelectQuery       =       'SELECT' ( 'DISTINCT' | 'REDUCED' )? ( Var+ | '*' ) DatasetClause* WhereClause SolutionModifier
 ; [6]     ConstructQuery    =       'CONSTRUCT' ConstructTemplate DatasetClause* WhereClause SolutionModifier
 ; [7]     DescribeQuery     =       'DESCRIBE' ( VarOrIRIref+ | '*' ) DatasetClause* WhereClause? SolutionModifier
 ; [8]     AskQuery      =       'ASK' DatasetClause* WhereClause
 ; [9]     DatasetClause     =       'FROM' ( DefaultGraphClause | NamedGraphClause )
 ; [10]    DefaultGraphClause    =       SourceSelector
 ; [11]    NamedGraphClause      =       'NAMED' SourceSelector
 ; [12]    SourceSelector    =       IRIref
 ; [13]    WhereClause       =       'WHERE'? GroupGraphPattern BindingClause?
 ; [13a]   BindingClause     =       "BINDINGS" (Var)+ "{" (Binding)* "}"
 ; [13b]   Binding           =       "(" (VarOrTerm | 'NULL')+ ")"
 ; [14]    SolutionModifier      =       OrderClause? LimitOffsetClauses?
 ; [15]    LimitOffsetClauses    =       ( LimitClause OffsetClause? | OffsetClause LimitClause? )
 ; [16]    OrderClause       =       'ORDER' 'BY' OrderCondition+
 ; [17]    OrderCondition    =       ( ( 'ASC' | 'DESC' ) BrackettedExpression )
 | ( Constraint | Var )
 ; [18]    LimitClause       =       'LIMIT' INTEGER
 ; [19]    OffsetClause      =       'OFFSET' INTEGER
 ; [20]    GroupGraphPattern     =       '{' TriplesBlock? ( ( GraphPatternNotTriples | Filter ) '.'? TriplesBlock? )* '}'
 ; [20a]   GraphTemplate          =       '{' TriplesBlock? ( ( 'GRAPH' VarOrIRIref GraphTemplate ) '.'? TriplesBlock? )* '}'
 ; [21]    TriplesBlock      =       TriplesSameSubject ( '.' TriplesBlock? )?
 ; [22]    GraphPatternNotTriples    =       OptionalGraphPattern | GroupOrUnionGraphPattern | GraphGraphPattern
 ; [23]    OptionalGraphPattern      =       'OPTIONAL' GroupGraphPattern
 ; [24]    GraphGraphPattern     =       'GRAPH' VarOrIRIref GroupGraphPattern
 ; [25]    GroupOrUnionGraphPattern      =       GroupGraphPattern ( 'UNION' GroupGraphPattern )*
 ; [26]    Filter    =       'FILTER' Constraint
 ; [27]    Constraint    =       BrackettedExpression | BuiltInCall | FunctionCall
 ; [28]    FunctionCall      =       IRIref ArgList
 ; [29]    ArgList       =       ( NIL | '(' Expression ( ',' Expression )* ')' )
 ; [30]    ConstructTemplate     =       '{' ConstructTriples? '}'
 ; [31]    ConstructTriples      =       TriplesSameSubject ( '.' ConstructTriples? )?
 ; [32]    TriplesSameSubject    =       VarOrTerm PropertyListNotEmpty | TriplesNode PropertyList
 ; [33]    PropertyListNotEmpty      =       Verb ObjectList ( ';' ( Verb ObjectList )? )*
 ; [34]    PropertyList      =       PropertyListNotEmpty?
 ; [35]    ObjectList    =       Object ( ',' Object )*
 ; [36]    Object    =       GraphNode
 ; [37]    Verb      =       VarOrIRIref | 'a'
 ; [38]    TriplesNode       =       Collection | BlankNodePropertyList
 ; [39]    BlankNodePropertyList     =       '[' PropertyListNotEmpty ']'
 ; [40]    Collection    =       '(' GraphNode+ ')'
 ; [41]    GraphNode     =       VarOrTerm | TriplesNode
 ; [42]    VarOrTerm     =       Var | GraphTerm
 ; [43]    VarOrIRIref       =       Var | IRIref
 ; [44]    Var       =       VAR1 | VAR2
 ; [45]    GraphTerm     =       IRIref | RDFLiteral | NumericLiteral | BooleanLiteral | BlankNode | NIL



 ; [46]    Expression    =       ConditionalOrExpression
 ; [47]    ConditionalOrExpression       =       ConditionalAndExpression ( '||' ConditionalAndExpression )*
 ; [48]    ConditionalAndExpression      =       ValueLogical ( '&&' ValueLogical )*
 ; [49]    ValueLogical      =       RelationalExpression
 ; [50]    RelationalExpression      =       NumericExpression ( '=' NumericExpression | '!=' NumericExpression | '<' NumericExpression | '>' NumericExpression | '<=' NumericExpression | '>=' NumericExpression )?
 ; [51]    NumericExpression     =       AdditiveExpression
 ; [52]    AdditiveExpression    =       MultiplicativeExpression ( '+' MultiplicativeExpression | '-' MultiplicativeExpression | NumericLiteralPositive | NumericLiteralNegative )*
 ; [53]    MultiplicativeExpression      =       UnaryExpression ( '*' UnaryExpression | '/' UnaryExpression )*
 ; [54]    UnaryExpression       =         '!' PrimaryExpression
 | '+' PrimaryExpression
 | '-' PrimaryExpression
 | PrimaryExpression
 ; [55]    PrimaryExpression     =       BrackettedExpression | BuiltInCall | IRIrefOrFunction | RDFLiteral | NumericLiteral | BooleanLiteral | Var
 ; [56]    BrackettedExpression      =       '(' Expression ')'
 ; [57]    BuiltInCall       =         'STR' '(' Expression ')'
 | 'LANG' '(' Expression ')'
 | 'LANGMATCHES' '(' Expression ',' Expression ')'
 | 'DATATYPE' '(' Expression ')'
 | 'BOUND' '(' Var ')'
 | 'sameTerm' '(' Expression ',' Expression ')'
 | 'isIRI' '(' Expression ')'
 | 'isURI' '(' Expression ')'
 | 'isBLANK' '(' Expression ')'
 | 'isLITERAL' '(' Expression ')'
 | RegexExpression
 ; [58]    RegexExpression       =       'REGEX' '(' Expression ',' Expression ( ',' Expression )? ')'
 ; [59]    IRIrefOrFunction      =       IRIref ArgList?
 ; [60]    RDFLiteral    =       String ( LANGTAG | ( '^^' IRIref ) )?
 ; [61]    NumericLiteral    =       NumericLiteralUnsigned | NumericLiteralPositive | NumericLiteralNegative
 ; [62]    NumericLiteralUnsigned    =       INTEGER | DECIMAL | DOUBLE
 ; [63]    NumericLiteralPositive    =       INTEGER_POSITIVE | DECIMAL_POSITIVE | DOUBLE_POSITIVE
 ; [64]    NumericLiteralNegative    =       INTEGER_NEGATIVE | DECIMAL_NEGATIVE | DOUBLE_NEGATIVE
 ; [65]    BooleanLiteral    =       'true' | 'false'
 ; [66]    String    =       STRING_LITERAL1 | STRING_LITERAL2 | STRING_LITERAL_LONG1 | STRING_LITERAL_LONG2
 ; [67]    IRIref    =       IRI_REF | PrefixedName
 ; [68]    PrefixedName      =       PNAME_LN | PNAME_NS
 ; [69]    BlankNode     =       BLANK_NODE_LABEL | ANON
 IRI_REF         =                      confix_p('<' ,*((anychar_p-chset_p("<>'{}|^`"))-range_p(0,'#20')), '>');
 PNAME_NS        =                      !NCNAME_PREFIX>>':';
 PNAME_LN        =                              !NCNAME_PREFIX>>':' >>!NCNAME;
 BLANK_NODE_LABEL        =      str_p("_:") >> NCNAME;
 VAR1    =                              ch_p('?') >> VARNAME;
 VAR2    =                              ch_p('$') >> VARNAME;
 LANGTAG         =                      ch_p('@') >> +alpha_p >> *(ch_p('-') >> +alnum_p);
 INTEGER         =                      int_p;
 DECIMAL         =                      real_p;
 DOUBLE          =                              real_p;
 STRING_LITERAL1         =              confix_p("'", *c_escape_ch_p, "'");//   "'" ( ([^#x27#x5C#xA#xD]) | ECHAR )* "'"
 STRING_LITERAL2         =      confix_p('"', *c_escape_ch_p, '"');//'"' ( ([^#x22#x5C#xA#xD]) | ECHAR )* '"'
 STRING_LITERAL_LONG1=          confix_p("'''", *c_escape_ch_p, "'''");//       "'''" ( [^'\] | ECHAR | ("'" [^']) | ("''" [^']) )* "'''"
 STRING_LITERAL_LONG2=          confix_p("\"\"\"", *c_escape_ch_p,"\"\"\"" );// '"""' ( [^"\] | ECHAR | ('"' [^"]) | ('""' [^"]) )* '"""'
 NIL     =                              confix_p('(' ,*space_p, ')');
 ANON    =                              confix_p('[' ,*space_p, ']');
 NCCHAR1p        =                      alpha_p
 | range_p(0x00C0,0x00D6)
 | range_p(0x00D8,0x00F6)
 | range_p(0x00F8,0x02FF)
 | range_p(0x0370,0x037D)
 | range_p(0x037F,0x1FFF)
 | range_p(0x200C,0x200D)
 | range_p(0x2070,0x218F)
 | range_p(0x2C00,0x2FEF)
 | range_p(0x3001,0xD7FF)
 | range_p(0xF900,0xFDCF)
 | range_p(0xFDF0,0xFFFD)
 | range_p(0x10000,0xEFFFF);
 NCCHAR1         =                      NCCHAR1p | '_';
 VARNAME         =                      ( NCCHAR1 | digit_p) >> *( NCCHAR1 | digit_p| ch_p(0xB7 ) | range_p(0x0300,0x036F) | range_p(0x203F0,0x2040) );
 NCCHAR          =                              NCCHAR1 | '-' | digit_p |  ch_p(0xB7 )  | range_p(0x0300,0x036F) | range_p(0x203F0,0x2040) ;
 NCNAME_PREFIX   =              NCCHAR1p>> !(*(NCCHAR|'.') >> NCCHAR);
 NCNAME          =                              NCCHAR1 >> !(*(NCCHAR|'.') >> NCCHAR);


 @terminals
 ; [70]    IRI_REF       =       '<' ([^<>\"{}|^`\\]-[#x00-#x20])* '>'
 ; [71]    PNAME_NS      =       PN_PREFIX? ':'
 ; [72]    PNAME_LN      =       PNAME_NS PN_LOCAL
 ; [73]    BLANK_NODE_LABEL      =       '_:' PN_LOCAL
 ; [74]    VAR1      =       '?' VARNAME
 ; [75]    VAR2      =       '$' VARNAME
 ; [76]    LANGTAG       =       '@' [a-zA-Z]+ ('-' [a-zA-Z0-9]+)*
 ; [77]    INTEGER       =       [0-9]+
 ; [78]    DECIMAL       =       [0-9]+ '.' [0-9]* | '.' [0-9]+
 ; [79]    DOUBLE    =       [0-9]+ '.' [0-9]* EXPONENT | '.' ([0-9])+ EXPONENT | ([0-9])+ EXPONENT
 ; [80]    INTEGER_POSITIVE      =       '+' INTEGER
 ; [81]    DECIMAL_POSITIVE      =       '+' DECIMAL
 ; [82]    DOUBLE_POSITIVE       =       '+' DOUBLE
 ; [83]    INTEGER_NEGATIVE      =       '-' INTEGER
 ; [84]    DECIMAL_NEGATIVE      =       '-' DECIMAL
 ; [85]    DOUBLE_NEGATIVE       =       '-' DOUBLE
 ; [86]    EXPONENT      =       [eE] [+-]? [0-9]+
 ; [87]    STRING_LITERAL1       =       "'" ( ([^#x27#x5C#xA#xD]) | ECHAR )* "'"
 ; [88]    STRING_LITERAL2       =       '"' ( ([^#x22#x5C#xA#xD]) | ECHAR )* '"'
 ; [89]    STRING_LITERAL_LONG1      =       "'''" ( ( "'" | "''" )? ( [^'\\] | ECHAR ) )* "'''"
 ; [90]    STRING_LITERAL_LONG2      =       '"""' ( ( '"' | '""' )? ( [^"\\] | ECHAR ) )* '"""'
 ; [91]    ECHAR     =       '\\' [tbnrf\\"']
 ; [92]    NIL       =       '(' WS* ')'
 ; [93]    WS    =       #x20 | #x9 | #xD | #xA
 ; [94]    ANON      =       '[' WS* ']'
 ; [95]    PN_CHARS_BASE     =       [A-Z] | [a-z] | [#x00C0-#x00D6] | [#x00D8-#x00F6] | [#x00F8-#x02FF] | [#x0370-#x037D] | [#x037F-#x1FFF] | [#x200C-#x200D] | [#x2070-#x218F] | [#x2C00-#x2FEF] | [#x3001-#xD7FF] | [#xF900-#xFDCF] | [#xFDF0-#xFFFD] | [#x10000-#xEFFFF]
 ; [96]    PN_CHARS_U    =       PN_CHARS_BASE | '_'
 ; [97]    VARNAME       =       ( PN_CHARS_U | [0-9] ) ( PN_CHARS_U | [0-9] | #x00B7 | [#x0300-#x036F] | [#x203F-#x2040] )*
 ; [98]    PN_CHARS      =       PN_CHARS_U | '-' | [0-9] | #x00B7 | [#x0300-#x036F] | [#x203F-#x2040]
 ; [99]    PN_PREFIX     =       PN_CHARS_BASE ((PN_CHARS|'.')* PN_CHARS)?
 ; [100]       PN_LOCAL      =       ( PN_CHARS_U | [0-9] ) ((PN_CHARS|'.')* PN_CHARS)?

 @pass: WS+
 | '#' [^\n]* "\n"

 [13:48]        so, summary of changes: ANON, NCCHAR, NCCHAR1, NCCHAR1p, NCNAME, NCNAME_PREFIX, and NIL needed to be in a lexeme_scanner because they were either skipping whitespace they weren't supposed to, or because they were explicitly parsing for whitespace which you cant do at the phrase level
[13:49] WhereClause, ObjectList, NIL, ANON, VARNAME, NCNAME_PREFIX, and NCNAME were wrong. the originals are commented out above the fixed versions
[13:50] there may be more inaccuracies, as the only branch of Query I've tested is SelectQuery -- ConstructQuery, DescribeQuery, AskQuery, Replace, Update, and Manage haven't been run */

#define BOOST_SPIRIT_DEBUG
#define BOOST_SPIRIT_DEBUG_OUT std::cerr

#pragma once
#include <cstdio>

#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <boost/spirit/core.hpp>
#include <boost/spirit/utility/confix.hpp>
#include <boost/spirit/utility/chset.hpp>
#include <boost/spirit/utility/escape_char.hpp>

using namespace boost::spirit;

using namespace std;
namespace
{
  struct sparql_parser : public grammar<sparql_parser>
  {
    template<typename ScannerT>
      struct definition
      {
        definition(sparql_parser const& /*self*/)
        {
          Query = Prologue >> (SelectQuery | ConstructQuery | DescribeQuery
              | AskQuery | Replace | Update | Manage);
          Update = Insert | Delete | Load | Clear;
          Replace = str_p("REPLACE") >> WhereClause >> str_p("WITH")
              >> GraphTemplate;
          Delete = str_p("DELETE") >> GraphTemplate >> !WhereClause;
          Insert = str_p("INSERT") >> GraphTemplate >> !WhereClause;
          GraphIRI = str_p("GRAPH") >> IRIref;
          Load = str_p("LOAD") >> +IRIref >> !(str_p("INTO") >> IRIref);
          Clear = str_p("CLEAR") >> !GraphIRI;
          Manage = Create | Drop;
          Create = str_p("CREATE") >> !str_p("SILENT") >> GraphIRI;
          Drop = str_p("DROP") >> !str_p("SILENT") >> GraphIRI;
          Prologue = !BaseDecl >> *PrefixDecl;
          BaseDecl = str_p("BASE") >> IRI_REF;
          PrefixDecl = str_p("PREFIX") >> PNAME_NS >> IRI_REF;
          SelectQuery = str_p("SELECT") >> !(str_p("DISTINCT") | str_p(
              "REDUCED")) >> (+Var | ch_p("*")) >> *DatasetClause
              >> WhereClause >> SolutionModifier;
          ConstructQuery = str_p("CONSTRUCT") >> ConstructTemplate
              >> !DatasetClause >> WhereClause >> SolutionModifier;
          DescribeQuery = str_p("DESCRIBE") >> (+VarOrIRIref | ch_p('*'))
              >> *DatasetClause >> !WhereClause >> SolutionModifier;
          AskQuery = str_p("ASK") >> *DatasetClause >> WhereClause;
          DatasetClause = str_p("FROM") >> (DefaultGraphClause
              | NamedGraphClause);
          DefaultGraphClause = SourceSelector;
          NamedGraphClause = str_p("NAMED") >> SourceSelector;
          SourceSelector = IRIref;
          //WhereClause = !str_p("WHERE") >> !GroupGraphPattern >> BindingClause;
          WhereClause = !str_p("WHERE") >> GroupGraphPattern >> !BindingClause;
          BindingClause = str_p("BINDINGS") >> +(Var) >> str_p("{")
              >> *(Binding) >> str_p("}");
          Binding = confix_p("(", +(VarOrTerm | str_p("NULL")), ")");
          SolutionModifier = !OrderClause >> !LimitOffsetClauses;
          LimitOffsetClauses = (LimitClause >> !OffsetClause | OffsetClause
              >> !LimitClause);
          OrderClause = str_p("ORDER") >> str_p("BY") >> +OrderCondition;
          OrderCondition = ((str_p("ASC") | str_p("DESC"))
              >> BrackettedExpression) | (Constraint | Var);
          LimitClause = str_p("LIMIT") >> int_p;
          OffsetClause = str_p("OFFSET") >> int_p;
          GroupGraphPattern = confix_p('{', !TriplesBlock
              >> *((GraphPatternNotTriples | Filter) >> !ch_p('.')
                  >> !TriplesBlock), '}');
          GraphTemplate = confix_p('{', !TriplesBlock >> *((str_p("GRAPH")
              >> VarOrIRIref >> GraphTemplate) >> !ch_p('.') >> !TriplesBlock),
              '}');;
          TriplesBlock = TriplesSameSubject >> !(ch_p('.') >> !TriplesBlock);
          GraphPatternNotTriples = OptionalGraphPattern
              | GroupOrUnionGraphPattern | GraphGraphPattern;
          OptionalGraphPattern = str_p("OPTIONAL") >> GroupGraphPattern;
          GraphGraphPattern = str_p("GRAPH") >> VarOrIRIref
              >> GroupGraphPattern;
          GroupOrUnionGraphPattern = GroupGraphPattern >> *(str_p("UNION")
              >> GroupGraphPattern);
          Filter = str_p("FILTER") >> Constraint;
          Constraint = BrackettedExpression | BuiltInCall | FunctionCall;
          FunctionCall = IRIref >> ArgList;
          ArgList = NIL | confix_p('(', Expression
              >> *(ch_p(',') >> Expression), ')');
          ConstructTemplate = confix_p('{', !ConstructTriples, '}');;
          ConstructTriples = TriplesSameSubject >> !(ch_p('.')
              >> !ConstructTriples);;
          TriplesSameSubject = VarOrTerm >> PropertyListNotEmpty | TriplesNode
              >> PropertyList;
          PropertyListNotEmpty = Verb >> ObjectList >> *(ch_p(';') >> !(Verb
              >> ObjectList));
          PropertyList = !PropertyListNotEmpty;
          //ObjectList = Object >> !(ch_p(',') >> Object);
          ObjectList = Object >> *(ch_p(',') >> Object);
          Object = GraphNode;
          Verb = VarOrIRIref | ch_p('a');
          TriplesNode = Collection | BlankNodePropertyList;
          BlankNodePropertyList = confix_p('[', PropertyListNotEmpty, ']');;
          Collection = confix_p('(', +GraphNode, ')');
          GraphNode = VarOrTerm | TriplesNode;
          VarOrTerm = Var | GraphTerm;
          VarOrIRIref = Var | IRIref;
          Var = VAR1 | VAR2;
          GraphTerm = IRIref | RDFLiteral | NumericLiteral | BooleanLiteral
              | BlankNode | NIL;
          Expression = ConditionalOrExpression;
          ConditionalOrExpression = ConditionalAndExpression >> *(str_p("||")
              >> ConditionalAndExpression);
          ConditionalAndExpression = ValueLogical >> *(str_p("&&")
              >> ValueLogical);
          ValueLogical = RelationalExpression;
          RelationalExpression = NumericExpression >> !(ch_p('=')
              >> NumericExpression | str_p("!=") >> NumericExpression | ch_p(
              '<') >> NumericExpression | ch_p('>') >> NumericExpression
              | str_p("<=") >> NumericExpression | str_p(">=")
              >> NumericExpression);
          NumericExpression = AdditiveExpression;
          AdditiveExpression = MultiplicativeExpression >> *(sign_p
              >> MultiplicativeExpression | NumericExpression);
          MultiplicativeExpression = UnaryExpression >> *(ch_p('*')
              >> UnaryExpression | ch_p('/') >> UnaryExpression);
          UnaryExpression = ch_p('!') >> PrimaryExpression | ch_p('+')
              >> PrimaryExpression | ch_p('-') >> PrimaryExpression
              | PrimaryExpression;
          PrimaryExpression = BrackettedExpression | BuiltInCall
              | IRIrefOrFunction | RDFLiteral | NumericLiteral | BooleanLiteral
              | Var;
          BrackettedExpression = ch_p('(') >> Expression >> ch_p(')');
          BuiltInCall = str_p("STR") >> confix_p('(', Expression, ')') | str_p(
              "LANG") >> confix_p('(', Expression, ')') | str_p("DATATYPE")
              >> confix_p('(', Expression, ')') | str_p("BOUND") >> confix_p(
              '(', Expression, ')') | str_p("isIRI") >> confix_p('(',
              Expression, ')') | str_p("isURI") >> confix_p('(', Expression,
              ')') | str_p("isBLANK") >> confix_p('(', Expression, ')')
              | str_p("isLITERAL") >> confix_p('(', Expression, ')') | str_p(
              "LANGMATCHES") >> confix_p('(', Expression >> ch_p(',')
              >> Expression, ')') | str_p("sameTerm") >> confix_p('(',
              Expression >> ch_p(',') >> Expression, ')') | RegexExpression;
          RegexExpression = str_p("REGEX") >> ch_p('(') >> Expression >> ch_p(
              ',') >> Expression >> !(ch_p(',') >> Expression) >> ch_p(')');
          IRIrefOrFunction = IRIref >> !ArgList;
          RDFLiteral = String >> !(LANGTAG | (str_p("^^") >> IRIref));
          NumericLiteral = NumericLiteralUnsigned | NumericLiteralPositive
              | NumericLiteralNegative;
          NumericLiteralUnsigned = int_p | real_p;
          NumericLiteralPositive = uint_p | ureal_p;
          NumericLiteralNegative = ch_p('-') >> (NumericLiteralUnsigned);
          BooleanLiteral = str_p("true") | str_p("false");
          String = STRING_LITERAL1 | STRING_LITERAL2 | STRING_LITERAL_LONG1
              | STRING_LITERAL_LONG2;
          IRIref = IRI_REF | PrefixedName;
          PrefixedName = PNAME_LN | PNAME_NS;
          BlankNode = (BLANK_NODE_LABEL | ANON);

          IRI_REF = confix_p('<', *((anychar_p - chset_p("<>'{}|^`"))
              - range_p(0, 0x20)), '>');

          PNAME_NS = !NCNAME_PREFIX >> ':';

          PNAME_LN = !NCNAME_PREFIX >> ':' >> !NCNAME;

          BLANK_NODE_LABEL = str_p("_:") >> NCNAME;

          VAR1 = ch_p('?') >> VARNAME;

          VAR2 = ch_p('$') >> VARNAME;

          LANGTAG = ch_p('@') >> +alpha_p >> *(ch_p('-') >> +alnum_p);

          INTEGER = int_p;

          DECIMAL = real_p;

          DOUBLE = real_p;

          STRING_LITERAL1 = confix_p("'", *c_escape_ch_p, "'");
          STRING_LITERAL2 = confix_p('"', *c_escape_ch_p, '"');
          STRING_LITERAL_LONG1 = confix_p("'''", *c_escape_ch_p, "'''");
          STRING_LITERAL_LONG2 = confix_p("\"\"\"", *c_escape_ch_p, "\"\"\"");
          //NIL = confix_p('(', *space_p, ')');
          NIL = *space_p >> '(' >> *space_p >> ')';
          //ANON = confix_p('[', *space_p, ']');
          ANON = *space_p >> '[' >> *space_p >> ']';
          NCCHAR1p = alpha_p | range_p(0x00C0, 0x00D6)
              | range_p(0x00D8, 0x00F6) | range_p(0x00F8, 0x02FF) | range_p(
              0x0370, 0x037D) | range_p(0x037F, 0x1FFF) | range_p(0x200C,
              0x200D) | range_p(0x2070, 0x218F) | range_p(0x2C00, 0x2FEF)
              | range_p(0x3001, 0xD7FF) | range_p(0xF900, 0xFDCF) | range_p(
              0xFDF0, 0xFFFD) | range_p(0x10000, 0xEFFFF);
          NCCHAR1 = NCCHAR1p | '_';

          //VARNAME = (NCCHAR1 | digit_p) >> *(NCCHAR1 | digit_p | ch_p(0xB7) | range_p(0x0300, 0x036F) | range_p(0x203F, 0x2040));
          VARNAME = (NCCHAR1 | digit_p) >> *(NCCHAR1 | digit_p | ch_p(0xB7)
              | range_p(0x0300, 0x036F) | range_p(0x203F, 0x2040));

          NCCHAR = NCCHAR1 | '-' | digit_p | ch_p(0xB7) | range_p(0x0300,
              0x036F) | range_p(0x203F, 0x2040);

          //NCNAME_PREFIX = NCCHAR1p >> !(*(NCCHAR | '.') >> NCCHAR);
          NCNAME_PREFIX = *space_p >> NCCHAR1p >> !(*((NCCHAR | '.') - (NCCHAR
              >> ':')) >> NCCHAR);

          //NCNAME = NCCHAR1 >> !(*(NCCHAR | '.') >> NCCHAR);
          NCNAME = NCCHAR1 >> !(*((NCCHAR | '.') - (NCCHAR >> ~eps_p(NCCHAR)))
              >> NCCHAR);

#if defined(BOOST_SPIRIT_DEBUG)
          BOOST_SPIRIT_DEBUG_RULE(ANON);
          BOOST_SPIRIT_DEBUG_RULE(AdditiveExpression);
          BOOST_SPIRIT_DEBUG_RULE(ArgList);
          BOOST_SPIRIT_DEBUG_RULE(AskQuery);
          BOOST_SPIRIT_DEBUG_RULE(BLANK_NODE_LABEL);
          BOOST_SPIRIT_DEBUG_RULE(BaseDecl);
          BOOST_SPIRIT_DEBUG_RULE(Binding);
          BOOST_SPIRIT_DEBUG_RULE(BindingClause);
          BOOST_SPIRIT_DEBUG_RULE(BlankNode);
          BOOST_SPIRIT_DEBUG_RULE(BlankNodePropertyList);
          BOOST_SPIRIT_DEBUG_RULE(BooleanLiteral);
          BOOST_SPIRIT_DEBUG_RULE(BrackettedExpression);
          BOOST_SPIRIT_DEBUG_RULE(BuiltInCall);
          BOOST_SPIRIT_DEBUG_RULE(Clear);
          BOOST_SPIRIT_DEBUG_RULE(Collection);
          BOOST_SPIRIT_DEBUG_RULE(ConditionalOrExpression);
          BOOST_SPIRIT_DEBUG_RULE(ConditionalAndExpression);
          BOOST_SPIRIT_DEBUG_RULE(Constraint);
          BOOST_SPIRIT_DEBUG_RULE(ConstructQuery);
          BOOST_SPIRIT_DEBUG_RULE(ConstructTemplate);
          BOOST_SPIRIT_DEBUG_RULE(ConstructTriples);
          BOOST_SPIRIT_DEBUG_RULE(Create);
          BOOST_SPIRIT_DEBUG_RULE(DECIMAL);
          BOOST_SPIRIT_DEBUG_RULE(DOUBLE);
          BOOST_SPIRIT_DEBUG_RULE(DatasetClause);
          BOOST_SPIRIT_DEBUG_RULE(DefaultGraphClause);
          BOOST_SPIRIT_DEBUG_RULE(Delete);
          BOOST_SPIRIT_DEBUG_RULE(DescribeQuery);
          BOOST_SPIRIT_DEBUG_RULE(Drop);
          BOOST_SPIRIT_DEBUG_RULE(Expression);
          BOOST_SPIRIT_DEBUG_RULE(Filter);
          BOOST_SPIRIT_DEBUG_RULE(FunctionCall);
          BOOST_SPIRIT_DEBUG_RULE(GraphGraphPattern);
          BOOST_SPIRIT_DEBUG_RULE(GraphIRI);
          BOOST_SPIRIT_DEBUG_RULE(GraphNode);
          BOOST_SPIRIT_DEBUG_RULE(GraphPatternNotTriples);
          BOOST_SPIRIT_DEBUG_RULE(GraphTemplate);
          BOOST_SPIRIT_DEBUG_RULE(GraphTerm);
          BOOST_SPIRIT_DEBUG_RULE(GroupGraphPattern);
          BOOST_SPIRIT_DEBUG_RULE(GroupOrUnionGraphPattern);
          BOOST_SPIRIT_DEBUG_RULE(INTEGER);
          BOOST_SPIRIT_DEBUG_RULE(IRI_REF);
          BOOST_SPIRIT_DEBUG_RULE(IRIref);
          BOOST_SPIRIT_DEBUG_RULE(IRIrefOrFunction);
          BOOST_SPIRIT_DEBUG_RULE(Insert);
          BOOST_SPIRIT_DEBUG_RULE(LANGTAG);
          BOOST_SPIRIT_DEBUG_RULE(LimitClause);
          BOOST_SPIRIT_DEBUG_RULE(LimitOffsetClauses);
          BOOST_SPIRIT_DEBUG_RULE(Load);
          BOOST_SPIRIT_DEBUG_RULE(Manage);
          BOOST_SPIRIT_DEBUG_RULE(MultiplicativeExpression);
          BOOST_SPIRIT_DEBUG_RULE(NCCHAR);
          BOOST_SPIRIT_DEBUG_RULE(NCCHAR1);
          BOOST_SPIRIT_DEBUG_RULE(NCCHAR1p);
          BOOST_SPIRIT_DEBUG_RULE(NCNAME);
          BOOST_SPIRIT_DEBUG_RULE(NCNAME_PREFIX);
          BOOST_SPIRIT_DEBUG_RULE(NIL);
          BOOST_SPIRIT_DEBUG_RULE(NamedGraphClause);
          BOOST_SPIRIT_DEBUG_RULE(NumericExpression);
          BOOST_SPIRIT_DEBUG_RULE(NumericLiteral);
          BOOST_SPIRIT_DEBUG_RULE(NumericLiteralNegative);
          BOOST_SPIRIT_DEBUG_RULE(NumericLiteralPositive);
          BOOST_SPIRIT_DEBUG_RULE(NumericLiteralUnsigned);
          BOOST_SPIRIT_DEBUG_RULE(Object);
          BOOST_SPIRIT_DEBUG_RULE(ObjectList);
          BOOST_SPIRIT_DEBUG_RULE(OffsetClause);
          BOOST_SPIRIT_DEBUG_RULE(OptionalGraphPattern);
          BOOST_SPIRIT_DEBUG_RULE(OrderClause);
          BOOST_SPIRIT_DEBUG_RULE(OrderCondition);
          BOOST_SPIRIT_DEBUG_RULE(PNAME_LN);
          BOOST_SPIRIT_DEBUG_RULE(PNAME_NS);
          BOOST_SPIRIT_DEBUG_RULE(PrefixDecl);
          BOOST_SPIRIT_DEBUG_RULE(PrefixedName);
          BOOST_SPIRIT_DEBUG_RULE(PrimaryExpression);
          BOOST_SPIRIT_DEBUG_RULE(Prologue);
          BOOST_SPIRIT_DEBUG_RULE(PropertyList);
          BOOST_SPIRIT_DEBUG_RULE(PropertyListNotEmpty);
          BOOST_SPIRIT_DEBUG_RULE(Query);
          BOOST_SPIRIT_DEBUG_RULE(RDFLiteral);
          BOOST_SPIRIT_DEBUG_RULE(RegexExpression);
          BOOST_SPIRIT_DEBUG_RULE(RelationalExpression);
          BOOST_SPIRIT_DEBUG_RULE(Replace);
          BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL1);
          BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL2);
          BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL_LONG1);
          BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL_LONG2);
          BOOST_SPIRIT_DEBUG_RULE(SelectQuery);
          BOOST_SPIRIT_DEBUG_RULE(SolutionModifier);
          BOOST_SPIRIT_DEBUG_RULE(SourceSelector);
          BOOST_SPIRIT_DEBUG_RULE(String);
          BOOST_SPIRIT_DEBUG_RULE(TriplesBlock);
          BOOST_SPIRIT_DEBUG_RULE(TriplesNode);
          BOOST_SPIRIT_DEBUG_RULE(TriplesSameSubject);
          BOOST_SPIRIT_DEBUG_RULE(UnaryExpression);
          BOOST_SPIRIT_DEBUG_RULE(Update);
          BOOST_SPIRIT_DEBUG_RULE(VAR1);
          BOOST_SPIRIT_DEBUG_RULE(VAR2);
          BOOST_SPIRIT_DEBUG_RULE(VARNAME);
          BOOST_SPIRIT_DEBUG_RULE(ValueLogical);
          BOOST_SPIRIT_DEBUG_RULE(Var);
          BOOST_SPIRIT_DEBUG_RULE(VarOrIRIref);
          BOOST_SPIRIT_DEBUG_RULE(VarOrTerm);
          BOOST_SPIRIT_DEBUG_RULE(Verb);
          BOOST_SPIRIT_DEBUG_RULE(WhereClause);
#endif
        }

        rule<ScannerT> /*ANON,*/AdditiveExpression, ArgList, AskQuery,
            BLANK_NODE_LABEL, BaseDecl, Binding, BindingClause, BlankNode,
            BlankNodePropertyList, BooleanLiteral, BrackettedExpression,
            BuiltInCall, Clear, Collection, ConditionalOrExpression,
            ConditionalAndExpression, Constraint, ConstructQuery,
            ConstructTemplate, ConstructTriples, Create, DECIMAL, DOUBLE,
            DatasetClause, DefaultGraphClause, Delete, DescribeQuery, Drop,
            Expression, Filter, FunctionCall, GraphGraphPattern, GraphIRI,
            GraphNode, GraphPatternNotTriples, GraphTemplate, GraphTerm,
            GroupGraphPattern, GroupOrUnionGraphPattern, INTEGER, IRI_REF,
            IRIref, IRIrefOrFunction, Insert, LANGTAG, LimitClause,
            LimitOffsetClauses, Load, Manage, MultiplicativeExpression, /*NCCHAR,
             NCCHAR1, NCCHAR1p, NCNAME, NCNAME_PREFIX, NIL,*/NamedGraphClause,
            NumericExpression, NumericLiteral, NumericLiteralNegative,
            NumericLiteralPositive, NumericLiteralUnsigned, Object, ObjectList,
            OffsetClause, OptionalGraphPattern, OrderClause, OrderCondition,
            PNAME_LN, PNAME_NS, PrefixDecl, PrefixedName, PrimaryExpression,
            Prologue, PropertyList, PropertyListNotEmpty, Query, RDFLiteral,
            RegexExpression, RelationalExpression, Replace, STRING_LITERAL1,
            STRING_LITERAL2, STRING_LITERAL_LONG1, STRING_LITERAL_LONG2,
            SelectQuery, SolutionModifier, SourceSelector, String,
            TriplesBlock, TriplesNode, TriplesSameSubject, UnaryExpression,
            Update, VAR1, VAR2, VARNAME, ValueLogical, Var, VarOrIRIref,
            VarOrTerm, Verb, WhereClause;

        rule<typename lexeme_scanner<ScannerT>::type> ANON, NCCHAR, NCCHAR1,
            NCCHAR1p, NCNAME, NCNAME_PREFIX, NIL;

        rule<ScannerT> const&
        start() const
        {
          return Query;
        }
      };
  };
}
