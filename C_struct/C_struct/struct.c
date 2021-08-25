// ��ǥ : �پ��� ������� ����ü(struct)�� �����ϰ� ������ ����غ���

#include <stdio.h>
#include <string.h>

// [ struct �⺻ ���� ]
/*
struct Person {           // ����ü ����
	char name[20];        // ������ ����ü ������ Ī��
	int age;
	char address[100];
};//p1;                      // ����ü ���ǿ� ������ ���ÿ� �ϴ� ���

int main() {

	// ����� �ʱ�ȭ�� ���ÿ�
	struct Person p1 = { .name = "���Ͽ�", .age = 26, .address = "����Ư���� �������� ��굿" };
	struct Person p2 = { "���ٿ�", 24, "�ּ��� ����" };

	// struct Person p1;  // ����ü ����
	//strcpy(p1.name, "���Ͽ�"); // ����ü �ʱ�ȭ
	//p1.age = 26;
	//strcpy(p1.address, "����Ư���� �������� ��굿");

	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);
	printf("\n");
	printf("�̸�: %s\n", p2.name);
	printf("����: %d\n", p2.age);
	printf("�ּ�: %s\n", p2.address);

	return 0;
}*/

///////////////////////////////////////////////////////////////

// [ typedef ��� ���� ]
typedef struct _Person {     // ����ü �̸� : _Person
	char name[20];
	int age;
	char address[100];
}Person;                     // ����ü ��Ī : Person

int main() {
	//Person p3;
	struct _Person p3;

	strcpy(p3.name, "���Ͽ�");
	p3.age = 26;
	strcpy(p3.address, "����Ư���� �������� ��굿");

	printf("�̸�: %s\n", p3.name);
	printf("����: %d\n", p3.age);
	printf("�ּ�: %s\n", p3.address);

	return 0;
}

// typedef �ڷ��� ��Ī : ����
// typedef �ڷ���* ��Ī : ����
// ex) typedef int* PMYINT;

// [ �͸� ����ü ]
/*
typedef struct {     // ����ü �̸��� ���� �͸� ����ü
	char name[20];
	int age;
	char address[100];
}Person;                     // ����ü ��Ī : Person
*/