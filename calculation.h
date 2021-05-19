struct Interval{
    Float_t min;
    Float_t max;
};

Float_t min(Float_t num){
    Float_t min = num;
    min.parts.mantissa--;

    return min;
}

Float_t max(Float_t num){
    Float_t max = num;
    max.parts.mantissa++;

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
