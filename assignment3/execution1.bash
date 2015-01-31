gcc -Wall -pg main_prog.c brute.c -o brute.out
./brute.out
gprof brute.out gmon.out > analysis.txt
