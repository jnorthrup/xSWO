/**
 *  sparql.h
 *  xSWO
 *
 *  Created by jim on 9/9/08.
 *  Copyright 2008 Glamdring Inc. Enterprises. All rights reserved.
 *  @ see http://www.w3.org/2005/01/yacker/uploads/SPARUL_EGP/bnf?markup=html
 ;*[1]     Query     =       Prologue
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
 ; [17]    OrderCondition    =       ( ( 'ASC' | 'DESC' ) BrackettedExpression ) | ( Constraint | Var )
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
 ; [49]    ValueLogical          = RelationalExpression
 ; [50]    RelationalExpression =       NumericExpression ( '=' NumericExpression | '!=' NumericExpression | '<' NumericExpression | '>' NumericExpression | '<=' NumericExpression | '>=' NumericExpression )?
 ; [51]    NumericExpression     =       AdditiveExpression
 ; [52]    AdditiveExpression    =       MultiplicativeExpression ( '+' MultiplicativeExpression | '-' MultiplicativeExpression | NumericLiteralPositive | NumericLiteralNegative )*
 ; [53]    MultiplicativeExpression = UnaryExpression ( '*' UnaryExpression | '/' UnaryExpression )*
 ; [54]    UnaryExpression       = '!' PrimaryExpression
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
 
 
 @terminals
 ; [70]    IRI_REF       =       '<' ([^<>\"{}|^`\\]-[\x000-\x020])* '>'
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
 ; [87]    STRING_LITERAL1       =       "'" ( ([^\x027\x05C\x0A\x0D]) | ECHAR )* "'"
 ; [88]    STRING_LITERAL2       =       '"' ( ([^\x022\x05C\x0A\x0D]) | ECHAR )* '"'
 ; [89]    STRING_LITERAL_LONG1      =       "'''" ( ( "'" | "''" )? ( [^'\\] | ECHAR ) )* "'''"
 ; [90]    STRING_LITERAL_LONG2      =       '"""' ( ( '"' | '""' )? ( [^"\\] | ECHAR ) )* '"""'
 ; [91]    ECHAR     =       '\\' [tbnrf\\"']
 ; [92]    NIL       =       '(' WS* ')'
 ; [93]    WS    =       \x020 | \x09 | \x0D | \x0A
 ; [94]    ANON      =       '[' WS* ']'
 ; [95]    PN_CHARS_BASE     =       [A-Z] | [a-z] | [\x000C0-\x000D6] | [\x000D8-\x000F6] | [\x000F8-\x002FF] | [\x00370-\x0037D] | [\x0037F-\x01FFF] | [\x0200C-\x0200D] | [\x02070-\x0218F] | [\x02C00-\x02FEF] | [\x03001-\x0D7FF] | [\x0F900-\x0FDCF] | [\x0FDF0-\x0FFFD] | [\x010000-\x0EFFFF]
 ; [96]    PN_CHARS_U    =       PN_CHARS_BASE | '_'
 ; [97]    VARNAME       =       ( PN_CHARS_U | [0-9] ) ( PN_CHARS_U | [0-9] | \x000B7 | [\x00300-\x0036F] | [\x0203F-\x02040] )*
 ; [98]    PN_CHARS      =       PN_CHARS_U | '-' | [0-9] | \x000B7 | [\x00300-\x0036F] | [\x0203F-\x02040]
 ; [99]    PN_PREFIX     =       PN_CHARS_BASE ((PN_CHARS|'.')* PN_CHARS)?
 ; [100]       PN_LOCAL      =       ( PN_CHARS_U | [0-9] ) ((PN_CHARS|'.')* PN_CHARS)?
 
 @pass: WS+
 | '#' [^\n]* "\n"
 
 */

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
				/* */     
				Query = Prologue >> (SelectQuery | ConstructQuery | DescribeQuery| AskQuery | Replace | Update | Manage) ;
				Update = Insert | Delete | Load | Clear;
				Replace = confix_p(str_p("REPLACE"), WhereClause, "WITH") >> GraphTemplate;
				Delete = str_p("DELETE") >> GraphTemplate >> !WhereClause;
				Insert = str_p("INSERT") >> GraphTemplate >> !WhereClause;
				GraphIRI = str_p("GRAPH") >> IRIref;
				Load = str_p("LOAD") >> +IRIref >> !(str_p("INTO") >> IRIref);
				Clear = str_p("CLEAR") >> !GraphIRI;
				Manage = Create | Drop;
				Create = str_p("CREATE")>> !str_p("SILENT")>> GraphIRI;
				Drop = confix_p("DROP", !str_p("SILENT"), GraphIRI);
				Prologue = !BaseDecl >> *PrefixDecl;
				BaseDecl = str_p("BASE") >> IRI_REF;
				PrefixDecl =str_p("PREFIX")>> PNAME_NS>> IRI_REF;
				SelectQuery = str_p("SELECT") 
				>> !(str_p("DISTINCT")| str_p("REDUCED")) 
				>> (Var|'*')  
				>> *DatasetClause 
				>> WhereClause
				>> SolutionModifier;
				ConstructQuery = str_p("CONSTRUCT")>> ConstructTemplate >> *DatasetClause >> WhereClause>> SolutionModifier;
				DescribeQuery = str_p("DESCRIBE")>> (VarOrIRIref | ch_p('*')) >> *DatasetClause >> !WhereClause>> SolutionModifier;
				AskQuery = str_p("ASK")>> *DatasetClause>>WhereClause;
				DatasetClause ="FROM" >> (DefaultGraphClause^ NamedGraphClause);  //TODO: address the spirit vs. spec issue
				DefaultGraphClause = SourceSelector;
				NamedGraphClause = str_p("NAMED") >> SourceSelector;
				SourceSelector = IRIref;
				WhereClause = !str_p("WHERE") >> GroupGraphPattern >> !BindingClause;
				BindingClause	= str_p("BINDINGS") >> +(Var) >> "{">> *(Binding)>> "}";
				Binding = ch_p('(')>> +(VarOrTerm | "NULL")>> ')';
				SolutionModifier = OrderClause || LimitOffsetClauses;
				LimitOffsetClauses = (LimitClause >> !OffsetClause) | (OffsetClause>> !LimitClause);
				OrderClause = str_p("ORDER") >> "BY" >> +OrderCondition;
				OrderCondition = ((str_p("ASC") | "DESC") >> BrackettedExpression)				| (Constraint | Var);
				LimitClause = str_p("LIMIT") >> int_p;
				OffsetClause = str_p("OFFSET") >> int_p;
				GroupGraphPattern = ch_p('{') >> !TriplesBlock>> *((GraphPatternNotTriples | Filter) >> !ch_p('.')>> !TriplesBlock) >> '}';
				GraphTemplate = ch_p('{') >> !TriplesBlock >> *((str_p("GRAPH") >> VarOrIRIref >> GraphTemplate) >> !ch_p('.') >> !TriplesBlock)>> '}';;
				TriplesBlock = TriplesSameSubject >> !(ch_p('.') >> !TriplesBlock);
				GraphPatternNotTriples = OptionalGraphPattern| GroupOrUnionGraphPattern | GraphGraphPattern;
				OptionalGraphPattern = str_p("OPTIONAL") >> GroupGraphPattern;
				GraphGraphPattern = str_p("GRAPH") >> VarOrIRIref	>> GroupGraphPattern;
				GroupOrUnionGraphPattern = GroupGraphPattern % str_p("UNION"); 
				Filter = str_p("FILTER") >> Constraint;
				Constraint = BrackettedExpression | BuiltInCall | FunctionCall;
				FunctionCall = IRIref >> ArgList;
				ArgList = NIL | ch_p('(') >> (Expression % ',') >> ')';
				ConstructTemplate = ch_p('{') >> !ConstructTriples >> '}';;
				ConstructTriples = TriplesSameSubject >> !(ch_p('.')  >> !ConstructTriples);;
				TriplesSameSubject = VarOrTerm >> PropertyListNotEmpty | TriplesNode >> PropertyList;
				PropertyListNotEmpty = (Verb >> ObjectList) % ';';
				PropertyList = !PropertyListNotEmpty;
				ObjectList = Object % ',';
				Object = GraphNode;
				Verb = VarOrIRIref | ch_p('a');
				TriplesNode = Collection | BlankNodePropertyList;
				BlankNodePropertyList = ch_p('[') >> PropertyListNotEmpty >> ']';
				Collection = confix_p('(', +GraphNode, ')');
				GraphNode = VarOrTerm | TriplesNode;
				VarOrTerm = Var | GraphTerm;
				VarOrIRIref = Var | IRIref;
				Var = VAR1 ^ VAR2;
				GraphTerm = IRIref | RDFLiteral | NumericLiteral | BooleanLiteral
				| BlankNode | NIL;
				Expression = ConditionalOrExpression;
				ConditionalOrExpression = ConditionalAndExpression % "||";
				ConditionalAndExpression = ValueLogical % "&&";
				ValueLogical = RelationalExpression;
				RelationalExpression = NumericExpression >> !(ch_p('=')>> NumericExpression | str_p("!=") >> NumericExpression | ch_p('<') >> NumericExpression | ch_p('>') >> NumericExpression| str_p("<=") >> NumericExpression | str_p(">=")>> NumericExpression);
				
				NumericExpression = AdditiveExpression;
				AdditiveExpression = MultiplicativeExpression >> *((sign_p>> MultiplicativeExpression) | NumericExpression);
				MultiplicativeExpression = UnaryExpression % (ch_p('*') | '/');
				UnaryExpression = PrimaryExpression % (ch_p('!') | sign_p);
				PrimaryExpression = BrackettedExpression | BuiltInCall				| IRIrefOrFunction | RDFLiteral | NumericLiteral | BooleanLiteral				| Var;
				BrackettedExpression = ch_p('(') >> Expression >> ')';
				BuiltInCall = ((str_p("STR") | "LANG" | "DATATYPE" | "BOUND" | "isIRI" | "isURI" | "isBLANK" | "isLITERAL") >> BrackettedExpression) | ((str_p("LANGMATCHES") | "sameTerm") >> confix_p('(', Expression >> ch_p(',') >> Expression, ')')) | RegexExpression;
				
				RegexExpression = str_p("REGEX") >> '(' >> Expression >> ',' >> Expression >> !(ch_p(',') >> Expression) >> ')';
				IRIrefOrFunction = IRIref >> !ArgList;
				RDFLiteral = String >> !(LANGTAG | (str_p("^^") >> IRIref));
				NumericLiteral = NumericLiteralUnsigned | NumericLiteralPositive | NumericLiteralNegative;
				NumericLiteralUnsigned = INTEGER | DECIMAL|DOUBLE;
				NumericLiteralPositive = INTEGER_POSITIVE| DECIMAL_POSITIVE|DOUBLE_POSITIVE;
				NumericLiteralNegative = INTEGER_NEGATIVE|DECIMAL_NEGATIVE|DOUBLE_NEGATIVE;
				BooleanLiteral = str_p("true") ^ "false";
				String = STRING_LITERAL1 | STRING_LITERAL2 | STRING_LITERAL_LONG1				| STRING_LITERAL_LONG2;
				IRIref = IRI_REF | PrefixedName;
				PrefixedName = PNAME_LN ^ PNAME_NS;
				BlankNode = BLANK_NODE_LABEL | ANON;
				IRI_REF = ch_p('<')>>  *IRISYM >> '>';
				PNAME_NS =  !(*(alnum_p|'_'|'.'|'-'|'#')) >> ':';
				PNAME_LN = PNAME_NS >>PN_LOCAL;
				BLANK_NODE_LABEL = str_p("_:") >> PN_LOCAL;
				PN_LOCAL =  alpha_p>>( VARNAME%'.') ;
				VAR1 = ch_p('?') >> *alnum_p ;
				VAR2 = ch_p('$') >> *alnum_p ;
				VARNAME=*alnum_p;   /*alpha_p>>*///*((alnum_p|'_'|'.'|'-'|'#')-eol_p-space_p);
 				LANGTAG = ch_p('@') >> +alpha_p >> *(ch_p('-') >> +alnum_p);
				IRISYM=print_p-'>';
				INTEGER = +digit_p;
				DECIMAL = +digit_p >> '.' >> *digit_p | '.' >> +digit_p;
				DOUBLE = +digit_p >> '.' >> *digit_p >> EXPONENT | '.' >> +digit_p >> EXPONENT | +digit_p >> EXPONENT;
				INTEGER_POSITIVE = ch_p('+') >> INTEGER;
				DECIMAL_POSITIVE = ch_p('+') >> DECIMAL;
				DOUBLE_POSITIVE = ch_p('+') >> DOUBLE;
				INTEGER_NEGATIVE = ch_p('-') >> INTEGER;
				DECIMAL_NEGATIVE = ch_p('-') >> DECIMAL;
				DOUBLE_NEGATIVE = ch_p('-') >> DOUBLE;
				EXPONENT = (ch_p('E') | 'e') >> !sign_p >> +digit_p;
				STRING_LITERAL1 = ch_p('\'') >> *((print_p | lex_escape_ch_p) - (ch_p( 0x27))) >> '\'';
				STRING_LITERAL2 = ch_p('"') >> *((print_p | lex_escape_ch_p) -  (ch_p(0x22))) >> '"';
				STRING_LITERAL_LONG1 = str_p("'''") >> *(print_p | lex_escape_ch_p)	>> "'''";
				STRING_LITERAL_LONG2 = str_p("\"\"\"") >> *(print_p | lex_escape_ch_p) >> "\"\"\"";
				//ECHAR = lex_escape_ch_p; ////ch_p('\\') >> chset_p("tbnrf\"\\'");
				NIL = confix_p('(', *(space_p | eol_p), ')');
				//  WS = chset_p("\x20\x9\xD\xA");
				ANON = confix_p('[', *(space_p | eol_p), ']');
				
#if defined(BOOST_SPIRIT_DEBUG)
				BOOST_SPIRIT_DEBUG_RULE(Query); // [0]
				BOOST_SPIRIT_DEBUG_RULE(Update); // [1]
				BOOST_SPIRIT_DEBUG_RULE(Replace); // [2]
				BOOST_SPIRIT_DEBUG_RULE(Delete); // [3]
				BOOST_SPIRIT_DEBUG_RULE(Insert); // [4]
				BOOST_SPIRIT_DEBUG_RULE(GraphIRI); // [5]
				BOOST_SPIRIT_DEBUG_RULE(Load); // [6]
				BOOST_SPIRIT_DEBUG_RULE(Clear); // [7]
				BOOST_SPIRIT_DEBUG_RULE(Manage); // [8]
				BOOST_SPIRIT_DEBUG_RULE(Create); // [9]
				BOOST_SPIRIT_DEBUG_RULE(Drop); // [10]
				BOOST_SPIRIT_DEBUG_RULE(Prologue); // [11]
				BOOST_SPIRIT_DEBUG_RULE(BaseDecl); // [12]
				BOOST_SPIRIT_DEBUG_RULE(PrefixDecl); // [13]
				BOOST_SPIRIT_DEBUG_RULE(SelectQuery); // [14]
				BOOST_SPIRIT_DEBUG_RULE(ConstructQuery); // [15]
				BOOST_SPIRIT_DEBUG_RULE(DescribeQuery); // [16]
				BOOST_SPIRIT_DEBUG_RULE(AskQuery); // [17]
				BOOST_SPIRIT_DEBUG_RULE(DatasetClause); // [18]
				BOOST_SPIRIT_DEBUG_RULE(DefaultGraphClause); // [19]
				BOOST_SPIRIT_DEBUG_RULE(NamedGraphClause); // [20]
				BOOST_SPIRIT_DEBUG_RULE(SourceSelector); // [21]
				BOOST_SPIRIT_DEBUG_RULE(WhereClause); // [22]
				BOOST_SPIRIT_DEBUG_RULE(BindingClause); // [23]
				BOOST_SPIRIT_DEBUG_RULE(Binding); // [24]
				BOOST_SPIRIT_DEBUG_RULE(SolutionModifier); // [25]
				BOOST_SPIRIT_DEBUG_RULE(LimitOffsetClauses); // [26]
				BOOST_SPIRIT_DEBUG_RULE(OrderClause); // [27]
				BOOST_SPIRIT_DEBUG_RULE(OrderCondition); // [28]
				BOOST_SPIRIT_DEBUG_RULE(LimitClause); // [29]
				BOOST_SPIRIT_DEBUG_RULE(OffsetClause); // [30]
				BOOST_SPIRIT_DEBUG_RULE(GroupGraphPattern); // [31]
				BOOST_SPIRIT_DEBUG_RULE(GraphTemplate); // [32]
				BOOST_SPIRIT_DEBUG_RULE(TriplesBlock); // [33]
				BOOST_SPIRIT_DEBUG_RULE(GraphPatternNotTriples); // [34]
				BOOST_SPIRIT_DEBUG_RULE(OptionalGraphPattern); // [35]
				BOOST_SPIRIT_DEBUG_RULE(GraphGraphPattern); // [36]
				BOOST_SPIRIT_DEBUG_RULE(GroupOrUnionGraphPattern); // [37]
				BOOST_SPIRIT_DEBUG_RULE(Filter); // [38]
				BOOST_SPIRIT_DEBUG_RULE(Constraint); // [39]
				BOOST_SPIRIT_DEBUG_RULE(FunctionCall); // [40]
				BOOST_SPIRIT_DEBUG_RULE(ArgList); // [41]
				BOOST_SPIRIT_DEBUG_RULE(ConstructTemplate); // [42]
				BOOST_SPIRIT_DEBUG_RULE(ConstructTriples); // [43]
				BOOST_SPIRIT_DEBUG_RULE(TriplesSameSubject); // [44]
				BOOST_SPIRIT_DEBUG_RULE(PropertyListNotEmpty); // [45]
				BOOST_SPIRIT_DEBUG_RULE(PropertyList); // [46]
				BOOST_SPIRIT_DEBUG_RULE(ObjectList); // [47]
				BOOST_SPIRIT_DEBUG_RULE(Object); // [48]
				BOOST_SPIRIT_DEBUG_RULE(Verb); // [49]
				BOOST_SPIRIT_DEBUG_RULE(TriplesNode); // [50]
				BOOST_SPIRIT_DEBUG_RULE(BlankNodePropertyList); // [51]
				BOOST_SPIRIT_DEBUG_RULE(Collection); // [52]
				BOOST_SPIRIT_DEBUG_RULE(GraphNode); // [53]
				BOOST_SPIRIT_DEBUG_RULE(VarOrTerm); // [54]
				BOOST_SPIRIT_DEBUG_RULE(VarOrIRIref); // [55]
				BOOST_SPIRIT_DEBUG_RULE(Var); // [56]
				BOOST_SPIRIT_DEBUG_RULE(GraphTerm); // [57]
				BOOST_SPIRIT_DEBUG_RULE(Expression); // [58]
				BOOST_SPIRIT_DEBUG_RULE(ConditionalOrExpression); // [59]
				BOOST_SPIRIT_DEBUG_RULE(ConditionalAndExpression); // [60]
				BOOST_SPIRIT_DEBUG_RULE(ValueLogical); // [61]
				BOOST_SPIRIT_DEBUG_RULE(RelationalExpression); // [62]
				BOOST_SPIRIT_DEBUG_RULE(NumericExpression); // [63]
				BOOST_SPIRIT_DEBUG_RULE(AdditiveExpression); // [64]
				BOOST_SPIRIT_DEBUG_RULE(MultiplicativeExpression); // [65]
				BOOST_SPIRIT_DEBUG_RULE(UnaryExpression); // [66]
				BOOST_SPIRIT_DEBUG_RULE(PrimaryExpression); // [67]
				BOOST_SPIRIT_DEBUG_RULE(BrackettedExpression); // [68]
				BOOST_SPIRIT_DEBUG_RULE(BuiltInCall); // [69]
				BOOST_SPIRIT_DEBUG_RULE(RegexExpression); // [70]
				BOOST_SPIRIT_DEBUG_RULE(IRIrefOrFunction); // [71]
				BOOST_SPIRIT_DEBUG_RULE(RDFLiteral); // [72]
				BOOST_SPIRIT_DEBUG_RULE(NumericLiteral); // [73]
				BOOST_SPIRIT_DEBUG_RULE(NumericLiteralUnsigned); // [74]
				BOOST_SPIRIT_DEBUG_RULE(NumericLiteralPositive); // [75]
				BOOST_SPIRIT_DEBUG_RULE(NumericLiteralNegative); // [76]
				BOOST_SPIRIT_DEBUG_RULE(BooleanLiteral); // [77]
				BOOST_SPIRIT_DEBUG_RULE(String); // [78]
				BOOST_SPIRIT_DEBUG_RULE(IRIref); // [79]
				BOOST_SPIRIT_DEBUG_RULE(PrefixedName); // [80]
				BOOST_SPIRIT_DEBUG_RULE(BlankNode); // [81]
				BOOST_SPIRIT_DEBUG_RULE(IRI_REF); // [82]
				BOOST_SPIRIT_DEBUG_RULE(PNAME_NS); // [83]
				BOOST_SPIRIT_DEBUG_RULE(PNAME_LN); // [84]
				BOOST_SPIRIT_DEBUG_RULE(BLANK_NODE_LABEL); // [85]
				BOOST_SPIRIT_DEBUG_RULE(VAR1); // [86]
				BOOST_SPIRIT_DEBUG_RULE(VAR2); // [87]
				BOOST_SPIRIT_DEBUG_RULE(LANGTAG); // [88]
				BOOST_SPIRIT_DEBUG_RULE(INTEGER); // [89]
				BOOST_SPIRIT_DEBUG_RULE(DECIMAL); // [90]
				BOOST_SPIRIT_DEBUG_RULE(DOUBLE); // [91]
				BOOST_SPIRIT_DEBUG_RULE(INTEGER_POSITIVE); // [92]
				BOOST_SPIRIT_DEBUG_RULE(DECIMAL_POSITIVE); // [93]
				BOOST_SPIRIT_DEBUG_RULE(DOUBLE_POSITIVE); // [94]
				BOOST_SPIRIT_DEBUG_RULE(INTEGER_NEGATIVE); // [95]
				BOOST_SPIRIT_DEBUG_RULE(DECIMAL_NEGATIVE); // [96]
				BOOST_SPIRIT_DEBUG_RULE(DOUBLE_NEGATIVE); // [97]
				BOOST_SPIRIT_DEBUG_RULE(EXPONENT); // [98]
				BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL1); // [99]
				BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL2); // [100]
				BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL_LONG1); // [101]
				BOOST_SPIRIT_DEBUG_RULE(STRING_LITERAL_LONG2); // [102]
//				BOOST_SPIRIT_DEBUG_RULE(ECHAR); // [103]
				BOOST_SPIRIT_DEBUG_RULE(NIL); // [104]
				//BOOST_SPIRIT_DEBUG_RULE(WS); // [105]
				BOOST_SPIRIT_DEBUG_RULE(ANON); // [106]
//				BOOST_SPIRIT_DEBUG_RULE(PN_CHARS_BASE); // [107]
//				BOOST_SPIRIT_DEBUG_RULE(PN_CHARS_U); // [108]
//				BOOST_SPIRIT_DEBUG_RULE(VARNAME); // [109]
//				BOOST_SPIRIT_DEBUG_RULE(PN_CHARS); // [110]
//				BOOST_SPIRIT_DEBUG_RULE(PN_PREFIX); // [111]
				BOOST_SPIRIT_DEBUG_RULE(PN_LOCAL); // [112]
//				BOOST_SPIRIT_DEBUG_RULE(BUZZKILL); // [112]
//				BOOST_SPIRIT_DEBUG_RULE(SYMBOL); // [112]
				//				BOOST_SPIRIT_DEBUG_RULE(MORPHEME); // [112]
				BOOST_SPIRIT_DEBUG_RULE(VARNAME); // [112]
				BOOST_SPIRIT_DEBUG_RULE(IRISYM); // [112]

#endif
			}
			
			rule<ScannerT> Query; // [0]
			rule<ScannerT> Update; // [1]
			rule<ScannerT> Replace; // [2]
			rule<ScannerT> Delete; // [3]
			rule<ScannerT> Insert; // [4]
			rule<ScannerT> GraphIRI; // [5]
			rule<ScannerT> Load; // [6]
			rule<ScannerT> Clear; // [7]
			rule<ScannerT> Manage; // [8]
			rule<ScannerT> Create; // [9]
			rule<ScannerT> Drop; // [10]
			rule<ScannerT> Prologue; // [11]
			rule<ScannerT> BaseDecl; // [12]
			rule<ScannerT> PrefixDecl; // [13]
			rule<ScannerT> SelectQuery; // [14]
			rule<ScannerT> ConstructQuery; // [15]
			rule<ScannerT> DescribeQuery; // [16]
			rule<ScannerT> AskQuery; // [17]
			rule<ScannerT> DatasetClause; // [18]
			rule<ScannerT> DefaultGraphClause; // [19]
			rule<ScannerT> NamedGraphClause; // [20]
			rule<ScannerT> SourceSelector; // [21]
			rule<ScannerT> WhereClause; // [22]
			rule<ScannerT> BindingClause; // [23]
			rule<ScannerT> Binding; // [24]
			rule<ScannerT> SolutionModifier; // [25]
			rule<ScannerT> LimitOffsetClauses; // [26]
			rule<ScannerT> OrderClause; // [27]
			rule<ScannerT> OrderCondition; // [28]
			rule<ScannerT> LimitClause; // [29]
			rule<ScannerT> OffsetClause; // [30]
			rule<ScannerT> GroupGraphPattern; // [31]
			rule<ScannerT> GraphTemplate; // [32]
			rule<ScannerT> TriplesBlock; // [33]
			rule<ScannerT> GraphPatternNotTriples; // [34]
			rule<ScannerT> OptionalGraphPattern; // [35]
			rule<ScannerT> GraphGraphPattern; // [36]
			rule<ScannerT> GroupOrUnionGraphPattern; // [37]
			rule<ScannerT> Filter; // [38]
			rule<ScannerT> Constraint; // [39]
			rule<ScannerT> FunctionCall; // [40]
			rule<ScannerT> ArgList; // [41]
			rule<ScannerT> ConstructTemplate; // [42]
			rule<ScannerT> ConstructTriples; // [43]
			rule<ScannerT> TriplesSameSubject; // [44]
			rule<ScannerT> PropertyListNotEmpty; // [45]
			rule<ScannerT> PropertyList; // [46]
			rule<ScannerT> ObjectList; // [47]
			rule<ScannerT> Object; // [48]
			rule<ScannerT> Verb; // [49]
			rule<ScannerT> TriplesNode; // [50]
			rule<ScannerT> BlankNodePropertyList; // [51]
			rule<ScannerT> Collection; // [52]
			rule<ScannerT> GraphNode; // [53]
			rule<ScannerT> VarOrTerm; // [54]
			rule<ScannerT> VarOrIRIref; // [55]
			rule<ScannerT> Var; // [56]
			rule<ScannerT> GraphTerm; // [57]
			rule<ScannerT> Expression; // [58]
			rule<ScannerT> ConditionalOrExpression; // [59]
			rule<ScannerT> ConditionalAndExpression; // [60]
			rule<ScannerT> ValueLogical; // [61]
			rule<ScannerT> RelationalExpression; // [62]
			rule<ScannerT> NumericExpression; // [63]
			rule<ScannerT> AdditiveExpression; // [64]
			rule<ScannerT> MultiplicativeExpression; // [65]
			rule<ScannerT> UnaryExpression; // [66]
			rule<ScannerT> PrimaryExpression; // [67]
			rule<ScannerT> BrackettedExpression; // [68]
			rule<ScannerT> BuiltInCall; // [69]
			rule<ScannerT> RegexExpression; // [70]
			rule<ScannerT> IRIrefOrFunction; // [71]
			rule<ScannerT> RDFLiteral; // [72]
			rule<ScannerT> NumericLiteral; // [73]
			rule<ScannerT> NumericLiteralUnsigned; // [74]
			rule<ScannerT> NumericLiteralPositive; // [75]
			rule<ScannerT> NumericLiteralNegative; // [76]
			rule<ScannerT> BooleanLiteral; // [77]
			rule<ScannerT> String; // [78]
			rule<ScannerT> IRIref; // [79]
			rule<ScannerT> PrefixedName; // [80]
			rule<ScannerT> BlankNode; // [81]
			rule<ScannerT> IRI_REF; // [82]
			rule<ScannerT> PNAME_NS; // [83]
			rule<ScannerT> PNAME_LN; // [84]
			rule<ScannerT> BLANK_NODE_LABEL; // [85]
			rule<ScannerT> VAR1; // [86]
			rule<ScannerT> VAR2; // [87]
			rule<ScannerT> LANGTAG; // [88]
			rule<ScannerT> INTEGER; // [89]
			rule<ScannerT> DECIMAL; // [90]
			rule<ScannerT> DOUBLE; // [91]
			rule<ScannerT> INTEGER_POSITIVE; // [92]
			rule<ScannerT> DECIMAL_POSITIVE; // [93]
			rule<ScannerT> DOUBLE_POSITIVE; // [94]
			rule<ScannerT> INTEGER_NEGATIVE; // [95]
			rule<ScannerT> DECIMAL_NEGATIVE; // [96]
			rule<ScannerT> DOUBLE_NEGATIVE; // [97]
			rule<ScannerT> EXPONENT; // [98]
			rule<ScannerT> STRING_LITERAL1; // [99]
			rule<ScannerT> STRING_LITERAL2; // [100]
			rule<ScannerT> STRING_LITERAL_LONG1; // [101]
			rule<ScannerT> STRING_LITERAL_LONG2; // [102]
			//rule<ScannerT> ECHAR; // [103]
			rule<ScannerT> NIL; // [104]
//			rule<ScannerT> WS; // [105]
			rule<ScannerT> ANON; // [106]
//			rule<ScannerT> PN_CHARS_BASE; // [107]
//			rule<ScannerT> PN_CHARS_U; // [108]
//			rule<ScannerT> VARNAME; // [109]
//			rule<ScannerT> PN_CHARS; // [110]
//			rule<ScannerT> PN_PREFIX; // [111]
			rule<ScannerT> PN_LOCAL; // [112]
//			
//			rule<ScannerT> BUZZKILL			; // [112]
//			rule<ScannerT> SYMBOL			; // [112]
			//			rule<ScannerT> MORPHEME			; // [112]
			rule<ScannerT> VARNAME			; // [112]
			rule<ScannerT> IRISYM			; // [112]
			
	rule<ScannerT> const&
			start() const
			{
				return Query;
			}
		};
	};
}

#if 0
/*
 #created by
 #!/bin/bash
 
 grep =  sparql.h |cut -f 1 -d=|grep -v '[;*]'|tr -s ' \t' ' '>hi.bak
 c=0;for i in $(cat hi.bak); do echo "BOOST_SPIRIT_DEBUG_RULE($i); // [${c}]";((c++));doneBOOST_SPIRIT_DEBUG_RULE
 c=0;for i in $(cat  hi.bak); do echo "rule<ScannerT> $i; // [${c}]";((c++));done
 */
#endif
