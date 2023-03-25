// Даты
// HW due 15.03.2023
// На вход дается дата и количество дней.
// Нужно написать какая дата будет через
// это количество дней (учитывая високосные
// годы). Обязательно использовать
// структуры(struct) и кейсы (switch)

// this version does not utilize struct

#include <stdio.h>
#include <time.h>


int leapYear = 0;

int daysInMonth(month)
{
    int output;
    output = (leapYear) ? 29 : 28;

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

    int d, m, y, days;

    // INPUT: D M Y
    scanf("%d%d%d%d", &d, &m, &y, &days);

    // INPUT: DD.MM.YYYY
    // char date[10];
    // for(int i = 0; i < 10; i++)
    // {
    //     scanf("%c", &date[i]);
    // }
    // d = ((int)date[0] - 48) * 10 + date[1] - 48;
    // m = ((int)date[3] - 48) * 10 + date[4] - 48;
    // y = ((int)date[6] - 48) * 1000 + ((int)date[7] - 48) * 100 + ((int)date[8] - 48) * 10 + (int)date[9] - 48;

    printf("Before:\t%d/%d/%d\n", d, m, y);
    
    int maxDays = daysInMonth(m);
    leapYear = leap(y);

    while (days)
    {
        d++;
        days--;
        if (d > maxDays)
        {
            m++;
            d = 1;
            if(m > 12)
            {
                y++;
                m = 1;
                leapYear = leap(y);
            }
            maxDays = daysInMonth(m);
        }
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("After:\t%d/%d/%d\n", d, m, y);

    printf("\nCompleted in %f seconds\n", time_taken);

    return 0;
}