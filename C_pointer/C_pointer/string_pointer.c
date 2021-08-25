// 목표 : 상수 형태의 문자열을 가리키는 포인터에 대해 이해하고 사용

// 동적할당 사용 시 : 읽기/쓰기 전용
// 동적할당 사용 x  : 읽기 전용

#include <stdio.h>
int main() {
	char str1[] = "My String";
	char* str = "Your String";

	printf("%s %s\n", str1, str);

	str = "string";
	printf("%s\n", str);

	str1[0] = 'x';    // 가능
	// str[0] = 'x';     // 불가능
	printf("%s %s\n", str1, str);
	return 0;
}

// 배열을 통한 문자열 선언 : 변수 형태의 문자열 (문자문자마다 변경 가능)
// 포인터를 통한 문자열 선언 : 상수 형태의 문자열 (각각의 요소에는 접근 불가능, 아예 대상을 바꾸는 건 가능)
// 상수 형태의 문자열 -> '읽기전용'
