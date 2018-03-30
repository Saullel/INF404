/* ------------------------------------------------------------------------
-- module analyse_lexicale
--
-- analyse lexicale d'une expression arithmetique
--
-- J-P. Peyrin, G. Serasset (version initiale) : janvier 1999
-- P.Habraken - 18/01/2010
--
-- 10 juin 2006 - PH :
-- remplacement record a champs variants par record "plat"
-- remplacement traitement iteratif par automate
--
-- Aout 2016 - LM : version C
------------------------------------------------------------------------ */

#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 

#include "lecture_caracteres.h"
#include "analyse_lexicale.h"

   /* --------------------------------------------------------------------- */


/* Les variables et fonctions locales au module */

   Lexeme lexeme_en_cours ;	/* le lexeme courant */

   void ajouter_caractere (char *s, char c);
   int est_separateur(char c ) ;
   int est_chiffre(char c ) ;
   int est_caractere(char c);
   int est_correct_dans_nom(char c);
   int est_nom_variable(char c);
   int est_symbole(char c ) ;
   Nature_Lexeme est_operation(Lexeme l);
   void reconnaitre_lexeme();

   /* --------------------------------------------------------------------- */

   void demarrer(char *nom_fichier) {
      demarrer_car(nom_fichier);
      avancer();
   }

   /* --------------------------------------------------------------------- */

   void avancer() {
      reconnaitre_lexeme();
   } 

   /* --------------------------------------------------------------------- */

   Lexeme lexeme_courant() {
      return lexeme_en_cours;
   } 

   /* --------------------------------------------------------------------- */

   int fin_de_sequence() {
      return lexeme_en_cours.nature == FIN_SEQUENCE;
   }

   /* --------------------------------------------------------------------- */

   void arreter() {
      arreter_car() ;
   }

   /* --------------------------------------------------------------------- */


   // reconnaissance d'un nouveau lexeme
   // etat initial : le caractere courant est soit separateur 
   //                soit le 1er caractere d'un lexeme
   // etat final : 
   //       - un nouveau lexeme est reconnu dans lexeme_en_cours
   //       - le caractere courant est soit la fin de fichier, 
   //		soit un separateur,  soit le 1er caractere d'un lexeme

   void reconnaitre_lexeme() {
   	typedef enum {E_INIT, E_ENTIER, /*E_FLOAT,*/ E_CAR, E_FIN} Etat_Automate ;
     Etat_Automate etat=E_INIT;

	// on commence par lire les separateurs
     while (est_separateur(caractere_courant())) {
        	avancer_car() ;
     } ;

     lexeme_en_cours.chaine[0] = '\0' ;

     // on utilise ensuite un automate pour reconnaitre le prochain lexeme

      while (etat != E_FIN) {
	    switch (etat) {
			case E_INIT:
				if (fin_de_sequence_car() != 0) {
                  		lexeme_en_cours.nature = FIN_SEQUENCE;
                  		etat = E_FIN;
				} 
				else {
		   			if  (est_chiffre(caractere_courant())) {
		     			lexeme_en_cours.nature = ENTIER;
                     		lexeme_en_cours.ligne = numero_ligne();
                     		lexeme_en_cours.colonne = numero_colonne();
		     			ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
                     		lexeme_en_cours.valeur = caractere_courant() - '0';
                    	 	etat = E_ENTIER;
	           		} 
					else {
		       			if  (est_symbole(caractere_courant())) { 
		        				lexeme_en_cours.ligne = numero_ligne();
                        			lexeme_en_cours.colonne = numero_colonne();
		        				ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
                        			switch (caractere_courant()) {
                           			case '+':
                           				lexeme_en_cours.nature = PLUS;
                           				etat = E_FIN;
			   						break;
                           			case '-':
                           				lexeme_en_cours.nature = MOINS;
                           				etat = E_FIN;
			   						break;
                           			case '*':
                           				lexeme_en_cours.nature = MUL;
                           				etat = E_FIN;
			   						break;
								case '/':
                           				lexeme_en_cours.nature = DIV;
                           				etat = E_FIN;
			   						break;
								case '(':
                           				lexeme_en_cours.nature = PARO;
                           				etat = E_FIN;
			   						break;
								case ')':
                           				lexeme_en_cours.nature = PARF;
                           				etat = E_FIN;
			   						break;
                           case '=':
                                    lexeme_en_cours.nature = AFF;
                                    etat = E_FIN;
                                    break;
                           case ';':
                                    lexeme_en_cours.nature = SEPAFF;
                                    etat = E_FIN;
                                    break;
		           				default:
									printf("Erreur_Lexicale") ;
				 					exit(0) ;
						
							} ;
						} 
						else if (est_caractere(caractere_courant())) {
							lexeme_en_cours.ligne = numero_ligne();
                     			lexeme_en_cours.colonne = numero_colonne();
		     				ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
							etat = E_CAR;
						}
						else {
				 			lexeme_en_cours.nature = ERREUR;
				 			lexeme_en_cours.ligne = numero_ligne();
                     lexeme_en_cours.colonne = numero_colonne();
		     	 			ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
				 			printf("Erreur_Lexicale : %c caractere non reconnu\n",caractere_courant()) ;
				 			etat = E_FIN;
	               		};
		  			} ;
		   			avancer_car() ;
	        		};
				break ;

			case E_ENTIER:
                  	if (est_chiffre(caractere_courant())) { 
		  			ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
                  		lexeme_en_cours.valeur = lexeme_en_cours.valeur * 10 + 
					caractere_courant() - '0';
                  		etat = E_ENTIER;
                  		avancer_car ();
               	} 
				//else if (caractere_courant() == '.') { 
				//	ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
				//	etat = E_FLOAT;
				//	avancer_car ();
				//}
				else {
                  		etat = E_FIN;
               	}
				break ;
			
			//case E_FLOAT:
			//	if (est_chiffre(caractere_courant())) { 
		  	//		ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
               //   	lexeme_en_cours.valeur = lexeme_en_cours.valeur * 10 + 
			//		caractere_courant() - '0';
               //   	etat = E_FLOAT;
               //  		avancer_car ();
               //	} 
			//	else if (caractere_courant() == '.') { }
			//	else {
               //  		etat = E_FIN;
               //	}
			//	break;
			
			case E_CAR:
				if (est_nom_variable(caractere_courant())) {
					ajouter_caractere (lexeme_en_cours.chaine, caractere_courant()) ;
					etat = E_CAR;
					avancer_car();
				} 
				else if (est_separateur(caractere_courant())){
					lexeme_en_cours.nature = IDF;
					etat = E_FIN;
				}
            else {
               lexeme_en_cours.nature = ERREUR;
               etat = E_FIN;
            }
				break;
					
				
	     	case E_FIN: 
				break ;
	    	} ;
	} ;
 }

   // --------------------------------------------------------------------- 

   // cette fonction ajoute le caractere c a la fin de la chaine s 
   // (la chaine s est donc modifiee)
 
   void ajouter_caractere (char *s, char c) {
	int l ;
	
	l = strlen(s) ;
	s[l] = c ;
	s[l+1] = '\0' ;
   }

   /* --------------------------------------------------------------------- */

   // vaut vrai ssi c designe un caractere separateur
   int est_separateur(char c) { 
      return c == ' ' || c == '\t' || c == '\n' ;
   }

   /* --------------------------------------------------------------------- */

   // vaut vrai ssi c designe un caractere chiffre
   int est_chiffre(char c) {
      return c >= '0' && c <= '9' ;
   }

/* --------------------------------------------------------------------- */

   // vaut vrai ssi c designe un caractere 
   int est_caractere(char c) {
      return c >= 'a' && c <= 'z' ;
   }


   /* --------------------------------------------------------------------- */

   // vaut vrai ssi c designe un caractere 
   int est_correct_dans_nom(char c) {
      return c == '_' ;
   }

    /* --------------------------------------------------------------------- */

   // vaut vrai ssi c designe un caractere 
   int est_nom_variable(char c) {
      return (est_caractere(c) || est_chiffre(c) || est_correct_dans_nom(c));
   }
   
   /* --------------------------------------------------------------------- */

   // vaut vrai ssi c designe un caractere correspondant a un symbole arithmetique
   int est_symbole(char c)  {
      switch (c) {
         case '+':  
	 	case '-':  
	 	case '*':
	 	case '/':
		case '(':
		case ')':
      case '=':
      case ';':
            return 1;

         default:
            return 0;
      } 
   }

 /* --------------------------------------------------------------------- */

   // vaut vrai ssi c designe une operation arithmetique
   Nature_Lexeme est_operation(Lexeme l)  {
      if (!strcmp(l.chaine,"plus")) {
	 	return PLUS;
	}
	if (!strcmp(l.chaine,"moins")) {
	 	return MOINS;
	}
	if (!strcmp(l.chaine,"mult")) {
	 	return MUL;
	}	
	if (!strcmp(l.chaine,"div")) {
	 	return DIV;
	} 
	else { printf("Erreur_Lexicale\n") ;
			return ERREUR; }	
      
   }
   
   /* --------------------------------------------------------------------- */

   // renvoie la chaine de caracteres correspondant a la nature du lexeme
   char *Nature_vers_Chaine (Nature_Lexeme nature) {
	switch (nature) {
		case ENTIER: return "ENTIER" ;
		case PLUS: return "PLUS" ;
      		case MOINS: return "MOINS" ;            
      		case MUL: return "MUL" ;    
			case DIV: return "DIV";   
			case PARO: return "PARO"; 
			case PARF: return "PARF"; 
      		case FIN_SEQUENCE: return "FIN_SEQUENCE" ;     
      		default: return "ERREUR" ;            
	} ;
   } 

   /* --------------------------------------------------------------------- */

   // affiche a l'ecran le lexeme l
   void afficher(Lexeme l) {

      switch (l.nature) {
         case FIN_SEQUENCE: 
            break;
         default: 
            printf("(ligne %d, ", l.ligne);
            printf("colonne %d) : ",l.colonne);
	    printf("[") ;
            printf("nature = %s", Nature_vers_Chaine(l.nature)) ;
            printf(", chaine = %s, ", l.chaine) ;
            switch(l.nature) {
                 case ENTIER:
                      printf("valeur = %d", l.valeur);
                 default:
                      break;
            } ;
	    printf("]\n") ;
	} ;
   }

   /* --------------------------------------------------------------------- */

