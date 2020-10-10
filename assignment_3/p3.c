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
				printf("error"); // Please enter only positive numbers!
				return -1;
			}

		input_arr[i - 1] = atoi(argv[i]);
	}

	// End of Command line input code

	if(input_arr[0] + 2 != argc)
	{
		printf("error");
		exit(0);
	}

	int* find_max_profit(int[], int);

	int arr_size = input_arr[0];

	int prices[arr_size];

	for(int i = 0; i < arr_size; i++)
		prices[i] = input_arr[i + 1];

	int * arr = find_max_profit(prices, arr_size);

	for(int i = 0; i < 3; i++)
		if(i == 2)
			printf("%d", arr[i]);
		else
			printf("%d ", arr[i]);
	
	return(0);
}

int* find_max_profit(int prices[], int arr_size)
{

	int *arr = (int*)malloc(3 * sizeof(int)), diff = -1;
	
	for(int i = 0; i < arr_size; i++)
		for(int j = 0; j < i; j++)
			if(prices[i] - prices[j] > diff)
			{
				arr[0] = prices[j];
				arr[1] = prices[i];
				diff = arr[2] = arr[1] - arr[0];
			}

	if(diff == -1)
		for(int i = 0; i < 3; i++)
			arr[i] = 0;

	return arr;
}

/*
	Oh yes I can finally return arrays in C! Feels so good.
*/