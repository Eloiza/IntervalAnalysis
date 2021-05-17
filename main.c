#include <stdio.h>
#include "read_stdin.h"

int main(){
    float * numbers;    //[1.54, 2.2, 3.21]
    int ** operations;  //[[0,2,1]] num[op[0][0]]
    int size_numbers, size_operations;

    read_stdin(&numbers, &operations, &size_numbers, &size_operations);

    for(int i=0; i<size_numbers; i++){
        printf("main - numbers[%i]: %f\n", i, numbers[i]);
    }

    for(int i=0; i<size_operations; i++){
        for(int j=0; j<4; j++){
            printf("main - operations[%i][%i]: %i\n", i, j, operations[i][j]);
        }
    }

    free(numbers);
    free(operations);

    return 0;
}
