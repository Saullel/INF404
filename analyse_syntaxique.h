

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

#include "analyse_lexicale.h"
#include "ast_construction.h"
#include "ast_parcours.h"
#include "table_des_symboles.h"



void seq_affectation(Ast *a, TableDesSymboles *T);

void seq_affectation(Ast *a, TableDesSymboles *T);
void rec_pgm(Ast *a, TableDesSymboles *T);
void rec_seq_inst(Ast *a, TableDesSymboles *T);
void rec_suite_seq_inst(Ast *a, TableDesSymboles *T);
void rec_condition(Ast *a, TableDesSymboles *T, Ast* valRetour);
void rec_inst(Ast *a, TableDesSymboles *T);

void rec_affectation(Ast *a, TableDesSymboles *T);
void Rec_eag(Ast *a, TableDesSymboles *T);
void Rec_seq_terme(Ast *a, TableDesSymboles *T);
void Rec_suite_seq_terme(Ast *a, TableDesSymboles *T);
void Rec_terme(Ast *a, TableDesSymboles *T);
void Rec_seq_facteur(Ast *a, TableDesSymboles *T);
void Rec_suite_seq_facteur(Ast *a, TableDesSymboles *T);
void Rec_facteur(Ast *a, TableDesSymboles *T);


int analyser (char* nom_fichier, int* res);
	// e.i : indifferent
	// e.f : une EA a ete lue dans le fichier de nom nom_fichier 
	// si elle ne contient pas d'erreur de syntaxe un message est affiche
	// sinon le pgm se termine sur un message d'ereur


