all:
	make -C test
	mv test/Tester .

.PHONY: clean

clean:
	@make clean -C test
