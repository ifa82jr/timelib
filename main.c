/**
 *  Julian Rutsch
 *
 *  Some tests for the timelib.h
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    struct date d;

    input_date(d);

    printf("%i, %i, %i\n", d.year, d.month, d.day);

    return 0;
}
