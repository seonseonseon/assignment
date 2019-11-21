/*
20186628 임선호
*/
#include <stdio.h>
//permutation of characters
//number of characters = n 이면 P(n,n)을 수행해서 나온 수만큼 해야돼
//with recursion
//첫번째 자리에 올 수 있는거 n개 두번째 자리에 올 수 있는거 n-1개 ...

void permutation(char* array, int depth, int num, FILE* write);
void swap(char* array, int i, int j);

int main(int argc, char* argv[]) {
	//file
	FILE *read, *write;
	fopen_s(&read, argv[1], "r");
	if (read == NULL) {
		printf("fail to open file.\n");
		return 0;
	}
	fopen_s(&write, "20186628_06_output.txt", "wt");
	if (write == NULL) {
		printf("fail to create file for write.\n");
		return 0;
	}
	printf("file ready\n");

	//input file read
	char str[10];
	fgets(str, sizeof(str), read);
	int num = atoi(str);
	printf("%d\n", num); // num is number of characters and assume num is 6
	char characters[6];
	char temp[10];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 10; j++) {
			temp[j] = NULL;
		}
		fgets(temp, sizeof(temp), read); //
		//fscanf_s(read, "%c\n", characters[i]);
		//strcpy_s
		printf("%s", temp);	//
		characters[i] = temp[0];
	}
	
	//calculate n factorial that is P(n,n)
	//int count = factorial(num);

	/*
	// make array to store string of permutation
	// it means char array[count][num];
	char **array;
	array = (int**)malloc(sizeof(int*) * count);
	for (int i = 0; i < count; i++) {
		array[i] = (int*)malloc(sizeof(int) * num);
	}
	*/



	// call permutation function
	//permutation(array, remain, count);
	permutation(characters, 0, num, write);

	//print name and student id
	printf("permutation of characters\n");
	printf("20186628 임선호\n");
	fprintf(write, "This program is permutation of six characters and written by 임선호 at 2019 11 15 ~ 2019 11 21 \n");
	fprintf(write, "Student Id Number is 20186628\n");

	//close
	fclose(read);
	fclose(write);

	return 0;
}
//count에 n이 들어오니까
/*
void permutation(char** array, char* remain, int count) {	//remain은 아직 사용하지 않은 character를 저장하는 용도
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < factorial(count - 1); i++) {
			//array[][] = remain[count];
		}
	}

	//remain을 줄이고
	permutation(array, remain, count - 1);

}*/
/*
int factorial(int input) {	//input >= 1
	if (input == 1) {
		return 1;
	}
	else {
		return factorial(input - 1) * input;
	}
}*/


void permutation(char* array, int depth, int num, FILE* write) {
	static int count = 1;
	if (depth == num) {
		//print
		printf("[%03d] ", count);
		fprintf(write, "[%03d] ", count);
		count++;
		for (int i = 0; i < num; i++) {
			printf("%c ", array[i]);
			fprintf(write, "%c ", array[i]);
		}
		printf("\n");
		fprintf(write, "\n");
		return;
	}

	for (int i = depth; i < num; i++) {
		swap(array, i, depth);
		permutation(array, depth + 1, num, write);
		swap(array, i, depth);
	}

}


void swap(char* array, int i, int j) {
	char temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	return;
}