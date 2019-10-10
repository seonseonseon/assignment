/*
20186628 �Ӽ�ȣ
C programming for obtaining the powerset of a given set
2019.10.04~2019.10.10
*/

#include <stdio.h>
#include <math.h>	//pow()�� ����ϱ� ����
#include <stdlib.h>	//malloc, calloc �� ����ϱ� ����

//A series of a character for a set
//The maximum number of elements in a given set is 10 argc <= 11
//n choose 0 ��(������ ������ 0), n choose 1��(������ ������ 1), n choose 2��(������ ������ 2) ~~~ n choose n(������ ������ n) ���� �� ���ϸ� 2�� n�� ��
//n choose r �� n!/r!*(n-r)!



int main(int argc, char* argv[]) {
	int num;
	num = argc - 1;	//�� �Էµ� element�� ���� num

	int count; //0001 ~ 2�� n�±����� subset���� �����
	count = (int)pow(2, num);

	//assignment03.exe �ܿ� �ƹ��͵� �Է� ��������
	if (num == 0) {
		printf("[%04d] ", 1);
		printf("��"); 
		printf("\n");
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
		int* eachCol = (int)calloc(count, sizeof(int));	//eachCol �迭�� subsets�迭�� ������ row���� �� ���� char�� ����Ǿ����� ī��Ʈ�ϱ� ����

		for (int i = 0; i < count; i++) {


				if (i == 0) {
					subsets[0][0] = '��';
					eachCol[0] = 1;
				}
				else {
					tmp = i;
					index = 1;
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

			for (int i = 1; i < count; i++) {
				printf("[%04d] ", i + 1);
				for (int j = 0; j < eachCol[i] - 1; j++) {
					printf("%c, ", subsets[i][j]);
				}
				printf("%c\n", subsets[i][eachCol[i] - 1]);

			}
		


	}

	//10�� �Ѱ� �Է�������
	else if (num > 11) {
		printf("\nToo many arguments are entered.\nMaximum number of elements in a given set is 10\n");
	}

	printf("\nHello. This is written by Seon-ho Im (20186628) \n\n");

	return 0;
}
