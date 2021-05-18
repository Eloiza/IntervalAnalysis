#include <stdio.h>
#include "read_stdin.h"
#include "calculation.h"

int main(){
    float * numbers;    //[1.54, 2.2, 3.21]
    struct Operation * operations;  //[[0,2,1,1]] num[op[0][0]]
    int size_numbers, size_operations;

    read_stdin(&numbers, &operations, &size_numbers, &size_operations);

    for(int i=0; i<size_numbers; i++){
        printf("main - numbers[%i]: %f\n", i, numbers[i]);
    }

    for(int i=0; i<size_operations; i++){
        printf("main - operations[%i]:\n", i);
        printf("num1: %f\n", operations[i].num1);
        printf("num2: %f\n", operations[i].num2);
        printf("result_idx: %i\n", operations[i].result_idx);
        printf("operation: %i\n", operations[i].op);
    }

    free(numbers);
    free(operations);

    return 0;
}
