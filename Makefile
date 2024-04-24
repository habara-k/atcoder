dbg:
	g++ -Wall -Wextra -fsanitize=address,undefined -fno-omit-frame-pointer \
		-g -std=c++20 -I. -I./ac-library -DLOCAL main.cpp && ./a.out
run:
	g++ -Wall -Wextra -O3 -std=c++20 -I. -I./ac-library main.cpp -DLOCAL && ./a.out
cp:
	cat main.cpp | wl-copy
