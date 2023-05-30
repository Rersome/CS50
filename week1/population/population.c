#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    do
    {
        start = get_int("Starting population size: ");
    }
    while (start < 9);

    int end;
    do
    {
        end = get_int("End population size: ");
    }
    while (end < start);

    int years = 0;
    while(start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    printf("Years: %i\n", years);
}
