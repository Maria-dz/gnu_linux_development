all: range

range: range.c
	cc -O0 -g range.c -o range

test: range
	gdb -x scenario1.gdb ./range --batch --quiet | grep '@@' > scenario1_out
	cmp scenario1_out scenario1_answers
	gdb -x scenario2.gdb ./range --batch --quiet | grep '@@' > scenario2_out
	cmp scenario2_out scenario2_answers

clean:
	rm -rf scenario1_out scenario2_out range
