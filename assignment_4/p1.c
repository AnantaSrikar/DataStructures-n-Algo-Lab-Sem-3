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

	if(!(argc > 1))
	{
		printf("error"); // Too less arguments!
		return -1;
	}

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
		printf("error"); // Too less arguments!
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

void exer_2(int input_arr[], int size)
{
	// TODO: finish it
}

void exer_3(int input_arr[], int size)
{
	// TODO: finish it
}