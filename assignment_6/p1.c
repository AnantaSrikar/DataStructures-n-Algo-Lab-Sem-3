#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node_int
{
	int data;
	struct node_int *left;
	struct node_int *right;
};

struct node_str
{
	char *data;
	struct node_str *left;
	struct node_str *right;
};

typedef struct node_int node_int;
typedef struct node_str node_str;

int main(int argc, char **argv)
{

	// Initial code to get all command line values

	// int input_arr[argc - 1];

	// for(int i = 1; i <= argc - 1; i++)
	// {
	// 	for(int j = 0; j < strlen(argv[i]); j++)
	// 		if(!isdigit(argv[i][j]) && argv[i][j] != '-')
	// 		{
	// 			printf("error"); // Please enter only numbers!
	// 			return -1;
	// 		}

	// 	input_arr[i - 1] = atoi(argv[i]);
	// }
	void *get_input_array(int, char**);
	void build_bin_tree(void*, int, int);

	// End of Command line input code

	// void exer_1(int[], int);
	// void exer_2(int[], int);
	// void exer_3(int[], int);

	int ques_no = atoi(argv[1]);

	if(ques_no == 3)
	{
		char *input_array = get_input_array(argc, argv);
		build_bin_tree(input_array, argc - 2, 1);
		// for(int i = 0; i < argc - 2; i++)
		// 	printf("%c\n", input_array[i]);
	}

	else if(ques_no == 1 || ques_no == 2)
	{
		int *input_array = get_input_array(argc, argv);

		build_bin_tree(input_array, argc - 2, 0);

		// for(int i = 0; i < argc - 2; i++)
		// 	printf("%d\n", input_array[i]);
	}

	else
	{
		printf("error"); // Invalid question number -_-
		return -1;
	}

	return(0);
}

void* get_input_array(int argc, char **argv)
{
	int ques_no = atoi(argv[1]);
	
	if(ques_no == 3)
	{
		char **input_arr = malloc(sizeof(char*) * (argc - 2));

		for(int i = 2; i < argc; i++)
		{
			input_arr[i - 2] = (char*)malloc(sizeof(char) * strlen(argv[i]));
			strcpy(input_arr[i - 2], argv[i]);
		}

		return input_arr;
	}

	else if(ques_no == 1 || ques_no == 2)
	{
		int *input_arr = (int*)malloc(sizeof(int) * (argc - 2));

		for(int i = 2; i < argc; i++)
		{
			for(int j = 0; j < strlen(argv[i]); j++)
				if(!isdigit(argv[i][j]) && argv[i][j] != '-')
				{
					printf("error"); // invalid input
					exit(0);
				}
			
			input_arr[i - 2] = atoi(argv[i]);
		}

		return input_arr;
	}
}

node_int* makeNewNode_int(int data)
{
	node_int *new_node = (node_int*)malloc(sizeof(node_int));

	new_node -> data = data;
	new_node -> left = new_node -> right = NULL;
	
	return new_node;
}

node_str* makeNewNode_str(char data[])
{
	node_str *new_node = (node_str*)malloc(sizeof(node_str));

	strcpy(new_node -> data, data);
	new_node -> left = new_node -> right = NULL;
	
	return new_node;
}

// Too lazy to make two functions as one ;-;
// Also rip, C doesn't have default arguments 

node_int* insertLevelOrder_int(int arr[], node_int *root, int size, int i)
{
	// Base case for recursion 
	if(i < size)
	{
		node_int *temp = makeNewNode_int(arr[i]);
		root = temp;

		// insert left child
		root -> left = insertLevelOrder_int(arr, root -> left, size, 2 * i + 1);

		// insert right child
		root -> right = insertLevelOrder_int(arr, root -> right, size, 2 * i + 2);
	}

	return root;
}

node_str* insertLevelOrder_str(char **arr, node_str *root, int size, int i)
{
	// Base case for recursion 
	if(i < size)
	{
		node_str *temp = makeNewNode_str(arr[i]);
		root = temp;

		// insert left child
		root -> left = insertLevelOrder_str(arr, root -> left, size, 2 * i + 1);

		// insert right child
		root -> right = insertLevelOrder_str(arr, root -> right, size, 2 * i + 2);
	}

	return root;
}


void inOrder_int(node_int* root)
{ 
	if (root != NULL)
	{ 
		inOrder_int(root -> left);
		printf("%d ", root -> data);
		inOrder_int(root -> right);
	} 
}

void inOrder_str(node_str* root)
{ 
	if (root != NULL)
	{ 
		inOrder_str(root -> left);
		printf("%s ", root -> data);
		inOrder_str(root -> right);
	} 
} 

void build_bin_tree(void *input_array_ptr, int size, int is_char)
{
	if(is_char)
	{
		char **input_array = (char**)input_array_ptr;
		
		// for(int i = 0; i < size; i++)
		// 	printf("%s\n", *(input_array + i));

		node_str *root;
		root = insertLevelOrder_str(input_array, root, size, 0);

		inOrder_str(root);
	}
	
	else
	{
		int *input_array = (int*)input_array_ptr;

		// for(int i = 0; i < size; i++)
		// 	printf("%d\n", *(input_array + i));

		node_int *root;

		root = insertLevelOrder_int(input_array, root, size, 0);

		inOrder_int(root);
	}
}