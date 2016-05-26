	#include "lu.h"

	#define EPSILON 0.000001

	/*Tous les appels à "malloc" sont supposés renvoyer une valeur différente de NULL*/

	void mult_mat(int n, int m, int p, FLOTTANT** A, FLOTTANT** B, FLOTTANT** C){//produit + précis

		int i, j, k;
		for(i=0;i<n;i++){
			for(j=0;j<p;j++){
				C[i][j] = 0.0;
				for(k=0;k<m;k++){
					C[i][j] += A[i][k]*B[k][j];
				}
			}
		}
	}


	void decomp_LU(int n, FLOTTANT **LU, const FLOTTANT **A, char** P/*[n-1][2]*/, char *nbperm){

		//LU contient la partie inf de L et la partie sup de U
		//PA=LU

		*nbperm=0;

		int i, j, k, l, imax;
		FLOTTANT* aux, max;

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				LU[i][j]=A[i][j];
			}
		}

		for(j=0;j<n-1;j++){
			max=fabs(LU[j][j]);
			imax=j;
			for(i=j+1;i<n;i++){
				if(fabs(LU[i][j])>max){
					max=fabs(LU[i][j]);
					imax=i;
				}
			}//sélection du max de la colonne courante
			if(max<=EPSILON){
				continue;//La colonne courante est quasiment nulle
			}
			if(imax!=j){//enregistrement des transpositions
				P[(int)*nbperm][0]=imax;
				P[(int)*nbperm][1]=j;
				(*nbperm)++;
			}
			i=imax;
			for(k=j;k<n;k++){
				if(k==i){
					continue;
				}
				LU[k][j]/=LU[i][j];//pour L
				for(l=j+1;l<n;l++){//pour U
					LU[k][l]-=LU[i][l]*LU[k][j];//L[k][j] déjà normalisé
				}

			}
			aux=LU[i];//transposition
			LU[i]=LU[j];
			LU[j]=aux;
		}


	}

	void afficher_LU(int n, FLOTTANT** A){

		FLOTTANT ** LU, **matP, *aux;
		char** P;
		char nbperm;

		int i, j;
		P=(char**)malloc(sizeof(char*)*(n-1));//n-1 transpositions au plus
		for(i=0;i<n;i++){
			P[i]=(char*)malloc(sizeof(char)*2);
		}

		LU=charger_matrice(NULL, &n, &n);

		decomp_LU(n, LU, (const FLOTTANT **)A, P, &nbperm);

		//création de la matrice de permutation
		matP=identite(n);
		for(i=0;i<nbperm;i++){
			aux=matP[(int)P[i][0]];
			matP[(int)P[i][0]]=matP[(int)P[i][1]];
			matP[(int)P[i][1]]=aux;
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%5.0lf", (double)matP[i][j]);//Id
			}
			for(j=0;j<n;j++){
				printf("%5.1lf", (double)A[i][j]);//A
			}
			if(2*i>=n-1 && 2*i<=n){
				printf(" =");
			}else{
				printf("  ");
			}
			printf("\n");
		}
		printf("\n\n");
		for(i=0;i<n;i++){
			//L puis U
			//L : j<i, j==i, j>i
			//U : j<i, j>=i
			for(j=0;j<i;j++){
				printf("%5.1lf", (double)LU[i][j]);
			}
			printf("  1.0");
			for(j=i+1;j<n;j++){
				printf("  0.0");
			}

			printf(" ");

			for(j=0;j<i;j++){
				printf("  0.0");
			}
			for(j=i;j<n;j++){
				printf("%5.1lf", (double)LU[i][j]);
			}
			printf("\n");
		}

		libere_matrice(n, LU);
		libere_matrice(n, matP);
	}

	FLOTTANT det(int n, FLOTTANT** A){

		FLOTTANT ** LU, detA=1.0;
		char** P;
		char nbperm;

		int i;
		P=(char**)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++){
			P[i]=(char*)malloc(sizeof(char)*2);
		}

		LU=charger_matrice(NULL, &n, &n);

		decomp_LU(n, LU, (const FLOTTANT**)A, P, &nbperm);

		for(i=0;i<n;i++){
			detA*=LU[i][i];
		}

		if(nbperm%2==1){
			detA*=-1.0;
		}
		
		for(i=0;i<nbperm;i++){
			free(P[i]);
		}
		free(P);
		libere_matrice(n, LU);

		return detA;
	}

	void tri_rapide(FLOTTANT* tab, int t){
		if(t<=1){
			return;
		}
		//pivot : élément du milieu
		int ind = (t-1)/2, i=0, j=t-1;
		FLOTTANT aux;
		while(j>i){
			while(tab[i]<tab[ind]){
				i++;
			}
			while(tab[ind]<tab[j]){
				j--;
			}
			if(tab[ind]==tab[i] && tab[ind]==tab[j]){
				while(tab[i]<=tab[ind] && i<ind){
					i++;
				}
				if(i<ind){
					//échange
					aux=tab[i];
					tab[i]=tab[j];
					tab[j]=aux;
					if(j==ind){
						ind=i;
					}
					continue;
				}
				while(tab[j]>=tab[ind] && ind<j){
					j--;
				}
				if(j>ind){
					//échange
					aux=tab[i];
					tab[i]=tab[j];
					tab[j]=aux;
					ind=j;
					continue;
				}
				break;
			}
			if(j>i){
				//échange
				aux=tab[i];
				tab[i]=tab[j];
				tab[j]=aux;
				if(i==ind){
					ind=j;
				}else{
					if(j==ind){
						ind=i;
					}
				}
			}
		}

		tri_rapide(tab, ind);
		tri_rapide(tab+ind+1, t-ind-1);
	}

	//pour résoudre un système linéaire LX=b, avec L triangulaire inférieure avec des 1 sur la diagonale
	void res_sys_lin_L(int n, FLOTTANT **L, FLOTTANT* b, FLOTTANT *X){
		int i, j;
		//X déjà alloué...

		X[0] = b[0];
		for(i=1;i<n;i++){
			X[i] = b[i];
			for(j=0;j<i;j++){
				X[i] -= L[i][j]*X[j];
			}
		}
	}

	//pour résoudre un système linéaire Ux=b, avec U triangulaire supérieure
	void res_sys_lin_U(int n, FLOTTANT**U, FLOTTANT* X, FLOTTANT* x){
		//x supposé déjà alloué
		int i, j;
		for(i=n-1;i>=0;i--){
			x[i] = X[i];
			for(j=i+1;j<n;j++){
				x[i] -= U[i][j]*x[j];
			}
			x[i]/=U[i][i];
		}
	}

	void res_sys_lin(int n, FLOTTANT** A, FLOTTANT* b, FLOTTANT* x){
		//x supposé déjà alloué
		//d'abord en supposant que A est inversible, on cherche x tel que Ax = b

		//décomposition LU: LUx=Pb, on cherche X tel que LX=Pb, puis x tel que Ux= X

		//permuter ici b avec P
		FLOTTANT ** LU, *X, aux, detA=1.0;
		char** P;
		char nbperm;
		int i, j;

		P=(char**)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++){
			P[i]=(char*)malloc(sizeof(char)*2);
		}

		LU=charger_matrice(NULL, &n, &n);

		X = (FLOTTANT*)malloc(sizeof(FLOTTANT)*n);

		decomp_LU(n, LU, (const FLOTTANT**)A, P, &nbperm);

		for(i=0;i<n;i++){
			detA*=LU[i][i];
		}

		if(fabs(detA)<EPSILON){
			free(X);
			for(i=0;i<nbperm;i++){
				free(P[i]);
			}
			free(P);
			libere_matrice(n, LU);
			printf("Le système passé en paramètre n\'admet pas de solution unique\n");
			return;//matrice singulière ->nombre de solutions : 0 ou infini!
		}

		//permutations dans b
		for(i=0;i<nbperm;i++){
			aux=b[(int)P[i][1]];
			b[(int)P[i][1]]=b[(int)P[i][0]];
			b[(int)P[i][0]]=aux;
		}

		res_sys_lin_L(n, LU, b, X);
		res_sys_lin_U(n, LU, X, x);

		//retrouver l'ancien second membre
		for(i=nbperm-1;i>=0;i--){
			aux=b[(int)P[i][1]];
			b[(int)P[i][1]]=b[(int)P[i][0]];
			b[(int)P[i][0]]=aux;
		}

		free(X);
		for(i=0;i<nbperm;i++){
			free(P[i]);
		}
		free(P);
		libere_matrice(n, LU);
		/*if(n<=10){
			printf("\nRésolution du système (avec des flottants FLOTTANT précision):\n");
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					printf("%7.2lf", A[i][j]);
				}
				printf("  ");
				printf("x_(%d)", i+1);
				if(i==n/2){
					printf(" = ");
				}else{
					printf("   ");
				}
				printf("%6.2lf\n", b[i]);
			}

			printf("\nOn obtient x =\n");
			for(i=0;i<n;i++){
				printf("\t");
				printf("x_(%d)", i+1);
				if(i==n/2){
					printf(" = ");
				}else{
					printf("   ");
				}
				printf("%7.3lf\n", x[i]);
			}
			printf("\n\n");
		}*/
	}

	int calcul_inverse(int n, FLOTTANT** A, FLOTTANT *** B/*B=A^-1*/){
		FLOTTANT ** LU, *X, detA=1.0, aux, *b, *x;
		char** P;
		char nbperm;
		//B sera alloué ici

		b=(FLOTTANT *)calloc(n, sizeof(FLOTTANT));//b=(0,...,1,...,0)

		int i, j;
		P=(char**)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++){
			P[i]=(char*)malloc(sizeof(char)*2);
		}

		LU=charger_matrice(NULL, &n, &n);

		x = (FLOTTANT*)malloc(sizeof(FLOTTANT)*n);//Ux=X
		X = (FLOTTANT*)malloc(sizeof(FLOTTANT)*n);//LX=b

		decomp_LU(n, LU, (const FLOTTANT**)A, P, &nbperm);

		for(i=0;i<n;i++){
			detA*=LU[i][i];
		}

		if(fabs(detA)<=EPSILON){
			free(b);
			free(x);
			free(X);
			for(i=0;i<nbperm;i++){
				free(P[i]);
			}
			free(P);
			libere_matrice(n, LU);
			return 0;
		}

		*B=charger_matrice(NULL, &n, &n);

		//initialisation de b et permutation de b
		for(j=0;j<n;j++){
			for(i=0;i<j;i++){
				b[i]=0.0;
			}
			b[j]=1.0;
			for(i=j+1;i<n;i++){
				b[i]=0.0;
			}//second membre initialisé

			for(i=0;i<nbperm;i++){
				aux=b[(int)P[i][1]];
				b[(int)P[i][1]]=b[(int)P[i][0]];
				b[(int)P[i][0]]=aux;
			}//permutation terminée

			res_sys_lin_L(n, LU, b, X);
			res_sys_lin_U(n, LU, X, x);

			for(i=0;i<n;i++){
				(*B)[i][j]=x[i];
			}
		}

		free(b);
		free(x);
		free(X);
		for(i=0;i<nbperm;i++){
			free(P[i]);
		}
		free(P);
		libere_matrice(n, LU);
		return 1;
	}

