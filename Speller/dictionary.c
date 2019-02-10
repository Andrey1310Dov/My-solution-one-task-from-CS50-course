// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#define bool _Bool

// Iniciate typedef
typedef struct node
{
    // It is for end of word
    bool is_word;

    // It is a pointer to other nodes
    struct node *children[27];
} NODE;

// Iniciate creation of a new node
NODE *createNode(void)
{
    // Malloc space for a new node
    NODE *ptr_node = NULL;
    ptr_node = (struct node *) malloc(sizeof(struct node));
    // Marker bool for a node
    ptr_node->is_word = false;

    // Fill the array with NULL
    for (int i = 0; i < 27; i++)
    {
        ptr_node->children[i] = NULL;
    }

    return ptr_node;
}

// Delete the trie
void delete_node(NODE *del_node)
{
    // If node doezn't excist return
    if (!del_node)
    {
        return;
    }

    // Travel to lowest possible node
    for (int i = 0; i < 27; i++)
    {
        // Free all children
        delete_node(del_node->children[i]);
    }
    free(del_node);
}

NODE *root_node; // Initiate a root of nodes
int word_count = 0; // Counter of all words

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = 0;

    // Make a pointer to root
    NODE *parent = root_node;

    // For each letter in input word
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == '\'')
        {
            // Index for '\''
            index = 26;
            if (parent->children[index] == NULL)
            {
                // If NULL, word is misspelled or not in dictionary
                return false;
            }
            else
            {
                parent = parent->children[index];
            }
        }
        else
        {
            if (parent->children[tolower(word[i]) - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                // Have children[i] point to it
                parent = parent->children[tolower(word[i]) - 'a'];
            }
        }
    }

    // Word found in dictionary
    if (parent->is_word)
    {
        return true;
    }

    // Word not found
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *inptr = fopen(dictionary, "r");

    if (inptr == NULL)
    {
        return false;
    }

    root_node = createNode(); // Create a new trie into memory (return a pointer to structure)
    char word[47];

    while (fgets(word, sizeof(word), inptr) != NULL)
    {
        NODE *parent = root_node;
        int index = 0;
        while (word[index] != '\n')
        {
            if (word[index] == '\'')
            {
                // Check the value in children
                if (parent->children[26] == NULL)
                {
                    // If NULL, create a new node
                    parent->children[26] = createNode();
                }
                // Go to next structure
                parent = parent->children[26];
            }
            else
            {
                if (parent->children[word[index] - 'a'] == NULL)
                {
                    parent->children[word[index] - 'a'] = createNode();
                }
                parent = parent->children[word[index] - 'a'];
            }
            index++;
        }

        // If at end of word, set is_word to true
        parent->is_word = true;
        word_count++;

    }

    fclose(inptr);

    return true;

}

unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    delete_node(root_node);
    return true;
}
