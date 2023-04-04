// Ханойские Башни
// hw due 01.03.2023
// касьянов. курс программирования на паскале
// все задания на рекурсию (никаких циклов)

// стр 240 номер 6.2.2

#include <stdio.h>

void tow(int n, int s, int e, int m)
{
    if (n == 1)
    {
        printf("Move top disk from %d to %d\n", s, e);
    }
    else
    {
        tow(n - 1, s, m, e);    //relocating the top to the "empty" tower
        tow(1, s, e, m);        // relocating the baseplate to the end goal
        tow(n - 1, m, e, s);    // relocating the top part of the tower from the "empty" to the end goal
    }
}


int main() {

    int n, s, e, m;

    printf("Enter the amount of rings:\t");
    scanf("%d", &n);
    printf("Enter the starting tower:\t");
    scanf("%d", &s);
    printf("Enter the ending tower:\t\t");
    scanf("%d", &e);
    m = 6 - s - e;
    
    //tow(3, 1, 3, 2);
    
    tow(n, s, e, m);

    return 0;
}