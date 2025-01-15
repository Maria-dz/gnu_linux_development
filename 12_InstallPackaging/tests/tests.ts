#include "guess.h"
#include <check.h>


#tcase to_roman_test
#test to_roman_func
        char tmp_roman[10]; 
	to_roman(1, tmp_roman);
	ck_assert_str_eq(tmp_roman, "I");
	to_roman(10, tmp_roman);
	ck_assert_str_eq(tmp_roman, "X");
	
	to_roman(100, tmp_roman);
	ck_assert_str_eq(tmp_roman, "C");
	
	to_roman(55, tmp_roman);
	ck_assert_str_eq(tmp_roman, "LV");
	

#tcase from_roman_test
#test roman_char_to_int_func
	ck_assert_uint_eq(roman_char_to_int('I'), 1);
	ck_assert_uint_eq(roman_char_to_int('X'), 10);
	ck_assert_uint_eq(roman_char_to_int('L'), 50);
	ck_assert_uint_eq(roman_char_to_int('C'), 100);


#test from_roman_func
	ck_assert_uint_eq(from_roman("XV"), 15);
	ck_assert_uint_eq(from_roman("I"), 1);
	ck_assert_uint_eq(from_roman("XI"), 11);
	ck_assert_uint_eq(from_roman("LXXVI"), 76);


