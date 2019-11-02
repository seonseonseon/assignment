// C programming for the summation of numbers in a list given by an input file using a recursive function
//2019 11 02
//임선호 20186628 

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int sumNumbers(int count_input, FILE *write, int *numbers);

//argv[1] input text file
int main(int argc, char* argv[]) {
	const char* filename = argv[1];
	//파일 준비
	FILE *read, *write;
	//fopen_s는 파일 열기에 성공했을때 0 을 반환한다
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


	//summation
	int summation = sumNumbers(count, write, numbers);

	printf("summation of numbers with recursive function call\n");
	printf("20186628 임선호\n");
	fprintf(write, "This program is written by 임선호 at 2019 11 02\n");
	fprintf(write, "Student Id Number is 20186628\n");

	fclose(read);
	fclose(write);
	return 0;
}


int sumNumbers(int count_input, FILE *write, int *numbers ) {
	int count = count_input - 1;

	if (count == 0) {
		fprintf(write, "[%03d] %d\n", count + 1, numbers[count]);
		return numbers[count];
	}
	else {
		fprintf(write, "[%03d] %d\n", count + 1, numbers[count] + sumNumbers(count - 1, write, numbers));
		return numbers[count] + sumNumbers(--count, write, numbers);
	}

}