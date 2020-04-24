#define SPLIT_SIZE 100
#define VALID_OPTIONS 25

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Struct containing the values of the colour
struct RGBA {
	long long r;
	long long g;
	long long b;
	double a;
};

void add_to_rgba(int i, int new_rgba, struct RGBA rgba_arr[VALID_OPTIONS], long long decimal) {
	if(i < 25) {
		rgba_arr[new_rgba].r = decimal;
	} else if (i < 50) {
	  rgba_arr[new_rgba].g = decimal;
	} else if (i < 75) {
	  rgba_arr[new_rgba].b = decimal;
	} else if(i < 99) {
		rgba_arr[new_rgba].a = (double) decimal / 255;
	}

	//Add last value to the last struct
	if(i == SPLIT_SIZE - 1) {
     rgba_arr[new_rgba].a = (double) decimal / 255;
	}
}

//Function that implements bubble sort to sort struct array by alpha value in ascending order
void sort_rgba(struct RGBA rgba_arr[VALID_OPTIONS]) {
	double temp;

	for(int i = 0; i < VALID_OPTIONS; i++) {
		for(int j = i + 1; j < VALID_OPTIONS; j++) {
			if(rgba_arr[i].a > rgba_arr[j].a) {
				temp = rgba_arr[i].a;

				rgba_arr[i].a = rgba_arr[j].a;
				rgba_arr[j].a = temp;
			}
		}
	}
}

//Function that prints RGBA values in the format 'rgba(R,G,B,A)' in ascending order
void print_rgba(struct RGBA rgba_arr[VALID_OPTIONS]) {
	//Sort the struct array in ascending order by the alpha value
	sort_rgba(rgba_arr);

	//Loop through the struct array and print
	for(int i = 0; i < VALID_OPTIONS; i++) {
	   //If the alpha value is NOT 0, we display the alpha value to 16 decimal places
	   if(rgba_arr[i].a != 0 && rgba_arr[i].a < 1) {
	     printf("rgba(%lld, %lld, %lld, %.16f)\n", rgba_arr[i].r, rgba_arr[i].g, rgba_arr[i].b, rgba_arr[i].a);
	   } else {
	     printf("rgba(%lld, %lld, %lld, %.0f)\n", rgba_arr[i].r, rgba_arr[i].g, rgba_arr[i].b, rgba_arr[i].a);
	   }
	}
}

int main() {
	struct RGBA rgba_arr[VALID_OPTIONS];
	char colour[4];
	int rgba_cntr = 0;
	int new_rgba = 0;
	long long decimal;

	//We loop 100 times (4 sections in RGBA, 4 x 25 valid colour codes = 100)
	for(int i = 0; i < SPLIT_SIZE; i++) {
		//Withdraw the values from stdin
		fgets(colour, 4, stdin);

		//Remove the \n at the end of the string literal so we can append 'ff'
		strtok(colour, "\n");

		//Turn hex number to decimal
		decimal = strtol(colour, NULL, 16);

		/*Once we have finished filling in 1 section, start again by reseting the counter
		  to add in the next section. E.G. If we filled in R value for all 25 structs, we now
		  fill in the G value.
		*/
		if(i % 25 == 0 && i != 0) {
			new_rgba = 0;
		}

		//Check what section we in (R, G, B or A) and add value to that section of struct
		add_to_rgba(i, new_rgba, rgba_arr, decimal);

		//Add to next struct
		new_rgba++;
	}

	//Loop through the struct and print the RGBA values
	print_rgba(rgba_arr);

	return 0;
}
