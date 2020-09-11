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
	
	int get_sum(int[], int, int);

	int num_of_coins = input_arr[0];

	int weights[num_of_coins];

	for(int i = 0; i < num_of_coins; i++)
		weights[i] = input_arr[i + 1];
	
	int l = 0, side_size = num_of_coins / 2;

	while(side_size >= 1)
	{
		printf("%d %d\n", get_sum(weights, l, l + side_size - 1), get_sum(weights, l + side_size, l + 2 * side_size - 1));
		printf("l = %d, side_size = %d\n", l, side_size);

		if(get_sum(weights, l, l + side_size - 1) == get_sum(weights, l + side_size, l + 2 * side_size - 1))
		{
			printf("Fake coin found at %d = %d\n", l + 2 * side_size, weights[l + 2 * side_size]);
			break;
		}

		else if(side_size == 1 && weights[l] != weights[l + 1])
		{
			if(weights[l] < weights[l + 1])
				printf("Fake coin found at %d = %d\n", l , weights[l]);
			
			else
				printf("Fake coin found at %d = %d\n", l + 1 , weights[l + 1]);
			
			break;
		}

		else if(get_sum(weights, l, l + side_size - 1) < get_sum(weights, l + side_size, l + 2 * side_size - 1))
		{
			printf("Do something\n");
			side_size /= 2;
		}

		else if(get_sum(weights, l, l + side_size - 1) > get_sum(weights, l + side_size, l + 2 * side_size - 1))
		{
			printf("Do something\n");
			l += side_size;
			side_size /= 2;
		}
	}

	return(0);
}

int get_sum(int arr[], int l, int r)
{
	int sum = 0;

	for(int i = l; i <= r; i++)
		sum += arr[i];

	return sum;
}