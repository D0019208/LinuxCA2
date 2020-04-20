#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
	printf("Argument 0 = %s\n", argv[1]);
	char input[20000];

	fgets(input, 20000, stdin);

	printf("Tt %s\n", input);

	return 0;
}
