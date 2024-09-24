#include <stdio.h>
#include <json-c/json.h>

//parses a json_object out of the string argument and prints the key values.

void bufferParser(char *movie) {
    	
    	struct json_object *jdata;
    	const char *string __attribute__((unused));

    	jdata = json_tokener_parse(movie);
    	if (jdata == NULL) {
    		fprintf(stderr, "Unable to tokenize string\n");
    		exit(1);
    	}
		
		struct json_object *title = json_object_object_get(jdata, "Title");
		struct json_object *year = json_object_object_get(jdata, "Year");
		struct json_object *rated = json_object_object_get(jdata, "Rated");
		struct json_object *cast = json_object_object_get(jdata, "Actors");
		struct json_object *genre = json_object_object_get(jdata, "Genre");
		struct json_object *plot = json_object_object_get(jdata, "Plot");

		printf("Title: %s\n", json_object_get_string(title));
		printf("Year: %s\n", json_object_get_string(year));
		printf("Rated: %s\n", json_object_get_string(rated));
		printf("Cast: %s\n", json_object_get_string(cast));
		printf("Plot: %s\n", json_object_get_string(plot));
		printf("Genre: %s\n", json_object_get_string(genre));
    	
    	exit(0);
    }
