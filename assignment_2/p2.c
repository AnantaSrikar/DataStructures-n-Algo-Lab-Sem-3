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

	if(argc != input_arr[0] + input_arr[input_arr[0] + 1] + 3)
	{
		printf("error");
		return -1;
	}

	int search_element(int[], int, int);
	void find_union_and_intersection(int*, int*, int, int);
	void find_union(int*, int*, int, int);

	int len_A = input_arr[0], len_B = input_arr[input_arr[0] + 1];

	int A[len_A], B[len_B];

	for(int i = 0; i < len_A; i++)
		A[i] = input_arr[i + 1];

	for(int i = 0; i < len_B; i++)
		B[i] = input_arr[len_A + 2 + i];

	// Sort both the arrays for easier logic

	// SortArray(A, len_A);
	// SortArray(B, len_B);

	find_union_and_intersection(A, B, len_A, len_B);


	// find_intersection(A, B, len_A, len_B);
	// find_union(A, B, len_A, len_B);

	return(0);
}


int search_element(int arr[], int size, int x) 
{
	for(int i = 0; i < size; i++)
		if(arr[i] == x)
			return x;

	// Element not found
	
	return -1; 
} 

void find_union_and_intersection(int A[], int B[], int len_A, int len_B)
{
	int U[len_A + len_B], I[len_A + len_B], u_size = len_A, i_size = 0;

	for(int i = 0; i < len_A; i++)
	{
		U[i] = A[i];

		if(search_element(B, len_B, A[i]) != -1)
			I[i_size++] = A[i];
	}
	
	for(int i = 0; i < len_B; i++)
		if(search_element(U, len_A, B[i]) == -1)
			U[u_size++] = B[i];
		

	for(int i = 0; i < u_size; i++)
		printf("%d ", U[i]);

	printf("\n");

	for(int i = 0; i < i_size; i++)
		printf("%d ", I[i]);

}

/* 
	Smh this didn't need me to sort anything. Just brute force your way up to the answers.
	Not a good way of asking someone to code. Especially in an Algorithms course.
*/