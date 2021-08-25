// 목표 : 포인터(Pointer)에 대한 이해와 사용

#include <stdio.h>

/* // 포인터의 기본 개념
void main() {
	int ival;
	int* iptr;

	ival = 1;
	iptr = &ival; // ival의 주소를 iptr 변수에 넣어줌 
	*iptr = 2;    // 포인터 변수에서 *연산자는 그 주소가 가리키는 내용(값)
	printf("ival = %d \n", ival);
}*/

/*
// ver1
void swapint(int a, int b) { // x,y와 a,b의 변수가 서로 다른 메모리에 잡히게 된다.
	int temp;
	temp = a;
	a = b;
	b = temp; // 따라서 x,y 변수가 아닌 a,b 변수의 값만 교환됨
}

void main() {
	int x, y;
	x = 1;
	y = 2;
	swapint(x, y);
	printf("(x, y) = (%d, %d)\n", x, y);
}
*/

// ver2
void swapint(int *a, int *b) { // x,y 의 메모리 주소를 넘김
	int temp;
	temp = *a;  
	*a = *b;   // *연산자를 이용해 주소가 가리키는 값을 수정
	*b = temp; 
}

void main() {
	int x, y;
	x = 1;
	y = 2;
	swapint(&x, &y);
	printf("(x, y) = (%d, %d)\n", x, y);
}

//////////////////////////////////////////////////////
/*
포인터(Pointer) : 메모리의 주소를 저장하는 변수
int *iptr; : iptr은 int형 자료를 가리키는 주소
*/