esub: esub.c
	cc esub.c -o esub

check: esub
	./esub > tmp_esub1
	./esub "a(b" "ab" "ab" > tmp_esub2
	./esub "ab" "a\1b" "ab" > tmp_esub3
	./esub "ab" "BA" "eabc" > tmp_esub4
	./esub "a(b)c" "\1_\1" "DabcE" > tmp_esub5
	./esub "(a)b(c)d(e)" "<\3\2\1>" "_abcdef_" > tmp_esub6
	./esub "([[:digit:]]{4}) +([[:digit:]]{1,2}) +([[:alpha:]]+) +([[:alpha:]]+)" "\4, \2 \3 year of \1" "2024 17 October Thursday" > tmp_esub7

	echo | sed -E '' > tmp_sed1
	#echo ab | sed -E 's/a(b/ab/' > tmp_sed2
	#echo ab | sed -E 's/a\1b/ab/' > tmp_sed3
	echo eabc | sed -E 's/ab/BA/' > tmp_sed4
	echo DabcE | sed -E 's/a(b)c/\1_\1/' > tmp_sed5
	echo _abcdef_ | sed -E 's/(a)b(c)d(e)/<\3\2\1>/' > tmp_sed6
	echo '2024 17 October Thursday' | sed -E 's/([[:digit:]]{4}) +([[:digit:]]{1,2}) +([[:alpha:]]+) +([[:alpha:]]+)/\4, \2 \3 year of \1/' > tmp_sed7

	#cmp tmp_esub1 tmp_sed1
	#cmp tmp_esub2 tmp_sed2
	#cmp tmp_esub3 tmp_sed3
	cmp tmp_esub4 tmp_sed4
	cmp tmp_esub5 tmp_sed5
	cmp tmp_esub6 tmp_sed6
	cmp tmp_esub7 tmp_sed7



clean:
	rm -rf esub tmp*  