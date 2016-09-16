
#include "lu.h"


#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

	clock_t t1, t2, t3;
	int n, i, fd, test_nb;
	FLOAT **M, **P;

	if(argc<3){
		printf("number of parameters for \"test_efficiency\": 2\n");
		return 1;
	}
	srand(time(NULL));

	test_nb=atoi(argv[2]);
	n = atoi(argv[1]);
	t3 = 0;

	for(i=0;i<test_nb;i++){
		M = charger_matrice(NULL, &n, &n);
		t1 = clock();
		calcul_inverse(n, M, &P);
		t2 = clock();
		t3 += t2-t1;
	}

	fd = open("wf_eff", O_WRONLY);

	write(fd, &t3, sizeof(clock_t));

	close(fd);

	return 0;
}
