// ��ǥ : ������(Pointer)�� ���� ���ؿ� ���

#include <stdio.h>

/* // �������� �⺻ ����
void main() {
	int ival;
	int* iptr;

	ival = 1;
	iptr = &ival; // ival�� �ּҸ� iptr ������ �־��� 
	*iptr = 2;    // ������ �������� *�����ڴ� �� �ּҰ� ����Ű�� ����(��)
	printf("ival = %d \n", ival);
}*/

/*
// ver1
void swapint(int a, int b) { // x,y�� a,b�� ������ ���� �ٸ� �޸𸮿� ������ �ȴ�.
	int temp;
	temp = a;
	a = b;
	b = temp; // ���� x,y ������ �ƴ� a,b ������ ���� ��ȯ��
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
void swapint(int *a, int *b) { // x,y �� �޸� �ּҸ� �ѱ�
	int temp;
	temp = *a;  
	*a = *b;   // *�����ڸ� �̿��� �ּҰ� ����Ű�� ���� ����
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
������(Pointer) : �޸��� �ּҸ� �����ϴ� ����
int *iptr; : iptr�� int�� �ڷḦ ����Ű�� �ּ�
*/