#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4


// int * read_operation(){
// [operation, index1, index2]
// };

float read_float(){
    float number;
    int count;
    char * token;
    char buffer[BUFFER_SIZE];

    if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
        printf("Error to catch a line\n");

    }else{
        //split the string
        token = strtok(buffer, " ");
        count = 0;
        while(token != NULL){
            if(count){
                //remove the \n and get a float number
                token = strtok(token, "\n");
                number = atof(token);
            }
            count++;

            token = strtok(NULL, " ");
        }
    }

    return number;
}
void read_stdin(float ** numbers, float ** operations){
    char line_buffer[BUFFER_SIZE];

    //read the first line to know how many numbers and operations we will read
    int size_numbers, size_operations;
    scanf("%d", &size_numbers);
    scanf("%d", &size_operations);

    printf("size_numbers: %d\n", size_numbers);
    printf("size_operations: %d\n", size_operations);

    //a wild getchat to give us time
    getchar();

    *numbers = malloc(sizeof(float) * size_numbers);
    *operations = malloc(sizeof(float) * size_operations);

    //read all the numbers
    for(int i=0; i<size_numbers; i++){
        (*numbers)[i] = read_float();
        printf("%f\n", *numbers[i]);
    }

    // for(int i=0; i<size_operations; i++){
    //     (*operations)[i] = read_operation();
    // }
}

int main(){
    float * numbers, * operations;

    read_stdin(&numbers, &operations);

    free(numbers);
    free(operations);

    return 0;
}
