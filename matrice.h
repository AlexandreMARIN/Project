
	#ifndef MATRICE_H

	#define MATRICE_H

		#include <cstdio>
		#include <cstdlib>
		#include <ctime>
		#include "wf_classes.hpp"
		#ifndef FLOTTANT
		#define FLOTTANT wf512_t
		#endif
		using namespace std;

		void libere_matrice(int n, FLOTTANT** M);

		FLOTTANT** charger_matrice(char* nom_fic, int* m, int* n);

		void afficher_matrice(int m, int n, FLOTTANT** M);

		FLOTTANT** identite(int n);








	#endif
