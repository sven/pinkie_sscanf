FLAGS_GCC = -Wall -Wextra -Werror -Wno-implicit-fallthrough -ggdb
FLAGS_CLANG = -Wall -Weverything -Werror -ggdb -Wno-address-of-packed-member -Wno-packed

all:
	gcc $(FLAGS_GCC) -m32 -o test test.c pinkie_sscanf.c
	gcc $(FLAGS_GCC) -m64 -o test test.c pinkie_sscanf.c
	clang $(FLAGS_CLANG) -m32 -o test test.c pinkie_sscanf.c
	clang $(FLAGS_CLANG) -m64 -o test test.c pinkie_sscanf.c
	./test
