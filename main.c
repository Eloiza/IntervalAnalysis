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

    print_operations(operations, size_operations);

    free(numbers);
    free(operations);

    return 0;
}
