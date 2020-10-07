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
	}

	return(0);
}

int find_element_2(int input_arr[], int size, int element)
{
	int first_found = 0;

	for(int i = 1; i < size; i++)
	{
		if(input_arr[i] == element)
			if(first_found)
				return i;
			else
				first_found = 1;
	}

	return -1;
}

int find_element_last(int input_arr[], int size, int element)
{
	int index = -1;
	for(int i = 1; i < size; i++)
		if(input_arr[i] == element)
				index = i;

	return index;
}

void exer_1(int input_arr[], int argc)
{

	if(input_arr[1] + 5 != argc)
	{
		printf("error");
		exit(0);
	}

	int arr_size = input_arr[1];

	int arr[arr_size + 1], key = input_arr[argc - 2];

	int index = find_element_2(input_arr, arr_size + 2, key);

	if(index > 1)
	{
		index -= 2;
		int new_element = input_arr[argc - 3];

		for(int i = 0; i < arr_size + 1; i++)
		{
			if(i <= index)
				arr[i] = input_arr[i + 2];

			else if(i == index + 1)
				arr[i] = new_element;

			else
				arr[i] = input_arr[i + 1];

			if(i == arr_size)
				printf("%d", arr[i]);

			else
				printf("%d ", arr[i]);
		}
	}

	else
	{
		printf("error");
		exit(0);
	}
}

void exer_2(int input_arr[], int argc)
{
	if(input_arr[1] + 4 != argc)
	{
		printf("error");
		exit(0);
	}

	int arr_size = input_arr[1] - 1;

	int arr[arr_size], key = input_arr[argc - 2];

	int index = find_element_last(input_arr, arr_size + 3, key);

	if(index > 1)
	{
		index -= 2;

		for(int i = 0; i < arr_size; i++)
		{
			if(i < index)
				arr[i] = input_arr[i + 2];

			else if (i >= index)
			{
				arr[i] = input_arr[i + 3];
			}

			if(i == arr_size - 1)
				printf("%d", arr[i]);

			else
				printf("%d ", arr[i]);
		}
	}

	else
	{
		printf("error");
		exit(0);
	}

}

void exer_3(int input_arr[], int argc)
{
	printf("p3");
}

