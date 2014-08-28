all:
	make preCom
	make -C test
	mv test/Tester .
	
preCom:
	gcc -c "./include/cFunctionCompileDefine.c"
	mv cFunctionCompileDefine.o "./test"
	
.PHONY: clean

clean:
	-make clean -C test
	-rm "Tester"
	-rm "./include/*.o"
