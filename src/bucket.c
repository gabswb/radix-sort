#include "bucket.h"

Bucket create(){
    return NULL;
}

bool is_empty(const Bucket b){
    return b==NULL;
}

char* head(const Bucket b){   
    return b->number;
}

Bucket rest(const Bucket b) {
    if(is_empty(b))
        return NULL;
    else
        return b->next;
}

Bucket insert_head(Bucket b, char* numb)
{
    Bucket new = malloc(sizeof(*new));//TODO peut être Element en *new

    if(new == NULL) exit(EXIT_FAILURE);
    
    new->number = numb;
    new->next = b;

    return new;
}

Bucket insert_tail(Bucket b, char *numb){

    Bucket new = malloc(sizeof(*new));  

    if(new == NULL) exit(EXIT_FAILURE);

    new->number = numb;
    new->next = NULL;

    if(is_empty(b)){
          b = new;
    }
    else{
        Bucket temp = b;
        while(!is_empty(rest(temp))){
        temp=rest(temp);
    }
    temp->next = new;
    }
    return b;
}

Bucket remove_head(Bucket b)
{
    Bucket new = NULL;
    
    if(!is_empty(b)){
        new = rest(b);
        free(b);
    }
    return new;
}

Bucket remove_tail(Bucket b)
{
    return b;
}

Bucket free_head(Bucket b)
{
    Bucket new = NULL;

    if(!is_empty(b)){
        new = rest(b);
        free(head(b));
        free(b);
    }
    return new;
}

Bucket free_tail(Bucket b){
    if(!is_empty(b)){

        if(is_empty(rest(b))){
            free(head(b));
            free(b);
            b=NULL;
        }
        else{
            Bucket temp = b;
            while(!is_empty(rest(rest(b)))){
                temp = rest(temp);
            }
            free(head(temp->next));
            free(temp->next);//TODO free(rest(temp)) ?
            temp->next = NULL;
        }
    }
    return b;
}

Bucket delete(Bucket b)
{
    if(!is_empty(b)){
        delete(rest(b));
        b->next = NULL;
        free(head(b));
        free(b);
    }

    return NULL;
}

void print_bucket(const Bucket b){

    if(is_empty(b)){
        printf(" *** empty bucket *** \n");
    }
    else{
        Bucket temp = b;

        printf("[");
        while(!is_empty(rest(temp))){
            printf("%s, ", head(temp));
            temp = rest(temp);
        }
        printf("%s]\n", head(temp));
    }
}