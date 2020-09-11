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
	
	int get_diff(int, int);

	int num_of_coins = input_arr[0];

	int weights[num_of_coins];

	for(int i = 0; i < num_of_coins; i++)
		weights[i] = input_arr[i + 1];
	
	for(int i = 0; i < num_of_coins; i++)	

		// For odd number of weights
		if(i == num_of_coins - 1 && num_of_coins % 2 != 0)
		{
			// printf("%d %d\n", weights[i], weights[0]); // Not asked in assignment

			if(get_diff(weights[i], weights[0]))
			{
				if(get_diff(weights[i], weights[0]) < 0)
					printf("%d %d\n", i, weights[0] - weights[i]);

				else
					printf("%d %d\n", 0, weights[i] - weights[0]);
				
				break;
			}
		}

		else
		{
			printf("%d %d\n", weights[i], weights[i + 1]);

			if(get_diff(weights[i], weights[i + 1]))
			{
				if(get_diff(weights[i], weights[i + 1]) < 0)
					printf("%d %d\n", i, weights[i + 1] - weights[i]);

				else
					printf("%d %d\n", i + 1, weights[i] - weights[i + 1]);
				
				break;
			}
			i++;
		}

	return(0);
}

int get_diff(int n1, int n2)
{
	return n1 - n2;
}