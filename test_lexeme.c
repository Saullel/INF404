
#include <stdio.h>

#include "analyse_syntaxique.h"


int main (int argc, char *argv[]) {
	int res;

   if (argc >= 1) {
   	analyser (argv[1],&res) ;
	printf("Resultat : %d \n", res);
   } 
   else {
	printf("Il faut donner un nom de fichier en argument !") ;
	return 1 ; 
   } ; 
   
    return 0 ;
}
