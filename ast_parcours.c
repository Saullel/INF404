

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
		case N_EQ:
			printf("=") ;
			break;
		case N_NEQ:
			printf("!=") ;
			break;
		case N_SUP:
			printf(">") ;
			break;
		case N_INF:
			printf("<") ;
			break;
		case N_SEQ:
			printf(">=") ;
			break;
		case N_IEQ:
			printf("<=") ;
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
			if(expr->operateur==N_EQ){
				return evaluation(expr->gauche)==evaluation(expr->droite);
			}
			if(expr->operateur==N_NEQ){
				return evaluation(expr->gauche)!=evaluation(expr->droite);
			}
			if(expr->operateur==N_SUP){
				return evaluation(expr->gauche)>evaluation(expr->droite);
			}
			if(expr->operateur==N_INF){
				return evaluation(expr->gauche)<evaluation(expr->droite);
			}
			if(expr->operateur==N_SEQ){
				return evaluation(expr->gauche)>=evaluation(expr->droite);
			}
			if(expr->operateur==N_IEQ){
				return evaluation(expr->gauche)<=evaluation(expr->droite);
			}
			return 0;
		}
	else {
			return expr->valeur;
		}
	}


