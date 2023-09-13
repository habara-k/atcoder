dbg:
	g++ -Wall -Wextra -fsanitize=address,undefined -fno-omit-frame-pointer -g -std=c++17 -I. main.cpp -DLOCAL && ./a.out
run:
	g++ -Wall -Wextra -O3 -std=c++17 -I. main.cpp -DLOCAL && ./a.out
cp:
	fish_clipboard_copy < main.cpp

