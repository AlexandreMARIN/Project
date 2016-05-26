
	#ifndef MATRICE_H

	#define MATRICE_H

		#include <stdio.h>
		#include <stdlib.h>
		#include "wf_classes.hpp"
		#define FLOTTANT wf512_t

		void libere_matrice(int n, FLOTTANT** M);

		FLOTTANT** charger_matrice(char* nom_fic, int* m, int* n);

		void afficher_matrice(int m, int n, FLOTTANT** M);

		FLOTTANT** identite(int n);








	#endif
