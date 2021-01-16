#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char *argv[])
{
    int x;
    // putchar(x);
    struct Node *root = EmptyTrie();
    int i = 0;
    char *txt = (char *)malloc(sizeof(char));
    int place = 0;
    char full_text = getc(stdin);

    //get text to str
    while (full_text != EOF)
    {
        if (full_text >= 'A' && full_text <= 'Z')
        {
            full_text = (int)full_text + 32;
        }

        if (full_text != ' ' && full_text != '\0' && full_text != '\t' && full_text != '\n' && full_text >= 'a' && full_text <= 'z')
        {

            txt = realloc(txt, (i + 1) * sizeof(char));
            *(txt + i) = full_text;
            i++;
            full_text = getc(stdin);
            if (full_text >= 'A' && full_text <= 'Z')
            {
                full_text = (int)full_text + 32;
            }
            if ((full_text < 'a' || full_text > 'z') && full_text != ' ' && full_text != '\0' && full_text != '\t' && full_text != '\n')
            {
                full_text = getc(stdin);
            }
            if (full_text == EOF)
            {
                put_word(root, txt);
                // free(txt);
            }
        }
        else
        {
            if ((full_text < 'a' || full_text > 'z') && full_text != ' ' && full_text != '\0' && full_text != '\t' && full_text != '\n')
            {
                full_text = getc(stdin);
            }
            else
            {
                if (strlen(txt)!=0)
                {
                   put_word(root, txt);
                }                
                i = 0;
                free(txt);
                txt = (char *)malloc(sizeof(char));
                full_text = getc(stdin);
            }
        }
    }
    free(txt);
    char *word = (char *)malloc(sizeof(char));

    if (argc == 1)
    {
        printTrie_defult(root, word, 0);
        free(word);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "r") == 0)
        {
            printTrie_parameter(root, word, 0);
        }
    }
    
    free_trie(root);
}