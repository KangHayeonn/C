// 목표 : 동적할당에 대해 이해하고 사용해보기

#include <stdio.h>
#include <stdlib.h>
/*
int main() {
	int num;
	int* pArr;
	int average = 0;

	printf("몇개의 과목을 저장할 것인가 : ");
	scanf("%d", &num);

	if (num == 0) return 0;

	pArr = (int*)malloc(sizeof(int) * num);

	if (pArr == NULL) {
		printf("malloc error");
		exit(1);   // 바로 프로세스 종료 -> exit(0) : 정상종료, exit(1) : 에러메시지 종료
	}

	for (int i = 0; i < num; ++i) {
		printf("[%d / %d] 점수 입력 : ", i + 1, num);
		scanf("%d", &pArr[i]);
	}

	for (int i = 0; i < num; ++i) {
		printf("%d 번째 과목의 점수 : %d\n", i + 1, pArr[i]);
		average += pArr[i];
	}

	average /= num;
	printf("평균 : %d\n", average);

	free(pArr);
	system("pause");
	return 0;  // 뒤 문장을 실행하면 프로세스 종료
}
*/

////////////////////////////////////////////////////////////
// malloc
// : 포인터를 받을 변수 = (자료형)malloc(할당받을 바이트 수)
/*
int main() {
	int size, i;
	scanf("%d", &size);
	int* arr = (int*)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) printf("arr[%d]=%d", i, arr[i]);  // 쓰레기값 출력됨

	printf("\n");

	for (i = 0; i < size; i++) scanf("%d", &arr[i]);

	for (i = 0; i < size; i++) printf("arr[%d] = %d\n", i, arr[i]);

	free(arr);

	return 0;
}*/

// calloc
// : malloc처럼 메모리를 힙영역에 동적 할당한 후 0으로 전부 초기화시킴
/*
int main() {
	int n, i;
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	printf("calloc 0으로 초기화\n");

	for (i = 0; i < n; i++) printf("arr[%d]=%d", i, arr[i]);

	printf("\n");

	for (i = 0; i < n; i++) scanf("%d", &arr[i]);

	for (i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);

	free(arr);
}
*/

// realloc
// : 할당된 메모리를 다시 할당할 때 사용
/*
int main() {
	int n, m, i;

	printf("처음 크기 입력\n");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);

	printf("다시 할당된 크기 입력\n");
	scanf("%d", &m);

	arr = (int*)realloc(arr, sizeof(int) * m);

	for (i = 0; i < m; i++) scanf("%d", &arr[i]);
	for (i = 0; i < m; i++) printf("arr[%d] = %d\n", i, arr[i]);
	free(arr);

	return 0;
}*/

// 2차원 배열
// : 1차원 배열의 메모리를 힙에 먼저 할당한 후 1차원 배열 각각 메모리를 할당하면 됨
// : 해제할 때도 일차원배열 메모리를 해제하고, 이후 2차원 배열 메모리를 해제하면 됨

int main() {
	int n, m, i;
	int** arr;
	scanf("%d %d", &n, &m);  // n: 행, m: 열

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