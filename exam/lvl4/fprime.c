#include <stdio.h>
#include <stdlib.h>
void fprime(int n)
{
    int i = 2;
    if (n == 1)
    {
        printf("1");
    }
    while (n >= i)
    {
        if (n % i == 0)
        {
            printf("%d", i);
            if (n != i)
                printf("*");
            n /= i;
            i--;
        }
        i++;
    }
}
int main(int ac, char **av)
{
    if (ac == 2)
        fprime(atoi(av[1]));
    printf("\n");
}