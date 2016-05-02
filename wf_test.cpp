
#include "wf_classes.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[]){


	wf256_t a;

	wf256_t g = 'e';

	wf512_t y;

	double v = 8.0;


	wf256_t var1 = 5.0;

	wf512_t var2 = 6.0;

	cout << (double)a << "\n" << "g = \'e\' = " <<(int)g << "\n" << "v = 8.0\ng + v = "<< (double)(g+v) << "\n" <<(double)var1<< " * " << (double)var2<<" = "<< (float)(var1*var2) << "\n";









	return 0;
}
