# makefile
# Created on: Aug 19, 2014
#     Author: ufo008ahw

target = Tester
flag =  -g

all: tester.cpp tester.h
	g++ $(flag) tester.cpp -c -o tester.o 
	g++ *.o -o $(target)
	
.PHONY: clean

clean:
	@rm *.o
	@rm Tester