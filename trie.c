#define SIZE 26
#define ascii 97
#include "trie.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

struct Node
{
   bool End_Word;
   char letter;
   int count;
   struct Node *child[SIZE];
} Node;

struct Node *EmptyTrie(void)
{
   struct Node *kNode = NULL;
   kNode = (struct Node *)malloc(sizeof(struct Node));
   kNode->count = 0;
   kNode->letter = '\0';
   kNode->End_Word = false;
   for (int i = 0; i < SIZE; i++)
   {
      kNode->child[i] = NULL;
   }
   return kNode;
}

void put_word(struct Node *root, char *word)
{
   // printf("%c",*(word +0));
   struct Node *temp = root;

   int keep_null = 0;
   int word_size = strlen(word);

   for (int j = 0; j < word_size; j++)
   {
      bool exist = false;
      int i = 0;
      while (i < SIZE && exist == false)
      {
         if (temp->child[i] != NULL)
         {
            struct Node *temp_place = temp->child[i];
            if (temp_place->letter != *(word + j))
            {
               i++;
            }
            else
            {

               exist = true;
               temp = temp->child[i];
            }
            // free(temp_place);
         }
         else
         {
            i++;
         }
      }
      if (exist == false)
      {
         keep_null = ((int)*(word + j)) - ascii;
         temp->child[keep_null] = EmptyTrie();
         temp = temp->child[keep_null];
         temp->letter = *(word + j);
      }
   }
   temp->End_Word = true;
   temp->count++;
   // free(temp);
}

void printTrie_defult(struct Node *root, char *word, int place)
{
   if (root == NULL)
   {
      printf("The trie is empty!");
      return;
   }
   if (root->End_Word == true)
   {
      word[place] = root->letter;
      word[place + 1] = 0;

      for (int f = 1; f <= place; f++)
      {
         printf("%c", word[f]);
      }
      printf(" %d", root->count);
      printf("\n");
      // printf("%s %d\n", word, root->count);
   }
   for (int i = 0; i < SIZE; i++)
   {
      if (root->child[i] != NULL)
      {
         // printf("%c", root->letter);

         word[place] = root->letter;
         struct Node *temp = root->child[i];
         word = realloc(word, (place + 1) * sizeof(char));
         place++;
         printTrie_defult(temp, word, place);
         place--;
      }
   }
}
void printTrie_parameter(struct Node *root, char *word, int place)
{
   if (root == NULL)
   {
      printf("The trie is empty!");
      return;
   }
   if (root->End_Word == true)
   {
      word[place] = root->letter;
      word[place + 1] = 0;

      for (int f = 0; f <= place; f++)
      {
         printf("%c", word[f]);
      }
      printf(" %d", root->count);
      printf("\n");
      // printf("%s %d\n", word, root->count);
   }
   for (int i = SIZE - 1; i >= 0; i--)
   {
      // printf("ff");
      if (root->child[i] != NULL)
      {
         // printf("g ");

         word[place] = root->letter;
         // printf("%c", word[place]);
         struct Node *temp = root->child[i];
         word = realloc(word, (place + 1) * sizeof(char));
         place++;
         printTrie_parameter(temp, word, place);
         place--;
      }
   }
}
void free_trie(struct Node *del)
{
   for (int i = 0; i < SIZE; i++)
   {
      if (del->child[i] != NULL)
      {
         free_trie(del->child[i]);
      }
   }
   // printf("%c ",del->letter);
   free(del);
}
