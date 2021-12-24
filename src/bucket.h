#ifndef DEF_LINKEDLIST_PRIMITIVES
#define DEF_LINKEDLIST_PRIMITIVES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Elem{

    char* number;
    struct Elem* next;

}Element;

typedef Element* Bucket;

Bucket create();
bool is_empty(const Bucket b);

char* head(const Bucket b);
Bucket rest(const Bucket b);

Bucket insert_head(Bucket b, char* numb);
Bucket insert_tail(Bucket b, char* numb);

Bucket remove_head(Bucket b);
Bucket remove_tail(Bucket b);

Bucket free_head(Bucket b);
Bucket free_tail(Bucket b);

Bucket delete(Bucket b);

void print_bucket(const Bucket b);

#endif