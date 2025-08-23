#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main()
{
    while(1)
    {
        greetingScreean();
        int wybor;

        scanf("%d", &wybor);
        system("clear");

        choose(wybor);
    }
    return 0;
}