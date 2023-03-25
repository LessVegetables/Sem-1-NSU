// Часики
// hw due 22.02.2023

// Задано время. Определить время до ближайшей встречи часовой и минутной стрелки

#include <stdio.h>
// #include <stdbool.h>
// #include <math.h>

// bool match(double hour, double minute)
// {

//     double hp, mp;

//     mp = minute / 60;
//     hp = hour / 12 + (mp * 1/12);

//     printf("%lf\n%lf", hp, mp);

//     if (fabs(hp - mp) - 0.001 < 0){ return 1;} //fuck this precision fuckary
//     else{ return 0;}
// }


int main()
{
    double hour, minute;
    printf("Enter the time:\t");

    scanf("%lf %lf", &hour, &minute);

    if (hour > 11){ hour -= 12;}
    minute += hour * 60;
    if (minute > 719){ minute -= 720;}

    double matched[] = {0.0, (1.0 + 1.0/11.0)*60, (2.0 + 2.0/11.0)*60, (3.0 + 3.0/11.0)*60, (4.0 + 4.0/11.0)*60, (5.0 + 5.0/11.0)*60, (6.0 + 6.0/11.0)*60, (7.0 + 7.0/11.0)*60, (8.0 + 8.0/11.0)*60, (9.0 + 9.0/11.0)*60, (10.0 + 10.0/11.0)*60, 720.0};

    int timeAdded = 0;
    for (int i = 0; i < 13; i++)
    {
        if (matched[i] - minute >= 0)
        {
            timeAdded = matched[i] - minute;
            break;
        }
    }

    // atttemp number one. The one where i did not want to be a little bitch and store the correct values of matched–up arms and instead be a big boi grownup man and calculate the relative positioning of the arms
    // if (hour > 11){ hour -= 12;}

    // double hp, mp;
    // hp = hour / 12;
    // mp = minute / 60;

    // hp = hp + (mp * 1/12);

    // printf("%lf\n%lf", hp, mp);

    // int timeAdded = 0;
    
    // while (!match(hour, minute))
    // {
    //     minute++;
    //     timeAdded++;
    //     if (minute > 59)
    //     {
    //         hour++;
    //         minute = 0;
    //     }
    //     if (hour > 11){ hour = 0;}
    // }

    // i failed
    // precision — is my achilles heel

    if (timeAdded)
    {
        printf("In %d hours %d minutes, the hands will meet up!", timeAdded / 60, timeAdded % 60);
    }
    else
    {
        printf("The hads are already matched up!");
    }
    return 0;
}