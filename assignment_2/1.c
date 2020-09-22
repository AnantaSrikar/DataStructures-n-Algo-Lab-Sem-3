#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char **argv)
{
	// Initial code to get all command line values

	int input_arr[argc - 1];

	for(int i = 1; i <= argc - 1; i++)
	{
		for(int j = 0; j < strlen(argv[i]); j++)
			if(!isdigit(argv[i][j]) && argv[i][j] != '-')
			{
				printf("error"); // Please enter only numbers!
				return -1;
			}

		input_arr[i - 1] = atoi(argv[i]);
	}

	// End of Command line input code

	if((input_arr[0] != 1) || (input_arr[1] > input_arr[2]) || argc != 7)
	{
		printf("error");
		return -1;
	}

	int lb = input_arr[1], ub = input_arr[2], ba = input_arr[3], ws = input_arr[4], loc = input_arr[5];

	printf("%d\n", (ub - lb + 1)); // No. of elements in array
	printf("%d\n", (ub - lb + 1) * ws); // Total memory consumed
	printf("%d", (loc - lb) * ws + ba); // Mem location of arr[loc]

	return(0);
}