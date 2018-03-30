

#include "ast_parcours.h"


void aff_operateur(TypeOperateur op){
	switch (op) {
		case N_PLUS:
			printf("+") ;
			break;
		case N_MOINS:
			printf("-") ;
			break;
		case N_MUL:
			printf("*") ;
			break;
		case N_DIV:
			printf("/") ;
			break;
	} 
}

void afficherArbre(Ast expr) {
	switch (expr->nature) {
               case OPERATION:
                        aff_operateur(expr->operateur) ;
                        printf("(");
                        afficherArbre(expr->gauche);
                        printf(", ");
                        afficherArbre(expr->droite);
                        printf(")");
						break ;
               case VALEUR:
                  	printf("%d", expr->valeur);
					break ;
	}
}

int evaluation(Ast expr) {
      // A COMPLETER !
	int a;
	if (expr->nature==OPERATION){
			if(expr->operateur==N_PLUS){
				return evaluation(expr->gauche)+evaluation(expr->droite);
			}
			if(expr->operateur==N_MOINS){
				return evaluation(expr->gauche)-evaluation(expr->droite);
			}
			if(expr->operateur==N_MUL){
				return evaluation(expr->gauche)*evaluation(expr->droite);
			}
			if(expr->operateur==N_DIV){
				a=evaluation(expr->droite);
				if(a==0){
					printf("Erreur : Division par 0\n");
					exit(2);
				}
				return evaluation(expr->gauche)/a;
			}
			return 0;
		}
	else {
			return expr->valeur;
		}
	}


