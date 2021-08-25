// ��ǥ : ������(Pointer)�� �̿��� �迭(Array)�� ���ؿ� ���

#include <stdio.h>

// Part1 : �⺻ ����
/*
void main() {
	int x[5] = { 1,2,3,4,5 };
	int* px;
	px = &x[1];

	printf("��� : %d\n", *px);
	px--; //�����ʹ� �����̹Ƿ� ����/��� �����ڸ� �̿��� �ּҸ� �̵�
	printf("��� : %d\n", *px);
	px = px + 3;
	printf("��� : %d\n", *px);
}*/

///////////////////////////////////////////////////////////
/*
�迭�� �ε���(Index) ǥ���� �������� �ɼ�(Offset) ǥ���� ����.
** Offset : � ���� �������������� ������� �Ÿ�
*/


// ������ �迭�� �迭 �������� ���� ( �׻� ���ʿ� �ִ°� MainPoint! )

// Part2 : ������ �迭
/*
������ �迭 : �����͵��� �迭 ( �迭�� ��Ұ� �����͵�� �̷���� ����)
���� ��� : char* arr[3]; // �迭 ����� �ڷ����� char*(������)�� �迭
*/
// ver1) ���ڿ� �̿�
/*
void main(){
	const char* arr[3];        // ������ �迭 ����

	arr[0] = "HAYEON";         // arr[0]�� ���ڿ� �ּҸ� ����Ŵ
	arr[1] = "C Programming";
	arr[2] = "Master";

	for (int i = 0; i < 3; i++) {
		printf("arr[%d] -> %s \n", i, arr[i]);
	}
}*/
///////////////////////////////////////////////////////////

// ver2) �����Ҵ� �̿�
#include <stdlib.h>
#include <string.h>
/*
void main() {
	char* arr[3];
	char tmp[30];
	int len, i;

	for (i = 0; i < 3; i++) {
		printf("[%d] : ", i);
		scanf("%s", tmp);      // ���ڿ� �Է��� & �Ⱦ�
  		len = strlen(tmp) + 1; // ���ڿ� ����+1 �Ҵ� ('\0' ���� ����)
		printf("[%d] : tmp \t�ּ� : %d\n", i, &tmp); 

		arr[i] = (char*)malloc(sizeof(char) * len); // �޸� �Ҵ�
		printf("[%d] : arr[%d]\t�ּ� : %d\n\n", i, i, &arr[i]);
		strcpy(arr[i], tmp);
	}

	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("arr[%d] = %s\t�ּ� : %p\n", i, arr[i], &arr[i]);
	}
	for (i = 0; i < 3; i++) {
		free(arr[i]);
	}
}*/
// ������ : arr[0],arr[1],arr[2] �ּڰ��� 4�� ���̳��� ���� ������ �ɸ�
// char* arr[] : char���� �ƴ� char*���� �迭
// - int* �̵� char* �̵� �����ʹ� �ּڰ��� �����ϴ� 4����Ʈ ũ���� ������ Ÿ��
// 32bit�� ������ �� : ������ ������ ũ�� = 4����Ʈ
// 64bit�� ������ �� : ������ ������ ũ�� = 8����Ʈ


/*
int main()
{
	int i;

	char(*p)[3] = (char(*)[3])malloc(3 * 10 * sizeof(char));
	strcpy(p[0], "dogaa");
	strcpy(p[1], "cowaa");
	strcpy(p[2], "cataa");


	for (i = 0; i < 3; i++) {
		puts(p[i]);
		printf("%d", &p[i]);
	}
	free(p);
}*/

// Part3 : �迭 ������
/*
�迭 ������ : Ư�� �������� �迭�� ����ų �� �ִ� �ϳ��� ������(�������� �ƴ϶� �� �ϳ�)
-> Ư�� �������� �迭�� ���ο� Ÿ���̶�� �����ϱ�
-> �׳� '�ϳ��� ������'
���� ��� : *�����Ͱ� Ÿ�� �ʿ� �ٴ°� �ƴ϶� ���� �̸� �ʿ� �Ұ�ȣ �ȿ� �ٰ� ��
ex) Ÿ���̸� (*�����̸�) [N];
ex) char (*arr)[3];

cf) int* pNum; // intŸ���� ����Ű�� ������
cf) char (*arr)[3] // charŸ���� �迭 ������[3]�� Ÿ���� ����Ű�� ������
*/
int main(void) {
	char(*arr)[3];

	char tmp1[3] = { 'b','l','o' };
	char tmp2[3] = { 'c','k','\0' };
	char tmp3[5] = { 'd','m','a','s','k' }; // �迭�� ����� �޶� ����Ű�� �Ұ���

	printf("tmp1[3]�� �ּ� : %p\n", tmp1);
	printf("tmp2[3]�� �ּ� : %p\n", tmp2);
	printf("tmp3[5]�� �ּ� : %p\n", tmp3); // ������ ���� ���޵Ǵ� ���� %p�� ���

	arr = &tmp1;
	printf("arr�� �ּ� : %p\t ���ڿ� : ", arr);
	printf("%d", sizeof(*arr));
	for (int i = 0; i < (int)sizeof(*arr); i++) {
		printf("%c", (*arr)[i]);
	}
	printf("\n");
	arr = &tmp2;
	printf("arr�� �ּ� : %p\t ���ڿ� : ", arr);
	for (int i = 0; i < (int)sizeof(*arr); i++) {
		printf("%c", (*arr)[i]);
	}
	printf("\n");
	arr = &tmp3;
	printf("arr�� �ּ� : %p\t ���ڿ� : ", arr);
	for (int i = 0; i < (int)sizeof(*arr); i++) {
		printf("%c", (*arr)[i]);
	}

	printf("\n\n");
}



// ** �ڵ� ��ó : https://blockdmask.tistory.com/56