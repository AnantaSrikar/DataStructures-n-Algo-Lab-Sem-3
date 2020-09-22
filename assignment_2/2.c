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
			if(!isdigit(argv[i][j]))
			{
				printf("error"); // Please enter only numbers!
				return -1;
			}

		input_arr[i - 1] = atoi(argv[i]);
	}

	// End of Command line input code

	if((input_arr[0] != 2) || (input_arr[1] < input_arr[5]) || (input_arr[2] < input_arr[6]) || argc != 8)
	{
		printf("error");
		return -1;
	}

	int r = input_arr[1], c = input_arr[2], ba = input_arr[3], ws = input_arr[4], i = input_arr[5], j = input_arr[6];

	// Since its row major
	int row_maj_addr = ba + ws * ((i * c) + j);
	
	printf("%d", row_maj_addr);

	return(0);
}