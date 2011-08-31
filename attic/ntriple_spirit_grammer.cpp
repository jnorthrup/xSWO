

/**
<p>
This unit test shapes the spirit code for the ntriples ebnf grammer.

During operation this also fires small console events to indicate the event state during a 
commandline pipe operation.

currently this is run by executing :

<pre>
jnorthrup@dove /c/work/sandbox/agent/release
$ ./ntriple_grammar.exe < ../agent_api/final.ntriples
</pre>


for more info on the grammar see:

<p>
http://www.w3.org/2001/sw/RDFCore/ntriples/

<p>
Extended Backus-Naur Form (EBNF) Grammar

An N-Triples document is a sequence of US-ASCII characters and is defined by the ntripleDoc grammar term below. Parsing it results in a sequence of RDF statements formed from the subject, predicate and object terms. The meaning of these are defined either in [RDFMS] or is ongoing as part of the RDF Core WG activity.
<pre>
This EBNF is the notation used in XML 1.0 second edition
		ntripleDoc 	::= 	line* 	 
		line 		::= 	ws* (comment | triple) ? eoln 	 
		comment 	::= 	'#' (character - ( cr | lf ) )* 	 
		triple 		::= 	subject ws+ predicate ws+ object ws* '.' ws* 	 
		subject 	::= 	uriref | namedNode 	 
		predicate 	::= 	uriref 	 
		object 		::= 	uriref | namedNode | literal 	 
		uriref 		::= 	'<' absoluteURI '>' 	 
		namedNode 	::= 	'_:' name 	 
		literal 	::= 	'"' string '"' 	 
		ws 			::= 	space | tab 	 
		eoln 		::= 	cr | lf | cr lf 	 
		space 		::= 	#x20 /* US-ASCII space - decimal 32 
		cr 			::= 	#xD /* US-ASCII carriage return - decimal 13 
		lf 			::= 	#xA /* US-ASCII linefeed - decimal 10  	 
		tab 		::= 	#x9 /* US-ASCII horizontal tab - decimal 9 
		string 		::= 	character* with escapes. Defined in section Strings 	 
		name 		::= 	[A-Za-z][A-Za-z0-9]* 	 
		absoluteURI ::= 	( character - ( '<' | '>' | space ) )+ 	 
		character 	::= 	[#x20-#x7E] /* US-ASCII space to decimal 127  
</pre>
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


namespace{
    void do_comment(const char*begin , const char* end){cout << "comment!" << endl;};
	void do_triple(const char*begin , const char* end){cout << "triple!\t";};
	void do_blank(const char*begin , const char* end){cout << "blank!\t";};
}

struct ntriples: public grammar<ntriples>
{
    template <typename ScannerT>
    struct definition
    {
        definition(ntriples const& /*self*/)
        {
		ntripleDoc 	= 	*(line);
		line 		= 	blank_p >> *(comment [&do_comment]
			| triple[&do_triple]
			)  >> !eol_p;
		comment 	= 	ch_p('#') >> * ( character - eol_p )	 ;
		triple 		= 	subject >> + blank_p >> predicate>> + blank_p >> object>> *blank_p >> '.' >> *blank_p; //see the cin<< parser statement to fine-tune 
		subject 	= 	uriref | namedNode ;
		predicate 	= 	uriref ;
		object 		= 	(uriref | namedNode |  literal);a
		literal		=   confix_p('"', *c_escape_ch_p, '"');
		uriref 		=   confix_p('<',absoluteURI,'>');
		namedNode	= 	(chseq_p("_:" ) >> alnum_p)[&do_blank];		
		absoluteURI = 	+( character  - (  blank_p| '<'  | '>' ) );
	    character   = range_p( 0x20 , 0x7E);    // /* US-ASCII space to decimal 127  
        }

        rule<ScannerT>  ntripleDoc 	,
						line 		,
						comment 	,
						triple 		,
						subject 	,
						predicate 	,
						object 		,
						literal		,
						uriref 		,
						namedNode	,
						absoluteURI ,
						 character;
        rule<ScannerT> const&
			start() const { return ntripleDoc; }
    };
};
int main(int argc, char**argv){

    ntriples triples; //our parser

    string str;
    while (getline(cin, str))
    {
		parse_info<> info = parse(str.c_str(), triples, eol_p);
		cout << (info.full ?"+":"-");
    }

    cout << "Bye... :-) \n\n";
    return 0;
 
};