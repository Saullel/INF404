#include <stdio.h>
#include "graphsimple.h"
#define NMAX 50
#define PIX 50



/* Menu de Depart */
	/* Jouer*/
   /*Quitter*/
  
void objectif(int x1,int y1, int x2, int y2){
/*Creation d'Objectif*/

ChangerCouleur(2);
	RectanglePlein(PIX*x1,PIX*y1, PIX*x2,PIX*y2);
	ChangerCouleur(5);
	RectanglePlein(PIX*x1,PIX*(y1+0.5), PIX*(x2-0.5),PIX*y2);
	RectanglePlein(PIX*(x1+0.5),PIX*y1, PIX*x2,PIX*(y2-0.5));
}


void perso(int x1,int y1, int x2, int y2){
/*Céation du Personnage*/

ChangerCouleur(4);
	RectanglePlein(PIX*x1,PIX*y1, PIX*x2,PIX*y2);
	ChangerCouleur(3);
	RectanglePlein(PIX*x1,PIX*(y1+0.5), PIX*(x2-0.5),PIX*y2);
	RectanglePlein(PIX*(x1+0.5),PIX*y1, PIX*x2,PIX*(y2-0.5));
}


int Menu (){
   int x,y,b;/*Possition du clique de la sourie, x: abscisse, y: ordonnee, b: bouton de la sourie avec lequelle on a cliquer*/
	Initialiser(PIX*4,PIX*6);
	Ecrire((PIX*2)-15,25, "Projet");
    Ecrire(((2*PIX))-37,50, "Jeu du codage");
	/*Case Jouer*/
    Rectangle(PIX-20,PIX*2-25,PIX*3+20,PIX*3-25);
    Ecrire((PIX*2)-12,(PIX*3)-45, "Jouer");
	/*Case Quitter*/
    Rectangle(PIX-20,PIX*3,PIX*3+20,PIX*4);
    Ecrire((PIX*2)-17,(PIX*5)-70, "Quitter");
	/*Case Jeu d'essaie*/
	 Rectangle(PIX-20,PIX*5-25,PIX*3+20,PIX*5+25);
    Ecrire((PIX*2)-33,(PIX*5)+5, "Jeu d'essaie");
    AttendreClicXY(&x,&y,&b);
	/*Cliquer sur quitter*/
   if((x>PIX-20 && x<PIX*3+20) && (y>PIX*3 && y<PIX*4)){
      return -1;
   }/*Cliquer sur Jeu d'essaie*/
   else if((x>PIX-20 && x<PIX*3+20) && (y>PIX*5-25 && y<PIX*5+25)){
	  return -2;
	}
	/*Clique autre part*/
   else{
      Clore();
      return 0;
   }
}



/*Choix du mode de jeu*/
	/*Mode 1*/
    /*Mode 2*/
    /*Mode 3*/
    /*Mode 4*/
	/*Mode 5*/





int SelectModes(){
	
   int x,y,b,niv =0;
   Initialiser(PIX*4 ,PIX*10.5);

   Ecrire(PIX*2-18 , 25, "Niveaux");
   Ecrire(PIX*1 + 10    , 50, "De Difficultes");

	/*Case Niveaux 1*/
   Rectangle(PIX-20 ,PIX*2-25,PIX*3+20 ,PIX*3-25);
   Ecrire((PIX*2-25),(PIX*2+4), "Niveaux 1");

	/*Case Niveaux 2*/
   Rectangle(PIX-20 ,PIX*3,PIX*3+20 ,PIX*4);
   Ecrire(PIX*2-25,PIX*3+29, "Niveaux 2");

	/*Case Niveaux 3*/
   Rectangle(PIX-20 ,PIX*5-25,PIX*3+20 ,PIX*6-25);
   Ecrire(PIX*2-25,PIX*5+4, "Niveaux 3");

	/*Case Niveaux 4*/
   Rectangle(PIX-20 ,PIX*6,PIX*3+20 ,PIX*7);
   Ecrire(PIX*2-25,PIX*6+29, "Niveaux 4");

	/*Case Niveaux 5*/
   Rectangle(PIX-20 ,PIX*8-25,PIX*3+20 ,PIX*9-25);
   Ecrire(PIX*2-25,PIX*8+4, "Niveaux 5");

	/*Case Quitter*/
   Rectangle(PIX-20 ,PIX*9,PIX*3+20 ,PIX*10);
   Ecrire(PIX*2-20,PIX*9+29, "Quitter");


   AttendreClicXY(&x,&y,&b);
	/*Cliquer sur Niveaux 1*/
   if((x>PIX-20 && x<PIX*3+20) && (y>PIX*2-25 && y<PIX*3-25)){
      niv=1;
   }
	/*Cliquer sur Niveaux 2*/
   else if((x>PIX-20 && x<PIX*3+20) && (y>PIX*2+25 && y<PIX*4)){
      niv=2;
   }
	/*Cliquer sur Niveaux 3*/
   else if((x>PIX-20 && x<PIX*3+20) && (y>PIX*5-25 && y<PIX*6-25)){
      niv=3;
   }
	/*Cliquer sur Niveaux 4*/
   else if((x>PIX-20 && x<PIX*3+20) && (y>PIX*6 && y<PIX*7)){
      niv=4;
   }
	/*Cliquer sur Niveaux 5*/
   else if((x>PIX-20 && x<PIX*3+20) && (y>PIX*8-25 && y<PIX*9-25)){
      niv=5;
   }
	/*Cliquer sur Quitter*/
	else if((x>PIX-20 && x<PIX*3+20) && (y>PIX*9 && y<PIX*10)){
      niv=0;
   }
   Clore();
   return niv;
}

void Regles(){
	Initialiser(PIX*9 ,PIX*9);

	/*Ligne(PIX*4+25, 0 , PIX*4+25 , PIX*9);*/

	Ecrire(PIX*4+8, PIX-20, "Regles");






	AttendreClic();
	
}





int Fin_de_niveau(int niv){
	int x,y,b;/*Possition du clique de la sourie, x: abscisse, y: ordonnee, b: bouton de la sourie avec lequelle on a cliquer*/
	Initialiser(PIX*9 ,PIX*4);

	Ecrire(PIX*4-9, PIX-20, "Fin du niveau");

	/*Case Recommencer*/
	Rectangle(PIX-20 ,PIX*1+25,PIX*3 ,PIX*3);
	Ecrire(PIX*1+10, PIX*2+18, "Recommencer");

	/*Case Quitter*/
	Rectangle(PIX*3+15 ,PIX*1+25,PIX*6-15 ,PIX*3);
	Ecrire(PIX*4+9, PIX*2+18, "Quitter");

	/*Case Niveau Suivant*/
	Rectangle(PIX*6 ,PIX*1+25,PIX*9-30 ,PIX*3);
	Ecrire(PIX*7-30, PIX*2+18, "Niveau Suivant");

	AttendreClicXY(&x,&y,&b);
	/*Cliquer sur Recommencer*/
   if((x>PIX-20 && x<PIX*3) && (y>PIX*1+25 && y<PIX*3)){
      niv=niv;
   }
	/*Cliquer sur Quitter*/
   else if((x>PIX*3+15 && x<PIX*6-15) && (y>PIX*1+25 && y<PIX*3)){
      niv=0;
   }
	/*Cliquer sur Niveau Suivant*/
   else if((x>PIX*6 && x<PIX*9-30) && (y>PIX*1+25 && y<PIX*3)){
      niv=niv+1;
	}
	Clore();
return niv;
}

void Niveau_1(){
	int x,y,b;/*Possition du clique de la sourie, x: abscisse, y: ordonnee, b: bouton de la sourie avec lequelle on a cliquer*/
	Initialiser(PIX*18, PIX*18);
	/*Contoure du Jeu*/
	Rectangle(PIX*5,PIX*5, PIX*15,PIX*15);
	Ligne(PIX*5,PIX*13,PIX*15,PIX*13);
	
	/*Couleur Noir*/
    ChangerCouleur(0);
	/*Creation du Sol*/
	RectanglePlein(PIX*5,PIX*13, PIX*15,PIX*15);

	/*Creation Du Personnage*/
	perso(6,12,7,13);
	/*Creation De L'Objectif*/
	objectif(13,12,14,13);

	AttendreClicXY(&x,&y,&b);
	Clore();
}


void Niveau_2(){
	int x,y,b;/*Possition du clique de la sourie, x: abscisse, y: ordonnee, b: bouton de la sourie avec lequelle on a cliquer*/
	Initialiser(PIX*20, PIX*20);
	/*Contoure du Jeu*/
	Rectangle(PIX*5,PIX*5, PIX*15,PIX*15);
	Ligne(PIX*5,PIX*13,PIX*15,PIX*13);


    /*Couleur Noir*/
    ChangerCouleur(0);
	/*Creation du Sol*/
	RectanglePlein(PIX*5,PIX*13, PIX*15,PIX*15);
	/*Creation Plateforme*/
	RectanglePlein(PIX*9,PIX*12,PIX*12,PIX*13);
	RectanglePlein(PIX*10,PIX*11,PIX*12,PIX*12);
	RectanglePlein(PIX*11,PIX*10,PIX*12,PIX*11);

	/*Creation Du Personnage*/
	perso(6,12,7,13);
	/*Creation De L'Objectif*/
	objectif(13,12,14,13);
 



	AttendreClicXY(&x,&y,&b);
	Clore();
}

void Niveau_3(){
	int x,y,b;/*Possition du clique de la sourie, x: abscisse, y: ordonnee, b: bouton de la sourie avec lequelle on a cliquer*/
	Initialiser(PIX*20, PIX*20);
	/*Contoure du Jeu*/
	Rectangle(PIX*5,PIX*5, PIX*15,PIX*15);
	Ligne(PIX*5,PIX*13,PIX*15,PIX*13);

	/*Couleur Noir*/
    ChangerCouleur(0);
	/*Creation du Sol*/
	RectanglePlein(PIX*5,PIX*13, PIX*15,PIX*15); /*Sol*/
	/*Creation Plateforme*/
	RectanglePlein(PIX*8,PIX*12,PIX*9,PIX*13);
	RectanglePlein(PIX*9,PIX*11,PIX*12,PIX*12);
	RectanglePlein(PIX*13,PIX*11,PIX*14,PIX*13);

	/*Creation Du Personnage*/
	perso(6,12,7,13);
	/*Creation De L'Objectif*/
	objectif(9,12,10,13);
 



	AttendreClicXY(&x,&y,&b);
	Clore();
}


void Niveau_4(){
	int x,y,b;/*Possition du clique de la sourie, x: abscisse, y: ordonnee, b: bouton de la sourie avec lequelle on a cliquer*/
	Initialiser(PIX*20, PIX*20);
	/*Contoure du Jeu*/
	Rectangle(PIX*5,PIX*5, PIX*15,PIX*15);
	Ligne(PIX*5,PIX*13,PIX*15,PIX*13);

	/*Couleur Noir*/
    ChangerCouleur(0);
	/*Creation du Sol*/
	RectanglePlein(PIX*5,PIX*13, PIX*15,PIX*15);
	/*Creation Plateforme*/
	RectanglePlein(PIX*5,PIX*11,PIX*6,PIX*12);
	RectanglePlein(PIX*6,PIX*12,PIX*7,PIX*13);
	RectanglePlein(PIX*8,PIX*9,PIX*9,PIX*11);
	RectanglePlein(PIX*9,PIX*11,PIX*12,PIX*12);
	RectanglePlein(PIX*14,PIX*11,PIX*15,PIX*13);

	/*Creation Du Personnage*/
	perso(9,10,10,11);
	/*Creation De L'Objectif*/
	objectif(5,10,6,11);
 



	AttendreClicXY(&x,&y,&b);
	Clore();
}


void Niveau_5(){
	int x,y,b;/*Possition du clique de la sourie, x: abscisse, y: ordonnee, b: bouton de la sourie avec lequelle on a cliquer*/
	Initialiser(PIX*20, PIX*20);
	/*Contoure du Jeu*/
	Rectangle(PIX*5,PIX*5, PIX*15,PIX*15);
	Ligne(PIX*5,PIX*13,PIX*15,PIX*13);

	/*Couleur Noir*/
    ChangerCouleur(0);
	/*Creation Plateforme*/
	RectanglePlein(PIX*5,PIX*13, PIX*15,PIX*15);
	RectanglePlein(PIX*6,PIX*12,PIX*7,PIX*13);
	RectanglePlein(PIX*8,PIX*11,PIX*10,PIX*12);
	RectanglePlein(PIX*10,PIX*12,PIX*11,PIX*13);
	RectanglePlein(PIX*14,PIX*11,PIX*15,PIX*13);
	RectanglePlein(PIX*12,PIX*8,PIX*15,PIX*9);
	RectanglePlein(PIX*12,PIX*8,PIX*13,PIX*11);	
	RectanglePlein(PIX*9,PIX*8,PIX*11,PIX*9);
	RectanglePlein(PIX*7,PIX*6,PIX*8,PIX*7);



	/*Creation Du Personnage*/
	perso(7,5,8,6);
	/*Creation De L'Objectif*/
	objectif(5,12,6,13);
 



	AttendreClicXY(&x,&y,&b);
	Clore();
}

void Niveau (int niv){
	/*Selection du niveau en fonction de la case Cliquer*/
	if(niv==1)
		Niveau_1();
	else if(niv==2)
		Niveau_2();
	else if(niv==3)
		Niveau_3();
	else if(niv==4)
		Niveau_4();
	else if(niv==5)
		Niveau_5();

		/*niv=Fin_de_niveau(niv);*/
	
}





int main(){
	int niv=0;
	/*Lancer Menu */
	/*Si Clique Quitter, programme terminer */
	if(Menu()==-1){
    	  return -1;
   	}
	
	/*Lancement du Jeu*/
	do{
		niv=SelectModes();/*Selection du niveau*/

	printf("%d", niv);/*A Supprimer*/

		Niveau(niv);/*Lancement du niveau choisi*/
		/*Si cliquer sur Quitter*/
		/*Lance le menu de depart*/
		if(niv==0){
			niv=Menu();
		}
	}while(niv!=-1);/*Tant que On ne clique pas sur Quitter Dans Le Menu de Depart*/ 
		printf("\nLe jeu est termine !\n");
	/*Regles();*/
return 0;
}
	










