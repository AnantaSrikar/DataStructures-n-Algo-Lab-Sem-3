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

	void SortArray(int *, int);

	if((input_arr[0] < input_arr[argc - 2]) || (input_arr[0] != argc - 3))
	{
		printf("error");
		return -1;
	}

	int arr_size = input_arr[0], k = input_arr[arr_size + 1];
	int arr[arr_size];

	for(int i = 0; i < arr_size; i++)
		arr[i] = input_arr[i + 1];

	
	// Easiest and fastest way. Sort the array.

	SortArray(arr, arr_size);

	printf("%d", arr[k - 1]);

	return (0);
}

void SortArray(int sortingList[], int numVals)
{
	for(int i = 0; i < numVals; i++) 
		for(int j = i + 1; j < numVals; j++)
			if (sortingList[i] < sortingList[j]) 
			{
				int temp = sortingList[i];
				sortingList[i] = sortingList[j];
				sortingList[j] = temp;
			}
}

/*
	Eze bonus question. Nothing more required than just simple sorting
*/