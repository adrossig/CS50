// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);

    if (table[hash_value] == NULL)
    {
        return false;
    }
    else
    {
        node *temp = table[hash_value];

        while (temp != NULL && (strcasecmp(word, temp->word) == 0))
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int length = strlen(word);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += tolower(word[i]);
        hash_value = hash_value * tolower(word[i]) % N;
    }
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    char buffer[LENGTH + 1];

    while (fscanf(dict, "%s", buffer) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return false;
        }
        temp->next = NULL;

        strcpy(temp->word, buffer);
        int hash_code = hash(temp->word);

        if (table[hash_code] == NULL)
        {
            table[hash_code] = temp;
        }
        else
        {
            temp->next = table[hash_code];
            table[hash_code] = temp;
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int word_count = 0;
    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        if (temp != NULL)
        {
            temp = temp->next;
            word_count++;
        }
    }
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        node *temp2 = table[i];

        while (temp2 != NULL)
        {
            temp = temp2;
            temp2 = temp2->next;
            free(temp);
        }
    }
    return true;
}
