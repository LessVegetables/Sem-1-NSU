// Даты
// HW due 15.03.2023
// На вход дается дата и количество дней.
// Нужно написать какая дата будет через
// это количество дней (учитывая високосные
// годы). Обязательно использовать
// структуры(struct) и кейсы (switch)

#include <stdio.h>
#include <time.h>

typedef struct Date
{
    int d, m, y, leapYear;
}date;

// returns the number of days in passed month
int daysInMonth(date day)
{
    int February = (day.leapYear) ? 29 : 28;

    switch (day.m)
    {
    case 1:
        return 31;
    case 2:
        return February;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        printf("OUT OF BOUNDS\n");
        break;
    }
    return 0;
}

// returns 1 if leap year, 0 — otherwise
int leap(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
        //printf("%d\tLEAP\n", year);
        return 1;
    }
    else{
        //printf("%d\tNOT\n", year);
        return 0;
    }
}

int main()
{
    clock_t t;
    t = clock();

    int days;    
    date startDate, endDate;

    // INPUT: D M Y
    scanf("%d%d%d%d", &startDate.d, &startDate.m, &startDate.y, &days);

    // INPUT: DD/MM/YYYY
    // char dateInput[10];
    // for(int i = 0; i < 10; i++)
    // {
    //     scanf("%c", &dateInput[i]);
    // }
    // startDate.d = ((int)dateInput[0] - 48) * 10 + dateInput[1] - 48;
    // startDate.m = ((int)dateInput[3] - 48) * 10 + dateInput[4] - 48;
    // startDate.y = ((int)dateInput[6] - 48) * 1000 + ((int)dateInput[7] - 48) * 100 + ((int)dateInput[8] - 48) * 10 + (int)dateInput[9] - 48;
    //
    // scnaf("%d", &days);

    endDate.d = startDate.d;
    endDate.m = startDate.m;
    endDate.y = startDate.y;
    
    int maxDays = daysInMonth(endDate);
    endDate.leapYear = leap(endDate.y);

    while (days)
    {
        endDate.d++;
        days--;
        if (endDate.d > maxDays)
        {
            endDate.m++;
            endDate.d = 1;
            if(endDate.m > 12)
            {
                endDate.y++;
                endDate.m = 1;
                endDate.leapYear = leap(endDate.y);
            }
            maxDays = daysInMonth(endDate);
        }
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("Before:\t%d/%d/%d\n", startDate.d, startDate.m, startDate.y);
    printf("After:\t%d/%d/%d\n", endDate.d, endDate.m, endDate.y);

    printf("\nCompleted in %f seconds\n", time_taken);

    return 0;
}