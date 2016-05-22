
#include "generation.h" 
#include <stdio.h>
#include <stdlib.h>

extern const char types[][25];
extern const char op[][4];
extern const char wf_size[][5];

int main(int argc, char* argv[]){


	FILE* f;
	int i, j, k;
	char buffer[150];
	char** args;
	char type[50];
	char name[50];
	args = (char**)malloc(sizeof(char*)*3);
	args[0] = (char*)malloc(sizeof(char)*50);
	args[1] = (char*)malloc(sizeof(char)*50);
	args[2] = (char*)malloc(sizeof(char)*50);

	f = fopen("wf_classes.hpp", "w");

	//macros
	fprintf(f, "#ifndef WF_CLASSES_HPP\n#define WF_CLASSES_HPP\n\nextern \"C\" {\n#include \"widefloat_float_types.h\"\n}\n\n#include <climits>\n");

	//declaration of all widefloat classes
	fprintf(f, "/*Declaration of all widefloat classes*/\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "class ");
		fprintf(f, "%s", types[i]);
		fprintf(f, ";\n");
	}

	//tool class for state (rounding mode and flags)
	fprintf(f, "\n\n/* tool class for state (rounding mode and flags) */");
	fprintf(f, "\n\nclass wf_fpstate {\n\tprivate :\n\twf_fpstate();\n\n\tpublic :\n\n\t/* setters */\n\n\tstatic int set_flags(widefloat_flags_t newflags);\n\tstatic int set_rounding_mode(widefloat_roundingmode_t new_rounding_mode);\n\n\t/* getters */\n\n\tstatic widefloat_flags_t get_flags();\n\tstatic widefloat_roundingmode_t get_rounding_mode();\n\n\t/* function which enables us to raise flags */\n\n\tstatic int raise_flags(widefloat_flags_t newflags);\n\n};\n\n\n");

	//wf classes definition
	fprintf(f, "\n\n\n/*widefloat classes definition*/\n\n");

	for(i=WF_TYPE;i<TYPE_NB;i++){

		//beginning of the definition
		fprintf(f, "class %s {\n\twidefloat_float%s_t value;//value\n\n", types[i], wf_size[i]);

		//friendship between widefloat classes-for constructors/assignments
		fprintf(f, "\t/*friendship between widefloat classes for constructors and assignments*/\n");
		for(j=WF_TYPE;j<TYPE_NB;j++){
			if(j==i){
				continue;
			}
			fprintf(f, "\tfriend class %s;\n", types[j]);
		}

		fprintf(f, "\tpublic:\n\t\t//constructors\n\t\t  %s();\n", types[i]);
		strcpy(type, types[i]);
		for(j=CPP_TYPE;j<TYPE_NB;j++){//constructors
			if(i==j){
				continue;//copy constructor by default
			}
			strcpy(args[0], "const ");
			strcat(args[0], types[j]);
			strcat(args[0], " &");
			function_sign(buffer, "\t\t", "", type, 1, args, NULL);
			fprintf(f, "%s\n", buffer);

		}

		//casts as members
		fprintf(f, "\n\n\t\t/*Casts : only towards C++ types*/\n\n");
		strcpy(name, "operator");
		for(j=CPP_TYPE;j<WF_TYPE;j++){
			strcpy(type, types[j]);
			function_sign(buffer, "", name, type, 0, NULL, "const");
			fprintf(f, "\t\t%s\n", buffer);
		}

		//+ - * /
		fprintf(f, "\n\t\t/*arithmetic operators as friend functions*/\n\n");
		for(j=ARITH;j<ASSIGN;j++){
			name[8]='\0';
			strcat(name, op[j]);
			strcpy(args[0], "const ");
			strcat(args[0], types[i]);
			strcat(args[0], " &");
			strcpy(type, types[i]);
			for(k=CPP_TYPE;k<TYPE_NB;k++){
				if(k>i){
					strcpy(type, types[k]);//cast to the bigger
				}
				strcpy(args[1], "const ");
				strcat(args[1], types[k]);
				strcat(args[1], " &");
				function_sign(buffer, "friend", type, name, 2, args, "");
				fprintf(f, "\t\t%s\n", buffer);
			}
			fprintf(f, "\n");
			strcpy(args[1], "const ");
			strcat(args[1], types[i]);
			strcat(args[1], " &");
			strcpy(type, types[i]);
			for(k=CPP_TYPE;k<TYPE_NB;k++){
				if(k==i){
					continue;//OK
				}
				if(k>i){
					strcpy(type, types[k]);
				}
				strcpy(args[0], "const ");
				strcat(args[0], types[k]);
				strcat(args[0], " &");
				function_sign(buffer, "friend", type, name, 2, args, "");
				fprintf(f, "\t\t%s\n", buffer);
			}
			fprintf(f, "\n");
		}

		//assignments as members
		fprintf(f, "\n\t\t/*assignments (as members)*/\n");
		name[8]='\0';
		strcat(name, "= ");
		strcpy(type, types[i]);
		for(j=CPP_TYPE;j<TYPE_NB;j++){
			if(j==i){
				continue;
			}
			strcpy(args[0], "const ");
			strcat(args[0], types[j]);
			strcat(args[0], " &");
			function_sign(buffer, "", type, name, 1, args, "");
			fprintf(f, "\t\t%s\n", buffer);
		}

		fprintf(f, "\n\n\t\t/*extended assignments as friend functions*/\n");
		for(j=ASSIGN+1;j<COMP;j++){
			name[8]='\0';
			strcat(name, op[j]);
			strcpy(type, types[i]);
			strcpy(args[0], types[i]);//not const - lvalue
			strcat(args[0], " &");
			for(k=CPP_TYPE;k<TYPE_NB;k++){
				strcpy(args[1], "const ");
				strcat(args[1], types[k]);
				strcat(args[1], " &");
				function_sign(buffer, "friend", type, name, 2, args, "");
				fprintf(f, "\t\t%s\n", buffer);
			}
			fprintf(f, "\n");
			strcpy(args[1], "const ");
			strcat(args[1], types[i]);
			strcat(args[1], " &");
			for(k=CPP_TYPE;k<TYPE_NB;k++){
				if(k==i){
					continue;
				}
				strcpy(args[0], types[k]);//not const
				strcat(args[0], " &");
				strcpy(type, types[k]);
				function_sign(buffer, "friend", type, name, 2, args, "");
				fprintf(f, "\t\t%s\n", buffer);
			}
			fprintf(f, "\n");
		}

		//comparisons
		fprintf(f, "\n\n\t\t/* comparisons */\n");
		strcpy(type, "bool");
		for(j=COMP;j<OP_NB;j++){
			name[8] = '\0';
			strcat(name, op[j]);
			strcpy(args[0], "const ");
			strcat(args[0], types[i]);
			strcat(args[0], " &");
			for(k=CPP_TYPE;k<TYPE_NB;k++){
				strcpy(args[1], "const ");
				strcat(args[1], types[k]);
				strcat(args[1], " &");
				function_sign(buffer, "friend", type, name, 2, args, "");
				fprintf(f, "\t\t%s\n", buffer);
			}
			strcpy(args[1], "const ");
			strcat(args[1], types[i]);
			strcat(args[1], " &");
			fprintf(f, "\n");
			for(k=CPP_TYPE;k<TYPE_NB;k++){
				if(k==i){
					continue;
				}
				strcpy(args[0], "const ");
				strcat(args[0], types[k]);
				strcat(args[0], " &");
				function_sign(buffer, "friend", type, name, 2, args, "");
				fprintf(f, "\t\t%s\n", buffer);
			}
			fprintf(f, "\n");
		}

		//Unary + -
		fprintf(f, "\n\n\t\t/* unary + and - */\n\t\t%s operator+ () const;\n\t\t%s operator- () const;\n", types[i], types[i]);

		//sqrt : towards smaller wf types
		fprintf(f, "\n\t\t/* square root */\n");
		for(j=WF_TYPE;j<=i;j++){
			fprintf(f, "\n\t\tfriend %s sqrt_to_%s(const %s &);", types[j], types[j], types[i]);
		}

		//fma : towards smaller wf types
		fprintf(f, "\n\n\t\t/* fma */\n");
		for(j=WF_TYPE;j<=i;j++){
			fprintf(f, "\n\t\tfriend %s fma_to_%s(const %s &, const %s &, const %s &);", types[j], types[j], types[i], types[i], types[i]);
		}

		//right brace of the class definition
		fprintf(f, "};\n\n");
	}



	//end of the macro #ifndef
	fprintf(f, "#endif");

	fclose(f);

	free(args[0]);
	free(args[1]);
	free(args[2]);
	free(args);

	return 0;
}
