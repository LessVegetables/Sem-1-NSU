#include <stdio.h>
#include <time.h>

typedef struct Date{
    int d, m, y, leapYear;
}date;

int daysInMonth(date day){
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

int leap(int year){
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int days;    
    date startDate, endDate;

    scanf("%d%d%d%d", &startDate.d, &startDate.m, &startDate.y, &days);
    
    clock_t t;
    t = clock();

    endDate.d = startDate.d;
    endDate.m = startDate.m;
    endDate.y = startDate.y;
    
    int maxDays = daysInMonth(endDate);
    endDate.leapYear = leap(endDate.y);

    while (days){
        endDate.d++;
        days--;
        if (endDate.d > maxDays){
            endDate.m++;
            endDate.d = 1;
            if(endDate.m > 12){
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