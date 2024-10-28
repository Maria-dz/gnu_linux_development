#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <errno.h>
#include <unistd.h>

typedef int (*remove_type)(const char *filename);

int remove(const char *pathname) {
    if (strstr(pathname, "PROTECT")) {
        return 0;
    }
    int output = ((remove_type)(dlsym(RTLD_NEXT, "remove")))(pathname);
    return output;
}