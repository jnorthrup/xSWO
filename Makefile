# drop a note and say hi once in a while! thanks
#
# -the authors
#
#

VER=0.9999
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
FIND ?= find
PWD ?= $(shell pwd -P)
UNAME ?=uname
OSTYPE ?=$(shell $(UNAME))

$(info using  $(OSTYPE))
#posix typically is and also default `lib%.so lib%.a'
ifeq ($(OSTYPE),Darwin)
override .LIBPATTERNS:=lib%.dylib lib%.a
override LINKFLAGS:= -dynamiclib  -Wl,-single_module 

#llvm-ld says no
#-current_version' '$(VER)
#-compatibility_version' '$(patsubst .%,,$(VER))	\

 			
else

ifeq	($(OSTYPE:windows%=windows),windows)
    override .LIBPATTERNS:=lib%.dll lib%.lib
#a quaint bit of humorous abstraction
endif    
endif
$(info OS lib patterns are $(.LIBPATTERNS))


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
LIB_MODULES+= -L$(PWD)

PACKAGE_NAME?=$(shell $(BASENAME) $(PWD))

### dirt simple generic static module ###i
LANG=FLEX BISON CXX
BISON_OBJ = $($(wildcard *.ypp):%.ypp=%.o)
FLEX_OBJ  = $($(wildcard *.lpp):%.lpp=%.o)
CXX_OBJ   = $(subst .cpp,.o,$(wildcard *.cpp))
LIB_OBJ   = $(patsubst %main.o,,$(BISON_OBJ) $(FLEX_OBJ) $(CXX_OBJ))
LIB_NAME  ?= $(PACKAGE_NAME)	
    
LINKFLAGS ?= -shared 	\
	     -Wl,--major-image-version=$(VER:.%=)	\
	     -Wl,--minor-image-version=$(VER:%.=)

#.PHONY: agenda
#agenda::
#
#$(LIB_OBJ): agenda


F1=$(LIB_NAME:%=$(.LIBPATTERNS))
LIB_FINAL=$(LIB_NAME:%=$(F1))

LIB_SHARED=$(firstword $(LIB_FINAL))

LIB_STATIC=$(lastword $(LIB_FINAL))

$(info compiler agenda: $(LIB_OBJ))
$(info linker   agenda: $(LIB_FINAL))
$(info runtime  agenda: $(TOOL_FINAL))
$(info test     agenda: $(TEST))

$(LIB_STATIC):  $(LIB_OBJ) 
	$(info linking $? into $@)
	$(AR) rcvs $(LIB_STATIC) $?

$(LIB_SHARED): $(LIB_OBJ)
	$(info linking $? into $@)
	$(LD) $(LINKFLAGS) $(CXXFLAGS) $? $(LIB_MODULES) -o $(LIB_SHARED) 

TOOL_LIB_MODULES+= -l$(LIB_NAME)
TOOL_FINAL = $(PACKAGE_NAME)

$(TOOL_FINAL): main.o $(TOOL_LIB_MODULES) #$(LIB_FINAL) 
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

TEST_SRC ?= $(wildcard tests/test_*.cpp)

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
	$(RM) */*.bak *.bak                        \
	$(TESTS) $(TEST_RESULTS) $(VALGRIND)	   \
	$(TOOL_BIN) $(TOOL_FINAL)                  \
	$(LIB_FINAL) $(LIB_OBJ)
	

cleaner: clean
	$(RM) *~ */*.d *.d $(BISON_HH:%=*/%)	    \
	$(BISON_OBJ:.o=.hpp) $(BISON_OBJ:.o=.cpp)   \
	$(FLEX_OBJ:.o=.cpp)
	-$(FIND) build Debug Release -delete	

DEPS=$(BISON_OBJ:.o=.d) $(FLEX_OBJ:.o=.d) $(LIB_OBJ:.o=.d) 

dep: $(DEPS)
BISON_HH=location.hh stack.hh position.hh
#$(BISON_HH): $(BISON_OBJ)
-include $(DEPS)

.PHONY: all dep tool lib test

tool: $(DEPS) $(LIB_FINAL) $(TOOL_FINAL)

all: dep lib tool test valgrind

.PHONY: all tool test valgrind


test:$(DEP) $(LIB_FINAL) $(TEST_RESULTS)

valgrind: $(DEP) $(LIB_FINAL) $(VALGRIND)

.PHONY: lib

lib: $(DEP) $(LIB_FINAL)
