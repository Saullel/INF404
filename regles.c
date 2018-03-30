#include "regles.h"

void AfficherRegle(int numRegle){
	switch(numRegle){
		case 1:
			printf("Règle n°1\n");
			break;
		default: 
			printf("Aucune règle à afficher.\n");
			break;
	}
}