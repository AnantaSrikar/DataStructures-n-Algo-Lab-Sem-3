#include<stdio.h>
#include<stdlib.h>

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
		printf("error"); // Please enter only numbers!
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

	void exer_1(int[]);
	void exer_2(int[]);
	void exer_3(int[]);

	switch(input_arr[1])
	{
		case 1:
				exer_1(input_arr);
				break;

		case 2:
				exer_2(input_arr);
				break;

		case 3:
				exer_3(input_arr);
				break;

		default:
				printf("error");
	}

	return(0);
}

void exer_1(int input_arr[])
{
	node *first_node_ptr, *temp;

	int size = sizeof(input_arr) - 1;

	for(int i = 1; i <= size ; i++)
	{
		node *new_node;

		if(i == 0)
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

		if(i == size)
			temp -> next = NULL;
	}

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

void exer_2(int input_arr[])
{
	// TODO: finish it
}

void exer_3(int input_arr[])
{
	// TODO: finish it
}