
#include "wf_classes.hpp"
#include <math.h>
#include <iostream>
using namespace std;

int main(){

wf512_t a(-300);
wf512_t b(9);
wf512_t c = 1;
wf256_t d = 1;
wf256_t deux = 2;
wf256_t trois = 3;
wf256_t quatre = 4;
cout<<wf_fpstate::get_flags()<<"\n";
cout<<(char)a<<"\n";
cout<<wf_fpstate::get_flags()<<"\n";
wf_fpstate::set_flags((widefloat_flags_t)0);
b/=9;

cout<<(double)b<<"\n";

cout<<(b!=0)<<"\n";

cout<<(c==d)<<"\n";
c=c*d;
c=1;
c=c/0;
cout<<wf_fpstate::get_flags()<<"\n";
+a;
cout<<((double)(-a))<<"\n";
cout<<((double)(+a))<<"\n";
cout<<((double)sqrt_to_wf256_t(-a))<<"\n";
cout<<((double)fma_to_wf256_t(deux, trois, quatre))<<'\n';
	return 0;
}
