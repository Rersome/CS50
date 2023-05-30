#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

void decimal_to_binary(int decimal);

int main(void)
{
    string word = get_string("Write ur word: \n");
    for (int i = 0; i < strlen(word); i++)
    {
        unsigned char byte = word[i];
        int binary[BITS_IN_BYTE];
        int quotient = byte;

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            binary[j] = quotient % 2;
            quotient /= 2;
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }
        printf("\n");
    }
}

/*void decimal_to_binary(int decimal)
{
    int binaryNum[BITS_IN_BYTE];
    int k = BITS_IN_BYTE;
    int i = 0;
    while (k > 0)
    {
        binaryNum[i++] = decimal % 2;
        decimal = decimal / 2;
        k--;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        print_bulb(binaryNum[j]);
    }
    printf("\n");
}*/

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
