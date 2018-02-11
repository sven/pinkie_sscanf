FLAGS_GCC = -Wall -Wextra -Werror -Wno-implicit-fallthrough -ggdb
FLAGS_CLANG = -Wall -Weverything -Werror -ggdb -Wno-address-of-packed-member -Wno-packed
FLAGS_TCC = -Wall -Werror

all:
	@-rm -f avail_*
	@-gcc -v >/dev/null 2>&1 && touch avail_gcc
	@-clang -v >/dev/null 2>&1 && touch avail_clang
	@-tcc -v >/dev/null 2>&1 && touch avail_tcc
	@if [ -e avail_gcc ]; then echo gcc $(FLAGS_GCC) -m32 -o test test.c pinkie_sscanf.c; gcc $(FLAGS_GCC) -m32 -o test test.c pinkie_sscanf.c; fi
	@if [ -e avail_gcc ]; then echo gcc $(FLAGS_GCC) -m64 -o test test.c pinkie_sscanf.c; gcc $(FLAGS_GCC) -m64 -o test test.c pinkie_sscanf.c; fi
	@if [ -e avail_clang ]; then echo clang $(FLAGS_CLANG) -m32 -o test test.c pinkie_sscanf.c; clang $(FLAGS_CLANG) -m32 -o test test.c pinkie_sscanf.c; fi
	@if [ -e avail_clang ]; then echo clang $(FLAGS_CLANG) -m64 -o test test.c pinkie_sscanf.c; clang $(FLAGS_CLANG) -m64 -o test test.c pinkie_sscanf.c; fi
	@if [ -e avail_tcc ]; then echo tcc $(FLAGS_TCC) -o test test.c pinkie_sscanf.c; tcc $(FLAGS_TCC) -o test test.c pinkie_sscanf.c; fi
	@if [ -e test ]; then echo ./test; ./test; fi
	@-rm -f avail_*
