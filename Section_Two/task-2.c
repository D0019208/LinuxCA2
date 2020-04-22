#define VALID_OPTIONS 25

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char colour[4];
	long long decimal;

	//We loop 25 times, (the ammount of correct colour codes)
	for(int i = 0; i < VALID_OPTIONS; i++) {
		//Withdraw the values from stdin
		fgets(colour, 4, stdin);

		//Remove the \n at the end of the string literal so we can append 'ff'
		strtok(colour, "\n");

		//Turn hex number to decimal
		decimal = strtol(colour, NULL, 16);

		//Print decimal values as comma separated list
		if(i != VALID_OPTIONS - 1) {
			printf("%lld, ", decimal);
		} else {
			printf("%lld\n", decimal);
		}
	}

	return 0;
}
