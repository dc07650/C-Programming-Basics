#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void numToChar(int num);


int main() {

	printf("Hello World!\n");
	
	numToChar(20170000);

	system("Pause");

	return 0;


}

void numToChar(unsigned int num) {

	int loop;
	int temp[50];
	double digit;

	loop = (int)(log10(num)) + 1;

	for (int i = 0; i < loop; i++) {
		temp[i] = (num % 10);
		num /= 10;

	}

	for (int j = loop - 1; j >= 0; j--) {
		printf("%c", temp[j] + 48);
	}

	printf("\n");


}