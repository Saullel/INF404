#include "analyse_syntaxique.h"

/*-----------------------------------------------------------------------------------------------*/

void Rec_eag(Ast *a){
	Rec_seq_terme(a);
}

void Rec_seq_terme(Ast *a){
	Rec_terme(a);
	Rec_suite_seq_terme(a);
}

void Rec_suite_seq_terme(Ast *a){
	Ast opde_d;
	Ast expr;
	if (lexeme_courant().nature == PLUS) {
		avancer();
		Rec_terme(&opde_d);
		expr=creer_operation(a,N_PLUS,&opde_d);
		*a=expr;
		Rec_suite_seq_terme(a);
	}
	else if (lexeme_courant().nature == MOINS){
		avancer();
		Rec_terme(&opde_d);
		expr=creer_operation(a,N_MOINS,&opde_d);
		*a=expr;
		Rec_suite_seq_terme(a);
	}

	/*else {
		printf("Erreur syntaxique: Il devrait y avoir un operateur  %d,%d\n",lexeme_courant().ligne,lexeme_courant().colonne);
		exit(1);
	}*/
}	

void Rec_terme(Ast *a){
	Rec_seq_facteur(a);
	
}

void Rec_seq_facteur(Ast *a){
	Rec_facteur(a);
	Rec_suite_seq_facteur(a);
	
}	
	
void Rec_suite_seq_facteur(Ast *a){
	Ast opde_d;
	Ast expr;
	if (lexeme_courant().nature == MUL){
		avancer();
		Rec_facteur(&opde_d);
		expr=creer_operation(a,N_MUL,&opde_d);
		*a=expr;
		Rec_suite_seq_facteur(a);
	}
}


void Rec_facteur(Ast *a){
	if(lexeme_courant().nature == ENTIER){	
		*a=creer_valeur(lexeme_courant().valeur);
		avancer();
	}
	else if(lexeme_courant().nature == PARO) {
		avancer();
		Rec_eag(a);
		if(lexeme_courant().nature != PARF){
			printf("Erreur syntaxique: Il devrait y avoir une parenthese fermante  l:%d,c:%d\n",lexeme_courant().ligne,lexeme_courant().colonne);
			exit(1);
		}
		avancer();
	}	 	
	else {
		printf("Erreur syntaxique: Il devrait y avoir un entier ou une parenthese ouvrante l:%d,c:%d\n",lexeme_courant().ligne,lexeme_courant().colonne);
		exit(1);
	}	
}
			



int analyser (char* nom_fichier, int* res) {
	Ast arbre;
	demarrer(nom_fichier);
	
	Rec_eag(&arbre);

	if(lexeme_courant().nature!=FIN_SEQUENCE){
		printf("Erreur syntaxique: il devrait y avoir un operateur l:%d,c:%d\n",lexeme_courant().ligne,lexeme_courant().colonne);
		return 0;
	}
	else {
		afficherArbre(arbre);
		printf("\n");
		*res=evaluation(arbre);
		return 1;
	}
	
}

