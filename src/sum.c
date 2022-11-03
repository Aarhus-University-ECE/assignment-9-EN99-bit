#include "sum.h"

int sum(int a[], int n) //sum function
{
    if (n == 0)
    {
        return 0; // if n == 0, return  0
                  // if n>0 return the sum
    }

    if (n > 0)
    {
        return sum(a, n - 1) + a[n - 1];
    }
}