#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int add(int, int);
int sub(int, int);

int main(int argc, char** argv) {
    int i1 = 10;
    int i2 = 5;

    int (*fun_ptr)(int, int) = &add;

    int x = (*fun_ptr)(i1, i2);

    fun_ptr = &sub;

    int y = (*fun_ptr)(i1, i2);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}
