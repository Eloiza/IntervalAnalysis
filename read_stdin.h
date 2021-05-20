#include <string.h>
#include <stdlib.h>
#include "FloatType.h"

#define BUFFER_SIZE 100

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

struct Operation{
    int num1;   //index first number in operation
    int num2;   //index second number in operation
    int op;     //operation type
    int result_idx; //index to store the operation result
};

struct Operation init_operation(){
    struct Operation new_op;
    new_op.num1 = 0;
    new_op.num2 = 0;
    new_op.op = 0;
    new_op.result_idx = 0;

    return new_op;
};

Float_t read_float(){
    Float_t number;
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
                number.f = atof(token);
            }
            count++;

            token = strtok(NULL, " ");
        }
    }

    return number;
}

int op2int(char op){
    int ret;
    switch (op){
        case '+':
            ret = ADD;
        break;

        case '-':
            ret = SUB;
        break;

        case '/':
            ret = DIV;
        break;

        case '*':
            ret = MUL;
        break;
    }

    return ret;
}

//op = [result_position, index_n1, operation, index_n2]
int * read_operation(){
    int * op = malloc(sizeof(int)*4);
    char buffer[BUFFER_SIZE];
    char * token;
    int index = 0;

    if(fgets(buffer, BUFFER_SIZE, stdin) == NULL){
        printf("Error to catch a line\n");
    }
    else{
        token = strtok(buffer, " ");
        while(token != NULL){
            if(token[0] != '='){
                //case we are reading a number
                if(token[0] == 'x'){
                    op[index] = ((int) token[1] - '0') - 1;
                }
                //we are reading a operation
                else{
                    //transform the operation simbol to an int
                    op[index] = op2int(token[0]);
                }
                index++;
            }

            token = strtok(NULL, " ");
        }

    }
    return op;
};

void print_operations(struct Operation * ops, int size_ops){
    for(int i=0; i< size_ops; i++){
        printf("operation[%i]:\n\tnum1: %i - num2: %i - op: %i - result:%i\n\n", i, ops[i].num1, ops[i].num2, ops[i].op, ops[i].result_idx);
    }
}

void print_numbers(Float_t * numbers, int size_numbers){
    for(int i=0; i < size_numbers; i++){
        printf("numbers[%i]: ",i);
        printFloat_t(numbers[i]);
    }
}

void read_stdin(Float_t ** numbers, struct Operation ** operations, int * size_numbers, int * size_operations ){

    //read the first line to know how many numbers and operations we will read
    // int size_numbers, size_operations;
    scanf("%d", size_numbers);
    scanf("%d", size_operations);

    printf("size_numbers: %d\n", *size_numbers);
    printf("size_operations: %d\n", *size_operations);

    //a wild getchat to give us time
    getchar();

    *numbers = malloc(sizeof(Float_t) * (*size_numbers));
    *operations = malloc(sizeof(struct Operation) * (*size_operations));

    //read all the numbers
    for(int i=0; i< *size_numbers; i++){
        (*numbers)[i] = read_float();
        printf("(*numbers)[%i]: ", i);
        printFloat_t((*numbers)[i]);
    }

    int * op_vector;
    //read all the operations
    for(int i=0; i< *size_operations; i++){
        op_vector = read_operation();

        (*operations)[i] = init_operation();
        (*operations)[i].num1 = op_vector[1];   //stores the index of the 1st number
        (*operations)[i].num2 = op_vector[3];
        (*operations)[i].result_idx = op_vector[0];
        (*operations)[i].op = op_vector[2];
    }
}
