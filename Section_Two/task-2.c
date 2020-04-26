#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int counter = 0;
	long long *colours = malloc(1000);
	char colour[4];
	long long decimal;

	/*Get all colours from stdin and establish how many elements we have so we can later
		print them all as comma separated strings without a trailing ',' at the end
	*/
	while(fgets(colour, 4, stdin) != NULL) {
		//Remove the \n at the end of the string literal so we can append 'ff'
		strtok(colour, "\n");

		//Turn hex number to decimal
		decimal = strtoll(colour, NULL, 16);

		colours[counter] = decimal;
		counter++;
	}

	//Print decimal values
	for(int i = 0; i < counter; i++) {
		if(i != counter - 1) {
			printf("%lld, ", colours[i]);
		} else {
			printf("%lld\n", decimal);
		}
	}
	return 0;
}
