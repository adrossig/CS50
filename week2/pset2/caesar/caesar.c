#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

// Prototype
int check(char *str);
int cipher(char *str, int key);

int main(int argc, char *argv[])
{
    if (argc == 2 && check(argv[1]) == 0)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        cipher(plaintext, key);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

// Take an input and verified if it's only digit char
int check(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return (-1);
        }
    }
    return (0);
}

// Cipher the text given by the User
int cipher(char *str, int key)
{
    printf("ciphertext: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]) && isupper(str[i]))
        {
            printf("%c", (((str[i] - 65) + key) % 26) + 65);
        }
        else if (isalpha(str[i]) && islower(str[i]))
        {
            printf("%c", (((str[i] - 97) + key) % 26) + 97);
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
