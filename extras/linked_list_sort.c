/*
	Solution for General assignment, C for Everyone: Structured Programming Week 3

	Author: Ananta Srikar
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Base data structure for a linked list
struct node
{
	int data;
	struct node *next;
};

typedef struct node node;

int main()
{
	// Function prototype. If you don't know what this is look it up before saying it wont work
	void bubble_sort(node*);

	// The root node for the linked list, and temp for iterative purposes
	node *root = NULL, *temp;

	// Generating 100 random number linked list
	
	// Use current time as seed for random generator
	srand(time(0));

	for(int i = 0; i < 100; i++)
	{
		// Creating a new node
		node *new_node = malloc(sizeof(node));
		new_node -> data = rand();

		// First node
		if(root == NULL)
			root = new_node;
		
		// For other nodes
		else
			temp -> next = new_node;
		
		temp = new_node;
		temp -> next = NULL;
	}

	// Sorting the linked list using bubble sort

	bubble_sort(root);

	// Printing the linked list after sorting it.

	temp = root;

	int cnt = 1;

	while(temp != NULL)
	{
		printf("%10d ", temp -> data);
		temp = temp -> next;
		
		if(cnt % 5 == 0) // For printing in rows of 5
			printf("\n");

		cnt++;
	}
	
	return(0);
}

// Function to swap the values of two nodes
void swap(node *n1, node*n2)
{
	int temp = n1 -> data;
	n1 -> data = n2 -> data;
	n2 -> data = temp;
}

void bubble_sort(node *root)
{
	if(root == NULL)
		return;

	int swapped;

	node *list_ptr, *prev_ptr = NULL;

	do
	{
		swapped = 0;

		list_ptr = root;

		while (list_ptr -> next != prev_ptr)
		{
			if(list_ptr -> data > list_ptr -> next -> data)
			{
				swap(list_ptr, list_ptr -> next);
				swapped = 1;
			}

			list_ptr = list_ptr -> next;
		}

		prev_ptr = list_ptr;
	} while(swapped);
}