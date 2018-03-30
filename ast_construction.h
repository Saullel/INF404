#include <stdlib.h>
#include <stdio.h> 

#include "type_ast.h"


Ast creer_operation(Ast *opde_gauche , TypeOperateur opr , Ast *opde_droit) ;
// renvoie un arbre abstrait de nature OPERATEUR,  d'operateur opr 
// et ayant opde_gauche et opde_droit pour fils gauche et droit

Ast creer_valeur(int val) ; 
// renvoie un arbre abstrait "feuille", de nature OPERATION  
// et de valeur val
