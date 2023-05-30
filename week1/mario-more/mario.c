#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers;
    do
    {
        numbers = get_int("Numbers: ");
    }
    while (numbers < 1 || numbers > 8);

    for (int line = 0, spaces, left_hashes, right_hashes; line < numbers; line++)
    {
        for (spaces = 0; spaces < numbers - line - 1; spaces++)
        {
            printf(" ");
        }
        for (left_hashes = 0; left_hashes < line + 1; left_hashes++)
        {
            printf("#");
        }
        printf("  ");
        for (right_hashes = 0; right_hashes < line + 1; right_hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}