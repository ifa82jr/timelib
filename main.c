/**
 *  Julian Rutsch
 *
 *  A library which contains various functions for the day, months and year calculation
 **/

#include <stdio.h>
#include <stdlib.h>

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
 *  This function returns the day of the year. Leap-years will be considered.
 *  If the given date is not correct, -1 will be returned.
 **/
int day_of_the_year(int day, int month, int year)
{
    if (!exists_date(day, month, year)) {
        return -1;
    }

    int day_of_the_year = 0, i;

    for (i = 1; i < month; i++) {
        day_of_the_year = day_of_the_year + get_days_for_month(i, year);
    }

    day_of_the_year = day_of_the_year + day;

    return day_of_the_year;
}

/**
 *  This function proves if the given date is valid. The year limits are 1582 - 2400.
 **/
int exists_date(int day, int month, int year)
{
    if (year < 1582 || year > 2400 || month < 1 || month > 12 || day < 1 || day > get_days_for_month(month, year)) {
        return 0;
    }

    return 1;
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
    printf("32.12.2000: %i\n", exists_date(32, 12, 2000));
    printf("31.12.2000: %i\n", exists_date(31, 12, 2000));
    printf("14.12.2410: %i\n", exists_date(14, 12, 2410));
    printf("14.12.1200: %i\n", exists_date(14, 12, 1200));
    printf("1.1.2000: %i\n", day_of_the_year(1, 1, 2000));
    printf("4.2.2000: %i\n", day_of_the_year(4, 2, 2000));
    printf("%i\n", get_days_for_month(1, 2000));
    return 0;
}
