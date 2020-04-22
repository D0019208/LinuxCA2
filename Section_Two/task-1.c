#define VALID_OPTIONS 25

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char colours[VALID_OPTIONS][20];
	char colour[11];

	//We loop 25 times, (the ammount of correct colour codes)
	for(int i = 0; i < VALID_OPTIONS; i++) {
		//Withdraw the values from stdin
		fgets(colour, 11, stdin);

		//Remove the \n at the end of the string literal so we can append 'ff'
		strtok(colour, "\n");

		//If the string legth is 7 (counting '\0'), add placeholder alpha value
		if(strlen(colour) == 7) {
			strcpy(colours[i], colour);
			strcat(colours[i], "ff");
		} else {
			strcpy(colours[i], colour);
		}

		printf("%s\n", colours[i]);
	}

	return 0;
}
