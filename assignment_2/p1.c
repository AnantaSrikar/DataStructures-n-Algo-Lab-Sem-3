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

	void exer_1(int [], int);
	void exer_2(int [], int);
	void exer_3(int [], int);


	switch(input_arr[0])
	{
		case 1:
				exer_1(input_arr, argc);
				break;
				
		case 2:
				exer_2(input_arr, argc);
				break;

		case 3:
				exer_3(input_arr, argc);
				break;

		default:
				printf("error");
				return -1;
	}

	return(0);
}


void exer_1(int input_arr[], int argc)
{
	if((input_arr[1] > input_arr[2]) || argc != 7)
	{
		printf("error");
		exit(0);
	}

	int lb = input_arr[1], ub = input_arr[2], ba = input_arr[3], ws = input_arr[4], loc = input_arr[5];

	printf("%d\n", (ub - lb + 1)); // No. of elements in array
	printf("%d\n", (ub - lb + 1) * ws); // Total memory consumed
	printf("%d", (loc - lb) * ws + ba); // Mem location of arr[loc]
}

void exer_2(int input_arr[], int argc)
{
	if((input_arr[1] < input_arr[5]) || (input_arr[2] < input_arr[6]) || argc != 8)
	{
		printf("error");
		exit(0);
	}

	int r = input_arr[1], c = input_arr[2], ba = input_arr[3], ws = input_arr[4], i = input_arr[5], j = input_arr[6];

	// Since its row major
	int row_maj_addr = ba + ws * ((i * c) + j);
	
	printf("%d", row_maj_addr);
}

void exer_3(int input_arr[], int argc)
{
	if((input_arr[1] < input_arr[5]) || (input_arr[2] < input_arr[6]) || argc != 8)
	{
		printf("error");
		exit(0);
	}

	int r = input_arr[1], c = input_arr[2], ba = input_arr[3], ws = input_arr[4], i = input_arr[5], j = input_arr[6];

	// Since its column major
	int column_maj_addr = ba + ws * (i + (j * r));
	
	printf("%d", column_maj_addr);
}

/*
	Why do we have to add all 3 questions in one file? I really miss DomJudge right now.
	Even ZyBooks was much better than submitting via google classrooms.
	I wanna go back to college ASAP ;-;
*/