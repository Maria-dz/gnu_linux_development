#include <rhash.h>

#include "config.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>


#ifdef USE_READLINE_LIB
    #include <readline/readline.h>
#endif


int main(int argc, char **argv){
    rhash_library_init();


    char *line = NULL;
    size_t len = 0;
    ssize_t lread;
    
    char *tmp_text;
    char *hash_name;
    int inp_format;
    bool msgflag;
    unsigned hashId;
    bool known_hash=false;
    char inp_hash[64];
    char output[240];
    
#ifdef USE_READLINE_LIB
    while (line = readline("> ")) {
#else
    while ((lread = getline(&line, &len, stdin)) != -1) {
#endif
    
        hash_name = strtok(line, " ");
        tmp_text = strtok(NULL, " ");

        if (!hash_name || !tmp_text) {
            fprintf(stderr, "Invalid input \n");
            continue;
        }

        tmp_text[strcspn(tmp_text, "\n")] = 0;

        int first_char = islower(hash_name[0]);
        if (first_char == 0) {
            inp_format = RHPR_HEX;
        } else {
            inp_format = RHPR_BASE64;
        }

        for(int i = 0 ; (hash_name[i] = toupper(hash_name[i])) ; i++);
        
        if (strcmp(hash_name, "SHA1") == 0){
            hashId = RHASH_SHA1;
            known_hash = true;
        }
        if (strcmp(hash_name, "MD5") == 0){
            hashId = RHASH_MD5;
            known_hash = true;
        }
        if (strcmp(hash_name, "TTH") == 0){
            hashId = RHASH_TTH;
            known_hash = true;
        }

        if (!known_hash){
            fprintf(stderr, "unknown hash: %s\n", hash_name);
            continue;
        }
        
        if (tmp_text[0] == '"'){
            int res = rhash_msg(hashId, tmp_text + 1, strlen(tmp_text) - 1, inp_hash);
            if(res < 0) {
                fprintf(stderr, " error:  %s\n",  strerror(errno));
                continue;
            }
        }
        else{
            int res = rhash_file(hashId, tmp_text, inp_hash);
            if(res < 0) {
                fprintf(stderr, " error: %s\n", strerror(errno));
                continue;
            }
        }

        rhash_print_bytes(output, inp_hash, rhash_get_digest_size(hashId), inp_format);
#ifndef USE_READLINE_LIB
        printf("hash\n%s\n", output);
#else
        printf("%s\n", output);
#endif

    }
    
}