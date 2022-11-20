#include <stdio.h>


static int cnt = 0;
int length(int);
int CheckIfArmStrong(int);

int isArmstrong(int num)
{  
    cnt = 0;
    int x = num;
    while (num>0)
        {
            num = num/10;
            cnt = cnt + 1;
        }
    num = x;
    if( CheckIfArmStrong(num) == x)
        {
        return 1;
        }

    else
        return 0;
}

int powi(int, int);
int CheckIfArmStrong(int num)
{    
    if(num>0)
        {
        return (powi(num%10, cnt) + CheckIfArmStrong(num/10));
        }
        return 0;
}

static int sum;

int reverseNum(int);
int isPalindrome(int a)
{
    if(a == reverseNum(a))
    {
        sum = 0;
        return 1;
    }
    else
    sum = 0;
        return 0;
}


int reverseNum(int num)
{
    int remainder = 0;
    if(num != 0)
    {
            remainder = num%10;
            sum = sum*10 + remainder;
            reverseNum(num/10);
    }
    return sum;
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

    int length(int a)
{
    static int length = 0;
    while (a>0)
        {
            a = a/10;
            length = length + 1;
        }
    return length;
}
