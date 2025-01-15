#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include <stdbool.h>

#define _(STRING) gettext(STRING)

int roman_char_to_int(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int from_roman(const char* roman){
    int total = 0;
    int prevValue = 0;
    
    for (int i = strlen(roman) - 1; i >= 0; i--) {
        int currentValue = roman_char_to_int(roman[i]);
        
        if (currentValue < prevValue) {
            total -= currentValue;
        } else {
            total += currentValue;
        }
        
        prevValue = currentValue;
    }
    
    return total;

}

void to_roman(int num, char *roman){
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};;
    roman[0] = '\0';        

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(roman, symbols[i]);
            num -= values[i];
        }
    }

   
}

void printHelp(){
    printf(_("Usage: ./guess [OPTIONS]\n"));
    printf(_("Options:\n"));
    printf(_("-r Use roman digits\n"));
    printf(_("--help See help information\n"));
}