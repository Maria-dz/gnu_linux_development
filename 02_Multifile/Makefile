GENERATES = prog README libout.a prog-a prog-so liboutput.so
TRASH = *.o *~ o.* *.a outfile* 
CFLAGS = -Wall


liboutput.so: fun.o const.o
	cc -shared fun.o const.o -o liboutput.so

liboutput_static.a : fun.o const.o
	ar -rcs liboutput_static.a fun.o const.o

prog: const.o fun.o prog.o
	cc const.o fun.o prog.o -o prog

prog-a: prog.o liboutput_static.a
	cc prog.o -L. -loutput_static -o prog-a

prog-so: prog.o liboutput.so
	cc prog.o -L. -loutput -o prog-so

README: prog
	./$< 2> $@

fun.o prog.o:  outlib.h

test: prog prog-a prog-so
	./prog > outfile 2>&1
	./prog-a > outfile-a 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so > outfile-so 2>&1

	cmp outfile outfile-a
	cmp outfile-a outfile-so
	cmp outfile-so outfile

	./prog cat > outfile_second 2>&1
	./prog-a cat > outfile-a_second 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so cat > outfile-so_second 2>&1

	cmp outfile_second outfile-a_second
	cmp outfile-a_second outfile-so_second
	cmp outfile-so_second outfile_second

	./prog cat cat cat > outfile_third 2>&1
	./prog-a cat cat cat > outfile-a_third 2>&1
	LD_LIBRARY_PATH=`pwd` ./prog-so cat cat cat > outfile-so_third 2>&1

	cmp outfile_third outfile-a_third
	cmp outfile-a_third outfile-so_third
	cmp outfile-so_third outfile_third


clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)