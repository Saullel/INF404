#include "analyse_syntaxique.h"

int main(int argc, char* argv[]){
	int res=0;

   if (argc >= 1) {
    if (analyser (argv[1],&res)==1){
	     printf("Resultat : %d \n", res);
      }
    else {
      printf("Le calcul ne peut être effectué.\n");
    }
   } 
   else {
	printf("Il faut donner un nom de fichier en argument !") ;
	return 1 ; 
   } ; 
   
    return 0 ;

}