#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Our array can be ROWS x COLUMNS in size
#define SIZE 20000
#define ROWS SIZE
#define COLUMNS SIZE

// Declare our array outside of main() so we don't have to worry about stack size
int array[ROWS][COLUMNS];


int main(int argc, char** argv) {

    ULONGLONG dwStartTime = GetTickCount64();
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            array[row][column]++;
        }
    }
    ULONGLONG dwEndTime = GetTickCount64();

    // Save the total ticks-time
    ULONGLONG rowMajorTicks = dwEndTime - dwStartTime;

    dwStartTime = GetTickCount64();
    for (int column = 0; column < COLUMNS; column++) {
        for (int row = 0; row < ROWS; row++) {
            array[row][column]++;
        }
    }
    dwEndTime = GetTickCount64();

    // Sage the total ticks-time
    ULONGLONG columnMajorTicks = dwEndTime - dwStartTime;

    // Output the results
    printf("Row-major:\t%llu ticks\n", rowMajorTicks);
    printf("Column-major:\t%llu ticks\n", columnMajorTicks);

    // Finally, return to OS
    return 0;
}

