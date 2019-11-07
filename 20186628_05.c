// C programming for the summation of numbers in a list given by an input file using a recursive function
//2019 11 02
//�Ӽ�ȣ 20186628 

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

//int sumNumbers(int count_input, FILE *write, int *numbers);
//int sumNumbers(int count_input, int numbers[]);
int sumNumbers(int array[], int count_input);

//argv[1] input text file
int main(int argc, char* argv[]) {
	const char* filename = argv[1];
	//���� �غ�
	FILE *read, *write;
	//fopen_s�� ���� ���⿡ ���������� 0 �� ��ȯ�Ѵ�
	fopen_s(&read, filename, "r");
	if (read == NULL) {		//fail to open file for read 
 		printf("fail to open file.");
		return 0;
	}
	fopen_s(&write, "20186628_05_output.txt", "wt");
	if (write == NULL) {		//fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}

	printf("file open success\n");

	//input file read
	char str[100];
	fgets(str, sizeof(str), read);
	int count = atoi(str);
	printf("%d\n", count); //

	for (int i = 0; i < 100; i++) {
		str[i] = NULL;
	}

	int numbers[100];
	for(int i = 0; i < count; i++) {
		fgets(str, sizeof(str), read);
		numbers[i] = atoi(str);
		printf("%d\n", numbers[i]); //
		for (int i = 0; i < 100; i++) {
			str[i] = NULL;
		}

	}	

	int reversed[100];

	for (int i = 0; i < count; i++) {
		reversed[i] = numbers[count - i - 1];
	}

	//summation

	//int summation = sumNumbers(numbers, 1);

	for (int i = 1; i <= count; i++) {
		int result = sumarray(reversed, i);
		//int result = sumNumbers(numbers, i);
		printf("result is %d\n", result); //
		fprintf(write, "[%03d] %d\n", count - i + 1, result);
	}

	

	//print name and student id
	printf("summation of numbers with recursive function call\n");
	printf("20186628 �Ӽ�ȣ\n");
	fprintf(write, "This program is summation of 12 numbers and written by �Ӽ�ȣ at 2019 11 02 ~ 2019 11 07\n");
	fprintf(write, "Student Id Number is 20186628\n");

	//close
	fclose(read);
	fclose(write);
	return 0;
}

int sumNumbers(int array[], int count_input)
{
	int i = count_input - 1;

	if (i == 11)
	{
		return array[11];
	}

	return sumNumbers(array, i + 1) + array[i];
}

int sumarray(int array[], int i)
{
	if (i <= 0)
	{
		return 0;
	}

	return sumarray(array, i - 1) + array[i - 1];
}
