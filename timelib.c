/**
 *  Julian Rutsch
 *
 *  A library which contains various functions for the day, months and year calculation
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/**
 *  Proves if the given year is an leap-year and if the year is not before 1582.
 *
 *  @param d the given date with d.year as the given year
 *
 *  @return returns 1 if the given year is a leap_year, 0 if it is no leap_year and -1 if the year is invalid
 **/
int is_leapyear(struct date d)
{
    if (d.year < 1582) {
        return -1;
    }

    return (d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0);
}

/**
 *  This function determines the amount of days of a given month in the given year.
 *  The given month needs to be between 1 and 12. Leap-years will be considered.
 *
 *  @param month the month for which you want to know the number of days
 *  @param year the year in which the requested month is
 *
 *  @return the number of days if the month and year is valid and 0 if the month or year is invalid
 **/
int get_days_for_month(int month, int year)
{
    if (month < 1 || month > 12 || year < 1582) {
        return -1;
    }

    int days[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    struct date d;
    d.month = month;
    d.year  = year;

    if (is_leapyear(d)) {
        days[2] = 29;
    }

    return days[month];
}

/**
 *  This function proves if the given date is valid. The year limits are 1582 - 2400.
 *
 *  @param d the given date with d.day, d.month and d.year
 *
 *  @return returns 0 if the date does not exist and 1 if it exists
 **/
int exists_date(struct date d)
{
    if (d.year < 1582 || d.year > 2400 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > get_days_for_month(d.month, d.year)) {
        return 0;
    }

    return 1;
}

/**
 *  This function returns the day of the year. Leap-years will be considered.
 *  If the given date is not correct, -1 will be returned.
 *
 *  @param d the given date with d.day, d.month and d.year
 *
 *  @return returns the day of the year
 **/
int day_of_the_year(struct date d)
{
    if (!exists_date(d)) {
        return -1;
    }

    int day_of_the_year = 0, i;

    for (i = 1; i < d.month; i++) {
        day_of_the_year = day_of_the_year + get_days_for_month(i, d.year);
    }

    day_of_the_year = day_of_the_year + d.day;

    return day_of_the_year;
}

/**
 *  This function reads in 3 integer values ​​for day, month, and year.
 *  If the read-in date is invalid, it is read in until a valid date has been entered.
 *
 *  @param d the given date with d.day, d.month and d.year
 *
 *  @return 0
 **/
int input_date(struct date d)
{
    int not_invalid;

    do {
        not_invalid = 1;

        printf("\nBitte geben Sie den Tag ihres Datums ein: ");
        scanf("%i", &d.day);
        printf("\nBitte geben Sie den Monat ihres Datums ein: ");
        scanf("%i", &d.month);
        printf("\nBitte geben sie das Jahr ihres Datums ein: ");
        scanf("%i", &d.year);

        if (exists_date(d) == 0) {
            not_invalid = 0;
            printf("\n\nUngueltiges Datum! Bitte erneut eingeben!\n\n");
        }
    } while (not_invalid == 0);

    return 0;
}

/**
 *  This function creates a date out of day, month and year.
 *
 *  @param *day memory address of the day
 *  @param *month memory address of the month
 *  @param *year memory address of the year
 *
 *  @return 0
 **/
struct date set_date(int day, int month, int year)
{
    struct date d;

    d.day   = day;
    d.month = month;
    d.year  = year;

    return d;
}
