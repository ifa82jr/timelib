/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *  This function determines the days of a given month in the given year.
 *  The given month needs to be between 1 and 12. Leap-years will be considered.
 **/
int get_days_for_month(int month, int year)
{
    if (month < 1 || month > 12 || year < 1582) {
        return -1;
    }

    int days[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (is_leapyear(year)) {
        days[2] = 29;
    }

    return days[month];
}

/**
 *  Proves if the given year is an leap-year and if the year is not before 1582.
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
    printf("Jahr 1400 ist: %i\n", is_leapyear(1400));
    printf("Januar: %i\n", get_days_for_month(1, 1800));
    printf("Februar: %i\n", get_days_for_month(2, 1980));
    printf("Februar: %i\n", get_days_for_month(2, 1979));
    return 0;
}
