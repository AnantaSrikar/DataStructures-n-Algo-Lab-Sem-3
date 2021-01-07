/*
	Solution for Honors Assignment, C for Everyone: Structured Programming Week 3
	
	Solved it by first bubble sorting the Doubly linked list and then deleting the
	duplicates by checking adjacent nodes.

	Author: Ananta Srikar
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Base data structure for a linked list
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

typedef struct node node;

int main()
{
	// Function prototype. If you don't know what this is look it up before saying it wont work
	void bubble_sort(node*);
	void print_list(node*);
	node* delete_dupes(node*);

	// The root node for the linked list, and temp for iterative purposes
	node *root = NULL, *temp;

	// Generating 200 random number linked list
	
	// Use current time as seed for random generator
	srand(time(0));

	for(int i = 0; i < 200; i++)
	{
		// Creating a new node
		node *new_node = malloc(sizeof(node));
		
		// Generate a random number from [0, 49]
		new_node -> data = rand() % 50;

		// First node
		if(root == NULL)
		{
			root = new_node;
			root -> prev = NULL;
		}
		
		// For other nodes
		else
		{
			temp -> next = new_node;
			new_node -> prev = temp;
		}
		
		temp = new_node;
		temp -> next = NULL;
	}

	// Printing list before sorting
	printf("Original doubly	linked list:\n\n");
	print_list(root);
	printf("\n\n\n");

	// Sorting the doubly linked list using bubble sort
	bubble_sort(root);

	// Printing the list after sorting
	printf("Sorted doubly linked list:\n\n");
	print_list(root);
	printf("\n\n\n");

	// Removing the duplicate elements
	root = delete_dupes(root);

	// Printing the linked list after sorting it.
	printf("Doubly linked list after deleting array elements:\n\n");
	print_list(root);
	
	return(0);
}

// Function to delete the previous node
void delete_prev_node(node *cur_node)
{
	node *del_node = cur_node -> prev;

	// If the node is not the 2nd one in the list
	if(cur_node -> prev -> prev)
	{
		cur_node -> prev -> prev -> next = cur_node;
		cur_node -> prev = cur_node-> prev -> prev;
	}

	else
		cur_node -> prev = NULL;

	free(del_node);
}

// Function to delete the next node
void delete_next_node(node *cur_node)
{
	node *del_node = cur_node -> next;

	// If the node is NOT the 2nd last in the list
	if(cur_node -> next -> next)
	{
		cur_node -> next -> next -> prev = cur_node;
		cur_node -> next = cur_node -> next -> next;
	}

	else
		cur_node -> next = NULL;

	free(del_node);
}

// Main logic to delete all duplicate entries in a doubly linked list
node* delete_dupes(node *cur_root)
{
	if(cur_root == NULL) // Empty list :(
		return NULL;

	node *temp, *root;
	temp = root = cur_root;

	int cnt = 0;

	while(temp != NULL)
	{
		if(temp -> prev && temp -> prev -> data == temp -> data)
		{
			if(temp -> prev == root) // If prev node is root, change it
				root = temp;
			// Delete prev node
			delete_prev_node(temp);
		}

		if(temp -> next && temp -> next -> data == temp -> data)
			// Delete next node
			delete_next_node(temp);

		temp = temp -> next;
		cnt++;
	}

	return root;
}

// Function to swap the values of two nodes
void swap(node *n1, node*n2)
{
	int temp = n1 -> data;
	n1 -> data = n2 -> data;
	n2 -> data = temp;
}

// Function to bubble sort the doubly linked list
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

// Simple function to print the doubly linked list
void print_list(node *root)
{
	node *temp = root;

	int cnt = 1;

	while(temp != NULL)
	{
		printf("%10d ", temp -> data);
		temp = temp -> next;
		
		if(cnt % 5 == 0) // For printing in rows of 5
			printf("\n");

		cnt++;
	}
}