#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	//Biggest VALID colour we can have 8 characters + '\n' and '\0'
	char colour[10];

	//Loop through stdin until all entries have been exhausted
	while(fgets(colour, 10, stdin) != NULL) {
		//Remove the \n at the end of the string literal so we can append 'ff'
		strtok(colour, "\n");

		//If the string legth is 7 (counting '\0'), add placeholder alpha value
		if(strlen(colour) == 7) {
			printf("%sff\n", colour);
		} else {
			printf("%s", colour);
		}
	}

	return 0;
}
