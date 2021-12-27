#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2//taille maximale de la chaine de caractère correspondant à la base entrée par l'utilisateur
#define MIN_BASE 2   //base minimale pour un nombre
#define MAX_BASE 16  //base maximale pour un nombre 

void flush_input_buffer();

int input_base();

void control_arguments(int base, char** array, int lenth);


