#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char str1[] = "abc";
char str2[] = "xyz";

void function1(char* ptr) {
    printf("\tfunction1() - START\n");
    printf("\tptr = %s\n", ptr);

    char str3[] = "def";
    strcpy_s(ptr, 4, str3);

    printf("\tptr = %s\n", ptr);
    printf("\tfunction1() - END\n");
}

void function2(char* ptr) {
    printf("\tfunction2() - START\n");
    printf("\tptr = %s\n", ptr);

    ptr = &str2;

    printf("\tptr = %s\n", ptr);
    printf("\tfunction2() - END\n");
}

int main(int argc, char** argv) {    
    printf("main() - START\n");

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    // Uncomment one of the two blocks of code

    /*
    char* ptr = &str1;
    function1(ptr);
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
     */

    /*
    char* ptr = &str1;
    printf("ptr = %s\n", ptr);
    function2(ptr);
    printf("ptr = %s\n", ptr);
    */
     
    printf("main() - END\n");
    return 0;
}
