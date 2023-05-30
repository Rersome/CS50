#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Number: ");
    }
    while (number < 1 || number > 8);

    for (int line = 0, left_hashes, spaces; line < number; line++)
    {
        for (spaces = 0; spaces < number - line - 1; spaces++)
        {
            printf(" ");
        }
        for (left_hashes = 0; left_hashes < line + 1; left_hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}