// build a dictionary of words from a given text file and count number of words, and save the results as a text file
// 20186628 임선호

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define _CRT_SECURE_NO_WARNINGS

typedef struct nodeStruct
{
	int tag; //
	char* value; //
	int count;
}node;

char* casedown(char* input);
void search_insert(char* target);
void printAll(FILE* write);

// argv[0] input.txt
// argv[1] output.txt

node nodes[1300000]; //1116092개 정도의 토큰이 있는듯
int main(int argc, char* argv[]) {
	for (int i = 0; i < 1300000; i++) {
		nodes[i].tag = 0;
	}

	//file
	FILE *read, *write;
	fopen_s(&read, argv[1], "r");
	if (read == NULL) {
		printf("fail to open file.\n");
		return 0;
	}
	fopen_s(&write, argv[2], "wt");
	if (write == NULL) {
		printf("fail to create file for write.\n");
		return 0;
	}
	printf("file ready\n");


	//input file read
	char str[1000];	//평균 한 라인에 200자가 넘지 않는 걸로 보임...
	int toknum = 0;
	
	const char delimiters[] = ", !.?\'\"#*-_=+[]():~^{}><@/&$%`;|\\\n\t\s";	//'s 를 포함할까
	

	while (fgets(str, sizeof(str), read) != NULL) {
		char *token = strtok(str, delimiters);

		while (token != NULL)
		{
			//대소문자 변경
			token = casedown(token);

			search_insert(token);
			
			printf("[%07d] %s\n", ++toknum, token); //

			//token을 저장 
			//temp[toknum] = token;
			token = strtok(NULL, delimiters);
			//NULL을 넣으면 방금전에 분리한 문자열의 남은 문자열을 가지고 다시
		}
	}


	//output file write
	printAll(write); //
	printf("\n");
	fprintf(write, "\n");

	//print name and student id
	printf("building a dictionary of words\n");
	printf("20186628 임선호\n");
	fprintf(write, "This program is building a dictionary of words and written by 임선호 at 2019 12 09 ~ 2019 12 12 \n");
	fprintf(write, "Student Id Number is 20186628\n");

	//close
	fclose(read);
	fclose(write);

	return 0;
}

char* casedown(char* input) {
	char* result = input;

	//대문자를 소문자로 모두 바꾸기
	for (int i = 0; i <= strlen(result); ++i)
	{
		result[i] = (char)tolower(result[i]);
	}

	return result;
}

//strcmp(s1, s2)
//s1 == s2 0
//s1 < s2 음수 사전순 s1 다음 s2
//s1 > s2 양수 사전순 s2 다음 s1



//Null 나오면 새로 insert
//search 하여 나온 노드 count++;
void search_insert(char *target) {
	int i = 0;
	while (nodes[i].tag != 0) {
		if (strcmp(nodes[i].value, target) == 0) {
			nodes[i].count++;
			return;
		}
		else
			i++;
	}

	char* tmp = (char*)malloc(sizeof(char) * 100); //
	memcpy(tmp, target, strlen(target) + 1);

	nodes[i].value = tmp;
	//strcpy_s(nodes[i].value, sizeof(target) - 1 , target);
	//nodes[i].value[99] = NULL;
	nodes[i].count = 1;
	nodes[i].tag = 1;
	return;
}

void printAll(FILE * write)
{
	if (nodes[0].tag == 0)
		return;

	int i = 0;
	while (nodes[i].tag != 0) {
		printf("[%07d]%s (%d)\n",i + 1, nodes[i].value, nodes[i].count); //
		fprintf(write, "[%07d]%s (%d)\n",i + 1, nodes[i].value, nodes[i].count);
		i++;
	}
	return;
}
