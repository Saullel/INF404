
#include "terrains.h"

void AfficherTerrain(int num){

	int i,j;
	printf("\n");
	for(i=0;i<10;i++){
		printf("\t");
		for(j=0;j<10;j++){
			switch (Terrain1[i][j]){
				case 0:
					printf(" . ");
					break;
				case 1:
					printf("===");
					break;
				case 2:
					printf("-@-");
				default:
					break;
			}
		}
		printf("\n\n");
	}
	printf("\n\n");
}
