#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bucket.h"
#include "sort.h"

#define MAX_SIZE 10 //nombre maximal de chiffres pour un nombre
#define MIN_BASE 2  //base minimale pour un nombre
#define MAX_BASE 16 //base maximale pour un nombre 


char* format_number(int nb_of_0, char* old_nb)
{
    int size = nb_of_0+strlen(old_nb)+1; /** +1 for '\0' **/
    char* new_number = calloc(size, sizeof(char));
    if(new_number==NULL) exit(EXIT_FAILURE);

    for(int i=0; i<nb_of_0; i++){
        new_number[i]='0';
    }
    for(int i=0; i<strlen(old_nb); i++){
        new_number[nb_of_0+i]=old_nb[i];
    }
    new_number[size-1] = '\0';

    return new_number;
}

int input_base(){
    int base = 0;
    printf("entrer la base\n");
    scanf("%d",&base);
    return base;
}

// Bucket* bucket_list = malloc(base*sizeof(Bucket));
    // if(bucket_list==NULL) exit(EXIT_FAILURE);

int main(int argc, char* argv[])
{   
    int base = input_base();
    int max  = max_length(argv,argc);
    Bucket list = create();

    for(int i=1; i<argc ; i++){
        list = insert_tail(list, format_number(max-strlen(argv[i]), argv[i]));
    }

    list = sort(base, max, list);
    print_bucket(list);
    list = delete(list);

    return 0;
}