#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;

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

	void exer_1(int[], int);
	void exer_2(int[], int);
	void exer_3(int[], int);

	switch(input_arr[0])
	{
		case 1:
				exer_1(input_arr, argc - 1);
				break;

		case 2:
				exer_2(input_arr, argc - 1);
				break;

		case 3:
				exer_3(input_arr, argc - 1);
				break;

		default:
				printf("error");
	}

	return(0);
}

node *get_linked_list(int input_arr[], int size)
{
	node *first_node_ptr, *temp;

	for(int i = 1; i < size ; i++)
	{
		node *new_node;

		if(i == 1)
		{
			first_node_ptr = (node*)malloc(sizeof(node));
			temp = first_node_ptr;

			temp -> data = input_arr[i];
		}
		
		else
		{
			new_node = (node*)malloc(sizeof(node));

			new_node -> data = input_arr[i];

			temp -> next = new_node;
			temp = new_node;
		}

		if(i == size - 1)
			temp -> next = NULL;
	}

	return first_node_ptr;
}

void exer_1(int input_arr[], int size)
{
	if(size < 2)
	{
		printf("error"); // No elements in the linked list!
		exit(0);
	}

	node *first_node_ptr, *temp;

	first_node_ptr = get_linked_list(input_arr, size);
	
	temp = first_node_ptr;

	int cnt = 0;

	while(temp != NULL)
	{
		cnt++;
		temp = temp -> next;
	}

	if(cnt % 2 == 0)
		printf("0");
	
	else
		printf("1");
}


int isPrime(int num)
{
	if(num <= 1)
		return 0;

	else if(num == 2)
		return 1;
		
	for(int i = num - 1; i >= 2; i--)
		if(num % i == 0)
			return 0;
	
	return 1;
}

void exer_2(int input_arr[], int size)
{
	node *first_node_ptr, *temp, *prime_nos = NULL, *prime_temp;

	first_node_ptr = get_linked_list(input_arr, size);
	
	temp = first_node_ptr;

	while(temp != NULL)
	{
		if(isPrime(temp -> data))
		{
			if(prime_nos == NULL)
			{
				prime_nos = (node*)malloc(sizeof(node));
				prime_temp = prime_nos;

				prime_temp -> data = temp -> data;
			}

			else
			{
				node *new_node = (node*)malloc(sizeof(node));

				new_node -> data = temp -> data;

				prime_temp -> next = new_node;
				prime_temp = new_node;
			}
		}
		temp = temp -> next;
	}

	if(prime_nos != NULL)
	{
		prime_temp -> next = NULL;

		temp = prime_nos;

		while(temp != NULL)
		{
			if(temp -> next != NULL)
				printf("%d ", temp -> data);
			else
				printf("%d", temp -> data);
			
			temp = temp -> next;
		}
	}

	else
		printf("#");

}

void exer_3(int input_arr[], int size)
{
	node *first_node_ptr, *temp;

	first_node_ptr = get_linked_list(input_arr, size);
	
	temp = first_node_ptr;

	int sum = 0;

	while(temp != NULL)
	{
		sum += temp -> data;
		temp = temp -> next;
	}

	printf("%d", sum);
}