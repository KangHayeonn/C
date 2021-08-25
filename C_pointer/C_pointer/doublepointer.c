// 목표 : 이중포인터에 대한 이해와 사용
// 사용용도 : 2차원 배열이나 포인터 그 자체를 다뤄야 할 때 사용

#include <stdio.h>

// Part1 : 이중포인터 간단 예시
/*int main() {
	int* numPtr1;         // 단일 포인터 선언
	int** numPtr2;        // 이중 포인터 선언
	int num1 = 10;

	numPtr1 = &num1;      // num1의 메모리 주소 저장
	numPtr2 = &numPtr1;   // numPtr1의 메모리 주소 저장

	printf("%d\n", **numPtr2); // 포인터를 두 번 역참조하여 num1의 메모리 주소에 담긴 값을 출력
							   // (numPtr2 -> numPtr1 -> num1)

	return 0;
}*/

// Part2 : 2차원 배열에 대한 예제
// -> 하지만 이중포인터를 사용하는 것 보다 [] 연산자를 사용하는 것이 가시성이 더 좋음
/*
void Print2D(int** ptr) {
	for (int i = 0; i < 3; i++) {
		int* ptr_temp = (ptr + i * 3);   // 가로길이가 3이라서 
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

// Part3 : 포인터 자체를 다루는 예제
void MemoryAlloc(int** ptr) {
	*ptr = malloc(sizeof(int));
	**ptr = 100;
}
int main() {
	int num = 10;
	int* ptr = &num;
	printf("ptr 가지고 있는 값 : %p \t 지시하고 있는 값 : %d\n", ptr, *ptr);
	MemoryAlloc(&ptr);
	printf("ptr 가지고 있는 값 : %p \t 지시하고 있는 값 : %d\n", ptr, *ptr);
	free(ptr);
}

// 2차원 배열을 함수의 인자로 전달하는 두가지 방법
// void Func(int(*parr1)[7]){...}
// void Func(int parr1[]){...}