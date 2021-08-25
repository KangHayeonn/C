// 목표 : 동적할당에 대해 이해하고 사용해보기

#include <stdio.h>
#include <stdlib.h>

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