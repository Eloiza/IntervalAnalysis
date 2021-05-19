struct Interval{
    Float_t min;
    Float_t max;
};

struct Interval find_interval(Float_t num){
    struct Interval interval;

    // num.parts.exponent
    // num.parts.sign

    interval.min = num;
    interval.min.parts.mantissa--;

    interval.max = num;
    interval.max.parts.mantissa++;

    return interval;
}

void print_interval(struct Interval interval){
    printf("min: ");
    printFloat_t(interval.min);

    printf("max: ");
    printFloat_t(interval.max);

}
