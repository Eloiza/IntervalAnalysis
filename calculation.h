struct Interval{
    Float_t min;
    Float_t max;
};

Float_t min(Float_t num){
    Float_t min = num;

    //case negative number
    if(min.parts.sign){
        min.parts.mantissa++;
    }
    else{
        min.parts.mantissa--;
    }

    return min;
}

Float_t max(Float_t num){
    Float_t max = num;

    //case negative number
    if(max.parts.sign){
        max.parts.mantissa--;
    }else{
        max.parts.mantissa++;
    }

    return max;
}

void calculate_intervals(struct Interval ** inter, Float_t * numbers, int size_numbers){
    int i, j=0;
    for(i=0; i< size_numbers; i++){
        (*inter)[j].min = min(numbers[i]);
        (*inter)[j].max = max(numbers[i]);
        j++;
    }
}

void print_interval(struct Interval interval){
    printf("\t[ %1.8e , %1.8e]", interval.min.f, interval.max.f);
    // printFloat_t(interval.min);

    // printf("\tmax: %.8f", interval.max.f);
    // printFloat_t(interval.max);
}

void print_intervals(struct Interval * inters, int size_inters){
    int i = 0;
    for(i=0; i< size_inters; i++){
        printf("X%i:", (i+1) );
        print_interval(inters[i]);
        printf("\n");
    }
}

void solve_operations(struct Interval ** intervals, struct Operation * operations, int size_operations){
    int i = 0, index = 0;
    Float_t result;
    struct Interval num1, num2;

    for(i=0; i< size_operations; i++){
        num1 = (*intervals)[operations[i].num1];
        num2 = (*intervals)[operations[i].num2];

        //stores the index to store the operation result
        index = operations[i].result_idx;
        printf("solve_operations - operation[%i]: %i\n", i, operations[i].op);
        switch (operations[i].op) {
            //calculate min and max
            case ADD:
                result.f = num1.min.f + num2.min.f;
                printf("ADD RESULT: %1.8e\n", result.f);
                (*intervals)[index].min = result;

                result.f = num1.max.f + num2.max.f;
                (*intervals)[index].max = result;
                break;

            //calculate min and max
            case SUB:
                result.f = num1.min.f - num2.min.f;
                (*intervals)[index].min = min(result);

                result.f = num1.max.f - num2.max.f;
                (*intervals)[index].max = max(result);
                break;

            //calculate min and max
            case DIV:
                result.f = num1.min.f / num2.min.f;
                (*intervals)[index].min =  min(result);

                result.f = num1.max.f / num2.max.f;
                (*intervals)[index].max =  max(result);
                break;

            //calculate min and max
            case MUL:
                result.f = num1.min.f * num2.min.f;
                (*intervals)[index].min = result;

                result.f = num1.max.f * num2.max.f;
                (*intervals)[index].max =  result;
                break;

        }
    }
}
