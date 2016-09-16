
#include "wf_classes.hpp"

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NB 1000
#define NB_ 50


int main(int argc, char* argv[]){

	clock_t t1, t2, t3;
	int i, j, k, fd, test_nb;
	FLOAT wf1, wf2, wf3;
	double d;

	if(argc==1){
		printf("number of parameters for \"test_op\": 1\n");
		return 1;
	}

	srand(time(NULL));

	test_nb=atoi(argv[1]);

	fd = open("wf_op", O_WRONLY);

	//tests the following operators : +, -, *, /, =, +=, -=, *=, /=, <, >, <=, >=, ==, !=, constructor, cast, square root, fma

	// +
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 + wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// -
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 - wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// *
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 * wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// /
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB_;j++){
			wf1 / wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB_;

	write(fd, &t3, sizeof(clock_t));

	// =
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 = wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// +=
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 += wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// -=
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 -= wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// *=
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 *= wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// /=
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB_;j++){
			wf1 /= wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB_;

	write(fd, &t3, sizeof(clock_t));

	// <
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 < wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// >
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 > wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// <=
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 <= wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// >=
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 >= wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// !=
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 != wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// ==
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			wf1 == wf2;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// square root
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			SQRT(wf1);
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// fma
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf2 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		wf3 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			FMA(wf1, wf2, wf3);
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// cast to int
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			(int)wf1;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// cast to double
	t3 = 0;

	for(i=0;i<test_nb;i++){
		wf1 = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			(double)wf1;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// constructor from int
	t3 = 0;

	for(i=0;i<test_nb;i++){
		t1 = clock();
		k = rand();
		for(j=0;j<NB;j++){
			(FLOAT)k;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));

	// constructor from double
	t3 = 0;

	for(i=0;i<test_nb;i++){
		d = ((rand()/RAND_MAX)-0.5)*(rand()/100000.0);
		t1 = clock();
		for(j=0;j<NB;j++){
			(FLOAT)d;
		}
		t2 = clock();
		t3 += t2-t1;
	}

	t3/=NB;

	write(fd, &t3, sizeof(clock_t));




	close(fd);

	return 0;
}
