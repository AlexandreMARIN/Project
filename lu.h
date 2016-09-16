
	#ifndef LU_H

	#define LU_H
		#include <cmath>
		#include "matrice.h"

		void mult_mat(int, int, int, FLOTTANT**, FLOTTANT**, FLOTTANT**);

		void decomp_LU(int, FLOTTANT **, const FLOTTANT **, char** /*[n-1][2]*/, char *);

		void afficher_LU(int, FLOTTANT**);

		FLOTTANT det(int, FLOTTANT**);

		void res_sys_lin_L(int, FLOTTANT **, FLOTTANT*, FLOTTANT *);

		void res_sys_lin_U(int, FLOTTANT**, FLOTTANT*, FLOTTANT*);

		void res_sys_lin(int, FLOTTANT**, FLOTTANT*, FLOTTANT*);

		int calcul_inverse(int, FLOTTANT**, FLOTTANT ***/*B=A^-1*/);

		void tri_rapide(FLOTTANT* , int );
	#endif
