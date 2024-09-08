/* This software has lines that only execute if you compile with debug option 
/* "cc -o main_debug -DDEBUG main.c" 
*/

#include <stdio.h>

int main(){

#ifdef DEBUG

    printf("Compiled: "__DATE__" at "__TIME__" \n");
    printf("This is line %d of file %s\n", __LINE__, __FILE__);

#endif  

    printf("Hello World!\n");
    return 0;
}