#include "linkedlist_primitives.h"

Bucket initialise(int const taille_max);

bool is_empty(Bucket b)
{
    return (b==NULL);
}

const char* head(Bucket b)
{   
    return (b->number);
}

Bucket rest(Bucket b)
{
    if(is_empty(b))
        return NULL;
    else
        return b->next;
}

Bucket insert_head(Bucket b, char *number);
Bucket insert_tail(Bucket b, char *number);