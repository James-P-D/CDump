#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TIME_SIZE (100000000)
ULONG time_array1[TIME_SIZE];
ULONG time_array2[TIME_SIZE];

int main(int argc, char** argv) {

	//https://embeddedgurus.com/stack-overflow/2011/02/efficient-c-tip-13-use-the-modulus-operator-with-caution/
	// Lets say current time is 12:34:56 (hh:mm:ss)
	ULONG currentTime = (12 * 60UL * 60UL) + (34 * 60UL) + 56;
	for (int i = 0; i < TIME_SIZE; i++) {
		time_array1[i] = currentTime;
		time_array2[i] = currentTime;
	}

	ULONGLONG startTime = GetTickCount64();
	for (int i = 0; i < TIME_SIZE; i++) {
		ULONG currentSeconds = time_array1[i] % 60UL;
		time_array1[i] /= 60UL;
		ULONG currentMinutes = time_array1[i] % 60UL;
		time_array1[i] /= 60UL;
		ULONG currentHours = time_array1[i];
	}
	ULONGLONG endTime = GetTickCount64();
	ULONGLONG withModulus = endTime - startTime;

	startTime = GetTickCount64();
	for (int i = 0; i < TIME_SIZE; i++) {
		ULONG currentHours = time_array2[i] / (60UL * 60UL);
		time_array2[i] -= currentHours * (60UL * 60UL);
		ULONG currentMinutes = time_array2[i] / 60UL;
		time_array2[i] -= currentMinutes * 60UL;
		ULONG currentSeconds = time_array2[i];
	}
	endTime = GetTickCount64();
	ULONGLONG withoutModulus = endTime - startTime;

	printf("With modulus:    %llu\n", withModulus);
	printf("Without modulus: %llu\n", withoutModulus);

	return 0;
}