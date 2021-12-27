#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bucket.h"
#include "sort.h"
#include "input.h"

#define MAX_SIZE 10 //nombre maximal de chiffres pour un nombre

/**
 * @brief fonction main
 * 
 * @param argc taille de argv 
 * @param argv tableau de dimension 2 qui contient les arguments passés avec l'appel au programme, argv[0] contient le nom du programme
 * @return int indique comment le programme s'est terminé
 */
int main(int argc, char* argv[])
{   
    int base = input_base();
    int max  = max_length(argv,argc);
    control_arguments(base, argv, argc);
    Bucket list = create();

    for(int i=1; i<argc ; i++){
        if(strlen(argv[i])>MAX_SIZE){
            perror("taille des arguments > 10");
            exit(EXIT_FAILURE);
        }                                                                      //max-strlen(argv[i]) retourne la différence de longueur entre la chaine de caractère contenue dans argv[i] et max.                                                                               
        list = insert_tail(list, format_number(max-strlen(argv[i]), argv[i])); //Cette différence de longueur correspond au nombre de 0 à ajouter à gauche.            
    }                                                                          //donc on appelle la fonction format_number() en passant en paramètre ce nombre de 0 et la chaine argv[i] à modifier                                                                            
                                                                               //et on insere en queue de notre liste le résultat de cette fonction
    list = sort(base, max, list);
    print_bucket(list);
    list = delete(list);

    return 0;
}