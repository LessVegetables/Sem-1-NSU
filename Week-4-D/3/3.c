#include <stdio.h>

//проблема Гольдбаха (гипотеза гольдбаха)

// проверка на то, простое ли число yя
bool simple(int x, int y)
{
    if (x == y)
    {
        return true;
    }
    else
    {
        return ((y % x != 0) && simple(x + 1, y));
    }
}



int main()
{
    f();
    return 0;
}