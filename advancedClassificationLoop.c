#include <stdio.h>
#include <math.h>

    int isPalindrome(int a)
    {   
        int r = 0;
        int x = 0;
        int num = a;

        while (a != 0) {
            x = a % 10;
            r = r * 10 + x;
            a /= 10;
        }

        if (num == r)
        {
            return 1;
        }
        return 0;
        
    }

    int powi(int base, int exp);
    int isArmstrong(int a) 
    {
        int length = 0;
        int num = a;
        int sum = 0;
        int x;
        while (num>0)
        {
            num = num/10;
            length = length + 1;
        }
        num = a;
        while (num > 0)
        {
            x = num%10;
            sum += powi (x, length);
            num = num/10;
        }

        if (a == sum)
        {
            return 1;
        }
        return 0;
        
    }

    int powi(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}
