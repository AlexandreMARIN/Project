
#include <stdio.h>


	enum domain {CPP_TYPE, WF_TYPE = 13, TYPE_NB = 15};
	enum op_type {ARITH, ASSIGN = 4, COMP = 9, OP_NB = 15};

	const char types[][25]={"char", "signed char", "unsigned char", "short int", "unsigned short int", "int", "unsigned int", "long int", "unsigned long int", "long long int", "unsigned long long int", "float", "double", "wf256_t", "wf512_t"};
	const char op[][4]={"+", "-", "*", "/", "=", "+=", "-=", "*=", "/=", "<", ">", "<=", ">=", "==", "!="};

	const char wf_size[][5] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "256", "512"};

	const char range[][2][15] = {{"CHAR_MIN", "CHAR_MAX"}, {"SCHAR_MIN", "SCHAR_MAX"}, {"0", "UCHAR_MAX"}, {"SHRT_MIN", "SHRT_MAX"}, {"0", "USHRT_MAX"}, {"INT_MIN", "INT_MAX"}, {"0", "UINT_MAX"}, {"LONG_MIN", "LONG_MAX"}, {"0", "ULONG_MAX"}};

int main(){

	FILE* f;
	int i, j, k;

	f = fopen("wf_test.cpp", "w");

	//libraries and resources for test
	fprintf(f, "#include \"wf_classes.hpp\"\n#include <cmath>\n#include <climits>\n#include <iostream>\nusing namespace std;\n\n");

	//function for writing message about flags
	fprintf(f, "void show_flags(){\n\twidefloat_flags_t flags = wf_fpstate::get_flags();\n\tcout<<\"\\nFlags :\\n\";\n\tif(((unsigned int)flags)%%2==1){\n\t\tcout<<\"INEXACT\\n\";\n\t}\n\tif(((unsigned int)flags)&(1u<<1)){\n\t\tcout<<\"INVALID\\n\";\n\t}\n\tif(((unsigned int)flags)&(1u<<2)){\n\t\tcout<<\"DIVISION BY ZERO\\n\";\n\t}\n\tif(((unsigned int)flags)&(1u<<3)){\n\t\tcout<<\"OVERFLOW\\n\";\n\t}\n\tif(((unsigned int)flags)&(1u<<4)){\n\t\tcout<<\"UNDERFLOW\\n\";\n\t}\n\tcout<<\"\\n\";\n}\n");

	//function for writing rounding mode
	fprintf(f, "void show_rounding_mode(){\n\tcout<<\"rounding mode : \";\n\tswitch(wf_fpstate::get_rounding_mode()){\n\t\tcase WIDEFLOAT_ROUNDINGMODE_NEAREST:\n\t\tcout<<\"NEAREST\\n\";\n\t\tbreak;\n\t\tcase WIDEFLOAT_ROUNDINGMODE_TOWARD_ZERO:\n\t\tcout<<\"TOWARDS_ZERO\\n\";\n\t\tbreak;\n\t\tcase WIDEFLOAT_ROUNDINGMODE_UP:\n\t\tcout<<\"TOWARDS INFINITY\\n\";\n\t\tbreak;\n\t\tcase WIDEFLOAT_ROUNDINGMODE_DOWN:\n\t\tcout<<\"TOWARDS -INFINITY\\n\";\n\t\tbreak;\n\t}\n}\n");

	//main
	fprintf(f, "int main(int argc, char* argv[]){\n\n");

	//variables of all c++ types -> constructors
	fprintf(f, "\n\t/* variables - use of all constructors */\n\n");

	for(i=CPP_TYPE;i<WF_TYPE;i++){
		fprintf(f, "\n\t%s var%d = 1;", types[i], i);//C++
	}

	fprintf(f, "\n\n\t/* constructors without parameter*/\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\t%s var%d;", types[i], i);//constructor without parameter
	}

	fprintf(f, "\n\n\t/* constructors from C++ types and widefloat */\n");//constructors
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<TYPE_NB;j++){
			if(j==i){
				continue;//copy constructor already exists
			}
			fprintf(f, "\n\t%s var%d_%s = var%d;", types[i], j, wf_size[i], j);//value : NAN from widefloat or 1
		}
	}

	//casts
	fprintf(f, "\n\n\t/* casts */\n");

	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<WF_TYPE;j++){
			fprintf(f, "\n\tif(((%s)var%d_%s)!=((%s)1)){\n\t\tcout<<\"problem while converting %s to %s : 1 is expected\\n\";\n\t\treturn 1;\n\t}\n", types[j], j, wf_size[i], types[j], types[i], types[j]);// 1 is expected
		}
		for(j=WF_TYPE;j<TYPE_NB;j++){
			if(i==j){
				fprintf(f, "\n\tif(!isnan(((double)var%d))){\n\t\tcout<<\"problem whith constructor of %s from nothing : NAN is expected\\n\";\n\t\treturn 1;\n\t}\n", i, types[i]);//void constructors set the value to NAN
			}else{
				fprintf(f, "\n\tif(!isnan(((double)var%d_%s))){\n\t\tcout<<\"problem whith constructor of %s from %s : NAN is expected\\n\";\n\t\treturn 1;\n\t}\n", j, wf_size[i], types[i], types[j]);//NAN normally
			}
		}
	}
	fprintf(f, "\n\tcout<<\"constructors and casts : OK\\n\";\n");

	//rounding mode : nearest
	fprintf(f, "\n\n\t/* the rounding mode is set to the nearest rounding to get exact computations */\n\twf_fpstate::set_rounding_mode(WIDEFLOAT_ROUNDINGMODE_NEAREST);\n");

	//assignments
	fprintf(f, "\n\t/* assignments towards widefloat types (assignments towards C++ types are defined by casts) */\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<TYPE_NB;j++){
			if(i==j){
				continue;//assignments are already defined when source type is destination type
			}
			fprintf(f, "\n\tif( ((int)(var%d_%s = ((%s)5))) != 5 || ((int)var%d_%s) != 5 ){\n\t\tcout<<\"problem while assigning %s to %s\\n\";\n\t\treturn 1;\n\t}\n", j, wf_size[i], types[j], j, wf_size[i], types[j], types[i]);
		}
	}
	fprintf(f, "\n\tcout<<\"assignments : OK\\n\";\n");


	//casts with overflows
	fprintf(f, "\n\n\t/* casts towards C++ integers with overflows */\n\twidefloat_flags_t flags;\n");

		//positive overflows
	fprintf(f, "\n\t/* positive overflow due to cast : test of the flags and results */");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\tvar%d = ULONG_MAX*10.0;\n", i);//big value
		for(j=CPP_TYPE;j<WF_TYPE-4;j++){
			fprintf(f, "\n\twf_fpstate::set_flags((widefloat_flags_t)0);\n\tif(((%s)%s)!=((%s)var%d)){\n\t\tcout<<\"problem while converting %s to %s : value after positive overflow\\n\";\n\t\treturn 1;\n\t}\n\tflags = wf_fpstate::get_flags();\n\tif((unsigned int)flags != 3u){\n\t\tcout<<\"problem while converting %s to %s : flags after positive overflow\\n\";\n\t\tshow_flags();\n\t\treturn 1;\n\t}\n", types[j], range[j][1], types[j], i, types[i], types[j], types[i], types[j]);
		}
	}
	fprintf(f, "\n\tcout<<\"positive overflows during cast : OK\\n\";\n");

		//negative overflows
	fprintf(f, "\n\t/* negative overflow due to cast : test of the flags and results */");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\tvar%d = LONG_MIN*10.0;\n", i);
		for(j=CPP_TYPE;j<WF_TYPE-4;j++){
			if(j!=0 && j%2==0){
				continue;
			}
			fprintf(f, "\n\twf_fpstate::set_flags((widefloat_flags_t)0);\n\tif(((%s)%s)!=((%s)var%d)){\n\t\tcout<<\"problem while converting %s to %s : value after negative overflow\\n\";\n\t\treturn 1;\n\t}\n\tflags = wf_fpstate::get_flags();\n\tif((unsigned int)flags != 3u){\n\t\tcout<<\"problem while converting %s to %s : flags after negative overflow\\n\";\n\t\tshow_flags();\n\t\treturn 1;\n\t}\n", types[j], range[j][0], types[j], i, types[i], types[j], types[i], types[j]);
		}
	}
	fprintf(f, "\n\tcout<<\"negative overflows during cast : OK\\n\";\n");

	//values set to 4 for test of arithmetic operators
	for(i=CPP_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\tvar%d = 4;\n", i);//set the value to 4
	}
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<TYPE_NB;j++){
			if(j==i){
				continue;
			}
			fprintf(f, "\n\tvar%d_%s = 4;", j, wf_size[i]);//set the value to 4
		}
	}

	//arithmetic operators
	fprintf(f, "\n\t/* arithmetic operators */\n");
	for(k=0;k<ASSIGN;k++){
		for(i=CPP_TYPE;i<TYPE_NB;i++){
			for(j=WF_TYPE;j<TYPE_NB;j++){
				if(i>=WF_TYPE && i!=j){
					fprintf(f, "\n\tif( ((int)(var%d", j);//avoids the error : unused variable
					fprintf(f, "_%s", wf_size[i]);
				}else{
					fprintf(f, "\n\tif( ((int)(var%d", i);
				}
				fprintf(f, " %s var", op[k]);
				if(i==j){
					fprintf(f, "0");//because of 'restrict'
				}else{
					fprintf(f, "%d", i);
				}
				fprintf(f, "_%s", wf_size[j]);
				fprintf(f, ")) != ");
				switch(k){
					case 0:
						fprintf(f, "8");// 4+4=8
						break;
					case 1:
						fprintf(f, "0");// 4-4=0
						break;
					case 2:
						fprintf(f, "16");// 4*4=16
						break;
					case 3:
						fprintf(f, "1");// 4/4=1
						break;
				}
				fprintf(f, "){\n\t\tcout<<\"problem with %s %s %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], op[k], types[j]);
			}
		}
		for(i=WF_TYPE;i<TYPE_NB;i++){
			for(j=CPP_TYPE;j<WF_TYPE;j++){
				if(i==j){
					continue;
				}
				fprintf(f, "\n\tif( ((int)(var%d", j);
				fprintf(f, "_%s", wf_size[i]);
				fprintf(f, " %s var", op[k]);
				fprintf(f, "%d", j);
				fprintf(f, ")) != ");
				switch(k){
					case 0:
						fprintf(f, "8");// 4+4=8
						break;
					case 1:
						fprintf(f, "0");// 4-4=0
						break;
					case 2:
						fprintf(f, "16");// 4*4=16
						break;
					case 3:
						fprintf(f, "1");// 4/4=1
						break;
				}
				fprintf(f, "){\n\t\tcout<<\"problem with %s %s %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], op[k], types[j]);
			}
		}
	}
	fprintf(f, "\n\tcout<<\"arithmetic operators : OK\\n\";\n");

	//extended assignments
	fprintf(f, "\n\t/* extended assignments */\n");
	for(i=CPP_TYPE;i<TYPE_NB;i++){
		for(j=WF_TYPE;j<TYPE_NB;j++){
			for(k=ASSIGN+1;k<COMP;k++){
				fprintf(f, "\n\tif( (int)(var%d %s var0_%s) != ", i, op[k], wf_size[j]);
				switch(k){
					case ASSIGN+1:
						fprintf(f, "8");// 4+4=8
						break;
					case ASSIGN+2:
						fprintf(f, "4");// 8-4=4
						break;
					case ASSIGN+3:
						fprintf(f, "16");// 4*4=16
						break;
					case ASSIGN+4:
						fprintf(f, "4");// 16/4=4
						break;
				}
				fprintf(f, " || ((int)var%d) != ", i);
				switch(k){
					case ASSIGN+1:
						fprintf(f, "8");// 4+4=8
						break;
					case ASSIGN+2:
						fprintf(f, "4");// 8-4=4
						break;
					case ASSIGN+3:
						fprintf(f, "16");// 4*4=16
						break;
					case ASSIGN+4:
						fprintf(f, "4");// 16/4=4
						break;
				}
				fprintf(f, " ){\n\t\tcout<<\"problem with %s %s %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], op[k], types[j]);
			}
			if(i>=WF_TYPE){
				fprintf(f, "\n\tvar%d = 4;\n",  i);//keeps the value close enough to 4 in spite of several roundings
			}
		}
	}
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<WF_TYPE;j++){
			for(k=ASSIGN+1;k<COMP;k++){
				fprintf(f, "\n\tif( (int)(var%d_%s %s var%d) != ", j, wf_size[i], op[k], j);
				switch(k){
					case ASSIGN+1:
						fprintf(f, "8");// 4+4=8
						break;
					case ASSIGN+2:
						fprintf(f, "4");// 8-4=4
						break;
					case ASSIGN+3:
						fprintf(f, "16");// 4*4=16
						break;
					case ASSIGN+4:
						fprintf(f, "4");// 16/4=4
						break;
				}
				fprintf(f, " || ((int)var%d_%s) != ", j, wf_size[i]);
				switch(k){
					case ASSIGN+1:
						fprintf(f, "8");// 4+4=8
						break;
					case ASSIGN+2:
						fprintf(f, "4");// 8-4=4
						break;
					case ASSIGN+3:
						fprintf(f, "16");// 4*4=16
						break;
					case ASSIGN+4:
						fprintf(f, "4");// 16/4=4
						break;
				}
				fprintf(f, " ){\n\t\tcout<<\"problem with %s %s %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], op[k], types[j]);
			}
			fprintf(f, "\n\tvar%d_%s = 4;\n", j, wf_size[i]);//keeps the value close enough to 4 in spite of several roundings
		}
	}
	fprintf(f, "\n\tcout<<\"extended assignments : OK\\n\";\n");

	fprintf(f, "\n\t/* comparisons */\n\n\t/* boolean variables for values returned by comparisons */\n");
	for(k=COMP;k<OP_NB;k++){
		fprintf(f, "\n\tbool b%d;", k-COMP);//declaration of boolean variables
	}
	//< > <= >= == !=
	//consistency in case numbers are close to each other
	fprintf(f, "\n\t/* consistency in case numbers are close to each other */\n");
	for(i=CPP_TYPE;i<TYPE_NB;i++){
		for(j=WF_TYPE;j<TYPE_NB;j++){
			for(k=COMP;k<OP_NB;k++){
				fprintf(f, "\n\tb%d = (var%d %s var0_%s);", k-COMP, i, op[k], wf_size[j]);
			}
			fprintf(f, "\n\tif(b4==b5){\n\t\tcout<<\"equality is not coherent with types %s and %s : equality and inequality return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b1==b2){\n\t\tcout<<\"inequality is not coherent with types %s and %s : > and <= return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b0==b3){\n\t\tcout<<\"inequality is not coherent with types %s and %s : < and >= return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b4==(b0 || b1)){\n\t\tcout<<\"equality is not coherent with types %s and %s : == and (< or >) return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
		}
	}
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<WF_TYPE;j++){
			for(k=COMP;k<OP_NB;k++){
				fprintf(f, "\n\tb%d = (var0_%s %s var%d);", k-COMP, wf_size[i], op[k], j);
			}
			fprintf(f, "\n\tif(b4==b5){\n\t\tcout<<\"equality is not coherent with types %s and %s : equality and inequality return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b1==b2){\n\t\tcout<<\"inequality is not coherent with types %s and %s : > and <= return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b0==b3){\n\t\tcout<<\"inequality is not coherent with types %s and %s : < and >= return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b4==(b0 || b1)){\n\t\tcout<<\"equality is not coherent with types %s and %s : == and (< or >) return the same value\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
		}
	}

	//values in another cases
	fprintf(f, "\n\t/* validity */\n");
	for(i=CPP_TYPE;i<TYPE_NB;i++){
		for(j=WF_TYPE;j<TYPE_NB;j++){
			fprintf(f, "\n\tvar0_%s = 2;", wf_size[j]);
			for(k=COMP;k<OP_NB;k++){
				fprintf(f, "\n\tb%d = (var%d %s var0_%s);", k-COMP, i, op[k], wf_size[j]);
			}// 4>2
			//< > <= >= == !=
			fprintf(f, "\n\tif(b0){\n\t\tcout<<\"invalid value for %s < %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b1){\n\t\tcout<<\"invalid value for %s > %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b2){\n\t\tcout<<\"invalid value for %s <= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b3){\n\t\tcout<<\"invalid value for %s >= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b4){\n\t\tcout<<\"invalid value for %s == %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b5){\n\t\tcout<<\"invalid value for %s != %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);

			fprintf(f, "\n\n\tvar0_%s = 10;", wf_size[j]);//4<10
			for(k=COMP;k<OP_NB;k++){
				fprintf(f, "\n\tb%d = (var%d %s var0_%s);", k-COMP, i, op[k], wf_size[j]);
			}
			//< > <= >= == !=
			fprintf(f, "\n\tif(!b0){\n\t\tcout<<\"invalid value for %s < %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b1){\n\t\tcout<<\"invalid value for %s > %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b2){\n\t\tcout<<\"invalid value for %s <= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b3){\n\t\tcout<<\"invalid value for %s >= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b4){\n\t\tcout<<\"invalid value for %s == %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b5){\n\t\tcout<<\"invalid value for %s != %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
		}
	}
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=CPP_TYPE;j<WF_TYPE;j++){
			fprintf(f, "\n\tvar0_%s = 2;", wf_size[i]);//2<4
			for(k=COMP;k<OP_NB;k++){
				fprintf(f, "\n\tb%d = (var0_%s %s var%d);", k-COMP, wf_size[i], op[k], j);
			}
			fprintf(f, "\n\tif(!b0){\n\t\tcout<<\"invalid value for %s < %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b1){\n\t\tcout<<\"invalid value for %s > %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b2){\n\t\tcout<<\"invalid value for %s <= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b3){\n\t\tcout<<\"invalid value for %s >= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b4){\n\t\tcout<<\"invalid value for %s == %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b5){\n\t\tcout<<\"invalid value for %s != %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);

			fprintf(f, "\n\n\tvar0_%s = 10;", wf_size[i]);//10>4
			for(k=COMP;k<OP_NB;k++){
				fprintf(f, "\n\tb%d = (var0_%s %s var%d);", k-COMP, wf_size[i], op[k], j);
			}
			//< > <= >= == !=
			fprintf(f, "\n\tif(b0){\n\t\tcout<<\"invalid value for %s < %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b1){\n\t\tcout<<\"invalid value for %s > %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b2){\n\t\tcout<<\"invalid value for %s <= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b3){\n\t\tcout<<\"invalid value for %s >= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(b4){\n\t\tcout<<\"invalid value for %s == %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
			fprintf(f, "\n\tif(!b5){\n\t\tcout<<\"invalid value for %s != %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[j]);
		}
	}

	//last case : same numbers
	fprintf(f, "\n\t/* last case : same numbers */\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(k=COMP;k<OP_NB;k++){
			fprintf(f, "\n\tb%d = (var0_%s %s var0_%s);", k-COMP, wf_size[i], op[k], wf_size[i]);
		}
		fprintf(f, "\n\tif(b0){\n\t\tcout<<\"invalid value for %s < %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[i]);
		fprintf(f, "\n\tif(b1){\n\t\tcout<<\"invalid value for %s > %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[i]);
		fprintf(f, "\n\tif(!b2){\n\t\tcout<<\"invalid value for %s <= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[i]);
		fprintf(f, "\n\tif(!b3){\n\t\tcout<<\"invalid value for %s >= %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[i]);
		fprintf(f, "\n\tif(!b4){\n\t\tcout<<\"invalid value for %s == %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[i]);
		fprintf(f, "\n\tif(b5){\n\t\tcout<<\"invalid value for %s != %s\\n\";\n\t\treturn 1;\n\t}\n", types[i], types[i]);
	}

	fprintf(f, "\n\tcout<<\"consistency of comparisons : OK\\n\";\n");//comparisons are coherent

	//unary plus
	fprintf(f, "\n\t/* unary plus */\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\tif(! (var%d == (+var%d)) ){\n\t\tcout<<\"problem with : + %s\\n\";\n\t\treturn 1;\n\t}\n", i, i, types[i]);
	}
	fprintf(f, "\n\tcout<<\"unary plus : OK\\n\";\n");

	//unary minus
	fprintf(f, "\n\t/* unary minus */\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		fprintf(f, "\n\tif((var%d+(-var%d)!=0)){\n\t\tcout<<\"problem with : - %s\\n\";\n\t\treturn 1;\n\t}\n", i, i, types[i]);
	}
	fprintf(f, "\n\tcout<<\"unary minus : OK\\n\";\n");

	//sqrt
	fprintf(f, "\n\t/* square root */\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=i;j<TYPE_NB;j++){
			fprintf(f, "\n\tvar0_%s = sqrt_to_%s(var%d);\n\tif( ((int)var0_%s)!=2 ){\n\t\tcout<<\"problem with sqrt_to_%s(%s)\\n\";\n\t\treturn 1;\n\t}\n", wf_size[i], types[i], j, wf_size[i], types[i], types[j]);
		}
	}
	fprintf(f, "\n\tcout<<\"square roots : OK\\n\";\n");

	//fma
	fprintf(f, "\n\t/* fma */\n");
	for(i=WF_TYPE;i<TYPE_NB;i++){//assignments for testing
		fprintf(f, "\n\tvar0_%s = 2;\n\tvar1_%s = 3;\n\tvar2_%s = 4;\n", wf_size[i], wf_size[i], wf_size[i]);
	}
	for(i=WF_TYPE;i<TYPE_NB;i++){
		for(j=i;j<TYPE_NB;j++){
			fprintf(f, "\n\tvar%d = fma_to_%s(var0_%s, var1_%s, var2_%s);\n\tif( ((int)var%d)!=10 ){\n\t\tcout<<\"problem with fma_to_%s(%s, %s, %s)\\n\";\n\t\treturn 1;\n\t}\n", i, types[i], wf_size[j], wf_size[j], wf_size[j], i, types[i], types[j], types[j], types[j]);
		}
	}
	fprintf(f, "\n\tcout<<\"fma functions : OK\\n\";\n");

	//end of the main function
	fprintf(f, "\nreturn 0;\n}");

	fclose(f);

	return 0;
}
