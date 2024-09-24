#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct web_data {
    char *buffer;
    size_t size;
};

size_t write_mem(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize;
    struct web_data *mem;

    realsize = size * nmemb;
    mem = (struct web_data *)userdata;

    mem->buffer = realloc(mem->buffer,
            mem->size + realsize + 1);
    if (mem->buffer == NULL) {
        fprintf(stderr,"Memory error\n");
        exit(1);
    }

    memcpy(&(mem->buffer[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->buffer[mem->size] = 0;

    return(realsize);
}
