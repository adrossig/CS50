#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

// Prototype
int check(char *str);
bool repeatedchar(char *str);
void cipher(char *str, char *key);

int main(int argc, char *argv[])
{
    if (argc == 2 && check(argv[1]) == 0 && repeatedchar(argv[1]) == false)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        char *plaintext = get_string("plaintext: ");
        cipher(plaintext, argv[1]);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

// Take an input and verified if it's only a char
int check(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]))
        {
            return (-1);
        }
    }
    return (0);
}

char *lowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

bool repeatedchar(char *str)
{
    char *temp = lowercase(str);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        for (int j = i + 1; temp[j] != '\0'; j++)
        {
            if (temp[i] == temp[j])
            {
                return true;
            }
        }
    }
    return false;
}

void cipher(char *str, char *key)
{
    printf("ciphertext: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]) && islower(str[i]))
        {
            printf("%c", tolower(key[str[i] - 97]));
        }
        else if (isalpha(str[i]) && isupper(str[i]))
        {
            printf("%c", toupper(key[(str[i] - 65)]));
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}
