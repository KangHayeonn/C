// ��ǥ : �����Ҵ翡 ���� �����ϰ� ����غ���

#include <stdio.h>
#include <stdlib.h>

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