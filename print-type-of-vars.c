//This software prints data types, their size and pointer size using a struct

#include <stdio.h>

typedef struct st_variables {
    char name[15];
    long int size;
    long int pointer_size;

} variables;

variables vars[] = {

    {"int", sizeof(int), sizeof(int*)},
    {"short int", sizeof(short int), sizeof(short int*)},
    {"long int", sizeof(long int), sizeof(long int*)},
    {"float", sizeof(float), sizeof(float*)},
    {"char", sizeof(char), sizeof(char*)},
    {"double", sizeof(double), sizeof(double*)},

    {"int[10]", sizeof(int[10]), sizeof(int*[10])},
    {"short int[10]", sizeof(short int[10]), sizeof(short int*[10])},
    {"long int[10]", sizeof(long int[10]), sizeof(long int*[10])},
    {"float[10]", sizeof(float[10]), sizeof(float*[10])},
    {"char[10]", sizeof(char[10]), sizeof(char*[10])},
    {"double[10]", sizeof(double[10]), sizeof(double*[10])}

};

int main(){
    for(int i=0; i<12; i++){
        printf("Type of data: %s | Size: %ld | Pointer size: %ld \n", vars[i].name, vars[i].size, vars[i].pointer_size);
    }
    return 0;
}