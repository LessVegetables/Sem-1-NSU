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


//int leapYear = 0;

int daysInMonth(date day)
{
    

    int output, month = day.m;
    output = (day.leapYear) ? 29 : 28;

    switch (month)
    {
    case 1:
        return 31;
    case 2:
        return output;
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

int leap(int year)
{
    // if (year % 4 == 0){
    //     if (year % 100 == 0){
    //         if (year % 400 == 0){
    //             return 1;
    //         }
    //         else{
    //             return 0;
    //         }
    //     }
    //     else{
    //         return 1;
    //     }
    // }
    // else{
    //     return 0;
    // }
    // return 0;

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

    //int d, m, y, days;

    int days;    
    date startDate, endDate;

    // INPUT: D M Y
    scanf("%d%d%d%d", &startDate.d, &startDate.m, &startDate.y, &days);

    // INPUT: DD.MM.YYYY
    // char date[10];
    // for(int i = 0; i < 10; i++)
    // {
    //     scanf("%c", &date[i]);
    // }
    // d = ((int)date[0] - 48) * 10 + date[1] - 48;
    // m = ((int)date[3] - 48) * 10 + date[4] - 48;
    // y = ((int)date[6] - 48) * 1000 + ((int)date[7] - 48) * 100 + ((int)date[8] - 48) * 10 + (int)date[9] - 48;


    // for (int i = 1; i < 13; i++)
    // {
    //     printf("%d:\t%d\n", i, daysInMonth(i));
    // }


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