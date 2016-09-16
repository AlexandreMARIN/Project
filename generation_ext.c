
#include "generation.h"
#include "var.h"

void function_sign(char* dest, char* prefix, char* returned_type, char* name, int arg_nb, char** arg_types, char *suffix){

	//'dest' is supposed wide enough
	int i;

	dest[0] = '\0';
	strcat(dest, prefix);
	strcat(dest, " ");
	strcat(dest, returned_type);
	strcat(dest, " ");
	strcat(dest, name);
	strcat(dest, "(");

	for(i=0;i<arg_nb-1;i++){
		strcat(dest, arg_types[i]);
		strcat(dest, ", ");
	}

	if(arg_nb >= 1){
		strcat(dest, arg_types[i]);
	}

	strcat(dest, ")");
	if(suffix!=NULL && strlen(suffix)>0){
		strcat(dest, " ");
		strcat(dest, suffix);
		strcat(dest, " ");
	}
	strcat(dest, ";");
}


void constructor(FILE* f, int wf_no, int arg_no){

	//parameter : void, signed int, unsigned int, float, double, wf

	//void : -1
	if(arg_no==-1){
		fprintf(f, "\n%s::%s (){\n\twidefloat_ext_float%s_from_ieee754_binary64(&value, NAN);\n}\n", types[wf_no], types[wf_no], wf_size[wf_no]);
		return;
	}

	//signed int
	if((arg_no<11 && arg_no%2==1 )||arg_no==0){
		if(strcmp("wf64_t", types[wf_no])!=0){
			fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_float64_t v2;\n\twidefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);\n\twidefloat_ext_convert_float64_to_float%s(&value, &v2);\n}\n", types[wf_no], types[wf_no], types[arg_no], wf_size[wf_no]);
			return;
		}else{
			fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_ext_convert_float64_from_signed_integer(&value, (int64_t)v);\n}\n", types[wf_no], types[wf_no], types[arg_no]);
			return;
		}
	}
	//unsigned int
	if(arg_no<11 && arg_no%2==0){
		if(strcmp("wf64_t", types[wf_no])!=0){
			fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_float64_t v2;\n\twidefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);\n\twidefloat_ext_convert_float64_to_float%s(&value, &v2);\n}\n", types[wf_no], types[wf_no], types[arg_no], wf_size[wf_no]);
			return;
		}else{
			fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_ext_convert_float64_from_unsigned_integer(&value, (uint64_t)v);\n}\n", types[wf_no], types[wf_no], types[arg_no]);
			return;
		}
	}

	//float
	if(arg_no==11){
		fprintf(f, "\n%s::%s (const float & v){\n\twidefloat_ext_float%s_from_ieee754_binary32(&value, v);\n}\n", types[wf_no], types[wf_no], wf_size[wf_no]);
		return;
	}
	//double
	if(arg_no==12){
		fprintf(f, "\n%s::%s (const double & v){\n\twidefloat_ext_float%s_from_ieee754_binary64(&value, v);\n}\n", types[wf_no], types[wf_no], wf_size[wf_no]);
		return;
	}

	//wf
	fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_ext_convert_float%s_to_float%s(&value, &(v.value));\n}\n", types[wf_no], types[wf_no], types[arg_no], wf_size[arg_no], wf_size[wf_no]);


}

void cast(FILE* f, int wf_no, int cpp_no){

	//signed integer
	if(cpp_no==0 || (cpp_no<11 && cpp_no%2==1)){
		fprintf(f, "\n%s::operator %s() const{\n\tint64_t res;\n\twidefloat_ext_convert_float%s_to_signed_integer_mode_exact(&res, &value, widefloat_ext_get_rounding_mode());", types[wf_no], types[cpp_no], wf_size[wf_no]);
		//overflow risk when returned type is smaller than int64_t =long int?
		if(strcmp(types[cpp_no], "long long int")!=0){
			fprintf(f, "\n\tif((res < (int64_t)%s)){\n\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INVALID);\n\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INEXACT);\n\t\treturn (%s)%s;\n\t}\n", range[cpp_no][0], types[cpp_no], range[cpp_no][0]);
			fprintf(f, "\n\tif((res > (int64_t)%s)){\n\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INVALID);\n\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INEXACT);\n\t\treturn (%s)%s;\n\t}\n", range[cpp_no][1], types[cpp_no], range[cpp_no][1]);
		}
		fprintf(f, "\n\treturn (%s)res;\n}\n", types[cpp_no]);
		return;
	}

	//unsigned integer
	if(cpp_no<11 && cpp_no%2==0){
		fprintf(f, "\n%s::operator %s() const{\n\tuint64_t res;\n\twidefloat_ext_convert_float%s_to_unsigned_integer_mode_exact(&res, &value, widefloat_ext_get_rounding_mode());", types[wf_no], types[cpp_no], wf_size[wf_no]);
		if(strcmp(types[cpp_no], "unsigned long long int")!=0){
			fprintf(f, "\n\tif((res > (uint64_t)%s)){\n\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INVALID);\n\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INEXACT);\n\t\treturn (%s)%s;\n\t}\n", range[cpp_no][1], types[cpp_no], range[cpp_no][1]);
		}
		fprintf(f, "\n\treturn (%s)res;\n}\n", types[cpp_no]);
		return;
	}

	//float
	if(cpp_no==11){
		fprintf(f, "\n%s::operator float() const{\n\tfloat res;\n\twidefloat_ext_float%s_to_ieee754_binary32(&res, &value);\n\treturn res;\n}\n", types[wf_no], wf_size[wf_no]);
		return;
	}
	//double
	if(cpp_no==12){
		fprintf(f, "\n%s::operator double() const{\n\tdouble res;\n\twidefloat_ext_float%s_to_ieee754_binary64(&res, &value);\n\treturn res;\n}\n", types[wf_no], wf_size[wf_no]);
		return;
	}
}

void arith(FILE* f, int arg1_no, int op_no, int arg2_no){

	if(arg1_no>arg2_no){//bigger type as returned type
		fprintf(f, "\n%s operator ", types[arg1_no]);
	}else{
		fprintf(f, "\n%s operator ", types[arg2_no]);
	}

	//symb
	fprintf(f, "%s ", op[op_no]);

	fprintf(f, "(const %s &op1, const %s &op2){\n\t", types[arg1_no], types[arg2_no]);

	if(arg1_no>arg2_no){//bigger type as returned type
		fprintf(f, "%s res;\n\t", types[arg1_no]);
	}else{
		fprintf(f, "%s res;\n\t", types[arg2_no]);
	}

	//cpp type
	if(arg1_no<WF_TYPE){
		fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg2_no]);
		if(strcmp(types[arg2_no], "wf64_t")!=0 && strcmp(types[arg1_no], "double")!=0 && strcmp(types[arg1_no], "float")!=0){
			fprintf(f, "widefloat_float64_t op3_64;\n\t");//we can convert integers only to float64
		}
		//construction of wf from cpp type
		if(strcmp(types[arg1_no], "double")==0){
			fprintf(f, "widefloat_ext_float%s_from_ieee754_binary64(&op3, op1);", wf_size[arg2_no]);
		}else{
			if(strcmp(types[arg1_no], "float")==0){
				fprintf(f, "widefloat_ext_float%s_from_ieee754_binary32(&op3, op1);", wf_size[arg2_no]);
			}else{
				if(strcmp(types[arg2_no], "wf64_t")==0){
					if(arg1_no==0 || arg1_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3, (int64_t)op1);");
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3, (uint64_t)op1);");
					}
				}else{
					if(arg1_no==0 || arg1_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3_64, (int64_t)op1);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg2_no]);
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3_64, (uint64_t)op1);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg2_no]);
					}
				}
			}
		}
		fprintf(f, "\n\twidefloat_ext_");
		switch(op_no){
			case ARITH :
				fprintf(f, "add");
				break;
			case ARITH+1 :
				fprintf(f, "sub");
				break;
			case ARITH+2 :
				fprintf(f, "mul");
				break;
			case ARITH+3 :
				fprintf(f, "div");
				break;
		}
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &op3, &(op2.value));\n\treturn res;\n}\n", wf_size[arg2_no], wf_size[arg2_no], wf_size[arg2_no]);
		return;
	}

	if(arg2_no<WF_TYPE){
		fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg1_no]);
		if(strcmp(types[arg1_no], "wf64_t")!=0 && strcmp(types[arg2_no], "double")!=0 && strcmp(types[arg2_no], "float")!=0){
			fprintf(f, "widefloat_float64_t op3_64;\n\t");//we can convert integers only to float64
		}
		//construction of wf from cpp type
		if(strcmp(types[arg2_no], "double")==0){
			fprintf(f, "widefloat_ext_float%s_from_ieee754_binary64(&op3, op2);", wf_size[arg1_no]);
		}else{
			if(strcmp(types[arg2_no], "float")==0){
				fprintf(f, "widefloat_ext_float%s_from_ieee754_binary32(&op3, op2);", wf_size[arg1_no]);
			}else{
				if(strcmp(types[arg1_no], "wf64_t")==0){
					if(arg2_no==0 || arg2_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3, (int64_t)op2);");
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3, (uint64_t)op2);");
					}
				}else{
					if(arg2_no==0 || arg2_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3_64, (int64_t)op2);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg1_no]);
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3_64, (uint64_t)op2);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg1_no]);
					}
				}
			}
		}
		fprintf(f, "\n\twidefloat_ext_");
		switch(op_no){
			case ARITH :
				fprintf(f, "add");
				break;
			case ARITH+1 :
				fprintf(f, "sub");
				break;
			case ARITH+2 :
				fprintf(f, "mul");
				break;
			case ARITH+3 :
				fprintf(f, "div");
				break;
		}
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op1.value), &op3);\n\treturn res;\n}\n", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
		return;
	}

	//wf type
	if(arg1_no!=arg2_no){
		if(arg1_no<arg2_no){
			fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg2_no]);
			fprintf(f, "widefloat_ext_convert_float%s_to_float%s(&op3, &(op1.value));\n\t", wf_size[arg1_no], wf_size[arg2_no]);
		}else{
			fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg1_no]);
			fprintf(f, "widefloat_ext_convert_float%s_to_float%s(&op3, &(op2.value));\n\t", wf_size[arg2_no], wf_size[arg1_no]);
		}
	}else{
		//we must pay attention to the keyword 'restrict'
		fprintf(f, "if(&op1 == &op2){\n\t\twidefloat_float%s_t op3 = op1.value;\n\t\twidefloat_ext_", wf_size[arg1_no]);
		switch(op_no){
			case ARITH :
				fprintf(f, "add");
				break;
			case ARITH+1 :
				fprintf(f, "sub");
				break;
			case ARITH+2 :
				fprintf(f, "mul");
				break;
			case ARITH+3 :
				fprintf(f, "div");
				break;
		}
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op1.value), &op3);\n\t\treturn res;\n\t\t}\n\t", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
	}

	fprintf(f, "widefloat_ext_");

	switch(op_no){
		case ARITH :
			fprintf(f, "add");
			break;
		case ARITH+1 :
			fprintf(f, "sub");
			break;
		case ARITH+2 :
			fprintf(f, "mul");
			break;
		case ARITH+3 :
			fprintf(f, "div");
			break;
	}
	if(arg1_no==arg2_no){
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op1.value), &(op2.value));\n\treturn res;\n}\n", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
		return;
	}
	if(arg1_no>arg2_no){
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op1.value), &op3);\n\treturn res;\n}\n", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
	}else{
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &op3, &(op2.value));\n\treturn res;\n}\n", wf_size[arg2_no], wf_size[arg2_no], wf_size[arg2_no]);
	}

}

void comp(FILE* f, int arg1_no, int op_no, int arg2_no){

	fprintf(f, "\nbool operator ");

	//symb
	switch(op_no){
		case COMP :
			fprintf(f, "< ");
			break;
		case COMP+1 :
			fprintf(f, "> ");
			break;
		case COMP+2 :
			fprintf(f, "<=");
			break;
		case COMP+3 :
			fprintf(f, ">=");
			break;
		case COMP+4 :
			fprintf(f, "==");
			break;
		case COMP+5 :
			fprintf(f, "!=");
			break;
	}

	fprintf(f, "(const %s &op1, const %s &op2){\n\t", types[arg1_no], types[arg2_no]);

	//variable for the result
	fprintf(f, "widefloat_comparison_t res;\n\t");

	//cpp type
	if(arg1_no<WF_TYPE){
		fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg2_no]);
		if(strcmp(types[arg2_no], "wf64_t")!=0 && strcmp(types[arg1_no], "double")!=0 && strcmp(types[arg1_no], "float")!=0){
			fprintf(f, "widefloat_float64_t op3_64;\n\t");//we can convert integers only to float64
		}
		//construction of wf from cpp type
		if(strcmp(types[arg1_no], "double")==0){
			fprintf(f, "widefloat_ext_float%s_from_ieee754_binary64(&op3, op1);", wf_size[arg2_no]);
		}else{
			if(strcmp(types[arg1_no], "float")==0){
				fprintf(f, "widefloat_ext_float%s_from_ieee754_binary32(&op3, op1);", wf_size[arg2_no]);
			}else{
				if(strcmp(types[arg2_no], "wf64_t")==0){
					if(arg1_no==0 || arg1_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3, (int64_t)op1);");
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3, (uint64_t)op1);");
					}
				}else{
					if(arg1_no==0 || arg1_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3_64, (int64_t)op1);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg2_no]);
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3_64, (uint64_t)op1);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg2_no]);
					}
				}
			}
		}

		fprintf(f, "\n\twidefloat_ext_compare_");
		if(strcmp(op[op_no], "==")==0 || strcmp(op[op_no], "!=")==0){
			fprintf(f, "quiet");
		}else{
			fprintf(f, "signaling");
		}
		fprintf(f, "_float%s_float%s(&res, &op3, &(op2.value));\n\t", wf_size[arg2_no], wf_size[arg2_no]);

	}

	if(arg2_no<WF_TYPE){
		fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg1_no]);
		if(strcmp(types[arg1_no], "wf64_t")!=0 && strcmp(types[arg2_no], "double")!=0 && strcmp(types[arg2_no], "float")!=0){
			fprintf(f, "widefloat_float64_t op3_64;\n\t");//we can convert integers only to float64
		}
		//construction of wf from cpp type
		if(strcmp(types[arg2_no], "double")==0){
			fprintf(f, "widefloat_ext_float%s_from_ieee754_binary64(&op3, op2);", wf_size[arg1_no]);
		}else{
			if(strcmp(types[arg2_no], "float")==0){
				fprintf(f, "widefloat_ext_float%s_from_ieee754_binary32(&op3, op2);", wf_size[arg1_no]);
			}else{
				if(strcmp(types[arg1_no], "wf64_t")==0){
					if(arg2_no==0 || arg2_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3, (int64_t)op2);");
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3, (uint64_t)op2);");
					}
				}else{
					if(arg2_no==0 || arg2_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3_64, (int64_t)op2);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg1_no]);
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3_64, (uint64_t)op2);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg1_no]);
					}
				}
			}
		}

		fprintf(f, "\n\twidefloat_ext_compare_");
		if(strcmp(op[op_no], "==")==0 || strcmp(op[op_no], "!=")==0){
			fprintf(f, "quiet");
		}else{
			fprintf(f, "signaling");
		}
		fprintf(f, "_float%s_float%s(&res, &(op1.value), &op3);\n\t", wf_size[arg1_no], wf_size[arg1_no]);

	}

	//wf type
	if(arg1_no>=WF_TYPE && arg2_no>=WF_TYPE){
		if(arg1_no!=arg2_no){
			if(arg1_no<arg2_no){
				fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg2_no]);
				fprintf(f, "widefloat_ext_convert_float%s_to_float%s(&op3, &(op1.value));\n\t", wf_size[arg1_no], wf_size[arg2_no]);
			}else{
				fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg1_no]);
				fprintf(f, "widefloat_ext_convert_float%s_to_float%s(&op3, &(op2.value));\n\t", wf_size[arg2_no], wf_size[arg1_no]);
			}
		}else{//both arguments are equal but NAN are unordered : in this case the 'invalid' flag is to be raised and the result is false for <, <=, > and >=
			fprintf(f, "if(&op1 == &op2){\n\t\t");
			switch(op_no){
				case COMP://<
					fprintf(f, "switch(op1.value.fpclass){\n\t\t\tcase WIDEFLOAT_FPCLASS_POS_NAN:\n\t\t\tcase WIDEFLOAT_FPCLASS_NEG_NAN:\n\t\t\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INVALID);\n\t\t\tdefault:\n\t\t\t\tbreak;\n\t\t}\n\t\treturn false;\n");
					break;
				case COMP+1://>
					fprintf(f, "switch(op1.value.fpclass){\n\t\t\tcase WIDEFLOAT_FPCLASS_POS_NAN:\n\t\t\tcase WIDEFLOAT_FPCLASS_NEG_NAN:\n\t\t\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INVALID);\n\t\t\tdefault:\n\t\t\t\tbreak;\n\t\t}\n\t\treturn false;\n");
					break;
				case COMP+2://<=
					fprintf(f, "switch(op1.value.fpclass){\n\t\t\tcase WIDEFLOAT_FPCLASS_POS_NAN:\n\t\t\tcase WIDEFLOAT_FPCLASS_NEG_NAN:\n\t\t\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INVALID);\n\t\t\t\treturn false;\n\t\t\tdefault:\n\t\t\t\treturn true;\n\t\t}\n");
					break;
				case COMP+3://>=
					fprintf(f, "switch(op1.value.fpclass){\n\t\t\tcase WIDEFLOAT_FPCLASS_POS_NAN:\n\t\t\tcase WIDEFLOAT_FPCLASS_NEG_NAN:\n\t\t\t\twidefloat_ext_raise_flags(WIDEFLOAT_FPFLAG_INVALID);\n\t\t\t\treturn false;\n\t\t\tdefault:\n\t\t\t\treturn true;\n\t\t}\n");
					break;
				case COMP+4://==
					fprintf(f, "switch(op1.value.fpclass){\n\t\t\tcase WIDEFLOAT_FPCLASS_POS_NAN:\n\t\t\tcase WIDEFLOAT_FPCLASS_NEG_NAN:\n\t\t\t\treturn false;\n\t\t\tdefault:\n\t\t\t\treturn true;\n\t\t}\n");
					break;
				case COMP+5://!=
					fprintf(f, "return false;\n");
					break;
			}
			fprintf(f, "\n\t}\n");
		}

		fprintf(f, "\n\twidefloat_ext_compare_");
		if(strcmp(op[op_no], "==")==0 || strcmp(op[op_no], "!=")==0){
			fprintf(f, "quiet");
		}else{
			fprintf(f, "signaling");
		}

		if(arg1_no==arg2_no){
			fprintf(f, "_float%s_float%s(&res, &(op1.value), &(op2.value));\n\t", wf_size[arg2_no], wf_size[arg2_no]);
		}else{
			if(arg1_no>arg2_no){
				fprintf(f, "_float%s_float%s(&res, &(op1.value), &op3);\n\t", wf_size[arg1_no], wf_size[arg1_no]);
			}else{
				fprintf(f, "_float%s_float%s(&res, &op3, &(op2.value));\n\t", wf_size[arg2_no], wf_size[arg2_no]);
			}
		}
	}

	//returns true or false
	switch(op_no){
		case COMP:/* < */
			fprintf(f, "if(res==WIDEFLOAT_COMPARISON_LESS){");
			break;
		case COMP+1:/* > */
			fprintf(f, "if(res==WIDEFLOAT_COMPARISON_GREATER){");
			break;
		case COMP+2:/* <= */
			fprintf(f, "if(res==WIDEFLOAT_COMPARISON_LESS || res==WIDEFLOAT_COMPARISON_EQUAL){");
			break;
		case COMP+3:/* >= */
			fprintf(f, "if(res==WIDEFLOAT_COMPARISON_GREATER || res==WIDEFLOAT_COMPARISON_EQUAL){");
			break;
		case COMP+4:/* == */
			fprintf(f, "if(res==WIDEFLOAT_COMPARISON_EQUAL){");
			break;
		case COMP+5:/* != */
			fprintf(f, "if(res!=WIDEFLOAT_COMPARISON_EQUAL){");
			break;
	}
	fprintf(f, "\n\t\treturn true;\n\t}\n\treturn false;\n}\n");//returns false for NANs

}

/*assignment as member !*/
void assign(FILE* f, int wf_no, int arg_no){//wf_no!=arg_no

	fprintf(f, "\n%s %s::operator= (const %s &op){\n", types[wf_no], types[wf_no], types[arg_no]);

	if(arg_no>=WF_TYPE){
		fprintf(f, "\twidefloat_ext_convert_float%s_to_float%s(&value, &(op.value));\n\treturn *this;\n}\n", wf_size[arg_no], wf_size[wf_no]);
		return;
	}

	if(strcmp("wf64_t", types[wf_no])!=0 && strcmp("double", types[arg_no])!=0 && strcmp("float", types[arg_no])!=0){
		fprintf(f, "\twidefloat_float64_t op2;\n\t");
	}
	//construction of float64 from cpp type in case the second argument is an integer and the widefloat is not a wf64_t variable
	if(strcmp(types[arg_no], "double")==0){
		fprintf(f, "widefloat_ext_float%s_from_ieee754_binary64(&value, op);", wf_size[wf_no]);
	}else{
		if(strcmp(types[arg_no], "float")==0){
			fprintf(f, "widefloat_ext_float%s_from_ieee754_binary32(&value, op);", wf_size[wf_no]);
		}else{
			if(strcmp("wf64_t", types[wf_no])==0){
				if(arg_no==0 || arg_no%2==1){
					fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&value, (int64_t)op);");
				}else{
					fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&value, (uint64_t)op);");
				}
			}else{
				if(arg_no==0 || arg_no%2==1){
					fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op2, (int64_t)op);\n\twidefloat_ext_convert_float64_to_float%s(&value, &op2);", wf_size[wf_no]);
				}else{
					fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op2, (uint64_t)op);\n\twidefloat_ext_convert_float64_to_float%s(&value, &op2);", wf_size[wf_no]);
				}
			}
		}
	}

	fprintf(f, "\n\treturn *this;\n}\n");
}

void ext_assign(FILE* f, int arg1_no, int op_no, int arg2_no){

	fprintf(f, "\n%s operator%s(%s &op1, const %s &op2){\n\t", types[arg1_no], op[op_no], types[arg1_no], types[arg2_no]);

	if(arg1_no==arg2_no){
		fprintf(f, "widefloat_float%s_t copy = op1.value;\n\twidefloat_ext_", wf_size[arg1_no]);
		switch(op_no){
			case ASSIGN+1:
				fprintf(f, "add");
				break;
			case ASSIGN+2:
				fprintf(f, "sub");
				break;
			case ASSIGN+3:
				fprintf(f, "mul");
				break;
			case ASSIGN+4:
				fprintf(f, "div");
				break;
		}
		fprintf(f, "_float%s_float%s_float%s(&(op1.value), &copy, &(op2.value));\n\treturn op1;\n}\n", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
		return;
	}

	if(arg1_no>arg2_no){
		fprintf(f, "widefloat_float%s_t op3 = op1.value, op4;\n\t", wf_size[arg1_no]);
		if(strcmp(types[arg1_no], "wf64_t")!=0 && strcmp(types[arg2_no], "double")!=0 && strcmp(types[arg2_no], "float")!=0 && arg2_no<WF_TYPE){
			fprintf(f, "widefloat_float64_t op4_64;\n\t");//we can convert integers only to float64
		}
		if(arg2_no>=WF_TYPE){
			fprintf(f, "widefloat_ext_convert_float%s_to_float%s(&op4, &(op2.value));", wf_size[arg2_no], wf_size[arg1_no]);
		}else{
			//construction of wf from cpp type
			if(strcmp(types[arg2_no], "double")==0){
				fprintf(f, "widefloat_ext_float%s_from_ieee754_binary64(&op4, op2);", wf_size[arg1_no]);
			}else{
				if(strcmp(types[arg2_no], "float")==0){
					fprintf(f, "widefloat_ext_float%s_from_ieee754_binary32(&op4, op2);", wf_size[arg1_no]);
				}else{
					if(strcmp(types[arg1_no], "wf64_t")==0){
						if(arg2_no==0 || arg2_no%2==1){
							fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op4, (int64_t)op2);");
						}else{
							fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op4, (uint64_t)op2);");
						}
					}else{
						if(arg2_no==0 || arg2_no%2==1){
							fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op4_64, (int64_t)op2);\n\twidefloat_ext_convert_float64_to_float%s(&op4, &op4_64);", wf_size[arg1_no]);
						}else{
							fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op4_64, (uint64_t)op2);\n\twidefloat_ext_convert_float64_to_float%s(&op4, &op4_64);", wf_size[arg1_no]);
						}
					}
				}
			}
		}
		fprintf(f, "\n\twidefloat_ext_");
		switch(op_no){
			case ASSIGN+1:
				fprintf(f, "add");
				break;
			case ASSIGN+2:
				fprintf(f, "sub");
				break;
			case ASSIGN+3:
				fprintf(f, "mul");
				break;
			case ASSIGN+4:
				fprintf(f, "div");
				break;
		}
		fprintf(f, "_float%s_float%s_float%s(&(op1.value), &op3, &op4);\n\treturn op1;\n}\n", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
		return;
	}

//arg1_no<arg2_no
	fprintf(f, "%s res;\n\t", types[arg2_no]);

	if(arg1_no<WF_TYPE){
		fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg2_no]);
		if(strcmp(types[arg2_no], "wf64_t")!=0 && strcmp(types[arg1_no], "double")!=0 && strcmp(types[arg1_no], "float")!=0){
			fprintf(f, "widefloat_float64_t op3_64;\n\t");//we can convert integers only to float64
		}
		//construction of wf from cpp type
		if(strcmp(types[arg1_no], "double")==0){
			fprintf(f, "widefloat_ext_float%s_from_ieee754_binary64(&op3, op1);", wf_size[arg2_no]);
		}else{
			if(strcmp(types[arg1_no], "float")==0){
				fprintf(f, "widefloat_ext_float%s_from_ieee754_binary32(&op3, op1);", wf_size[arg2_no]);
			}else{
				if(strcmp(types[arg2_no], "wf64_t")==0){
					if(arg1_no==0 || arg1_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3, (int64_t)op1);");
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3, (uint64_t)op1);");
					}
				}else{
					if(arg1_no==0 || arg1_no%2==1){
						fprintf(f, "widefloat_ext_convert_float64_from_signed_integer(&op3_64, (int64_t)op1);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg2_no]);
					}else{
						fprintf(f, "widefloat_ext_convert_float64_from_unsigned_integer(&op3_64, (uint64_t)op1);\n\twidefloat_ext_convert_float64_to_float%s(&op3, &op3_64);", wf_size[arg2_no]);
					}
				}
			}
		}
		fprintf(f, "\n\twidefloat_ext_");
		switch(op_no){
			case ASSIGN+1 :
				fprintf(f, "add");
				break;
			case ASSIGN+2 :
				fprintf(f, "sub");
				break;
			case ASSIGN+3 :
				fprintf(f, "mul");
				break;
			case ASSIGN+4 :
				fprintf(f, "div");
				break;
		}
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &op3, &(op2.value));\n\top1 = (%s)res;\n\treturn op1;\n}\n", wf_size[arg2_no], wf_size[arg2_no], wf_size[arg2_no], types[arg1_no]);
		return;
	}
//arg1_no>=WF_TYPE
	fprintf(f, "widefloat_float%s_t op3;\n\t", wf_size[arg2_no]);
	fprintf(f, "widefloat_ext_convert_float%s_to_float%s(&op3, &(op1.value));\n\t", wf_size[arg1_no], wf_size[arg2_no]);

	fprintf(f, "widefloat_ext_");

	switch(op_no){
		case ASSIGN+1 :
			fprintf(f, "add");
			break;
		case ASSIGN+2 :
			fprintf(f, "sub");
			break;
		case ASSIGN+3 :
			fprintf(f, "mul");
			break;
		case ASSIGN+4 :
			fprintf(f, "div");
			break;
	}
	fprintf(f, "_float%s_float%s_float%s(&(res.value), &op3, &(op2.value));\n\twidefloat_ext_convert_float%s_to_float%s(&(op1.value), &(res.value));\n\treturn op1;\n}\n", wf_size[arg2_no], wf_size[arg2_no], wf_size[arg2_no], wf_size[arg2_no], wf_size[arg1_no]);

}

void plus(FILE* f, int wf_no){

	fprintf(f, "\n%s %s::operator + () const{\n\treturn *this;\n}\n", types[wf_no], types[wf_no]);

}


void minus(FILE* f, int wf_no){

	fprintf(f, "\n%s %s::operator -() const {\n\t%s res;\n\twidefloat_ext_neg_float%s_float%s(&(res.value), &value);\n\treturn res;\n}\n", types[wf_no], types[wf_no], types[wf_no], wf_size[wf_no], wf_size[wf_no]);

}

void wf_sqrt(FILE* f, int wf_in, int wf_out){

	fprintf(f, "\n%s sqrt_to_%s(const %s &op){\n\t%s res;\n\twidefloat_ext_sqrt_float%s_float%s(&(res.value), &(op.value));\n\treturn res;\n}\n", types[wf_out], types[wf_out], types[wf_in], types[wf_out], wf_size[wf_in], wf_size[wf_out]);

}

void wf_fma(FILE* f, int wf_in, int wf_out){

	fprintf(f, "\n%s fma_to_%s(const %s &op1, const %s &op2, const %s &op3){\n\t%s res;\n\twidefloat_float%s_t op4, op5;", types[wf_out], types[wf_out], types[wf_in], types[wf_in], types[wf_in], types[wf_out], wf_size[wf_in]);
	//we must pay attention to the keyword 'restrict'
	fprintf(f, "\n\tif(&op1 == &op2){\n\t\tif(&op2 == &op3){");//the three references emboby the same variable
	fprintf(f, "\n\t\t\top4 = op1.value;\n\t\t\top5 = op1.value;");
	fprintf(f, "\n\t\t\twidefloat_ext_fma_float%s_float%s_float%s_float%s(&(res.value), &(op1.value), &op4, &op5);", wf_size[wf_in], wf_size[wf_in], wf_size[wf_in], wf_size[wf_out]);

	fprintf(f, "\n\t\t}else{");//the fist two parameters embody the same variable
	fprintf(f, "\n\t\t\top4 = op1.value;");
	fprintf(f, "\n\t\t\twidefloat_ext_fma_float%s_float%s_float%s_float%s(&(res.value), &(op1.value), &op4, &(op3.value));", wf_size[wf_in], wf_size[wf_in], wf_size[wf_in], wf_size[wf_out]);

	fprintf(f, "\n\t\t}\n\t}else{\n\t\tif(&op2 == &op3){");//the last two parameters embody the same variable
	fprintf(f, "\n\t\t\top4 = op2.value;");
	fprintf(f, "\n\t\t\twidefloat_ext_fma_float%s_float%s_float%s_float%s(&(res.value), &(op1.value), &op4, &(op3.value));", wf_size[wf_in], wf_size[wf_in], wf_size[wf_in], wf_size[wf_out]);

	fprintf(f, "\n\t\t}else{\n\t\t\tif(&op1 == &op3){");//the first and the last references embody the same vaiable
	fprintf(f, "\n\t\t\t\top4 = op1.value;");
	fprintf(f, "\n\t\t\t\twidefloat_ext_fma_float%s_float%s_float%s_float%s(&(res.value), &op4, &(op2.value), &(op3.value));", wf_size[wf_in], wf_size[wf_in], wf_size[wf_in], wf_size[wf_out]);

	fprintf(f, "\n\t\t\t}else{");//the three parameters refer to three different variables
	fprintf(f, "\n\t\t\t\twidefloat_ext_fma_float%s_float%s_float%s_float%s(&(res.value), &(op1.value), &(op2.value), &(op3.value));", wf_size[wf_in], wf_size[wf_in], wf_size[wf_in], wf_size[wf_out]);

	fprintf(f, "\n\t\t\t}\n\t\t}\n\t}");
	fprintf(f, "\n\treturn res;\n}\n");

}

