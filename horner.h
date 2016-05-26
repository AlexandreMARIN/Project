
	

	#ifndef HORNER_H

	#define HORNER_H

	#include <stdlib.h>
	#include <stdio.h>
	#include "matrice.h"

	typedef struct polynome_ {
		FLOTTANT coeff;
		int deg;
		struct polynome_ * suiv;
	} polynome;

	void afficher_polynome(polynome*);

	polynome* conversion(FLOTTANT *, int n);

	FLOTTANT horner(FLOTTANT theta, polynome*);

	FLOTTANT horner_bis(polynome*, FLOTTANT*, int i);

	void ajouter_monome(polynome **, polynome* monome);

	FLOTTANT * exponentiation(FLOTTANT theta, int n);

	FLOTTANT horner_po(FLOTTANT theta, FLOTTANT*, int deg);

	#endif
