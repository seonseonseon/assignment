/*
20186628 �Ӽ�ȣ
*/

#include <stdio.h>
#include <math.h>	//pow()�� ����ϱ� ����
#include <stdlib.h>	//malloc, calloc, exit �� ����ϱ� ����


int main(int argc, char* argv[]) {
	const char* filename = argv[1];
	FILE *fp;
	fopen_s(&fp, filename, "w");	//fopen�Լ��� ����, 
	//FILE *fp = wfsopen_s(&fp, filename,"w");
	if (fp == NULL) {	//��� NULL ��ȯ��
		printf("can not open file\n");
		exit(1);
	}
	

	int num;
	num = argc - 2;	//�� �Էµ� element�� ���� num

	int count; //0001 ~ 2�� n�±����� subset���� �����
	count = (int)pow(2, num);

	//assignment03.exe �� ~~~.txt �ܿ� �ƹ��͵� �Է� ��������
	if (num == 0) {
		printf("[%04d] ", 1);
		printf("��");
		printf("\n");

		fprintf(fp, "[%04d] ", 1);
		fprintf(fp, "��");
		fprintf(fp, "\n");
	}

	//1��~10���� char���� �� �Է�������
	else if (1 <= num && num <= 10) {

		//power set���� ����� subsets�̶�� ������ �迭 int** subsets
		//row�� 2�� num ��, col�� num �̵��� malloc���� ������ �Ҵ��Ѵ�
		//�ִ� element�� ������ 10���� ���������Ƿ� �̸� �������� �Ҵ��� ���� �־�����
		//2�� 10������ ���ڰ� �� ũ�� ������ �޸� ���� ���̱� ���� ���� �Ҵ��� ����Ͽ���
		char** subsets = (char**)malloc(count * sizeof(char*));
		for (int i = 0; i < count; i++) {
			subsets[i] = (char*)malloc(num * sizeof(char));
		}

		//power set ����
		int tmp, col, index;
		int* eachCol = (int*)calloc(count, sizeof(int));	//eachCol �迭�� subsets�迭�� ������ row���� �� ���� char�� ����Ǿ����� ī��Ʈ�ϱ� ����

		for (int i = 0; i < count; i++) {


			if (i == 0) {
				subsets[0][0] = "��";
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

				//�� element�� ���ϰų� ������ �ʰų� �� �� �ϳ��̹Ƿ�
				//tmp�� Ȧ�� �� ���� �����ϰ� �ƴҶ� tmp /2 index���̱�
			}

		}

		//���
		printf("[%04d] ", 1);
		printf("��");
		printf("\n");

		fprintf(fp, "[%04d] ", 1);
		fprintf(fp, "��");
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

	//10�� �Ѱ� �Է�������
	else if (num > 11) {
		printf("\nToo many arguments are entered.\nMaximum number of elements in a given set is 10\n");
	}

	fclose(fp);
	printf("\nHello. This is written by Seon-ho Im (20186628) \n\n");

	return 0;
}