
	#include "horner.h"

	void afficher_polynome(polynome* p){
		printf("\n[");
		while(p){
			printf("(%.2lf, %d), ", (double)p->coeff, p->deg);
			p=p->suiv;
		}
		printf("\b\b]\n");
	}


	polynome* conversion(FLOTTANT *A, int n){
		int i;
		polynome *p=NULL, *monome;
		for(i=0;i<n;i++){
			monome=(polynome*)malloc(sizeof(polynome));
			monome->deg=i;
			monome->coeff=A[i];
			ajouter_monome(&p, monome);
		}
		return p;
	}


	void ajouter_monome(polynome ** p, polynome* monome){
		polynome *ptr=*p;

		if(*p==NULL){
			*p=monome;
			monome->suiv=NULL;
			return;
		}

		if((*p)->deg<monome->deg){
			monome->suiv=*p;
			*p=monome;
			return;
		}

		while(ptr->suiv && ptr->suiv->deg>monome->deg){
			ptr=ptr->suiv;
		}


		monome->suiv=ptr->suiv;
		ptr->suiv=monome;
		
	}

	FLOTTANT * exponentiation(FLOTTANT theta, int n){
		int i;
		FLOTTANT * C = (FLOTTANT*)malloc(sizeof(FLOTTANT)*n);
		C[0]=theta;
		for(i=1;i<n;i++){
			C[i]=C[i-1]*C[i-1];
		}

		return C;
	}


	FLOTTANT horner(FLOTTANT theta, polynome* p){
		FLOTTANT aux;
		FLOTTANT *C = exponentiation(theta, 5);//pour des polynomes de faible degré
		aux = horner_bis(p, C, 0);
		free(C);
		return aux;
	}

	FLOTTANT horner_bis(polynome* p, FLOTTANT* C, int i){

		polynome* p2=NULL, *ptr, *aux, *ptr2;
		FLOTTANT res;

		if(!p){
			return 0.0;
		}

		if(p->deg==0){
			return p->coeff;
		}

		ptr=p;
		while(ptr && ptr->deg%2==0){
			ptr->deg/=2;
			aux=ptr;
			ptr=ptr->suiv;
			aux->suiv=NULL;
			ajouter_monome(&p2, aux);
		}

		if(ptr){
			ptr->deg/=2;
			ptr2=ptr->suiv;
			while(ptr2){
				if(ptr2->deg%2==0){
					aux=ptr2;
					ptr2->deg/=2;
					ptr2=ptr2->suiv;
					ptr->suiv=ptr2;
					aux->suiv=NULL;
					ajouter_monome(&p2, aux);
				}else{
					ptr2->deg/=2;
					ptr=ptr2;
					ptr2=ptr2->suiv;
				}
			}
		}

		res = horner_bis(p2, C, i+1)+C[i]*horner_bis(p, C, i+1);

		ptr=p;
		while(ptr){
			ptr->deg=2*(ptr->deg)+1;
			ptr=ptr->suiv;
		}

		ptr=p2;
		while(ptr){
			ptr->deg*=2;
			aux=ptr->suiv;
			ptr->suiv=NULL;
			ajouter_monome(&p, ptr);
			ptr=aux;
		}//polynome intact

		return res;
	}

	FLOTTANT horner_po(FLOTTANT theta, FLOTTANT* p, int deg){
		FLOTTANT res = p[deg];//pour une représentation dense du polynôme, les monômes étant triés par ordre croissant des degrés

		deg--;
		while(deg>=0){
			res*=theta;
			res+=p[deg];
			deg--;
		}

		return res;
	}

