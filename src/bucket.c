#include "bucket.h"

/**
 * @brief initialise à NULL la liste
 * 
 * @return Bucket retourne NULL
 */
Bucket create()
{
    return NULL;
}

/**
 * @brief retourne true si la liste en paramètre est vide, false si elle n'est pas vide
 * 
 * @param b liste à tester
 * @return true 
 * @return false 
 */
bool is_empty(const Bucket b)
{
    return b==NULL;
}

/**
 * @brief retourne la valeur contenue dans l'Element pointé par la variable de type Bucket
 * 
 * @param b liste
 * @return char* valeur contenue par l'Element qui correspond au nombre
 */
char* value(const Bucket b)
{   
    return b->number;
}

/**
 * @brief retourne le reste de la liste chaînée en paramètre c'est à dire le suivant contenu dans le premier Element de la liste
 * 
 * @param b liste
 * @return Bucket : (*b).next <=> b->next
 */
Bucket rest(const Bucket b)
{
    if(is_empty(b))
        return NULL;
    else
        return b->next;
}

/**
 * @brief on insere en queue de la liste un Element contenant la chaine de caractère passée en paramètre
 * 
 * @param b ancienne liste dans laquelle on doit insérer un element
 * @param numb chaine de caractère 
 * @return Bucket  est une nouvelle liste avec l'Element inséré en queue et l'ancienne liste
 */
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

/**
 * @brief permet de retirer l'Element en tête de la liste et libérer la mémoire allouée 
 * pour l'Element sans libérer la mémoire allouée pour la chaine de caractère qu'elle possède
 * 
 * @param b ancienne liste 
 * @return Bucket nouvelle liste 
 */
Bucket remove_head(Bucket b)
{
    Bucket new = NULL;
    
    if(!is_empty(b)){
        new = rest(b);
        free(b);
    }
    return new;
}


/**
 * @brief supprime la liste c'est à dire tous ces éléments et libère aussi la mémoire allouée 
 * pour chaque élément et chaque chaine de caractère que contient chaque élément
 * 
 * @param b ancienne liste
 * @return Bucket nouvelle liste égale à NULL car tous ses éléments ont été supprimés
 */
Bucket delete(Bucket b)
{
    if(!is_empty(b)){
        delete(rest(b));
        b->next = NULL;
        free(value(b));
        free(b);
    }

    return NULL;
}

/**
 * @brief affiche dans la console la liste en paramètre
 * 
 * @param b liste à afficher
 */
void print_bucket(const Bucket b)
{

    if(is_empty(b)){
        printf(" *** empty bucket *** \n");
    }
    else{
        Bucket temp = b;

        printf("[");
        while(!is_empty(rest(temp))){
            printf("%s, ", value(temp));
            temp = rest(temp);
        }
        printf("%s]\n", value(temp));
    }
}

/**
 * @brief affiche une liste de liste
 * Cette fonction est utile pour le debugger
 * 
 * @param bl la liste de liste
 * @param length lonqueur de la liste de liste
 */
void print_bucket_list(const Bucket* bl, int length)
{
    for(int i=0; i<length; i++){
        printf("bucket %d : ",i);
        print_bucket(bl[i]);
    }
    printf("\n\n");
}

