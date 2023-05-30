#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long credit_card = number;
    int i = 0;

    while (credit_card > 0)
    {
        credit_card = credit_card / 10;
        i++;
    }

    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum_1 = 0;
    int sum_2 = 0;
    int total = 0;
    long x = number;
    int module_1, module_2, d1, d2;

    do
    {
        module_1 = x % 10;
        x = x / 10;
        sum_1 += module_1;

        module_2 = x % 10;
        x = x / 10;

        module_2 = module_2 * 2;
        d1 = module_2 % 10;
        d2 = module_2 / 10;
        sum_2 += + d1 + d2;
    }
    while (x > 0);

    total = sum_1 + sum_2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = number;

    do
    {
        start = start / 10;
    }
    while (start > 100);

    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}