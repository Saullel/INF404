#include "ast_construction.h"

Ast creer_operation(Ast* opde_gauche , TypeOperateur opr ,  Ast* opde_droit) 
{
      Ast expr ;
      expr = (Ast) malloc (sizeof(NoeudAst));
      expr->nature = OPERATION;
      expr->operateur = opr;
      if (opde_gauche == NULL || opde_droit == NULL) {
         printf("ERREUR_EXPRESSION\n") ;
	 exit(1) ;
      } else {
         expr->gauche = *opde_gauche;
         expr->droite = *opde_droit;
      } ;
      return expr ;
}

Ast creer_valeur(int val) { 
      Ast expr ;
      expr = (Ast) malloc (sizeof(NoeudAst));
      expr->nature = VALEUR;
      expr->valeur = val;
      return expr ;
}
