#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Our array can be 100 billion elements in size
#define SIZE 100000000

// Declare our array outside of main() so we don't have to worry about stack size
int array[SIZE];

// Declare the compare function for sorting 
int compareInts(const void* int1, const void* int2) {
    return (*(int*)int1 - *(int*)int2);
}

int main(int argc, char** argv) {
    // Declare the random number gnerator
    srand((unsigned int)time(NULL));
    
    // Initialise the array with values -500 to +500
    for (int i = 0; i < SIZE; i++) {
        array[i] = (rand() % 1000) - 500;
    }
            
    // Calculate the number of positive, negative and zero values in array,
    // and calculate the time to do so
    int positive = 0;
    int negative = 0;
    int zero = 0;
    ULONGLONG dwStartTime = GetTickCount64();
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > 0) positive++;
        else if (array[i] < 0) negative++;
        else zero++;
    }    
    ULONGLONG dwEndTime = GetTickCount64();

    // Save the total ticks-time
    ULONGLONG unsortedTicks = dwEndTime - dwStartTime;

    // Now sort the array...
    printf("Sorting array. Please wait...\n");
    qsort(array, SIZE, sizeof(int), compareInts);
    printf("Sorting complete!\n");

    // And recalculate the positive, negative and zero values in array,
    // and again measure time to do so.
    positive = 0;
    negative = 0;
    zero = 0;
    dwStartTime = GetTickCount64();
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > 0) positive++;
        else if (array[i] < 0) negative++;
        else zero++;
    }
    dwEndTime = GetTickCount64();

    // Sage the total ticks-time
    ULONGLONG sortedTicks = dwEndTime - dwStartTime;
    
    // Output the results
    printf("Unsorted:\t%llu ticks\n", unsortedTicks);
    printf("Sorted:  \t%llu ticks\n", sortedTicks);
        
    // Finally, return to OS
    return 0;
}

