#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>

#include "var.h"//name of types
#include "generation.h"//counters

#define TEST_NB 1500

// parameters for bar diagrams
#define SCALE 20000000.0
#define STEP 0.00000005//50 ns
#define MAX_VAL 10.0

#define SCALE_ 2000000.0
#define STEP_ 0.000001//1 µs
#define MAX_VAL_ 10.0
#define OFFSET_ 0.000005

#define SCALE__ 400000000.0
#define STEP__ 0.000000005//5 ns
#define MAX_VAL__ 10.0

#define SCALE___ 10000000.0
#define STEP___ 0.0000001//100 ns
#define MAX_VAL___ 10.0

#define SCALE____ 200000000.0
#define STEP____ 0.000000005//5 ns
#define MAX_VAL____ 10.0

const char colors[][20] = {"yellow!15!black", "blue", "green", "cyan", "yellow", "magenta", "orange", "purple", "red", "blue!20", "green!20", "red!20!black", "blue!20!black", "green!20!black", "orange!40", "red!33!blue", "yellow!33!black", "red", "cyan", "green", "blue!80!black"};

int main(int argc, char* argv[1]){

	//compiles tests, executes them and gathers measures

	int i, j, fd;
	char buffer1[100], buffer2[100], buffer3[100];
	clock_t dur[TYPE_NB-WF_TYPE][OP_NB+6];
	FILE* f;

	if(argc==1){
		printf("One parameter is expected\n");
		return 1;
	}

	if(argc==2 || strcmp(argv[2], "skip")!=0){

		//named pipe for results of tests
		if(mkfifo("wf_op", S_IRUSR|S_IWUSR)==-1){
			printf("mkfifo fails\n");
		}

		for(i=WF_TYPE;i<TYPE_NB;i++){
			//we need : wf_classes.o, widefloat_float.o, test_op.o

			if(fork()==0){
				strcpy(buffer1, "FLOAT=");
				strcat(buffer1, types[i]);
				strcpy(buffer2, "SQRT=sqrt_to_");
				strcat(buffer2, types[i]);
				strcpy(buffer3, "FMA=fma_to_");
				strcat(buffer3, types[i]);
				execl("/usr/bin/g++", "g++", "-D", buffer1, "-D", buffer2, "-D", buffer3, "-o", "test_op.o", "-c", "test_op.cpp", (char*)NULL);
			}
			wait(NULL);


			if(fork()==0){
				if(strcmp(argv[1], "c")==0){
					execl("/usr/bin/g++", "g++", "-o", "test_op", "widefloat_float.o", "wf_classes.o", "test_op.o", (char*)NULL);
				}else{
					execl("/usr/bin/g++", "g++", "-o", "test_op", "wf_classes.o", "test_op.o", (char*)NULL);
				}
			}
			wait(NULL);

			sprintf(buffer1, "%d", TEST_NB);

			if(fork()==0){
				execl("./test_op", "./test_op", buffer1, (char*)NULL);
			}

			fd = open("wf_op", O_RDONLY);

			for(j=0;j<OP_NB+6;j++){

				read(fd, dur[i-WF_TYPE]+j, sizeof(clock_t));

			}

			close(fd);

			wait(NULL);

		}


		//writes measures in files
		for(i=0;i<OP_NB+6;i++){
			sprintf(buffer1, "data_%d.txt", i);
			f = fopen(buffer1, "w");
			for(j=WF_TYPE;j<TYPE_NB;j++){
				if(i==COMP-1 || i==ASSIGN-1){// operators / /=
					fprintf(f, "%.2lf %d\n", SCALE_*((((double)dur[j-WF_TYPE][i])/(TEST_NB*CLOCKS_PER_SEC))-OFFSET_), j-WF_TYPE);
				}else{
					if(i>=COMP && i<OP_NB+1){//comparisons ans sqrt
						fprintf(f, "%.2lf %d\n", ((double)dur[j-WF_TYPE][i]*SCALE__)/(TEST_NB*CLOCKS_PER_SEC), (j-WF_TYPE));
					}else{
						if(i>=OP_NB+1 && i<=OP_NB+2){//fma, cast to int
							fprintf(f, "%.2lf %d\n", ((double)dur[j-WF_TYPE][i]*SCALE___)/(TEST_NB*CLOCKS_PER_SEC), j-WF_TYPE);
						}else{
							if(i>=OP_NB+3){
								fprintf(f, "%.2lf %d\n", ((double)dur[j-WF_TYPE][i]*SCALE____)/(TEST_NB*CLOCKS_PER_SEC), j-WF_TYPE);
							}else{
								fprintf(f, "%.2lf %d\n", ((double)dur[j-WF_TYPE][i]*SCALE)/(TEST_NB*CLOCKS_PER_SEC), j-WF_TYPE);
							}
						}
					}
				}
			}
			fclose(f);
		}
	}

	//writes a TeX file including graphs
	f = fopen("durations.tex", "w");

fprintf(f, "\\documentclass[a4paper]{article}\n\\usepackage{tikz}\n\\usepackage[latin1]{inputenc}\n\n\\definecolor{orange}{rgb}{1,0.5,0}\n\\definecolor{purple}{rgb}{0.6,0.2,0.8}\n\\begin{document}\n\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.2lf,ystep=16] (%.1lf,16);", SCALE*STEP, MAX_VAL);

	// + - *
	for(i=0;i<=2;i++){
		fprintf(f, "\n\\draw[line width=2mm,color=%s, yshift=%dmm] plot[xcomb] file {data_%d.txt};", colors[i], i*2, i);
	}

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw (-0.25, %d) node[left]{\\ttfamily wf%s\\_t};", i-WF_TYPE, wf_size[i]);
	}

	for(i=0;i<5;i++){
		fprintf(f, "\n\\draw (%.1lf, -0.5) node{%.0lf};", SCALE*i*STEP*2, i*100.0);
	}

	fprintf(f, "\n\\end{tikzpicture}\n\\end{center}\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.2lf,ystep=16] (%.1lf,16);", SCALE_*STEP_, MAX_VAL_);
	// / and /=

	for(i=3;i<COMP;i+=COMP-4){
		fprintf(f, "\n\\draw[line width=2mm,color=%s, yshift=%dmm] plot[xcomb] file {data_%d.txt};", colors[i], ((i-3)%2)*2, i);
	}

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw (-0.25, %d) node[left]{\\ttfamily wf%s\\_t};", i-WF_TYPE, wf_size[i]);
	}

	for(i=0;i<5;i++){
		fprintf(f, "\n\\draw (%.1lf, -0.5) node{%.0lf};", SCALE_*i*STEP_, i+OFFSET_*1000000);
	}

	fprintf(f, "\n\\end{tikzpicture}\n\\end{center}\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.2lf,ystep=16] (%.1lf,16);", SCALE*STEP, MAX_VAL);
	// =, +=, -=, *=

	for(i=ASSIGN+1;i<COMP-1;i++){
		fprintf(f, "\n\\draw[line width=2mm,color=%s, yshift=%dmm] plot[xcomb] file {data_%d.txt};", colors[i], (i-ASSIGN-1)*2, i);
	}

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw (-0.25, %d) node[left]{\\ttfamily wf%s\\_t};", i-WF_TYPE, wf_size[i]);
	}

	for(i=0;i<5;i++){
		fprintf(f, "\n\\draw (%.1lf, -0.5) node{%.0lf};", SCALE*i*STEP*2, i*100.0);
	}

	fprintf(f, "\n\\end{tikzpicture}\n\\end{center}\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.2lf,ystep=16] (%.1lf,16);", SCALE__*STEP__, MAX_VAL__);
	// < > <= >=

	for(i=COMP;i<OP_NB-2;i++){
		fprintf(f, "\n\\draw[line width=2mm,color=%s, yshift=%dmm] plot[xcomb] file {data_%d.txt};", colors[i], (i-COMP)*2, i);
	}

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw (-0.25, %d) node[left]{\\ttfamily wf%s\\_t};", (i-WF_TYPE), wf_size[i]);
	}

	for(i=0;i<5;i++){
		fprintf(f, "\n\\draw (%.1lf, -0.5) node{%.0lf};", SCALE__*i*STEP__, i*5.0);
	}

	fprintf(f, "\n\\end{tikzpicture}\n\\end{center}\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.2lf,ystep=16] (%.1lf,16);", SCALE__*STEP__, MAX_VAL__);
	// != == square root

	for(i=OP_NB-2;i<OP_NB+1;i++){
		fprintf(f, "\n\\draw[line width=2mm,color=%s, yshift=%dmm] plot[xcomb] file {data_%d.txt};", colors[i], (i-OP_NB+2)*2, i);
	}

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw (-0.25, %d) node[left]{\\ttfamily wf%s\\_t};", (i-WF_TYPE), wf_size[i]);
	}

	for(i=0;i<5;i++){
		fprintf(f, "\n\\draw (%.1lf, -0.5) node{%.0lf};", SCALE__*i*STEP__, i*5.0);
	}

	fprintf(f, "\n\\end{tikzpicture}\n\\end{center}\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.2lf,ystep=16] (%.1lf,16);", SCALE___*STEP___, MAX_VAL___);
	// fma, casts to int

	for(i=OP_NB+1;i<OP_NB+3;i++){
		fprintf(f, "\n\\draw[line width=2mm,color=%s, yshift=%dmm] plot[xcomb] file {data_%d.txt};", colors[i], (i-OP_NB-1)*2, i);
	}

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw (-0.25, %d) node[left]{\\ttfamily wf%s\\_t};", (i-WF_TYPE), wf_size[i]);
	}

	for(i=0;i<5;i++){
		fprintf(f, "\n\\draw (%.1lf, -0.5) node{%.0lf};", SCALE___*i*STEP___*2, i*200.0);
	}

	fprintf(f, "\n\\end{tikzpicture}\n\\end{center}\n\\begin{center}\n\\begin{tikzpicture}\n\n\\draw[very thin] (0,0) grid[xstep=%.2lf,ystep=16] (%.1lf,16);", SCALE____*STEP____, MAX_VAL____);
	// constructors and cast to double

	for(i=OP_NB+3;i<OP_NB+6;i++){
		fprintf(f, "\n\\draw[line width=2mm,color=%s, yshift=%dmm] plot[xcomb] file {data_%d.txt};", colors[i], (i-OP_NB-3)*2, i);
	}

	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\\draw (-0.25, %d) node[left]{\\ttfamily wf%s\\_t};", (i-WF_TYPE), wf_size[i]);
	}

	for(i=0;i<5;i++){
		fprintf(f, "\n\\draw (%.1lf, -0.5) node{%.0lf};", SCALE____*i*STEP____*2, i*10.0);
	}

	fprintf(f, "\n\n\\end{tikzpicture}\n\\end{center}\n\\end{document}");

	fclose(f);



	return 0;
}
