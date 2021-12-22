#ifndef DEF_LINKEDLIST_PRIMITIVES
#define DEF_LINKEDLIST_PRIMITIVES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Node{
    char *number;
    struct Node *next;
}Node;

typedef Node * Bucket;


Bucket initialise(int const taille_max);
bool is_empty(Bucket b);

const char* head(Bucket b);
Bucket rest(Bucket b);

Bucket insert_head(Bucket b, char *number);
Bucket insert_tail(Bucket b, char *number);


#endif