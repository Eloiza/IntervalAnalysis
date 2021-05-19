#include <stdio.h>
#include "read_stdin.h"
#include "calculation.h"



int main(){
    Float_t * numbers;    //[1.54, 2.2, 3.21]
    struct Operation * operations;
    int size_numbers, size_operations;

    read_stdin(&numbers, &operations, &size_numbers, &size_operations);

    for(int i=0; i<size_numbers; i++){
        printf("main - numbers[%i]: %lf\n", i, numbers[i]);
    }

    print_operations(operations, size_operations);

    struct Interval inter_num1 = find_interval(numbers[0]);
    struct Interval inter_num2 = find_interval(numbers[1]);

    print_interval(inter_num1);
    printf("\n");
    print_interval(inter_num2);

    free(numbers);
    free(operations);

    return 0;
}
