#include "sort.h"

/**
 * @brief calcule la longueur de la plus grande chaîne de caractère du tableau
 * 
 * @param array tableau contenant la ou les chaînes de caractère
 * @param size taille du tableau
 * @return int la longueur 
 */
int max_length(char** array, int size)
{
    int max = 0;
    for(int i=1; i<size;i++){ /** On commence à i=1 car argv[0] contient le nom du programme **/
        if(max< strlen(array[i]))
            max = strlen(array[i]);
    }
    return max;
}

/**
 * @brief ajoute des '0' a gauche de chaque nombre dont la longueur est < à la longueur max
 * 
 * @param nb_of_0 nombre de 0 à ajouter à la chaîne de caractère
 * @param old_nb  ancien nombre sans les 0 ahoutés
 * @return char* nombre dont la longueur est mtn égale à la longueur max 
 */
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


/**
 * @brief fonction principale du programme qui trie selon la méthode du sujet la liste de nombre reçue en paramètre
 * 
 * @param base base numérique dans laquelle on travaille
 * @param max longueur de la chaine de caractère codant les nombres à triés
 * @param l liste des nombres à triés
 * @return Bucket : liste triées
 */
Bucket sort(int base, int max, Bucket l)
{
    Bucket  list = l;
    Bucket* bucket_list = malloc(base*sizeof(Bucket)); 
    if(bucket_list==NULL) exit(EXIT_FAILURE);

    for(int i = 0; i<base; i++){
        bucket_list[i] = create();
    }

    for(int i = max-1; i>=0; i--){
        while(!is_empty(list)){
            insert_bucket_list(bucket_list, list, head(list)[i]);                
            list = remove_head(list);    
        }
        //print_bucket_list(bucket_list, base); //Décommenter cette ligne pour pouvoir voir les différentes étapes                                                  
        for(int j = 0; j<base;j++){
            while(!is_empty(bucket_list[j])){
                list = insert_tail(list, head(bucket_list[j]));
                bucket_list[j] = remove_head(bucket_list[j]);
            }
        }
    }
    free(bucket_list);
    return list;
}

/**
 * @brief insert le nombre ième nombre de la liste dans la liste des seaux
 * 
 * @param bucket_list liste des seaux
 * @param list liste de nombres
 * @param position position du ième nombre à insérer
 */
void insert_bucket_list(Bucket* bucket_list, Bucket list, char position)
{
    switch(position)
    {
        case '0':
            bucket_list[0] = insert_tail(bucket_list[0], head(list));
            break;
        case '1':
            bucket_list[1] = insert_tail(bucket_list[1], head(list));
            break;
        case '2':
            bucket_list[2] = insert_tail(bucket_list[2], head(list));
            break;
        case '3':
            bucket_list[3] = insert_tail(bucket_list[3], head(list));
            break;
        case '4':
            bucket_list[4] = insert_tail(bucket_list[4], head(list));
            break;
        case '5':
            bucket_list[5] = insert_tail(bucket_list[5], head(list));
            break;
        case '6':
            bucket_list[6] = insert_tail(bucket_list[6], head(list));
            break;
        case '7':
            bucket_list[7] = insert_tail(bucket_list[7], head(list));
            break;
        case '8':
            bucket_list[8] = insert_tail(bucket_list[8], head(list));
            break;
        case '9':
            bucket_list[9] = insert_tail(bucket_list[9], head(list));
            break;
        case 'a':
        case 'A':
            bucket_list[10] = insert_tail(bucket_list[10], head(list));
            break;
        case 'b':
        case 'B':
            bucket_list[11] = insert_tail(bucket_list[11], head(list));
            break;
        case 'c':
        case 'C':
            bucket_list[12] = insert_tail(bucket_list[12], head(list));
            break;
        case 'd':
        case 'D':
            bucket_list[13] = insert_tail(bucket_list[13], head(list));
            break;
        case 'e':
        case 'E':
            bucket_list[14] = insert_tail(bucket_list[14], head(list));
            break;
        case 'f':
        case 'F':
            bucket_list[15] = insert_tail(bucket_list[15], head(list));
            break;
        default:
            exit(EXIT_FAILURE);
    }
}