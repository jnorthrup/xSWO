/***

<pre>
#  Taken from http://www.w3.org/DesignIssues/Notation3.html
#  on 2001-08-03 (version of 2001-04-10)
#
#  Modifications:
#     
# $Log: n3.bnf,v $
# Revision 1.4  2001/08/06 20:56:21  sandro
# added space* and space+ in several places
# removed "#" from forbidden chars in URI_Reference
# handles comments
# made directives actually part of the grammar (!)
# allowed nprefix to be zero-length
#
# Revision 1.3  2001/08/03 13:44:43  sandro
# filled in remaining non-terminals
#
# Revision 1.2  2001/08/03 13:02:48  sandro
# standardized BNF so blindfold can compile it
#    added ::= for each rule
#    added | for branches
#    added ; at end of rule
#    added # before comments
#    put quotes around literals
#    turn hypen into underscore in identifiers
#    rename prefix to nprefix (hack around blindfold keyword for now)
#
# Revision 1.1  2001/08/03 12:34:38  sandro
# added opening comments
#


document ::= void 
| statementlist;

space ::= " " | "\n" | "\r" | comment;

comment ::= "#" [^\r\n]*;

statement ::= subject space+ property_list
| directive
;

statementlist ::= (statement space* ("." space*)?)* ;

subject ::= node;

verb ::= ">-" prop "->"    # has xxx of 
| "<-" prop "<-"    # is xxx of 
#  | operator          # has operator:xxx of??? NOT IMPLMENTED
| prop              # has xxx of -- shorthand
| "has" prop        # has xxx of
| "is" prop "of"    # is xxx of
| "a"               # has rdf:type of
| "="		   # has daml:equivaent of
;

prop ::= node;

node ::= uri_ref2 
| anonnode
| "this"
| node 
;

nodelist ::= void    # (used in lists) 
| node
| node nodelist
;

anonnode ::= "[" property_list "]"  # something which ...
| "{" statementlist "}"  # the statementlist itself as a resource
| "(" nodelist ")"       # short for eg [ n3:first node1; n3:rest [ n3:first node2; n3:rest: n3:null ]]
;

property_list ::= void   # to allow [...]. 
| verb space+ object_list
| verb space+ object_list space+ ";" space+ property_list
| ":-" anonnode  #to allow two anonymous forms to be given eg [ a :Truth; :- { :sky :color :blue } ] )
| ":-" anonnode ";" property_list
;

object_list ::= object 
| object "," object_list
;

uri_ref2 ::= qname 
| "<" URI_Reference ">"
;

qname ::= nprefix ":" localname; # ??? Allow omit colon when prefix void - keyword clash 

object ::= subject 
| string1 # " constant-value-with-escaping "
| string2 # """ constant value with escaping including single or double occurences of quotes and/or newlines """
#      well-formed-xml-element ???? legacy or structured stuff - not implemented or distinguished
;

directive ::= "bind" space+ nprefix ":" uri_ref2   # Namespace declartion. Trailing "#" is omitted & assumed. Obsolete.
| "@prefix" space+ nprefix ":" space+ uri_ref2  # Namespace declaration
;

# operator ::=  (Not implemented) 
#      + >- operator:plus -> 
#      - >- operator:minus ->
#      / >- operator:slash->
#      * >- operator:star-> (etc? @@)

fragid ::= alpha alphanumeric* ;

alpha ::= [a-zA-Z];

alphanumeric ::= alpha | [0-9] | "_";

void ::= "" ;   # nothing

URI_Reference ::= [^{}<>]*;    # short version

nprefix ::= "" | ((alpha | "_") alphanumeric*);

localname ::= fragid;

string1 ::= '"' string1_char* '"';

string1_char ::= '\\"' | [^\"] ;           # should disallow some other characters, etc.

string2 ::= '"""' string2_char* '"""';

string2_char ::= [^"] | ([^] [^] [^"]);    # something like this; need to think about it some more
</pre>


http://spirit.sourceforge.net/distrib/spirit_1_8_3/libs/spirit/doc/quickref.html
*/
#include <boost/spirit/core.hpp>
#include <boost/spirit/utility/confix.hpp>
#include <boost/spirit/utility/chset.hpp>
#include <boost/spirit/utility/escape_char.hpp>

#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////
using namespace std;
using namespace boost::spirit;

////////////////////////////////////////////////////////////////////////////
//
//  Semantic actions
//
////////////////////////////////////////////////////////////////////////////
namespace
{


}

////////////////////////////////////////////////////////////////////////////
//
//  Our grammar
//
////////////////////////////////////////////////////////////////////////////
struct n3parser : public grammar<n3parser>
{
	template <typename ScannerT>
	struct definition
	{
		definition(n3parser const& /*self*/)
		{

			document  =		nothing_p 
				| statementlist;
			space =			space_p | comment;
			comment =		ch_p("#") >>*(anychar_p-eol_p );
			statement =		subject  >> +space	>>  property_list	| directive	;
			statementlist = *(statement >> * space >> !(ch_p('.') >> *space)  );
			subject =		node;
			verb = 			confix_p(">-" ,prop ,"->")		// has xxx of 
				| confix_p("<-" ,prop ,"<-"   )	// is xxx of 
				| prop							// has xxx of -- shorthand
				| str_p	("has") >> prop		// has xxx of
				| confix_p ("is" ,prop ,"of")	// is xxx of
				| ch_p("a")						// has rdf:type of
				| ch_p("=")						// has daml:equivalent of
				;
			prop =			node;
			node =			uri_ref2 
				| anonnode
				| str_p("this")
				| node 
				;
			nodelist =		nothing_p						//# (used in lists) 							
				| node >> !nodelist
				;
			anonnode =		confix_p('[' ,property_list ,']')	//# something which ...
				| confix_p("{",statementlist,"}")	//# the statementlist itself as a resource
				| confix_p("(",nodelist,")")		//# short for eg [ n3:first node1; n3:rest [ n3:first node2; n3:rest: n3:null ]]
				;
			property_list =	nothing_p      //  # to allow [...]. 								
				| verb  >> +space  >> object_list >> !(+ space >> ";" >> +space >> property_list)
				| str_p(":-" ) >> anonnode >> !(";" >> property_list)
				;
			object_list =	object >> !(","	>>	object_list)
				;
			uri_ref2 =		qname 
							| confix_p( "<" ,URI_Reference ,">")
				;
			qname =			nprefix >> ":" >>localname; //# ??? Allow omit colon when prefix void - keyword clash 
			object =		subject 
				| string1 
				;
			directive =		str_p("bind")		>> +space	>> nprefix >>	":" >>	uri_ref2   //# Namespace declartion. Trailing "#" is omitted & assumed. Obsolete.
						  | str_p("@prefix")	>> +space	>> nprefix >>	":" >>	+space	>> uri_ref2  //# Namespace declaration
				;
			fragid =		alpha_p >> *alnum_p ; 
			URI_Reference = *(anychar_p-(chset_p("{}<>")|space_p));    //# short version
			nprefix	=		nothing_p | (alpha_p | "_") >> *alnum_p ;
			localname =		fragid;
			triple_quote =  ch_p('"')>>ch_p('"')>>ch_p('"');
			string1 =	    confix_p('"', *c_escape_ch_p, '"')|
				confix_p(triple_quote , *c_escape_ch_p, triple_quote);
		};

		rule<ScannerT> URI_Reference , 
						anonnode ,		
						comment ,		
						directive ,		
						document ,		
						fragid ,		
						localname ,		
						node ,			
						nodelist ,		
						nprefix	,		
						object ,		
						object_list ,	
						prop ,			
						property_list ,	
						qname ,			
						space ,			
						statement ,		
						statementlist , 
						string1  ,
						subject ,		
						triple_quote , 
						uri_ref2 ,		
						verb ;

		rule<ScannerT> const&
			start() const { return document; }
	};
};

////////////////////////////////////////////////////////////////////////////
//
//  Main program
//
////////////////////////////////////////////////////////////////////////////
int
main(int argc, char** argv)
{
	n3parser n3;    //  Our parser

	string str;
	while (getline(cin, str))
	{
		parse_info<> info = parse(str.c_str(), n3, end_p);
		cout << (info.full ?"+":"-");
	}

	cout << "Bye... :-) \n\n";
	return 0;
};



