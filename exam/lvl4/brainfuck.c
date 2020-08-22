#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void ft_brainfuck(char *str)
{
    int i;
    char *ptr;

    i = 0;
    ptr = (char *)malloc(sizeof(ptr) * 2048);
    while (str[i] != 0)
    {
        *ptr += str[i] == '+' ? 1 : 0;
        *ptr -= str[i] == '-' ? 1 : 0;
        ptr += str[i] == '>' ? 1 : 0;
        ptr -= str[i] == '<' ? 1 : 0;
        if (str[i] == '[' && *ptr == 0)
            while (str[i] != ']')
                i++;
        if (str[i] == ']' && *ptr != 0)
            while (str[i] != '[')
                i--;
        if (str[i] == '.')
            write(1, ptr, 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ft_brainfuck(av[1]);
        write(1, "\n", 1);
    }
}