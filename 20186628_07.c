// build a dictionary of words from a given text file and count number of words, and save the results as a text file
// 20186628 임선호

#include <stdio.h>
#include <stdlib.h>

//binary search tree
typedef struct nodeStruct
{
	char* value;
	int count;
	struct NodeStruct* leftChild;
	struct NodeStruct* rightChild;
}Node;

Node* root = NULL;

char* casedown(char* input);
Node* insert(Node* root, char* value);
Node* search(Node* root, char* value);
void printAll(Node* root);

// argv[0] input.txt
// argv[1] output.txt
int main(int argc, char* argv[]) {
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
	char* temp[100000]; //1116092개 정도의 토큰이 있는 듯
	const char delimiters[] = ", !.?\'\"#*-_=[]():\n~^{}><@/&$%`;|\\";	//'s 를 포함할까
	//fgets(str, sizeof(str), read);
	while(fgets(str, sizeof(str), read) != NULL){
		char *token = strtok(str, delimiters);

		while (token != NULL)
		{
			//대소문자 변경
			token = casedown(token);

			printf("%d: [%s]\n", ++toknum, token); //

			//이미 있는지 체크하여 token을 저장하거나 count++
			Node* tempNode = search(root, token);
			if (tempNode == NULL) {
				insert(root, token);
			}
			else {
				tempNode->count++;
			}

			//token을 저장 
			//temp[toknum] = token;

			token = strtok(NULL, delimiters);
			//NULL을 넣으면 방금전에 분리한 문자열의 남은 문자열을 가지고 다시
		}

	}


	


	//output file write
	//static int count = 0;
	//printf("[%03d] ", count);
	//fprintf(write, "[%03d] ", count);
	//count++;

	printAll(root);

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

Node* insert(Node* root, char* value)
{
	if (root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->value = value;
		root->count = 0;
		return root;
	}
	else
	{
		if (strcmp(root->value, value) > 0) //
			root->leftChild = insert(root->leftChild, value);

		else
			root->rightChild = insert(root->rightChild, value);
	}


	return root;
}





Node* search(Node* root, char* value)
{
	if (root == NULL)
		return NULL;

	if (strcmp(root->value, value) == 0) //
		return root;
	else if (strcmp(root->value, value) > 0) //
		return search(root->leftChild, value);
	else
		return search(root->rightChild, value);
}
//Null 나오면 새로 insert
//search 하여 나온 노드 count++;


void printAll(Node* root)
{
	if (root == NULL)
		return;

	printf("%s  (%d)\n", root->value, root->count);
	fprintf("%s  (%d)\n", root->value, root->count);
	printAll(root->leftChild);
	printAll(root->rightChild);
}

/*
for (int i = 0; i < strlen(result); i++) {
char ch = result;
if ('A' <= ch && ch <= 'Z') {
ch = ch + 32;
}
}*/