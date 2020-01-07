#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE (100000000)
int array[SIZE];

int main(int argc, char** argv) {
	// Check how long it takes to incrememnt when counting up from 0..SIZE-1
	ULONGLONG startTime = GetTickCount64();
	for (int i = 0; i < SIZE; i++) {
		array[i]++;
	}
	ULONGLONG endTime = GetTickCount64();

	// Check how long it takes to decrement when counting down from SIZE-1 to 0
	ULONGLONG fromZero = endTime - startTime;
	startTime = GetTickCount64();
	for (int i = SIZE - 1; i >= 0; i--) {
		array[i]++;
	}
	endTime = GetTickCount64();
	ULONGLONG toZero = endTime - startTime;

	printf("From zero to size: %llu\n", fromZero);
	printf("From size to zero: %llu\n", toZero);

	return 0;
}