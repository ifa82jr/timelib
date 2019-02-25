/**
 *  Julian Rutsch
 *
 *  A library which contains various functions for the day, months and year calculation
 **/

#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
    int day;
    int month;
    int year;
};

int is_leapyear(struct date d);

int get_days_for_month(int month, int year);

int day_of_the_year(struct date d);

int exists_date(struct date d);

int input_date(struct date *d);

struct date set_date(int day, int month, int year);

#endif // TIMELIB_H_INCLUDED
