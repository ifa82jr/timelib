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

    input_date(&d);

    printf("\n%i, %i, %i\n", d.year, d.month, d.day);

    struct date yolo = set_date(5, 5, 1999);

    printf("\n%i, %i, %i\n", yolo.year, yolo.month, yolo.day);

    return 0;
}
