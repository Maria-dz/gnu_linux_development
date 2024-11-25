all: lab lab1 lab2 lab3

lab: lab.c
	cc -O0 -g lab.c -o lab

lab1: lab.c diff1.patch
	cp lab.c lab1.c
	patch lab1.c < diff1.patch
	cc -O0 -g lab1.c -o lab1

lab2: lab.c diff2.patch
	cp lab.c lab2.c
	patch lab2.c < diff2.patch
	cc -O0 -g lab2.c -o lab2

lab3: lab.c diff3.patch
	cp lab.c lab3.c
	patch lab3.c < diff3.patch
	cc -O0 -g lab3.c -o lab3

run: all
	@echo "Basic maze"
	@./lab
	@echo "\nMaze with size 10"
	@./lab1 10
	@echo "\nMaze with size 7 and -* as separators"
	@./lab2 '-*' 7
	@echo "\nMaze with random seed  3 -+ as separators and size 6:"
	@./lab3 3 '-+' 6


clean:
	rm -rf lab lab1 lab2 lab3 lab1.c lab2.c lab3.c