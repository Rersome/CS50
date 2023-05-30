// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int H_SIZE = 10000;

// TODO: Choose number of buckets in hash table

// Hash table
node *table[H_SIZE];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char copy[LENGTH + 1];
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        copy[i] = toupper(word[i]);
    }

    copy[n] = '\0';
    int h = hash(word);
    node *cursor = table[h];

    while(cursor != NULL)
    {
        if (strcasecmp(cursor->word, copy) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0; i <= strlen(word); i++)
    {
        hash = (31 * hash + toupper(word[i]));
    }
    return hash % H_SIZE;
}

int count = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    while(fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;
        int h = hash(word);
        node *head = table[h];

        if (head == NULL)
        {
            table[h] = n;
            count++;
        }
        else
        {
            n->next = table[h];
            table[h] = n;
            count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < H_SIZE; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *temp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
