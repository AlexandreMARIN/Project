#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "var.h"//name of types
#include "generation.h"//counters

#define TEST_NB 50
#define TEST_NB_DOUBLE 1500
#define PT_NB 5
#define XSCALE 2
#define YSCALE 1100
#define OFFSET 19
#define YOFFSET 0.015
#define COEFF 1
#define LENGTH(x) (COEFF*x+OFFSET)//length of matrices in tests, x in [1:PT_NB]

const char colors[][20] = {"", "blue", "green", "cyan", "yellow", "magenta", "orange", "purple", "red", "blue!20", "green!20", "red!20!black", "blue!20!black", "green!20!black", "orange!40", "red!33!blue", "yellow!33!black"};

int main(int argc, char* argv[1]){

	//compiles tests, executes them and gathers measures

	int i, j, fd;
	char buffer1[100];
	char buffer2[100];
	clock_t dur[TYPE_NB-WF_TYPE+1][PT_NB];
	FILE* f;

	if(argc==2 || strcmp(argv[2], "skip")!=0){
		for(i=WF_TYPE-1;i<TYPE_NB;i++){
			//we need : wf_classes.o, widefloat_float.o, lu.o, matrice.o, test_efficiency.o
			strcpy(buffer2, "-D FLOTTANT=");
			strcat(buffer2, types[i]);
			if(fork()==0){
				strcpy(buffer1, "-D FLOAT=");
				strcat(buffer1, types[i]);
				execl("/usr/bin/g++", "g++", buffer1, buffer2, "-o", "test_efficiency.o", "-c", "test_efficiency.cpp", (char*)NULL);
			}
			wait(NULL);

			if(fork()==0){
				execl("/usr/bin/g++", "g++", buffer2, "-o", "matrice.o", "-c", "matrice.cpp", (char*)NULL);
			}
			wait(NULL);

			if(fork()==0){
				execl("/usr/bin/g++", "g++", buffer2, "-o", "lu.o", "-c", "lu.cpp", (char*)NULL);
			}
			wait(NULL);

			if(fork()==0){
				if(strcmp(argv[1], "c")==0){
					execl("/usr/bin/g++", "g++", buffer2, "-o", "test_efficiency", "matrice.o", "lu.o", "widefloat_float.o", "wf_classes.o", "test_efficiency.o", (char*)NULL);
				}else{
					execl("/usr/bin/g++", "g++", buffer2, "-o", "test_efficiency", "matrice.o", "lu.o", "wf_classes.o", "test_efficiency.o", (char*)NULL);
				}
			}
			wait(NULL);

			//named pipe for results of tests
			mkfifo("wf_eff", S_IRUSR|S_IWUSR);

			if(strcmp(types[i], "double")==0){
				sprintf(buffer2, "%d", TEST_NB_DOUBLE);
			}else{
				sprintf(buffer2, "%d", TEST_NB);
			}

			for(j=1;j<=PT_NB;j++){
				if(fork()==0){
					sprintf(buffer1, "%d", LENGTH(j));
					execl("./test_efficiency", "test_efficiency", buffer1, buffer2, (char*)NULL);
				}

				fd = open("wf_eff", O_RDONLY);

				read(fd, (dur[i-WF_TYPE+1])+j-1, sizeof(clock_t));

				close(fd);

				wait(NULL);
			}

		}

		//writes measures in files
		for(i=WF_TYPE;i<TYPE_NB;i++){
			sprintf(buffer1, "lu_data_%s.txt", types[i]);
			f = fopen(buffer1, "w");
			for(j=1;j<=PT_NB;j++){
				fprintf(f, "%.2lf %.2lf\n", (double)(XSCALE*(LENGTH(j)-LENGTH(1))), YSCALE*((/*TEST_NB_DOUBLE**/((double)dur[i-WF_TYPE+1][j-1])/(TEST_NB*CLOCKS_PER_SEC/**dur[0][j-1]*/))-YOFFSET));
			}
			fclose(f);
		}
	}

	//writes a TeX file including graphs
	f = fopen("diagrams.tex", "w");

fprintf(f, "\\documentclass[a4paper]{article}\n\\usepackage{tikz}\n\\usepackage[latin1]{inputenc}\n\n\\definecolor{orange}{rgb}{1,0.5,0}\n\\definecolor{purple}{rgb}{0.6,0.2,0.8}\n\\begin{document}\n\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.1lf,ystep=%.2lf] (%d,20);", (double)(COEFF*XSCALE), (double)(0.0025*YSCALE), (int)((LENGTH(PT_NB)-LENGTH(1))*XSCALE)+1);

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw[thin,color=%s] plot[mark=*] file {lu_data_%s.txt} node[right, fill=white]{\\small \\ttfamily wf%s\\_{}t};", colors[i-WF_TYPE+1], types[i], wf_size[i]);
	}

	for(i=1;i<=PT_NB;i+=1){
		fprintf(f, "\n\\draw (%.1lf, -0.25) node[below]{%d};", (double)((LENGTH(i)-LENGTH(1))*XSCALE), LENGTH(i));
	}

	for(i=0;i<=15;i+=5){
		fprintf(f, "\n\\draw (-0.5, %.1lf) node{%.0lf};", (0.001*i)*YSCALE, (double)((i)+YOFFSET*1000.0));
	}

	fprintf(f, "\n\\draw[text width=12cm] (%.1lf,19) node{\\flushleft \\upshape \\'e{}volution de la dur\\'ee de \\texttt{calcul\\_inverse} en millisecondes, en fonction de la dimension de la matrice \\`a inverser et pour diff\\'e{}rents coefficients \\`a virgule flottante};", ((LENGTH(PT_NB)-LENGTH(1))*XSCALE)/2.0);

	fprintf(f, "\n\n\\end{tikzpicture}\n\\end{center}\n\\end{document}");

	fclose(f);



	return 0;
}
