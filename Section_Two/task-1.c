#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int i = 0;
	char **colours = malloc(1000);
	char *colour = malloc(11 * sizeof(char));

	//Loop through stdin until all entries have been exhausted
	while(fgets(colour, 11, stdin) != NULL) {
		//Remove the \n at the end of the string literal so we can append 'ff'
		strtok(colour, "\n");

		//If the string legth is 7 (counting '\0'), add placeholder alpha value
		if(strlen(colour) == 7) {
			colours[i] = malloc(11 * sizeof(char));
			strcpy(colours[i], colour);
			strcat(colours[i], "ff");
		} else {
			colours[i] = malloc(11 * sizeof(char));
			strcpy(colours[i], colour);
		}

		printf("%s\n", colours[i]);
		i++;
	}

	return 0;
}
