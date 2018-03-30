#include <stdio.h>

#ifdef TERRAIN
int Terrain1[10][10] ={	{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,2},
						{1,1,1,1,1,1,1,1,1,1 }};
#endif
#define LMAX 50
/*typedef struct T{
	int largeur;
	int hauteur;
	int grille[LMAX][LMAX];
} Terrain;
typedef struct MaillonTerrain{
	Terrain T;
	MaillonTerrain* Suivant;
} ListeTerrain;
*/

void AfficherTerrain(int numTerrain);

/*
int LargeurTerrain(Terrain T){
	return T.largeur;
}

int HauteurTerrain(Terrain T){
	return T.hauteur;
}

int CaseTerrain(Terrain T, int i, int j){
	if (i<HauteurTerrain(T)&&i>=0&&j<LargeurTerrain(T)&&j>=0)
		return T.grille[i][j];
	else
		return -1;
}

Terrain ChargerTerrain(FILE* f){
	Terrain T;
	fscanf(f,"%d",T->largeur);
	fscanf(f,"%d",T->hauteur);
	for(int i;i<LargeurTerrain(T);i++){
		for(int j;j<HauteurTerrain(T);j++){
			fscanf(f,"%d",T->grille[i][j]);
		}
	}
	return T;
}

/*ListeTerrain* ChargeurTerrains(char* fichier ){
	FILE* f=
}
*/


