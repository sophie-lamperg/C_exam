#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int wc(char str)
{
    return (str == '\t' || str == ' ');
}

void rostring(char *str)
{
    int i;
    int start;
    int end;

    i = 0;
    while (str[i] && wc(str[i]))
        i++;
    start = i;
    while (str[i] && !wc(str[i]))
        i++;
    end = i;
    while (str[i])
    {
        while (str[i] && wc(str[i]))
            i++;
        if (str[i] && !wc(str[i]))
        {
            while (str[i] && !wc(str[i]))
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
        }
    }
    while (start < end)
    {
        write(1, &str[start], 1);
        start++;
    }
}
int main(int ac, char **av)
{
    if (ac == 2)
        rostring(av[1]);
    write(1, "\n", 1);
    return (0);
}