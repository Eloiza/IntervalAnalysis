struct Interval{
    Float_t min;   //interval min
    Float_t max;   //interval max
    int uni;   //bool to check if is unitary interval
};

Float_t min(Float_t num){
    Float_t min = num;
    if(min.parts.sign){
        // min.parts.mantissa++;
        min.i++;
    }
    else{
        // printf("MIN Antes:\n");
        // printFloat_t(min);
        // printf("Mantissa: %i\n", min.parts.mantissa);
        // min.parts.mantissa--;

        min.i--;
        // printf("MIN Depois:\n");
        // printFloat_t(min);
        // printf("Mantissa: %i\n", min.parts.mantissa);

    }

    return min;
}

Float_t max(Float_t num){
    Float_t max = num;
    if(max.parts.sign){
        // max.parts.mantissa--;
        max.i--;
    }
    else{
        // printf("MAX Antes:\n");
        // printFloat_t(max);

        // max.parts.mantissa++;
        max.i++;
        // printf("MAX Depois:\n");
        // printFloat_t(max);

    }

    return max;
}

void calculate_intervals(struct Interval ** inter, Float_t * numbers, int size_numbers){
    int i, j=0;
    for(i=0; i< size_numbers; i++){
        (*inter)[j].min = min(numbers[i]);
        // printf("numbers[%i]: %f\n",i,numbers[i].f);
        //check if the number calculated is Nan
        if(isnan((*inter)[j].min.f)){
            // printf("Min is nan for: %f\n", numbers[i].f);
            (*inter)[j].min = numbers[i];
        }

        (*inter)[j].max = max(numbers[i]);

        if(isnan((*inter)[j].max.f)){
            // printf("Max is nan for: %f\n", numbers[i].f);
            (*inter)[j].max = numbers[i];
        }

        j++;
    }
}

void print_interval(struct Interval interval){
    printf("[ \t %1.8e,\t %1.8e]", interval.min.f, interval.max.f);
    // printFloat_t(interval.min);

    // printf("\tmax: %.8f", interval.max.f);
    // printFloat_t(interval.max);
}

void print_intervals(struct Interval * inters, int size_inters){
    int i = 0;
    for(i=0; i< size_inters; i++){
        printf("X%i = ", (i+1) );
        print_interval(inters[i]);
        printf("\n");
    }
}

void print_non_unitary(struct Interval * inters, int size_inters, int size_operations){
    printf("Não unitários:\n");
    int i;
    int start = (size_inters - size_operations);
    for(i = start; i<size_inters; i++){
        if(!inters[i].uni){
            printf("X%i = ", (i+1) );
            print_interval(inters[i]);
            printf("\n");
        }
    }
}

//check if a interval is unitary
//a interval is unitary if both numbers are the same
int is_unitary(struct Interval inter){
    //check if the numbers are equal
    if(AlmostEqualRelative(inter.min, inter.max)){
        return 1;
    }

    return 0;
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
        switch (operations[i].op) {
            //calculate min and max
            case ADD:
                result.f = num1.min.f + num2.min.f;
                (*intervals)[index].min = min(result);

                result.f = num1.max.f + num2.max.f;
                (*intervals)[index].max = max(result);

                //check if the interval is unitary
                (*intervals)[index].uni = is_unitary((*intervals)[index]);
                break;

            //calculate min and max
            case SUB:
                result.f = num1.min.f - num2.min.f;
                (*intervals)[index].min = min(result);

                result.f = num1.max.f - num2.max.f;
                (*intervals)[index].max = max(result);

                //check if the interval is unitary
                (*intervals)[index].uni = is_unitary((*intervals)[index]);
                break;

            //calculate min and max
            case DIV:
                result.f = num1.min.f / num2.min.f;
                (*intervals)[index].min =  min(result);

                result.f = num1.max.f / num2.max.f;
                (*intervals)[index].max =  max(result);

                //check if the interval is unitary
                (*intervals)[index].uni = is_unitary((*intervals)[index]);
                break;

            //calculate min and max
            case MUL:
                result.f = num1.min.f * num2.min.f;
                (*intervals)[index].min = min(result);

                result.f = num1.max.f * num2.max.f;
                (*intervals)[index].max =  max(result);

                //check if the interval is unitary
                (*intervals)[index].uni = is_unitary((*intervals)[index]);
                break;

        } //end switch
    }
}
