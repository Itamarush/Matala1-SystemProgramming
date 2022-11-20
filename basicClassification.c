#include <stdio.h>

    int isPrime(int a)
    {
        int b;

        for (b = 2; b <= a-1; b++)
        {
            if (a%b == 0)
            {
                return 0;
            }
        }
        return 1;
    }

    int isStrong(int a)  //145
    {
        int x = a;
        int sum = 0;
        int temp = 0;

        while (x>0)
        {
        int factorial = 1;
        temp = x%10;
        x=x/10;
            while (temp>0)
                {
                factorial*=temp;
                temp = temp-1;
                }
        sum+=factorial;   
        }
        if (a == sum)
        {
            return 1;
        }
        return 0;
    }
