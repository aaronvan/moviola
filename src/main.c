#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "movie.h"

int main(void) {

	const char base_url[] = "http://www.omdbapi.com/?t=";
	char movie_title[20];
	const char apikey[] = "&apikey={your API key}";
	
	printf("Enter the movie title: ");
	if (fgets(movie_title, 20, stdin)) {
		// overwrite the newline character with a 0
		movie_title[strcspn(movie_title, "\n")] = 0;
	}
	
	/* create a properly formatted URL */
	char *url = (char *)malloc(sizeof(char) * 100);
	sprintf(url, "%s%s%s", base_url, movie_title, apikey);
	replaceWhiteSpace(url);
	//puts(url);

    /* initialize struct with one byte buffer and size 0 */
    struct movie_data movie;
    movie.buffer = malloc(1);
    if (movie.buffer == NULL) {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }
    movie.size = 0;

    /* initialize curl */
    CURL *curl = curl_easy_init();
    if (!curl) {
    	fprintf(stderr, "curl init failed\n");
    }

    /* pass a pointer back to the callback function */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_mem);
	/* pass a struct pointer to the write callback function */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&movie);
	/* pass a pointer to the URL with the data */
    curl_easy_setopt(curl, CURLOPT_URL, url);
	/* in the case of redirects */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    /* set to 1 for debugging connection information */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);   
   
    /* curl */
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }
    
    /* cleanup */
    curl_easy_cleanup(curl);
    free(url);

    /* output results */
    //printf("Read %ld bytes:\n", movie.size);
    //puts(movie.buffer);
    bufferParser(movie.buffer);

    return EXIT_SUCCESS;
}

