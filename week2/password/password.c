// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    enum
    {
        lowercase = 1,
        uppercase = 2,
        number = 4,
        symbol = 8,
        correctpassword = 15
    };
    int PasswordFlags = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            PasswordFlags |= number;
        }
        else if (ispunct(password[i]))
        {
            PasswordFlags |= symbol;
        }
        else if (isupper(password[i]))
        {
            PasswordFlags |= uppercase;
        }
        else
        {
            PasswordFlags |= lowercase;
        }
    }
    return (PasswordFlags == correctpassword);
}
