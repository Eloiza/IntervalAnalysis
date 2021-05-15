#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void read_stdin(){
    char line_buffer[BUFFER_SIZE];
    char * token;
    int count = 0;

    //read the first line to know how many numbers and operations we will read
    int size_numbers, size_operations;
    scanf("%d", &size_numbers);
    scanf("%d", &size_operations);

    printf("size_numbers: %d\n", size_numbers);
    printf("size_operations: %d\n", size_operations);

    //a wild getchat to give us time
    getchar();

    //read all the numbers
    for(int i=0; i<size_numbers; i++){
        if(fgets(line_buffer, BUFFER_SIZE, stdin) == NULL){
            printf("Error to catch a line\n");

        }else{
            printf("I read: %s", line_buffer);

            //divide the string
            token = strtok(line_buffer, " ");
            count = 0;
            while(token != NULL){
                if(count){
                    //remove the \n and get a float number
                    token = strtok(token, "\n");
                    printf("str num: %s\n", token);
                    printf("number: %f\n",atof(token));
                }
                count++;
                // printf("token: %s\n", token);
                token = strtok(NULL, " ");
            }
        }
    }
}

int main(){
    // int * numbers, operations;

    read_stdin();
    return 0;
}
