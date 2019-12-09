// build a dictionary of words from a given text file and count number of words, and save the results as a text file
// 20186628 �Ӽ�ȣ

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

node nodes[1300000]; //1116092�� ������ ��ū�� �ִµ�
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
	char str[1000];	//��� �� ���ο� 200�ڰ� ���� �ʴ� �ɷ� ����...
	int toknum = 0;
	
	const char delimiters[] = ", !.?\'\"#*-_=+[]():~^{}><@/&$%`;|\\\n\t\s";	//'s �� �����ұ�
	

	while (fgets(str, sizeof(str), read) != NULL) {
		char *token = strtok(str, delimiters);

		while (token != NULL)
		{
			//��ҹ��� ����
			token = casedown(token);

			search_insert(token);
			
			printf("[%07d] %s\n", ++toknum, token); //

			//token�� ���� 
			//temp[toknum] = token;
			token = strtok(NULL, delimiters);
			//NULL�� ������ ������� �и��� ���ڿ��� ���� ���ڿ��� ������ �ٽ�
		}
	}


	//output file write
	printAll(write); //
	printf("\n");
	fprintf(write, "\n");

	//print name and student id
	printf("building a dictionary of words\n");
	printf("20186628 �Ӽ�ȣ\n");
	fprintf(write, "This program is building a dictionary of words and written by �Ӽ�ȣ at 2019 12 09 ~ 2019 12 12 \n");
	fprintf(write, "Student Id Number is 20186628\n");

	//close
	fclose(read);
	fclose(write);

	return 0;
}

char* casedown(char* input) {
	char* result = input;

	//�빮�ڸ� �ҹ��ڷ� ��� �ٲٱ�
	for (int i = 0; i <= strlen(result); ++i)
	{
		result[i] = (char)tolower(result[i]);
	}

	return result;
}

//strcmp(s1, s2)
//s1 == s2 0
//s1 < s2 ���� ������ s1 ���� s2
//s1 > s2 ��� ������ s2 ���� s1



//Null ������ ���� insert
//search �Ͽ� ���� ��� count++;
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
