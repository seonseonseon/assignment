/*
20186628 임선호
*/

#include <stdio.h>
#include <math.h>	//pow()를 사용하기 위함
#include <stdlib.h>	//malloc, calloc, exit 을 사용하기 위함


int main(int argc, char* argv[]) {
	const char* filename = argv[1];
	FILE *fp;
	fopen_s(&fp, filename, "w");	//fopen함수는 오류, 
	//FILE *fp = wfsopen_s(&fp, filename,"w");
	if (fp == NULL) {	//계속 NULL 반환됨
		printf("can not open file\n");
		exit(1);
	}
	

	int num;
	num = argc - 2;	//총 입력된 element의 개수 num

	int count; //0001 ~ 2의 n승까지의 subset들이 생긴다
	count = (int)pow(2, num);

	//assignment03.exe 과 ~~~.txt 외에 아무것도 입력 안했을때
	if (num == 0) {
		printf("[%04d] ", 1);
		printf("ø");
		printf("\n");

		fprintf(fp, "[%04d] ", 1);
		fprintf(fp, "ø");
		fprintf(fp, "\n");
	}

	//1개~10개의 char들을 잘 입력했을때
	else if (1 <= num && num <= 10) {

		//power set들이 저장될 subsets이라는 이차원 배열 int** subsets
		//row가 2의 num 승, col이 num 이도록 malloc으로 공간을 할당한다
		//최대 element의 개수가 10개로 정해졌으므로 미리 정적으로 할당할 수도 있었으나
		//2의 10승으로 숫자가 꽤 크기 때문에 메모리 낭비를 줄이기 위해 동적 할당을 사용하였다
		char** subsets = (char**)malloc(count * sizeof(char*));
		for (int i = 0; i < count; i++) {
			subsets[i] = (char*)malloc(num * sizeof(char));
		}

		//power set 생성
		int tmp, col, index;
		int* eachCol = (int*)calloc(count, sizeof(int));	//eachCol 배열은 subsets배열의 각각의 row마다 몇 개의 char이 저장되었는지 카운트하기 위함

		for (int i = 0; i < count; i++) {


			if (i == 0) {
				subsets[0][0] = "ø";
				eachCol[0] = 1;
			}
			else {
				tmp = i;
				index = 2;
				col = 0;

				while (tmp > 0) {
					if (tmp & 1) {
						subsets[i][col] = argv[index][0];
						col++;
					}
					tmp = tmp / 2;
					index++;
				}
				eachCol[i] = col;

				//한 element는 속하거나 속하지 않거나 둘 중 하나이므로
				//tmp가 홀수 일 때만 대입하고 아닐땐 tmp /2 index줄이기
			}

		}

		//출력
		printf("[%04d] ", 1);
		printf("ø");
		printf("\n");

		fprintf(fp, "[%04d] ", 1);
		fprintf(fp, "ø");
		fprintf(fp, "\n");

		for (int i = 1; i < count; i++) {
			printf("[%04d] ", i + 1);
			fprintf(fp, "[%04d] ", i + 1);
			for (int j = 0; j < eachCol[i] - 1; j++) {
				printf("%c, ", subsets[i][j]);
				fprintf(fp, "%c, ", subsets[i][j]);
			}
			printf("%c\n", subsets[i][eachCol[i] - 1]);
			fprintf(fp, "%c\n", subsets[i][eachCol[i] - 1]);
		}



	}

	//10개 넘게 입력했을때
	else if (num > 11) {
		printf("\nToo many arguments are entered.\nMaximum number of elements in a given set is 10\n");
	}

	fclose(fp);
	printf("\nHello. This is written by Seon-ho Im (20186628) \n\n");

	return 0;
}