#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//https://stackoverflow.com/questions/7652293/how-do-i-dynamically-allocate-an-array-of-strings-in-c
int main(int argc, char * argv[]) {
	char **colours = malloc(26 * sizeof(char *));
	int length = 0;

	for(int i = 0; i < 26; i++) {
		colours[i] = (char *)malloc(26+1);
	}

	for(int i = 1; i < argc; i++) {
		length = strlen(argv[i]);

		if(length == 7) {
			strcat(colours[i], argv[i]);
			strcat(colours[i], "ff");
		} else {
			strcat(colours[i], argv[i]);
		}

		printf("%s\n", colours[i]);
	}

	return 0;
}
