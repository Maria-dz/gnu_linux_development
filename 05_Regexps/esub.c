#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define MAXGR 10
#define MAX_ERROR 200


int main(int argc, char *argv[]) {
        int base_sign = '0';
        int chars;
        regex_t regex;
        regmatch_t bags[MAXGR];

        //regexp substitution string
        if (argc < 4){
                fprintf(stderr, "Not enough params\n");
                return 0;
        }

        char* inp_string = argv[3];
        char* substitution = argv[2];
        char* inp_regexp = argv[1];
        

        int error_check = regcomp(&regex, inp_regexp, REG_EXTENDED);
        if (error_check){
                char errbuf[MAX_ERROR];
                regerror(error_check, &regex, errbuf, sizeof(errbuf));
                fprintf(stderr, "Regex compilation failed with error: %s\n", errbuf);
                regfree(&regex);
                return 0;

        }


        int execution_status = regexec(&regex, inp_string, MAXGR, bags, 0);
        if (execution_status == 0){
                const char *p = substitution;
                for (const char *p = substitution; *p != '\0'; p++){
                        if ((*p == '\\') && (*(p + 1) != '\0')){
                                p++;
                                if (*p >= '0' && *p <= '9'){
                                        if (bags[*p - base_sign].rm_so == -1) {
                                                printf("Bad referance: %s\n", substitution);
                                                regfree(&regex);
                                                return 0;
                                        }
                                }
                        }
                }
                int bags_start = bags[0].rm_so;
                for (int i = 0; i < bags_start; i++) {
                    putchar(inp_string[i]);
                }

                for (const char *p = substitution; *p != '\0'; p++){
                        if ((*p == '\\') && (*(p + 1) != '\0')) {
                                p++;
                                if (*p >= '0' && *p <= '9') {
                                for (int i = bags[*p - base_sign].rm_so; i < bags[*p - base_sign].rm_eo; i++) {
                                        char replacement = inp_string[i];
                                        putchar(replacement);
                                }
                                } else{
                                        if (*p == '\\') {
                                                putchar('\\');
                                        }
                                        else {
                                                putchar(*p);
                                        }
                                }
                        } else {
                                putchar(*p);
                        }
                }

                int bags_end = bags[0].rm_eo;
                for (int i = bags_end; inp_string[i] != '\0'; i++) {
                    putchar(inp_string[i]);
                }

        }
        else{
                if (execution_status != REG_NOMATCH) {
                        char errbuf[MAX_ERROR];
                        regerror(error_check, &regex, errbuf, sizeof(errbuf));
                        fprintf(stderr, "Regex failed with error: %s\n", errbuf);

                } else {
                        printf("%s\n", inp_string);
                }
        }
        putchar('\n');
        regfree(&regex);
        return 0;
}