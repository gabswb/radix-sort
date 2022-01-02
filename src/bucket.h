#ifndef DEF_LINKEDLIST_PRIMITIVES
#define DEF_LINKEDLIST_PRIMITIVES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/** Cette partie contient toutes les primitves des chaînes listées nécessaires au programme, nous avons utilisé le mot clé Bucket pour 
 *  les coder pour correspondre au sujet mais il n'y a aucune différence avec les liste chainée 
**/


typedef struct Elem{

    char* number;
    struct Elem* next;

}Element;

typedef Element* Bucket;

Bucket create();
bool is_empty(const Bucket b);

char* value(const Bucket b);
Bucket rest(const Bucket b);

Bucket insert_tail(Bucket b, char* numb);

Bucket remove_head(Bucket b);

Bucket delete(Bucket b);

void print_bucket(const Bucket b);
void print_bucket_list(const Bucket* bl, int length);

#endif