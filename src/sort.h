#ifndef DEF_SORT
#define DEF_SORT

#include "bucket.h"


int max_length_bucket(Bucket b);
int max_length(char** array, int size);

Bucket sort(int base, int max, Bucket liste);

void insert_bucket_list(Bucket* bucket_list, Bucket list, char position);

#endif  