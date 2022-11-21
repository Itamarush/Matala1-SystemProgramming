#include<stdio.h>
#include "NumClass.h"

int main()
{
    int num1;
    int num2;
    int i;

    //printf("Enter two integers: ");
    scanf("%d", &num1);
    scanf("%d", &num2);

    if (num1>=0 && num2>=0)
    {
            printf("\n");
            printf("The Armstrong numbers are:");
            for (i = num1; i <= num2; i++)
            {
                if(isArmstrong(i) == 1)
                {
                    printf(" %d", i);
                }
            }

            printf("\n");
            printf("The Palindromes are:");
            for (i = num1; i <= num2; i++)
            {
                    if(isPalindrome(i) == 1)
                {
                    printf(" %d", i);
                }
            }

            printf("\n");
            printf("The Prime numbers are:");
            for (i = num1; i <= num2; i++)
            {
                 if(isPrime(i) == 1)
                {
                    printf(" %d", i);
                }
            }

            printf("\n");
            printf("The Strong numbers are:");
            for (i = num1; i <= num2; i++)
            {
                 if(isStrong(i) == 1)
                {
                    printf(" %d", i);
                }
            }
    }
     
}
