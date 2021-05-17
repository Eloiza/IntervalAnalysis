float sum(float * numbers, int ** op){

    return sum;
}

void solve_operations(float * numbers, int ** op, int size_operations){
    int i, idx_1, idx_2, idx_r, operation;

    //[result_idx, idx_1, operation, idx_2]
    for(i=0; i<size_operations; i++){
        idx_1 = op[i][1]; //index first number
        idx_2 = op[i][3]; //index second number
        idx_r = op[i][0] + 1; //index result
        operation = op[i][2]

        switch (operation) {
            case MUL:
            break;

            case ADD:
            break;

            case SUB:
            break;

            case DIV:
            break;
        }

    }
}
