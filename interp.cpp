
	#include "interp.h"

	void interp_poly(){
	/*
	F : fonction à approximer
	K : nombre de points de la subdivision régulière
	A, B : extrémités de l'intervalle
	pas : pas
	C : dérivée à l'origine A
	
	il suffit de résoudre le système MX=b où :

	Les fonctions polynomiales f_i sont de degré 2, de coefficients a_i, b_i, et c_i

	X=(c_i, b_i, a_i)=f_i

	M=(1, A+(B-A)i/(K-1), (A+(B-A)i/(K-1))²)
	  (1, A+(B-A)(i+1)/(K-1), (A+(B-A)(i+1)/(K-1))²)
	  (0, 1, 2(A+(B-A)i/(K-1)))

	b=(F(A+(B-A)i/(K-1)), F(A+(B-A)(i+1)/(K-1)), F'(A+(B-A)i/(K-1)))

	On calcule les images de F avec les fonctions de la biliothèque math.h; De plus :
	F'(A)=C
	F'(A+(B-A)i/(K-1))=f_i'(A+(B-A)i/(K-1))=f_(i-1)'(A+(B-A)i/(K-1))
			=b_(i-1)+2*a_(i-1)(A+(B-A)i/(K-1)) si i>0
	*/

	int i, j, k;
	FLOTTANT *f_i, **M, *b;

	f_i = (FLOTTANT*)malloc(sizeof(FLOTTANT)*3);
	b = (FLOTTANT*)malloc(sizeof(FLOTTANT)*3);
	M = (FLOTTANT**)malloc(sizeof(FLOTTANT*)*3);
	M[0] = (FLOTTANT*)malloc(sizeof(FLOTTANT)*3);
	M[1] = (FLOTTANT*)malloc(sizeof(FLOTTANT)*3);
	M[2] = (FLOTTANT*)malloc(sizeof(FLOTTANT)*3);

	M[0][0] = 1.0;
	M[1][0] = 1.0;
	M[2][0] = 0.0;
	M[2][1] = 1.0;
	M[1][1] = A;
	b[2] = C;
	b[1] = F(A);

		for(i=0;i<K-1;i++){

			M[0][1] = M[1][1];//M[0][1] := x_i
			M[1][1] = A+(B-A)*((FLOTTANT)(i+1))/(K-1);
			M[0][2] = M[0][1]*M[0][1];
			M[1][2] = M[1][1]*M[1][1];
			M[2][2] = M[0][1]*2.0;
			/* M complétée */
			b[0] = b[1];
			b[1] = F(M[1][1]);

			//Résolution du système puis calcul par pas de p
			res_sys_lin(3, M, b, f_i);

			//nombre de valeurs à calculer : x(i+1)-x_i/pas
			j = (int)((M[1][1]-M[0][1])/pas);
			for(k=0;k<=j;k++){
				printf("%.20lf %.20lf %.20lf\n", (double)(M[0][1]+((FLOTTANT)k)*pas), (double)(F(M[0][1]+((FLOTTANT)k)*pas)), (double)horner_po(M[0][1]+((FLOTTANT)k)*pas, f_i, 2));
			}

			b[2] = f_i[1]+2.0*f_i[2]*M[1][1];

		}

	free(M[0]);
	free(M[1]);
	free(M[2]);
	free(M);
	free(b);
	free(f_i);

	}

	void interp_poly_lag(int n, FLOTTANT *e, FLOTTANT* y){
		int i, j;
		FLOTTANT *a, **M;

		a = (FLOTTANT*)malloc(sizeof(FLOTTANT)*n);
		M = (FLOTTANT**)malloc(sizeof(FLOTTANT*)*n);
		for(i=0;i<n;i++){
			M[i] = (FLOTTANT*)malloc(sizeof(FLOTTANT)*n);
		}


		for(i=0;i<n;i++){
			M[i][0] = 1.0;
		}

		for(i=0;i<n;i++){
			for(j=1;j<n;j++){
				M[i][j] = M[i][j-1]*e[i];
			}
		}

		res_sys_lin(n, M, y, a);

		printf("\"y = ");
		for(i=n-1;i>=0;i--){
			if(i!=n-1 && a[i]>=0.0){
				printf("+");
			}
			printf("%.2lf", (double)a[i]);
			if(i!=0){
				printf(" x^(%d) ", i);
			}
		}
		printf("\"\n");

		tri_rapide(e, n);//e est modifié !
		j = (int)((e[n-1]-e[0])/pas);
		for(i=0;i<j;i++){
			printf("%.20lf %.20lf\n", (double)(e[0]+((double)i)*pas), (double)(horner_po(e[0]+((double)i)*pas, a, n-1)));
		}

		for(i=0;i<n;i++){
			free(M[i]);
		}
		free(M);
		free(a);
	}
