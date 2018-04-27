#include <stdio.h>
#include "terrains.h"
#include "regles.h"

//ne pas oublier l'ouverture et la fermeture des fichiers

void ecritureFichier(FILE* f){

fichier = fopen(f,"w")

if (commande == 1){
	printf(f,"else ");
}
else if (commande == 2){
	printf(f,"if ");
}
else if (commande == 3){
	printf(f,"for ");
}
else if (commande == 4){
	printf(f,"while ");
}
else if (commande == 5){
	printf(f,"( ");
}
else if (commande == 6){
	printf(f,") ");
}
else if (commande == 7){
	printf(f,"; ");
}
else if (commande == 8){
	printf(f,"{ ");
}
else if (commande == 8){
	printf(f,"} ");
}
else if (commande == 9){
	printf(f,"=");
}
else if (commande == 10){
	printf(f,"&& ");
}
else if (commande == 11){
	printf(f,"|| ");
}
/*else if (commande){
	printf(f,". ");
}*/
/*else if (commande){
	printf(f,", ");
}*/
}