// ��ǥ : ���������Ϳ� ���� ���ؿ� ���
// ���뵵 : 2���� �迭�̳� ������ �� ��ü�� �ٷ�� �� �� ���

#include <stdio.h>

// Part1 : ���������� ���� ����
/*int main() {
	int* numPtr1;         // ���� ������ ����
	int** numPtr2;        // ���� ������ ����
	int num1 = 10;

	numPtr1 = &num1;      // num1�� �޸� �ּ� ����
	numPtr2 = &numPtr1;   // numPtr1�� �޸� �ּ� ����

	printf("%d\n", **numPtr2); // �����͸� �� �� �������Ͽ� num1�� �޸� �ּҿ� ��� ���� ���
							   // (numPtr2 -> numPtr1 -> num1)

	return 0;
}*/

// Part2 : 2���� �迭�� ���� ����
// -> ������ ���������͸� ����ϴ� �� ���� [] �����ڸ� ����ϴ� ���� ���ü��� �� ����
/*
void Print2D(int** ptr) {
	for (int i = 0; i < 3; i++) {
		int* ptr_temp = (ptr + i * 3);   // ���α��̰� 3�̶� 
		for (int j = 0; j < 3; j++) {
			printf("%d\n", *ptr_temp + j);
		}
	}
}
int main() {
	int arr[3][3] = {
					{1,2,3},
					{4,5,6},
					{7,8,9} 
	};
	Print2D(arr);
}*/

// Part3 : ������ ��ü�� �ٷ�� ����
void MemoryAlloc(int** ptr) {
	*ptr = malloc(sizeof(int));
	**ptr = 100;
}
int main() {
	int num = 10;
	int* ptr = &num;
	printf("ptr ������ �ִ� �� : %p \t �����ϰ� �ִ� �� : %d\n", ptr, *ptr);
	MemoryAlloc(&ptr);
	printf("ptr ������ �ִ� �� : %p \t �����ϰ� �ִ� �� : %d\n", ptr, *ptr);
	free(ptr);
}

// 2���� �迭�� �Լ��� ���ڷ� �����ϴ� �ΰ��� ���
// void Func(int(*parr1)[7]){...}
// void Func(int parr1[]){...}