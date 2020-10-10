#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct student
{
	int roll_no, ds_marks, pe_marks, total_marks;
};

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

	if(input_arr[0] * 2 + 2 != argc)
	{
		printf("error");
		exit(0);
	}

	int arr_size = input_arr[0];

	struct student* get_grade_sheet(int[], int[], int);

	int arr_DS[arr_size], arr_PE[arr_size];

	for(int i = 1; i < arr_size + 1; i++)
		arr_DS[i - 1] = input_arr[i];

	for(int i = arr_size + 1; i < arr_size * 2 + 1; i++)
		arr_PE[i - (arr_size + 1)] = input_arr[i];

	struct student *grade_sheet = get_grade_sheet(arr_DS, arr_PE, arr_size);

	for(int i = 0; i < arr_size; i++)
		if(i == arr_size - 1)
			printf("%d %d %d %d", (grade_sheet + i) -> roll_no, (grade_sheet + i) -> total_marks, (grade_sheet + i) -> ds_marks, (grade_sheet + i) -> pe_marks);
		else
			printf("%d %d %d %d\n", (grade_sheet + i) -> roll_no, (grade_sheet + i) -> total_marks, (grade_sheet + i) -> ds_marks, (grade_sheet + i) -> pe_marks);

	return(0);
}

int comparator(const void* student_1_ptr, const void* student_2_ptr)
{
	struct student *student_1 = (struct student*)student_1_ptr;
	struct student *student_2 = (struct student*)student_2_ptr;

	if((student_1 -> total_marks) == (student_2 -> total_marks))
		
		if((student_1 -> ds_marks) == (student_2 -> ds_marks))
			return((student_1 -> roll_no) > (student_2 -> roll_no));
		else
			return((student_1 -> ds_marks) < (student_2 -> ds_marks));
	
	return ((student_1 -> total_marks) < (student_2 -> total_marks));
}

struct student* get_grade_sheet(int arr_DS[], int arr_PE[], int arr_size)
{
	struct student *grade_sheet = malloc(arr_size * sizeof(struct student));

	// Assigning the values

	for(int i = 0; i < arr_size; i++)
	{
		(grade_sheet + i) -> roll_no = i;
		(grade_sheet + i) -> ds_marks = arr_DS[i];
		(grade_sheet + i) -> pe_marks = arr_PE[i];
		(grade_sheet + i) -> total_marks = arr_DS[i] + arr_PE[i];
	}

	// Sorting them according to total_marks

	qsort(grade_sheet, arr_size, sizeof(struct student), comparator);
	
	return grade_sheet;
}