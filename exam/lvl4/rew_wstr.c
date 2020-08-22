#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int len_str(char *str)
{
    int len = 0;
    while (*str)
    {
        *str++;
        len++;
    }
    return (len);
}
int wc(char str)
{
    return (str == '\t' || str == ' ');
}
void reverse_w(char *str)
{
    int fast;
    int slow;
    int curr;

    fast = len_str(str) - 1;
    slow = fast;
    curr = fast;

    while (fast >= 0)
    {
        slow = fast;
        curr = fast;
        while (fast >= 0 && !wc(str[fast]))
        {
            fast--;
        }
        fast++;
        curr = fast;
        while (curr <= slow)
        {
            write(1, &str[curr], 1);
            curr++;
        }
        if (fast > 0)
            write(1, " ", 1);
        fast--;
        fast--;
    }
}
int main(int ac, char **av)
{
    if (ac == 2)
        reverse_w(av[1]);
    write(1, "\n", 1);
    return (1);
}