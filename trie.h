struct Node;
struct Node *EmptyTrie(void);
void put_word(struct Node *root, char *word);
void print_Trie(struct Node *root, char *word);
void printTrie_defult(struct Node *root, char *word, int lev);
void free_trie (struct Node *del);
void printTrie_parameter(struct Node *root, char *word, int place);
