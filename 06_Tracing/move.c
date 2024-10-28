#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define OPEN_ERROR  1 
#define WRITE_ERROR  2
#define STRUCTURE_ERROR  3 
#define READING_ERROR 4
#define DELETE_ERROR 5

int main(int argc, char *argv[]){
    if (argc < 3) {
        exit(STRUCTURE_ERROR);
    }

    char *infile = argv[1];
    char *outfile = argv[2];

    FILE* in_f = fopen(infile, "r");
    FILE* out_f = fopen(outfile, "w");

    if (!in_f) {
        exit(OPEN_ERROR);
    }
    if (!out_f) {
        exit(OPEN_ERROR);
    }


    char tmp_batch[1024];
    ssize_t bytes_read;
    
    while ((bytes_read = fread(tmp_batch, 1, 1024, in_f)) > 0) {
        fwrite(tmp_batch, 1, bytes_read, out_f);
        if (EOF == fflush(out_f)) {
            fclose(in_f);
            fclose(out_f);
	        remove(outfile);
            exit(WRITE_ERROR);
        }
    }
    
    if (ferror(in_f)) {
        exit(READING_ERROR);
    }

    fclose(in_f);
    fclose(out_f);

    if (remove(infile)) {
        exit(DELETE_ERROR);
    }

    return 0;
}