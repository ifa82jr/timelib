/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 * Proves if the given year is an leap-year and if the year is not before 1582.
 **/
int is_leapyear(int year)
{
    if (year < 1582) {
        return -1;
    }

    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    return 0;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    printf("Jahr 1999 ist: %i\n", is_leapyear(1999));
    printf("Jahr 2000 ist: %i\n", is_leapyear(2000));
    printf("Jahr 1980 ist: %i\n", is_leapyear(1980));
    printf("Jahr 1980 ist: %i\n", is_leapyear(1400));
    return 0;
}
