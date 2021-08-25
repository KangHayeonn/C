// 목표 : 포인터(Pointer)를 이용한 배열(Array)의 이해와 사용

#include <stdio.h>

// Part1 : 기본 문법
/*
void main() {
	int x[5] = { 1,2,3,4,5 };
	int* px;
	px = &x[1];

	printf("요소 : %d\n", *px);
	px--; //포인터는 변수이므로 증감/산술 연산자를 이용해 주소를 이동
	printf("요소 : %d\n", *px);
	px = px + 3;
	printf("요소 : %d\n", *px);
}*/

///////////////////////////////////////////////////////////
/*
배열의 인덱스(Index) 표현과 포인터의 옵셋(Offset) 표현은 동일.
** Offset : 어떤 기준 번지에서부터의 상대적인 거리
*/


// 포인터 배열과 배열 포인터의 차이 ( 항상 뒤쪽에 있는게 MainPoint! )

// Part2 : 포인터 배열
/*
포인터 배열 : 포인터들의 배열 ( 배열의 요소가 포인터들로 이루어져 있음)
선언 방법 : char* arr[3]; // 배열 요소의 자료형이 char*(포인터)인 배열
*/
// ver1) 문자열 이용
/*
void main(){
	const char* arr[3];        // 포인터 배열 선언

	arr[0] = "HAYEON";         // arr[0]는 문자열 주소를 가리킴
	arr[1] = "C Programming";
	arr[2] = "Master";

	for (int i = 0; i < 3; i++) {
		printf("arr[%d] -> %s \n", i, arr[i]);
	}
}*/
///////////////////////////////////////////////////////////

// ver2) 동적할당 이용
#include <stdlib.h>
#include <string.h>
/*
void main() {
	char* arr[3];
	char tmp[30];
	int len, i;

	for (i = 0; i < 3; i++) {
		printf("[%d] : ", i);
		scanf("%s", tmp);      // 문자열 입력은 & 안씀
  		len = strlen(tmp) + 1; // 문자열 길이+1 할당 ('\0' 문자 포함)
		printf("[%d] : tmp \t주소 : %d\n", i, &tmp); 

		arr[i] = (char*)malloc(sizeof(char) * len); // 메모리 할당
		printf("[%d] : arr[%d]\t주소 : %d\n\n", i, i, &arr[i]);
		strcpy(arr[i], tmp);
	}

	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("arr[%d] = %s\t주소 : %p\n", i, arr[i], &arr[i]);
	}
	for (i = 0; i < 3; i++) {
		free(arr[i]);
	}
}*/
// 문제점 : arr[0],arr[1],arr[2] 주솟값이 4씩 차이나는 것이 마음에 걸림
// char* arr[] : char형이 아닌 char*형의 배열
// - int* 이든 char* 이든 포인터는 주솟값을 저장하는 4바이트 크기의 데이터 타입
// 32bit로 컴파일 시 : 포인터 변수의 크기 = 4바이트
// 64bit로 컴파일 시 : 포인터 변수의 크기 = 8바이트


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

// Part3 : 배열 포인터
/*
배열 포인터 : 특정 사이즈의 배열만 가리킬 수 있는 하나의 포인터(여러개가 아니라 딱 하나)
-> 특정 사이즈의 배열을 새로운 타입이라고 생각하기
-> 그냥 '하나의 포인터'
선언 방법 : *포인터가 타입 쪽에 붙는게 아니라 변수 이름 쪽에 소괄호 안에 붙게 됨
ex) 타입이름 (*변수이름) [N];
ex) char (*arr)[3];

cf) int* pNum; // int타입을 가리키는 포인터
cf) char (*arr)[3] // char타입의 배열 사이즈[3]의 타입을 가리키는 포인터
*/
int main(void) {
	char(*arr)[3];

	char tmp1[3] = { 'b','l','o' };
	char tmp2[3] = { 'c','k','\0' };
	char tmp3[5] = { 'd','m','a','s','k' }; // 배열의 사이즈가 달라서 가리키기 불가능

	printf("tmp1[3]의 주소 : %p\n", tmp1);
	printf("tmp2[3]의 주소 : %p\n", tmp2);
	printf("tmp3[5]의 주소 : %p\n", tmp3); // 포인터 값이 전달되는 경우는 %p를 사용

	arr = &tmp1;
	printf("arr의 주소 : %p\t 문자열 : ", arr);
	printf("%d", sizeof(*arr));
	for (int i = 0; i < (int)sizeof(*arr); i++) {
		printf("%c", (*arr)[i]);
	}
	printf("\n");
	arr = &tmp2;
	printf("arr의 주소 : %p\t 문자열 : ", arr);
	for (int i = 0; i < (int)sizeof(*arr); i++) {
		printf("%c", (*arr)[i]);
	}
	printf("\n");
	arr = &tmp3;
	printf("arr의 주소 : %p\t 문자열 : ", arr);
	for (int i = 0; i < (int)sizeof(*arr); i++) {
		printf("%c", (*arr)[i]);
	}

	printf("\n\n");
}



// ** 코드 출처 : https://blockdmask.tistory.com/56