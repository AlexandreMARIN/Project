	#include "matrice.h"

	void libere_matrice(int n, FLOTTANT** M){
		int i;
		for(i=0;i<n;i++){
			free(M[i]);
		}
		free(M);
	}

	FLOTTANT** charger_matrice(char* nom_fic, int* m, int* n){
		int i, j;
		double aux;
		FLOTTANT** M;
		FILE* f;

		if(!nom_fic){
			srand(time(NULL));
			M=(FLOTTANT**)malloc(sizeof(FLOTTANT*)*(*m));
			for(i=0;i<*m;i++){
				M[i]=(FLOTTANT*)malloc(sizeof(FLOTTANT)*(*n));
				for(j=0;j<*n;j++){
					M[i][j]=((FLOTTANT)rand()/RAND_MAX)*100.0;
				}
			}
			return M;
		}

		f = fopen(nom_fic, "r");

		fscanf(f, "%d %d", m, n);

		M=(FLOTTANT**)malloc(sizeof(FLOTTANT*)*(*m));

		for(i=0;i<*m;i++){
			M[i]=(FLOTTANT*)malloc(sizeof(FLOTTANT)*(*n));
			for(j=0;j<*n;j++){
				fscanf(f, "%lf", &aux);
				M[i][j] = aux;
			}
		}

		fclose(f);
		return M;
	}

	void afficher_matrice(int m, int n, FLOTTANT** M){

		int i, j;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				printf("%7.2lf ", (double)(M[i][j]));
			}
			printf("\n");
		}

	}

	FLOTTANT** identite(int n){

		FLOTTANT** I=charger_matrice(NULL, &n, &n);
		int i, j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){
					I[i][j]=1.0;
				}else{
					I[i][j]=0.0;
				}
			}
		}
		return I;
	}
