/** @mainpage Guess the number

    The rules: user chooses the nubmer between 1 and 100. The program tries to guess which number it is by asking questions.

    You can use two modes of the game:
    - With arabic numbers 1-100 (default)
    - With roman numbers I-C

    Eng and Ru languages are supported.

    Options:
    -r Use roman digits
    --help See help information

*/
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

/** Convert roman string to arabic integer
 *
 * @param num integer to be converted
 * @param roman the result will be stored here
 * @
 */
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


/** Convert arabic integer to roman string
*
* @param num integer to be converted
* @param roman the result will be stored here
*/
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

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    bindtextdomain("guess", LOCALE_PATH);
    textdomain("guess");

    int low = 1;
    int high = 100;
    int mid;
    char response[200];
    char start_roman[10];
    char end_roman[10];
    char roman_mid[10];

    bool roman_usage = false;
    if (argc == 2 && strcmp(argv[1], "-r") == 0) {
        roman_usage = true;
    }

    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        printHelp();
        return 0;
    }

    if (roman_usage){
	to_roman(1, start_roman);
	to_roman(100, end_roman);
        printf(_("Choose a number in range %s - %s\n"), start_roman, end_roman);
    }
    else {
         printf(_("Choose a number in range 1 - 100\n"));
    }

    while (low <= high) {
        mid = (low + high) / 2;

        if (roman_usage) {
           char roman_mid[10];
	   to_roman(mid,roman_mid);
           printf(_("Is your number greater than %s? Answer 'yes' or 'no': "), roman_mid);
        }
        else{
            printf(_("Is your number greater than %d? Answer 'yes' or 'no': "), mid);
        }

        scanf("%s", response);

	if (strcmp(response, _("yes"))==0) {
            low = mid + 1;
        } else if (strcmp(response, _("no"))==0) {
            high = mid - 1;
        } else {
            printf(_("Incorrect format\n"));
        }

        if (low > high) {
            if (roman_usage) {
		char roman_mid[10];
		to_roman(mid,roman_mid);
                printf(_("Your number is: %s\n"), roman_mid);
            }
            else{
                printf(_("Your number is: %d\n"), mid);
            }

            break;
        }
    }
    return 0;
}
