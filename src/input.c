#include "input.h"

/**
 * @brief permet de vider le buffer du système d'exploitation lorsque la chaine de caractère rentrer pour fgets() est trop grande
 * 
 */
void flush_input_buffer()
{
    int c=0;
    while(c != '\n' && c != EOF){
        c=getchar();
    }
}

/**
 * @brief demande à l'utilisateur d'entrer la base est contrôle sa valeur
 * 
 * @return int la base entrée par l'utilisateur si conforme
 */
int input_base()
{

    char string[BUFFER_SIZE+1];
    int base = 0;
    char* res;
    char* position_enter = NULL;

    printf("Entrer la base (entre entre 2 et 16) :\n");
    res = fgets(string, BUFFER_SIZE+1, stdin);
    position_enter = strchr(string, '\n');
    base = strtol(string, NULL, 10);

    while(res == NULL || base<MIN_BASE || base>MAX_BASE){        
        if(position_enter==NULL)
            flush_input_buffer();
        perror("Erreur, entrer la base (entre 2 et 16) :\n");
        position_enter = NULL;
        res = fgets(string, BUFFER_SIZE+1, stdin);
        position_enter = strchr(string, '\n');
        base = strtol(string, NULL, 10);
    }
    return base;
}

/**
 * @brief permet de contrôler les nombres de la liste à triés entrés en arguments, pour vois s'ils ne sont pas incompatibles avec la base entrée
 * 
 * @param base base entrée par l'utilisateur
 * @param array arguments passés avec l'execution du programme (argv)
 * @param length taille de array
 */
void control_arguments(int base, char** array, int length)
{
    for(int i=1; i<length; i++){
        for(int j=0; j<strlen(array[i]); j++){ 
             switch(array[i][j])
            {
                case '0':
                case '1':
                    break;
                case '2':
                    if(base<3){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case '3':
                    if(base<4){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case '4':
                    if(base<5){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case '5':
                    if(base<6){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case '6':
                    if(base<7){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case '7':
                    if(base<8){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case '8':
                    if(base<9){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case '9':
                    if(base<10){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'a':
                case 'A':
                   if(base<11){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'b':
                case 'B':
                    if(base<12){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'c':
                case 'C':
                    if(base<13){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'd':
                case 'D':
                    if(base<14){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'e':
                case 'E':
                    if(base<15){
                        perror("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                case 'f':
                case 'F':
                    if(base<16){
                        printf("La base ne correspond pas aux arguments");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    perror("default");
                    exit(EXIT_FAILURE);
            }
        }
    }
}