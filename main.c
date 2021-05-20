#include <stdio.h>
#include "read_stdin.h"
#include "calculation.h"



int main(){
    Float_t * numbers;    //[1.54, 2.2, 3.21]
    struct Operation * operations;
    int size_numbers, size_operations;

    read_stdin(&numbers, &operations, &size_numbers, &size_operations);
    // print_operations(operations, size_operations);

    //create a vector to store all the intervals we gonna need
    int size_intervals = size_numbers + size_operations;
    struct Interval * result_intervals = malloc(sizeof(struct Interval) * (size_intervals));

    calculate_intervals(&result_intervals, numbers, size_numbers);
    // print_intervals(result_intervals, size_numbers);
    // printf("\n");

    //calculate the operations with the intervals
    solve_operations(&result_intervals, operations, size_operations);
    print_intervals(result_intervals, size_intervals);

    //free the memory used in the vectors
    free(numbers);
    free(operations);
    free(result_intervals);

    return 0;
}
