#ifndef MOVIE_H
#define MOVIE_H

/* memory buffer structure */
struct movie_data {
	char *buffer;
	size_t size;
};

/* parse a string into a json object */
void bufferParser(char *buffer_holding_CURL_data);

/* creates the buffer to hold the data from the Internet */
size_t write_mem(void *, size_t, size_t, void *);

/* replaces white space to properly format URL */
void replaceWhiteSpace(char *title_of_movie);

#endif /* MOVIE_H */

