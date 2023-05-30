#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(*argv[1]))
    {
        int numeric = atoi(argv[1]);

        string plain_text = get_string("Plaintext: ");
        printf("ciphertext: ");
        for (int j = 0, n = strlen(plain_text); j < n; j++)
        {
            if (plain_text[j] >= 'a' && plain_text[j] <= 'z')
            {
                printf("%c", (((plain_text[j] - 'a') + numeric) % 26) + 'a');
            }
            else if (plain_text[j] >= 'A' && plain_text[j] <= 'Z')
            {
                printf("%c", (((plain_text[j] - 'A') + numeric) % 26) + 'A');
            }
            else
            {
                printf("%c", plain_text[j]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
