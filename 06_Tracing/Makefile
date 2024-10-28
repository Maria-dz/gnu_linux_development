all: move protection_lib.so

move: move.c
	cc -g -Wall move.c -o move

protection_lib.so: protection_lib.c
	cc -shared -o protection_lib.so protection_lib.c

test_reload: protection_lib.so move
	echo "DO NOT DELETE" > PROTECT_tmp
	LD_PRELOAD=`pwd`/protection_lib.so ./move PROTECT_tmp output_tmp
	cmp PROTECT_tmp output_tmp

test_move: move
	echo "text" > inp_tmp
	./move inp_tmp outp_tmp
    
	echo "text" > inp_tmp
	echo "+++ exited with 1 +++" > error_tmp
	strace -e openat -P inp_tmp -e fault=openat ./move inp_tmp outp_tmp 2>&1 | grep '+++' > test_err
	cmp error_tmp test_err

	echo "text" > inp_tmp
	echo "+++ exited with 2 +++" > error_tmp
	strace -e write -P outp_tmp -e fault=write ./move inp_tmp outp_tmp 2>&1 | grep '+++' > test_err
	cmp error_tmp test_err

	echo "text" > inp_tmp
	echo "+++ exited with 3 +++" > error_tmp
	strace -e write -e fault=write ./move inp_tmp  2>&1 | grep '+++' > test_err
	cmp error_tmp test_err

	echo "text" > inp_tmp
	echo "+++ exited with 4 +++" > error_tmp
	strace -e read -P inp_tmp -e fault=read ./move inp_tmp outp_tmp 2>&1 | grep '+++' > test_err
	cmp error_tmp test_err

	echo "text" > inp_tmp
	echo "+++ exited with 4 +++" > error_tmp
	strace -e read -P inp_tmp -e fault=read ./move inp_tmp outp_tmp 2>&1 | grep '+++' > test_err
	cmp error_tmp test_err

	echo "text" > inp_tmp
	echo "+++ exited with 5 +++" > error_tmp
	strace -e unlinkat -P inp_tmp -e fault=unlinkat ./move inp_tmp outp_tmp 2>&1 | grep '+++' > test_err
	cmp error_tmp test_err


clean:
	rm -rf move protection_lib.so test_* *tmp