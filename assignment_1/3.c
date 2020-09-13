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

	int l = 0, k = num_of_coins / 3;

	while(k >= 1)
	{
		printf("%d %d\n", get_sum(weights, l, l + k - 1), get_sum(weights, l + k, l + 2 * k - 1));

		if(k != 1)
		{
			if(get_sum(weights, l, l + k - 1) == get_sum(weights, l + k, l + 2 * k - 1))
			{
				l += 2 * k;
				k = (num_of_coins - l) / 3;
			}

			else if(get_sum(weights, l, l + k - 1) < get_sum(weights, l + k, l + 2 * k - 1))
				k /= 3;

			else if(get_sum(weights, l, l + k - 1) > get_sum(weights, l + k, l + 2 * k - 1))
			{
				l += k;
				k /= 3;
			}
		}

		else
		{
			if(weights[l] == weights[l + 1])
				l += 2;

			else if(weights[l] < weights[l + 1])
			{
				printf("%d %d\n", l, weights[l + 1] - weights[l]);
				break;
			}

			else
			{
				printf("%d %d\n", l + 1, weights[l] - weights[l + 1]);
				break;
			}
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