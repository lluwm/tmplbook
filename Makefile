CXX = g++
VPATH = ./basics
CXXFLAGS = -Wall -g -Iinclude -std=c++14 -stdlib=libc++

CHAP1 = max1 maxauto maxdecltype maxdecltypedecay maxcommon maxdefault1 maxdefault3 \
		max2 maxdefault4 max3val max3ref max4 maxconstexpr

CHAP2 = stack1test stack2test stackpartspectest stack3test

CHAP3 = stacknontype

CHAP4 = varprint1 varprint2

CHAP5 = printcoll

TARGET =  $(CHAP1) $(CHAP2) $(CHAP3) $(CHAP4) $(CHAP5)

all: $(TARGET)

chap1: $(CHAP1)
chap2: $(CHAP2)
chap3: $(CHAP3)
chap4: $(CHAP4)
chap5: $(CHAP5)

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

stacknontype: stacknontype.o
	$(CXX) $(CXXFLAGS) $< -o $@

varprint1: varprint1.o
	$(CXX) $(CXXFLAGS) $< -o $@

varprint2: varprint2.o
	$(CXX) $(CXXFLAGS) $< -o $@

printcoll: printcoll.o
	$(CXX) $(CXXFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f *.o $(TARGET)