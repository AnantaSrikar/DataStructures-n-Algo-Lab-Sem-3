#include<stdio.h>
int main()
{
	int get_diff(int, int);

	int num_of_coins;

	scanf("%d", &num_of_coins);

	int weights[num_of_coins];

	for(int i = 0; i < num_of_coins; i++)
		if(i != num_of_coins - 1)
			scanf("%d ", &weights[i]);
		else
			scanf("%d", &weights[i]);

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