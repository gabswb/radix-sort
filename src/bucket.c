#include "bucket.h"

Bucket create(){
    return NULL;
}

bool is_empty(const Bucket b){
    return b==NULL;
}

char* head(Bucket b){   
    return b->number;
}

Bucket rest(const Bucket b) {
    if(is_empty(b))
        return NULL;
    else
        return b->next;
}

Bucket insert_head(const Bucket b, const char* numb){
    Bucket new = (Bucket) malloc(sizeof(Element));//TODO peut être Element en *new

    if(new == NULL)
        exit(EXIT_FAILURE);
    
    new->number = numb;
    new->next = b;

    return new;
}

Bucket insert_tail(Bucket b, const char *numb){

    Bucket new = (Bucket) malloc(sizeof(Element));

    if(new == NULL)
        exit(EXIT_FAILURE);
        
    new->number = numb;
    new->next = NULL;

    if(is_empty(temp)){
          l = new;
    }
    else{
        Bucket temp = b;
        while(!is_empty(temp->next)){
        temp=temp->next;
    }
    temp->next = new;
    }
    return b;
}

Bucket remove_head(Bucket b){
    Bucket new = NULL;

    if(!is_empty(b)){
        new = b->next;
        free(b);
    }
    return new;
}

Bucket remove_tail(Bucket b){
    if(!is_empty(b)){

        if(is_empty(b->next)){
            free(b);
            b=NULL;
        }
        else{
            Bucket temp = b;
            while(!is_empty(b->next->next)){
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
    }
    return b;
}

void print_bucket(Bucket b){

    if(is_empty(b)){
        printf(" *** empty bucket ***")
    }
    else{
        Bucket temp = b;

        printf("[");
        while(!is_empty(temp)){
            printf("%s", temp->number);
            temp = temp->next;
        }
        printf("]");
    }
}