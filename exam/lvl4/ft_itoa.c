#include <stdio.h>
#include <stdlib.h>

int minus_plus(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int get_len(int n)
{
    int len = 0;
    if (n <= 0)
        ++len;
    while (n != 0)
    {
        ++len;
        n = n / 10;
    }
    return len;
}
char *ft_itoa(int nbr)
{
    char *res;
    int len;

    len = get_len(nbr);
    res = malloc(sizeof(char) * (len + 1));
    res[len] = '\0';

    if (nbr < 0)
        res[0] = '-';
    else if (nbr == 0)
        res[0] = '0';
    while (nbr != 0)
    {
        --len;
        res[len] = minus_plus(nbr % 10) + '0';
        nbr /= 10;
    }
    return res;
}
int main(void)
{
    int d = INT_MIN;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = -13;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = 0;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = 5;
    printf("%d =? %s\n", d, ft_itoa(d));

    d = INT_MAX;
    printf("%d =? %s\n", d, ft_itoa(d));
}