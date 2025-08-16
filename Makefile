CXX = g++
VPATH = ./basics
CXXFLAGS = -Wall -g -Iinclude -std=c++14 -stdlib=libc++

TARGET = max1 maxauto maxdecltype maxdecltypedecay maxcommon maxdefault1 maxdefault3 \
		 max2

OBJS = 	max1.o maxauto.o maxdecltype.o maxdecltypedecay.o maxcommon.o maxdefault1.o maxdefault3.o \
		max2.o

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

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)