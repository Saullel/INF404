#include "analyse_syntaxique.h"



/*-----------------------------------------------------------------------------------------------*/
void seq_affectation(Ast *a, TableDesSymboles *T){
	while(lexeme_courant().nature != FIN_SEQUENCE){
		rec_affectation(a, T);
	}
}


void rec_pgm(Ast *a, TableDesSymboles *T){
	rec_seq_inst(a, T);
}

void rec_seq_inst(Ast *a, TableDesSymboles *T){
	rec_inst(a, T);
	rec_suite_seq_inst(a, T);
}

void rec_suite_seq_inst(Ast *a, TableDesSymboles *T){
	if(lexeme_courant().nature != FIN_SEQUENCE && lexeme_courant().nature != FI){
		rec_seq_inst(a, T);
	}
}

void rec_condition(Ast *a, TableDesSymboles *T, Ast* valRetour){
	Ast opde_g;
	Ast opde_d;
	Rec_eag(&opde_g, T);
	if(lexeme_courant().nature == EQ){
		avancer();
		Rec_eag(&opde_d, T);
		*valRetour=creer_operation(&opde_g,N_EQ,&opde_d);
	}
	else if(lexeme_courant().nature == NEQ){
		avancer();
		Rec_eag(&opde_d, T);
		*valRetour=creer_operation(&opde_g,N_NEQ,&opde_d);
	}
	else if(lexeme_courant().nature == SUP){
		avancer();
		Rec_eag(&opde_d, T);
		*valRetour=creer_operation(&opde_g,N_SUP,&opde_d);
	}
	else if(lexeme_courant().nature == SUPEQ){
		avancer();
		Rec_eag(&opde_d, T);
		*valRetour=creer_operation(&opde_g,N_SEQ,&opde_d);
	}
	else if(lexeme_courant().nature == INF){
		avancer();
		Rec_eag(&opde_d, T);
		*valRetour=creer_operation(&opde_g,N_INF,&opde_d);
	}
	else if(lexeme_courant().nature == INFEQ){
		avancer();
		Rec_eag(&opde_d, T);
		*valRetour=creer_operation(&opde_g,N_IEQ,&opde_d);
	}
	else {
		printf("Erreur syntaxique: l'operateur de comparaison n'est pas valide\n");
		exit(1);
	}
}



void rec_inst(Ast *a, TableDesSymboles *T){
	Ast cond=0;
	int res;
	if(lexeme_courant().nature == IF){
		avancer();
		rec_condition(a, T, &cond);
		res=evaluation(cond);
		if(res==1){
			if(lexeme_courant().nature == THEN){
				avancer();
				rec_seq_inst(a, T);
				if(lexeme_courant().nature == ELSE){
					while(lexeme_courant().nature != FIN_SEQUENCE || lexeme_courant().nature != FI){
						avancer();
					}
					if(lexeme_courant().nature == FIN_SEQUENCE){
						printf("Erreur syntaxique: la condition n'est pas valide (manque \"fin_si\")\n");
						exit(1);
					}
				}
				if(lexeme_courant().nature == FI){
					avancer();
				}
				if(lexeme_courant().nature == SEPAFF){
					printf("Attention syntaxe: il ne faut pas mettre de \";\" à la fin d'une condition\n");
					avancer();
				}

			}
			else{
				printf("Erreur syntaxique: la condition n'est pas valide (manque \"alors\")\n");
				exit(1);
			}
		}
		else{
			if(lexeme_courant().nature == THEN){
				while(lexeme_courant().nature != FIN_SEQUENCE && lexeme_courant().nature != ELSE && lexeme_courant().nature != FI){
						avancer();
					}
				if(lexeme_courant().nature == FIN_SEQUENCE){
					printf("Erreur syntaxique: la condition n'est pas valide (manque \"fin_si\")\n");
					exit(1);
				}
				else if(lexeme_courant().nature == ELSE){
					avancer();
					rec_seq_inst(a, T);
				}
				if(lexeme_courant().nature == FIN_SEQUENCE){
					printf("Erreur syntaxique: la condition n'est pas valide (manque \"fin_si\")\n");
					exit(1);
				}
				if(lexeme_courant().nature == FI){
					avancer();
				}
				if(lexeme_courant().nature == SEPAFF){
					printf("Attention syntaxe: il ne faut pas mettre de \";\" à la fin d'une condition\n");
					avancer();
				}

			}
			else{
				printf("Erreur syntaxique: la condition n'est pas valide (manque \"alors\")\n");
				exit(1);
			}
		}
	}
	
	else{
		rec_affectation(a, T);
	}
	
}







void rec_affectation(Ast *a, TableDesSymboles *T){
	if(lexeme_courant().nature == IDF)
	{
		int valeurIDF=0;
		char* nomIDF=malloc(sizeof(lexeme_courant().chaine));
		
	
		strcpy(nomIDF,(char*)lexeme_courant().chaine);
		avancer();
		if(lexeme_courant().nature == AFF)
		{
			avancer();
			Rec_eag(a, T);
			valeurIDF=evaluation(*a);
			insererNouvVal(T,nomIDF,valeurIDF);
		}
		else
		{
			printf("Erreur syntaxique: il manque une affectation [l:%d,c:%d]\n",lexeme_courant().ligne,lexeme_courant().colonne);
			exit(1);
		}
		if(lexeme_courant().nature == SEPAFF)
		{
			avancer();
		}
		else
		{
			printf("Erreur syntaxique: il manque un separateur [l:%d,c:%d]\n",lexeme_courant().ligne,lexeme_courant().colonne);	
			exit(1);
		}
	}
}


void Rec_eag(Ast *a, TableDesSymboles *T){
	Rec_seq_terme(a, T);
}

void Rec_seq_terme(Ast *a, TableDesSymboles *T){
	Rec_terme(a, T);
	Rec_suite_seq_terme(a, T);
}

void Rec_suite_seq_terme(Ast *a, TableDesSymboles *T){
	Ast opde_d;
	Ast expr;
	if (lexeme_courant().nature == PLUS) {
		avancer();
		Rec_terme(&opde_d, T);
		expr=creer_operation(a,N_PLUS,&opde_d);
		*a=expr;
		Rec_suite_seq_terme(a, T);
	}
	else if (lexeme_courant().nature == MOINS){
		avancer();
		Rec_terme(&opde_d, T);
		expr=creer_operation(a,N_MOINS,&opde_d);
		*a=expr;
		Rec_suite_seq_terme(a, T);
	}
}	

void Rec_terme(Ast *a, TableDesSymboles *T){
	Rec_seq_facteur(a, T);
	
}

void Rec_seq_facteur(Ast *a, TableDesSymboles *T){
	Rec_facteur(a, T);
	Rec_suite_seq_facteur(a, T);
}	
	
void Rec_suite_seq_facteur(Ast *a, TableDesSymboles *T){
	Ast opde_d;
	Ast expr;
	if (lexeme_courant().nature == MUL){
		avancer();
		Rec_facteur(&opde_d, T);
		expr=creer_operation(a,N_MUL,&opde_d);
		*a=expr;
		Rec_suite_seq_facteur(a, T);
	}
}


void Rec_facteur(Ast *a, TableDesSymboles *T){
	if(lexeme_courant().nature == ENTIER){	
		*a=creer_valeur(lexeme_courant().valeur);
		avancer();
	}
	else if(lexeme_courant().nature == PARO) {
		avancer();
		Rec_eag(a, T);
		if(lexeme_courant().nature != PARF){
			printf("Erreur syntaxique: Il devrait y avoir une parenthese fermante [l:%d,c:%d]\n",lexeme_courant().ligne,lexeme_courant().colonne);
			exit(1);
		}
		avancer();
	}
	else if(lexeme_courant().nature == IDF){
		int valeurIDF=0;
		char* nomIDF=malloc(sizeof(lexeme_courant().chaine));
		strcpy(nomIDF,(char*)lexeme_courant().chaine);
		if(consulterVal(T,nomIDF,&valeurIDF)==-1){
			printf("Erreur syntaxique: la variable %s n'existe pas [l:%d,c:%d]\n",nomIDF,lexeme_courant().ligne,lexeme_courant().colonne);
			exit(1);
		}
		else {
			*a=creer_valeur(valeurIDF);
			avancer();
		}
	} 	
	else {
		printf("Erreur syntaxique: Il devrait y avoir un entier ou une parenthese ouvrante [l:%d,c:%d]\n",lexeme_courant().ligne,lexeme_courant().colonne);
		exit(1);
	}	
}
			



int analyser (char* nom_fichier, int* res) {
	Ast arbre;
	TableDesSymboles* T;
	T=initTDS();
	demarrer(nom_fichier);
	
	//seq_affectation(&arbre, T);
	rec_pgm(&arbre, T);

	/*if(lexeme_courant().nature!=FIN_SEQUENCE){
		printf("Erreur syntaxique: il devrait y avoir un operateur [l:%d,c:%d]\n",lexeme_courant().ligne,lexeme_courant().colonne);
		return 0;
	}
	else {
		*/
		//afficherArbre(arbre);
		//printf("\n");
		AfficherTDS(T);
		//*res=evaluation(arbre);
	return 1;
	
	
}

