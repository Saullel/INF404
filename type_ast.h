
#ifndef __TYPE_AST__
#define __TYPE_AST__ 

typedef enum {OPERATION, VALEUR} TypeAst ;
typedef enum {N_PLUS, N_MUL, N_MOINS, N_DIV, N_EQ, N_NEQ, N_SUP, N_INF, N_SEQ, N_IEQ} TypeOperateur ;

typedef struct noeud { 
	TypeAst nature ;
	TypeOperateur operateur ;
	struct noeud *gauche, *droite ;
      	int valeur ;
} NoeudAst ;

typedef NoeudAst *Ast ;

#endif  
