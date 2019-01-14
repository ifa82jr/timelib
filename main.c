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
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    printf("Jahr 1999 ist: %i\n", is_leapyear(1999));
    printf("Jahr 2000 ist: %i\n", is_leapyear(2000));
    printf("Jahr 1980 ist: %i\n", is_leapyear(1980));
    printf("Jahr 1400 ist: %i\n", is_leapyear(1400));
    printf("Januar: %i\n", get_days_for_month(1, 1800));
    printf("Februar: %i\n", get_days_for_month(2, 1980));
    printf("Februar: %i\n", get_days_for_month(2, 1979));
    printf("32.12.2000: %i\n", exists_date(32, 12, 2000));
    printf("31.12.2000: %i\n", exists_date(31, 12, 2000));
    printf("14.12.2410: %i\n", exists_date(14, 12, 2410));
    printf("14.12.1200: %i\n", exists_date(14, 12, 1200));
    printf("1.1.2000: %i\n", day_of_the_year(9, 8, 2000));
    printf("4.2.2000: %i\n", day_of_the_year(4, 2, 2000));
    printf("%i\n", get_days_for_month(1, 2000));
    return 0;
}
