#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

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
                    op[index] = (int) token[1] - '0';
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
}

void read_stdin(float ** numbers, int *** operations, int * size_numbers, int * size_operations ){

    //read the first line to know how many numbers and operations we will read
    // int size_numbers, size_operations;
    scanf("%d", size_numbers);
    scanf("%d", size_operations);

    printf("size_numbers: %d\n", *size_numbers);
    printf("size_operations: %d\n", *size_operations);

    //a wild getchat to give us time
    getchar();

    *numbers = malloc(sizeof(float) * (*size_numbers));
    *operations = malloc(sizeof(float) * (*size_operations));

    //read all the numbers
    for(int i=0; i< *size_numbers; i++){
        (*numbers)[i] = read_float();
        printf("(*numbers)[%i]: %f\n", i, (*numbers)[i]);
    }

    //read all the operations
    for(int i=0; i< *size_operations; i++){
        (*operations)[i] = malloc(sizeof(int) * 4);
        (*operations)[i] = read_operation();
        for(int j=0; j< 4; j++){
            printf("read_stdin - (*operations)[%i]: %i\n", i, (*operations)[i][j]);
        }
    }
}
