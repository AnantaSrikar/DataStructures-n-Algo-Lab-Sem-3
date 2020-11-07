/*
	Solution to the bonus exercise 1
	Author: AnantaSrikar
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;

int main(int argc, char **argv)
{

	// function definiton

	node *get_node(node *, int);

	// Initial code to get all command line values

	if(argc < 2)
	{
		printf("error"); // Too less arguments!
		return -1;
	}

	// getting the size of the inital linked list

	int size = atoi(argv[1]);

	// making the linked list

	node *linked_list, *temp;

	for(int i = 2; i <= size + 1 ; i++)
	{
		node *new_node;

		// First element in the linked list
		if(i == 2)
		{
			linked_list = (node*)malloc(sizeof(node));
			temp = linked_list;

			temp -> data = atoi(argv[i]);
		}
		
		else
		{
			new_node = (node*)malloc(sizeof(node));

			new_node -> data = atoi(argv[i]);

			temp -> next = new_node;
			temp = new_node;
		}

		// Last element
		if(i == size + 1)
			temp -> next = NULL;
	}


	// Linking modifications needed now

	for(int i = size + 2; i < argc; i += 2)
	{
		// Updating the linked list with the pairs

		char in[sizeof(argv[i])], out[sizeof(argv[i + 1])];
		strcpy(in, argv[i]);
		strcpy(out, argv[i + 1]);

		if(strcmp(in, "#") == 0)
		{
			node *out_node = get_node(linked_list, atoi(out));
			
			if(out_node != NULL)
				linked_list = out_node;
			
			else
			{
				printf("error");
				return -1;
			}
			
		}
		
		else if(strcmp(out, "#") == 0)
		{
			node *in_node = get_node(linked_list, atoi(in));

			if(in_node != NULL)
				in_node -> next = NULL;

			else
			{
				printf("error");
				return -1;
			}
			
		}

		else
		{
			int first = atoi(in), second = atoi(out);

			node *in_node = get_node(linked_list, first), *out_node = get_node(linked_list, second);

			if(in_node == NULL || out_node == NULL)
			{
				printf("error");
				return -1;
			}

			else
				in_node -> next = out_node;
		}
	}
	
	temp = linked_list;

	// testing for cycle

	while(temp != NULL)
	{
		temp = temp -> next;

		if(temp == linked_list)
		{
			printf("error");
			return -1;
		}
	}

	// If it passes, print values

	temp = linked_list;

	while(temp != NULL)
	{
		printf("%d\n", temp -> data);
		temp = temp -> next;
	}

	return(0);
}

node *get_node(node *linked_list, int num)
{
	node *temp = linked_list;
	
	while (temp != NULL)
	{
		if(temp -> data == num)
			return temp;
		
		temp = temp -> next;

		// Fixing looping 

		if(temp == linked_list)
			return NULL;
	}

	return NULL;
}

/*
	Note to self: Again, check for '=='! Don't use '==' in place of '='. Wasted 2 hours.
	This question would make your understanding of pointers even better imo.
*/