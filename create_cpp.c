
#include "generation.h"
#include <stdio.h>
#include <stdlib.h>

extern const char types[][20];
extern const char op[][4];
extern const char wf_size[][5];

int main(int argc, char* argv[]){

	if(argc!=2){
		return 1;
	}


	FILE* f;
	int i, j, k;
/*	char buffer[150];
	char** args;
	char type[20];
	char name[20];
	args = (char**)malloc(sizeof(char*)*3);
	args[0] = (char*)malloc(sizeof(char)*20);
	args[1] = (char*)malloc(sizeof(char)*20);
	args[2] = (char*)malloc(sizeof(char)*20);
*/
	f = fopen(argv[1], "w");

	//macros
	fprintf(f, "extern \"C\" {\n#include \"widefloat_float_ext.h\"\n}\n\n\n#include \"wf_classes.h\"\n\n\n");

	//constructors
	fprintf(f, "\n\t/* constructors */\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		constructor(f, i, -1);
		for(j=CPP_TYPE;j<TYPE_NB;j++){
			if(j==i){
				continue;
			}
			constructor(f, i, j);
		}
	}

	//casts
	fprintf(f, "\n\t/* casts */\n\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<WF_TYPE;j++){
			cast(f, i, j);
		}
	}

	//arithmetic
	fprintf(f, "\n\n\t/* operators : + - * / */\n");

	for(i=ARITH;i<ASSIGN;i++){
		for(j=CPP_TYPE;j<TYPE_NB;j++){
			for(k=WF_TYPE;k<TYPE_NB;k++){
				arith(f, j, i, k);
			}
		}
		for(j=WF_TYPE;j<TYPE_NB;j++){
			for(k=CPP_TYPE;k<WF_TYPE;k++){
				arith(f, j, i, k);
			}
		}
	}

	fclose(f);

/*	free(args[0]);
	free(args[1]);
	free(args[2]);
	free(args);
*/
	return 0;
}
