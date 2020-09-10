#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char **argv)
{
	int input_arr[argc - 1];

	for(int i = 1; i <= argc - 1; i++)
	{
		for(int j = 0; j < strlen(argv[i]); j++)
			if(!isdigit(argv[i][j]))
			{
				printf("Please enter only numbers!\n");
				return -1;
			}

		input_arr[i - 1] = atoi(argv[i]);
	}

	for(int i = 0; i < argc - 1; i++)
		printf("%d\n", input_arr[i]);
		
	return(0);
}