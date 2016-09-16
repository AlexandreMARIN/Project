
	#include "horner.h"

	int main(){

		FLOTTANT A[]={-8.0, 12.0, -6.0, 1.0};
		polynome* p=conversion((FLOTTANT*)A, 4);
		FLOTTANT theta;
		int i;

		printf("Voici quelques valeurs au voisinage de 2 pour le polynôme suivant (algorithme de horner second ordre en haut et premier ordre en bas) :\n");

		afficher_polynome(p);

		for(i=0;i<10;i++){
			theta=2.0+((FLOTTANT)i)*0.001;
			printf("\np(%.3lf) = %.20lf\n           %.20lf\n", (double)theta, (double)horner(theta, p), (double)horner_po(theta, A, 3));
		}








		return 0;
	}
