// æË¿∫∫πªÁ & ±Ì¿∫∫πªÁ 

#include <stdio.h>
#include <stdlib.h>

int main() {
	struct man {
		int* name;
		int age;
	}man;

	struct man alice, bob;

	alice.name = (int*)malloc(8);
	bob.name = (int*)malloc(8);

	*alice.name = 1;
	alice.age = 23;
	*bob.name = 2;
	bob.age = 22;

	*bob.name = *alice.name;
	alice.name[0] = 100;

	//strcpy(alice.name, "alice2");


	printf("name: %d, age: %d\n", alice.name[0], alice.age);
	printf("name: %d, age: %d\n", bob.name[0], bob.age);
}