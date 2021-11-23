#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Ask a text from the user
    string text = get_string("Text: ");

    int nbr_words = 1;
    int nbr_letters = 0;
    int nbr_sentences = 0;
    // We calculate the numbers of letters, words and sentences
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            nbr_letters++;
        }
        if (isspace(text[i]))
        {
            nbr_words++;
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            nbr_sentences++;
        }
    }

    // We calculate the grade
    float avgL = ((float)nbr_letters / (float)nbr_words) * 100;
    float avgS = ((float)nbr_sentences / (float)nbr_words) * 100;
    float index = 0.0588 * avgL - 0.296 * avgS - 15.8;
    int grade = round(index);
    printf("%d\n", nbr_words);
    // We print the grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
