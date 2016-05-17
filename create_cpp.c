
#include "generation.h"
#include <stdio.h>
#include <stdlib.h>

extern const char types[][25];
extern const char op[][4];
extern const char wf_size[][5];

int main(int argc, char* argv[]){

	FILE* f;
	int i, j, k;
	f = fopen("wf_classes.cpp", "w");

	//macros
	fprintf(f, "extern \"C\" {\n#include \"widefloat_float_ext.h\"\n}\n\n\n#include \"wf_classes.hpp\"\n\n\n");

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


	return 0;
}
