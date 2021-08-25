// 목표 : 다양한 방식으로 구조체(struct)를 정의하고 선언해 사용해보기

#include <stdio.h>
#include <string.h>

// [ struct 기본 문법 ]
/*
struct Person {           // 구조체 정의
	char name[20];        // 각각을 구조체 멤버라고 칭함
	int age;
	char address[100];
};//p1;                      // 구조체 정의와 선언을 동시에 하는 방법

int main() {

	// 선언과 초기화를 동시에
	struct Person p1 = { .name = "강하연", .age = 26, .address = "서울특별시 영등포구 당산동" };
	struct Person p2 = { "강다연", 24, "주소지 동일" };

	// struct Person p1;  // 구조체 선언
	//strcpy(p1.name, "강하연"); // 구조체 초기화
	//p1.age = 26;
	//strcpy(p1.address, "서울특별시 영등포구 당산동");

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);
	printf("\n");
	printf("이름: %s\n", p2.name);
	printf("나이: %d\n", p2.age);
	printf("주소: %s\n", p2.address);

	return 0;
}*/

///////////////////////////////////////////////////////////////

// [ typedef 사용 문법 ]
typedef struct _Person {     // 구조체 이름 : _Person
	char name[20];
	int age;
	char address[100];
}Person;                     // 구조체 별칭 : Person

int main() {
	//Person p3;
	struct _Person p3;

	strcpy(p3.name, "강하연");
	p3.age = 26;
	strcpy(p3.address, "서울특별시 영등포구 당산동");

	printf("이름: %s\n", p3.name);
	printf("나이: %d\n", p3.age);
	printf("주소: %s\n", p3.address);

	return 0;
}

// typedef 자료형 별칭 : 가능
// typedef 자료형* 별칭 : 가능
// ex) typedef int* PMYINT;

// [ 익명 구조체 ]
/*
typedef struct {     // 구조체 이름이 없는 익명 구조체
	char name[20];
	int age;
	char address[100];
}Person;                     // 구조체 별칭 : Person
*/