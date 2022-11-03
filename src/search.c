#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{

    if (n == 0) // Casse to stop us from going beyond the array
    {
        return false;
    }

    if (n > 0 && a[n - 1] == x)
    {
        return true;
    }

    if (n > 0 && a[n - 1] != x)
    {
        return search(a, n - 1, x);
    }

    // if n>0 && a[n-1] == x
    // if n>0 && a[n-1] != x
    // if n = 0

    // if
}

//  step 1: look through array to find x
//  step