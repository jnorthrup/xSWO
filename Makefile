# $Id: Makefile,v 1.40 2008/09/08 08:16:35 eric Exp $
# SWObjects build rules -- see http://www.w3.org/2008/04/SPARQLfed/

# recipies:
#   normal build:
#     make SPARQLfed
#   force the use of the tracing facilities (and redirect to stdout):
#     make -W sample_RuleMap1.cpp test
#   have valgrind start a debugger (works as M-x gdb invocation command):
#     valgrind --db-attach=yes --leak-check=yes sample_RuleMap1 query_HealthCare1.rq ruleMap_HealthCare1.rq
#   same, if you aren't working in gdb:
#     make valgrind
#   debugging in emacs:
#     gdb --annotate=3 sample_RuleMap1    (set args query_HealthCare1.rq ruleMap_HealthCare1.rq)


LEX_?=flex
YACC?=bison
TEE?=tee
SED?=sed
#LIBS
DEBUG?=-g
#OPT=-O4
DEFS?=-DYYTEXT_POINTER=1
WARN?=-W -Wall -Wextra -Wnon-virtual-dtor
BASENAME ?= basename
MV ?= mv
RM ?= rm
PWD ?= $(shell pwd -P)

INCLUDES += -I${PWD}
LIB_MODULES+= -L${PWD}


BOOST_PREFIX?=/usr/local
BOOST_VER?=1_36
BOOST_INC?=$(BOOST_PREFIX)/include/boost-$(BOOST_VER)/
INCLUDES+= -I$(BOOST_INC) 

BOOST_LIB?=$(BOOST_PREFIX)/lib
LIB_MODULES+=-L$(BOOST_LIB)


I2=$(subst /, ,$(BISON_OBJ:.o=))
I3=$(sort $(I2))

INCLUDES += $(I3:%=-I${PWD}/%)  

.SECONDARY:

%.d : %.cpp
	-touch $@
	-makedepend -y -f $@ $^ $(DEFS) $(INCLUDES) 2>/dev/null

%.cpp  %.hpp : %.ypp
	$(YACC) -o $(@:.hpp=.cpp) $<
	$(SED) -i~ 's,# define PARSER_HEADER_H,#pragma once,' $(@:.cpp=.hpp)

%.cpp : %.lpp
	$(LEX) -o $@  $<

#%.bin : %.o 
#	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)


#the gcc commands to make DEPS used in .d rules
#if -M[M]D is also in the build-clause without -E it update .d's as needed
TOONOISEY=-ansi
#for macports
CFLAGS += $(DEFS) $(OPT) $(DEBUG) $(WARN) $(INCLUDES) -pipe
CXXFLAGS += $(CFLAGS)

### absolutely neccessry for c++ linking ###
LD = $(CXX)
LDFLAGS += $(LIB_MODULES)
VER=0.1

#some progressive macports
#CC=llvm-gcc
#CXX=llvm-g++
#LLVMCFLAGS = ` llvm-config --cflags` -O4
#LLVMCXXFLAGS = ` llvm-config --cxxflags` -O4
#LLVMLDFLAGS = ` llvm-config --ldflags --libs `
#LLVMLIBS= ` llvm-config --libs`
# ... you get the idea...
CFLAGS	+= $(LLVMCFLAGS)
LIB_MODULES	+= -L$(PWD)

### dirt simple generic static module ###
BISON_OBJ ?= $($(wildcard *.ypp):%.ypp=%.o)
FLEX_OBJ  ?= $($(wildcard *.lpp):%.lpp=%.o)
CXX_OBJ   ?= $(subst .cpp,.o,$(wildcard *.cpp))
LIB_OBJ   ?= $(CXX_OBJ:%main.o=)
LIB_NAME  ?= $(shell $(BASENAME) $(PWD))
LIB_FINAL ?= lib$(LIB_NAME).a
LIB_MODULES+=	 -l$(LIB_NAME)
#$(shell $(BASENAME) $(PWD))

$(LIB_FINAL): $(DEPS)

$(LIB_FINAL): $(BISON_OBJ) $(FLEX_OBJ) $(LIB_OBJ)
	$(AR) rcvs $@ $^

#TOOL_OBJ=$(subst .cpp,.o,$(wildcard *main.cpp))
#TOOL_BIN=$(TOOLOBJ:.o=.bin)

#$(TOOL_BIN): dep lib

#TOOL_NAME_PREFIX=$(shell $(BASENAME) $(PWD))

#$(TOOL_NAME_PREFIX)% : %main.bin
#	$(MV) $@ $<

#TOOL_FINAL = $(TOOL_BIN:%main.bin=$(TOOL_NAME_PREFIX)%)

TOOL_FINAL = $(shell $(BASENAME) $(PWD))

$(TOOL_FINAL): main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


.PHONY: tool


##### packaged tests ####
## test inferenced based on T, test_<T>.o=C/C++ query_<T>.rq ruleMap<T>.rq
#tests/test_%  : tests/test_%.cpp $(LIB) $(DEPS)
#	$(Cxx) $(Cxxflags) -O $@ $< $(LDFLAGS)

%_test.results : tests/test_% tests/query_%.rq tests/ruleMap_%.rq
	$^ -s http://someClinic.exampe/DB/ > $@  && cat $@

%_test.valgrind  : tests/test_% tests/query_%.rq tests/ruleMap_%.rq
	valgrind --leak-check=yes --xml=no $^ -s http://someClinic.exampe/DB/

### named unit tests

TEST_SRC?=$(wildcard tests/test_*.cpp)

TESTS=$($(TEST_SRC):.cpp=)

TEST_RESULTS=$(TESTS:%=.results)
VALGRIND=$(TEST_RESULTS:.results=.valgrind)

# Distributions

release:
	$(RM) -f SWObjects_$(VER).tar.gz README.html
	lynx -dump -source http://www.w3.org/2008/04/SPARQLfed/ | perl -pe 's{href="\.\./\.\./\.\.}{href="http://www.w3.org}g;s{href="\.\./\.\.}{href="http://www.w3.org/2008}g'> README.html
	@echo "Generating the inclusion from the manifest (HEADER.html)"
	@perl -ne 'print join("\n", "README.html", m/href="([a-zA-Z]{2}[a-zA-Z0-9._\/]+)"/g, undef)' HEADER.html | xargs tar czf SWObjects_$(VER).tar.gz --transform s,,SWObjects_$(VER)/,1
	$(RM) README.html


# Clean - rm everything we remember to rm.
.PHONY: clean cleaner
clean:
	$(RM) *.o */*.o *.a *.dylib *.so *.la */*.bak *.bak \
        $(subst .lpp,.cpp,$(wildcard *.lpp)) \
        $(subst .ypp,.cpp,$(wildcard */*.ypp)) \
        $(subst .ypp,.hpp,$(wildcard */*.ypp)) \
        $(TESTS) $(TEST_RESULTS) $(VALGRIND) \
	$(TOOL_BIN) $(TOOL_FINAL)
	

cleaner: clean
	 $(RM) *~ */*.d *.d $(BISON_HH:%=*/%)

DEPS=$(BISON_OBJ:.o=.d) $(FLEX_OBJ:.o=.d) $(LIB_OBJ:.o=.d) 

dep: $(DEPS)

BISON_HH=location.hh stack.hh position.hh
#$(BISON_HH): $(BISON_OBJ)
-include $(DEPS)

.PHONY: all dep tool lib test

tool: lib $(TOOL_FINAL)

all: tool test

.PHONY: all tool test valgrind


test: dep lib $(TEST_RESULTS)

valgrind: $(VALGRIND)

.PHONY: lib

lib: dep $(LIB_FINAL)


