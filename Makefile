CXX = g++
VPATH = ./basics
CXXFLAGS = -Wall -g -Iinclude -std=c++14 -stdlib=libc++

TARGET = max1 maxauto maxdecltype maxdecltypedecay maxcommon maxdefault1 maxdefault3 \
		 max2 maxdefault4 max3val max3ref max4 maxconstexpr stack1test stack2test \
		 stackpartspectest stack3test

OBJS = 	max1.o maxauto.o maxdecltype.o maxdecltypedecay.o maxcommon.o maxdefault1.o maxdefault3.o \
		max2.o maxdefault4.o max3val.o max3ref.o max4.o maxconstexpr.o stack1test.o stack2test.o \
		stackpartspectest.o stack3test.o

all: $(TARGET)

max1: max1.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxauto: maxauto.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxdecltype: maxdecltype.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxdecltypedecay: maxdecltypedecay.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxcommon: maxcommon.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxdefault1: maxdefault1.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxdefault3: maxdefault3.o
	$(CXX) $(CXXFLAGS) $< -o $@

max2: max2.o
	$(CXX) $(CXXFLAGS) $< -o $@

max3val: max3val.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxdefault4: maxdefault4.o
	$(CXX) $(CXXFLAGS) $< -o $@

max3ref: max3ref.o
	$(CXX) $(CXXFLAGS) $< -o $@

max4: max4.o
	$(CXX) $(CXXFLAGS) $< -o $@

maxconstexpr: maxconstexpr.o
	$(CXX) $(CXXFLAGS) $< -o $@

stack1test: stack1test.o
	$(CXX) $(CXXFLAGS) $< -o $@

stack2test: stack2test.o
	$(CXX) $(CXXFLAGS) $< -o $@

stackpartspectest: stackpartspectest.o
	$(CXX) $(CXXFLAGS) $< -o $@

stack3test: stack3test.o
	$(CXX) $(CXXFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)