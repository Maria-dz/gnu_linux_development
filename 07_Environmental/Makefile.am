GENERATES = *.m4 test* compile config.h.in config.log configure install-sh missing autom4te.cache config.h config.h.in~ config.status configure~ depcomp Makefile Makefile.in rhasher stamp-h1 rhasher.o .deps .dirstamp

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

TESTS=tests.sh

tests.sh:
	echo 'echo "testing_md5" > test_file_md5' >> tests.sh
	echo 'echo "testing_sha" > test_file_sha' >> tests.sh

	echo 'md5sum test_file_md5 |  cut -d " " -f 1 > test_true_ans_md5' >> tests.sh
	echo 'sha1sum test_file_sha |  cut -d " " -f 1 > test_true_ans_sha' >> tests.sh

	echo 'echo "MD5 test_file_md5" | ./rhasher | sed -n '2p' > test_ans_md5' >> tests.sh
	echo 'echo "SHA1 test_file_sha" | ./rhasher | sed -n '2p' > test_ans_sha1' >> tests.sh

	echo 'cmp test_true_ans_sha test_ans_sha1' >> tests.sh
	echo 'cmp test_true_ans_md5 test_ans_md5' >> tests.sh
	chmod +x $@
clean:
	rm -rf $(GENERATES)
