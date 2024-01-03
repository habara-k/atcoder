dbg:
	g++ -Wall -Wextra -fsanitize=address,undefined -fno-omit-frame-pointer -g -std=c++20 -I. main.cpp -DLOCAL && ./a.out
run:
	g++ -Wall -Wextra -O3 -std=c++20 -I. main.cpp -DLOCAL && ./a.out
cp:
	cat main.cpp | xsel --clipboard --input

