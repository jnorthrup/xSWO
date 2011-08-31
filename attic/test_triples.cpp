// test_triples.cpp : Defines the entry point for the console application.
//

#include <agent_api/agent_api.hxx>
using namespace glamdring;

void test_sequence_semantics( vector<triple<string> >&t)
{ 
	triple<string>::log_triple_context test_context;
	for(vector<triple<string> >::iterator iter=t.begin();iter!=t.end();++iter){
		test_context.push_back(*iter);
	}


	/** 
	node serialization (out)
	*/
	{
		//use this mandatory scoping for the automatic close/flush of the archive.
		boost::archive::xml_oarchive oa(cout);
		oa << make_nvp("sequence_context",test_context);     
	};
}

void test_set_semantics( vector<triple<string> >&t)
{ 
	triple<string>::normalized_triple_context test_context;
	for(vector<triple<string> >::iterator iter=t.begin();iter!=t.end();++iter){
		test_context.insert(*iter);
	}


	/** 
	node serialization (out)
	*/
	{
		//use this mandatory scoping for the automatic close/flush of the archive.
		boost::archive::xml_oarchive oa(cout);
		oa << make_nvp("set_context",test_context);     
	}

}

int main(int argc, const char** argv)
{
	/* 
	Reply-To: "Microsoft" <20_27151_2OL1q5tFptc6SxGkz2p3Uw@newsletters.microsoft.com>
	From: "Microsoft" <20_27151_2OL1q5tFptc6SxGkz2p3Uw@newsletters.microsoft.com>
	To: <jnorthrup@glamdring.com>
	Subject: Microsoft Download Notifications: December 30, 2005
	Date: Fri, 30 Dec 2005 12:56:43 -0800
	Message-ID: <258dc901c60d83$8a54fbe0$7e02280a@phx.gbl>
	Content-Class: urn:content-classes:message
	*/
	/**
	node creation.
	*/

	glamdring::triple<string> jim("<jnorthrup@glamdring.com>",		"dc:fullName",		"James Northrup");
	glamdring::triple<string> bill("mailto://billg@microsoft.com",		"dc:fullName",		"Bill Gates");
	glamdring::triple<string> msgId("_:1",		"smtp:Id",		"<258dc901c60d83$8a54fbe0$7e02280a@phx.gbl>");
	glamdring::triple<string> msgTo("_:1",		"smtp:To",		"<jnorthrup@glamdring.com>");
	glamdring::triple<string> msgType("_:1",		"Content-Class",		"urn:content-classes:message");


	//create a test vector

	vector<triple<string> > t;
	t.push_back(jim);
	t.push_back(bill);
	t.push_back(jim);
	t.push_back(jim);
	t.push_back(msgId);
	t.push_back(msgTo);
	t.push_back(msgTo);
	t.push_back(msgType);


	/** node insertion
	*/
	test_set_semantics(t );
	test_sequence_semantics(t);

	return 0;
};
