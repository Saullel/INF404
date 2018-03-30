

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include "analyse_lexicale.h"
#include "ast_construction.h"
#include "ast_parcours.h"



void Rec_eag(Ast *a);
void Rec_seq_terme(Ast *a);
void Rec_suite_seq_terme(Ast *a);
void Rec_terme(Ast *a);
void Rec_seq_facteur(Ast *a);
void Rec_suite_seq_facteur(Ast *a);
void Rec_facteur(Ast *a);


int analyser (char* nom_fichier, int* res);
	// e.i : indifferent
	// e.f : une EA a ete lue dans le fichier de nom nom_fichier 
	// si elle ne contient pas d'erreur de syntaxe un message est affiche
	// sinon le pgm se termine sur un message d'ereur


