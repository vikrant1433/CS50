/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"
unsigned int count=0;

char* dict[143091];

/**
 * Returns true if word is in dictionary else false.
 */

int StrCmp(char* temp, const char * word)
{
    while(*word || *temp)
    { 
        if (tolower(*temp) != tolower(*word))
           return tolower(*temp) - tolower(*word);
        word++;
        temp++;       
    }
    return 0;
    

}



int mystrcmp(const void* vp1,const void* vp2)
{
    char* s1 = *(char**) vp1;
    char* s2 = *(char**) vp2;
    return StrCmp(s1,s2);
}

bool check(const char* word)
{

    char** res = (char**) bsearch(&word, dict, count, sizeof(char*), mystrcmp);
    if (res == NULL)
        return false;
    return true;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
char* mystrdup(char* word)
{
    char* temp = malloc(sizeof(char)*strlen(word)+1);
    assert(temp != NULL);
    strcpy(temp,word);
    return temp;
}


bool load(const char* dictionary)
{

    FILE* fp = fopen(dictionary,"r");
    if (fp == NULL)
        return false;
    char word[LENGTH+1];
    while(fscanf(fp, "%s", word) == 1)
    {

        dict[count]  = mystrdup(word);
        count++;
    }

    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    int i;
    for (i = 0; i < count; ++i)
    {
        free(dict[i]);
    }
    return true;
}

