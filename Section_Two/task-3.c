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

void add_to_rgba(int i, struct RGBA *rgba, long long decimal, int counter) {
	if(i < 25) {
		rgba->r = decimal;
	} else if (i < 50) {
	  rgba->g = decimal;
	} else if (i < 75) {
	  rgba->b = decimal;
	} else if(i < 99) {
		rgba->a = (double) decimal / 255;
	}

	//Add last value to the last struct
	if(i == counter - 1) {
     rgba->a = (double) decimal / 255;
	}
}

//Function that prints RGBA values in the format 'rgba(R,G,B,A)' in ascending order
void print_rgba(int uniq_col_num, struct RGBA *rgba_arr) {
	struct RGBA rgba;

	//Loop through the struct array and print
	for(int i = 0; i < uniq_col_num; i++) {
		 rgba = rgba_arr[i];
	   //If the alpha value is NOT 0, we display the alpha value to 16 decimal places
	   if(rgba.a != 0 && rgba.a < 1) {
	     printf("rgba(%lld, %lld, %lld, %.16f)\n", rgba.r, rgba.g, rgba.b, rgba.a);
	   } else {
	     printf("rgba(%lld, %lld, %lld, %.0f)\n", rgba.r, rgba.g, rgba.b, rgba.a);
	   }
	}
}

int main() {
	int counter = 0;
	int uniq_col_num = 0;
	long long *all_data = malloc(1000);
	char colour[4];
	int new_rgba = 0;
	long long decimal;

	while(fgets(colour, 4, stdin) != NULL) {
		//Remove the \n at the end of the string literal so we can append 'ff'
		strtok(colour, "\n");

		//Turn hex number to decimal
		decimal = strtoll(colour, NULL, 16);

		//Add decimal value to the array of data
		all_data[counter] = decimal;
		counter++;
	}

	/*To get the number of unique colors we have, we devide the total number of entries by 4
		as all colours have 4 sections R,G,B,A and the file has them all split.
	*/
	uniq_col_num = counter / 4;

	struct RGBA *rgba_arr = malloc(uniq_col_num * sizeof(struct RGBA));

	for(int i = 0; i < counter; i++) {
		/*Once we have finished filling in 1 section, start again by reseting the counter
		  to add in the next section. E.G. If we filled in R value for all 25 structs, we now
	    fill in the G value.
		*/
		if(i % uniq_col_num == 0 && i != 0) {
			new_rgba = 0;
		}

		//Check what section we in (R, G, B or A) and add value to that section of struct
		add_to_rgba(i, &rgba_arr[new_rgba], all_data[i], counter);

		//Add to next struct
		new_rgba++;
	}

	//Loop through the struct and print the RGBA values
	print_rgba(uniq_col_num, rgba_arr);

	return 0;
}
