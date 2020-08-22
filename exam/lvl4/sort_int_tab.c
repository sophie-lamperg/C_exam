#include <stdio.h>
#include <stdlib.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;
    while (i < (size - 1))
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i] = temp;
            i = 0;
        }
        else
            i++;
    }
}
int main(void)
{
    int size = 4;
    int i = 0;
    int *arr = {5, 3, 7, 2};
    while (i < size)
    {
        sort_int_tab(arr[i], size);
        printf(arr[i]);
    }
    i++;
}