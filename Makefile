all:
	gcc -ggdb -o test test.c pinkie_sscanf.c
	./test
