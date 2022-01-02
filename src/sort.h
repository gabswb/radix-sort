#ifndef DEF_SORT
#define DEF_SORT

#include "bucket.h"


int max_length(char** array, int size);

char* format_number(int nb_of_0, char* old_nb);

Bucket sort(int base, int max, Bucket liste);

void insert_bucket_list(Bucket* bucket_list, char* value, char position);

#endif  