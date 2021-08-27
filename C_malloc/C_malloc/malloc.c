// ��ǥ : �����Ҵ翡 ���� �����ϰ� ����غ���

#include <stdio.h>
#include <stdlib.h>
/*
int main() {
	int num;
	int* pArr;
	int average = 0;

	printf("��� ������ ������ ���ΰ� : ");
	scanf("%d", &num);

	if (num == 0) return 0;

	pArr = (int*)malloc(sizeof(int) * num);

	if (pArr == NULL) {
		printf("malloc error");
		exit(1);   // �ٷ� ���μ��� ���� -> exit(0) : ��������, exit(1) : �����޽��� ����
	}

	for (int i = 0; i < num; ++i) {
		printf("[%d / %d] ���� �Է� : ", i + 1, num);
		scanf("%d", &pArr[i]);
	}

	for (int i = 0; i < num; ++i) {
		printf("%d ��° ������ ���� : %d\n", i + 1, pArr[i]);
		average += pArr[i];
	}

	average /= num;
	printf("��� : %d\n", average);

	free(pArr);
	system("pause");
	return 0;  // �� ������ �����ϸ� ���μ��� ����
}
*/

////////////////////////////////////////////////////////////
// malloc
// : �����͸� ���� ���� = (�ڷ���)malloc(�Ҵ���� ����Ʈ ��)
/*
int main() {
	int size, i;
	scanf("%d", &size);
	int* arr = (int*)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) printf("arr[%d]=%d", i, arr[i]);  // �����Ⱚ ��µ�

	printf("\n");

	for (i = 0; i < size; i++) scanf("%d", &arr[i]);

	for (i = 0; i < size; i++) printf("arr[%d] = %d\n", i, arr[i]);

	free(arr);

	return 0;
}*/

// calloc
// : mallocó�� �޸𸮸� �������� ���� �Ҵ��� �� 0���� ���� �ʱ�ȭ��Ŵ
/*
int main() {
	int n, i;
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	printf("calloc 0���� �ʱ�ȭ\n");

	for (i = 0; i < n; i++) printf("arr[%d]=%d", i, arr[i]);

	printf("\n");

	for (i = 0; i < n; i++) scanf("%d", &arr[i]);

	for (i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);

	free(arr);
}
*/

// realloc
// : �Ҵ�� �޸𸮸� �ٽ� �Ҵ��� �� ���
/*
int main() {
	int n, m, i;

	printf("ó�� ũ�� �Է�\n");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);

	printf("�ٽ� �Ҵ�� ũ�� �Է�\n");
	scanf("%d", &m);

	arr = (int*)realloc(arr, sizeof(int) * m);

	for (i = 0; i < m; i++) scanf("%d", &arr[i]);
	for (i = 0; i < m; i++) printf("arr[%d] = %d\n", i, arr[i]);
	free(arr);

	return 0;
}*/

// 2���� �迭
// : 1���� �迭�� �޸𸮸� ���� ���� �Ҵ��� �� 1���� �迭 ���� �޸𸮸� �Ҵ��ϸ� ��
// : ������ ���� �������迭 �޸𸮸� �����ϰ�, ���� 2���� �迭 �޸𸮸� �����ϸ� ��

int main() {
	int n, m, i;
	int** arr;
	scanf("%d %d", &n, &m);  // n: ��, m: ��

	arr = (int**)malloc(sizeof(int*) * n);

	for (i = 0; i < n; i++) arr[i] = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	printf("\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);

	for (i = 0; i < n; i++) free(arr[i]);
	free(arr);
}