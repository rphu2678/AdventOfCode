#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node{
    int val;
    struct Node* next;
} Node;

void init_list(Node**, Node**);
void add_item(Node**, Node*);
int search_num(Node*, int);


#endif