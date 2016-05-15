
#include "generation.h"

	const char types[][20]={"char", "signed char", "unsigned char", "int16_t", "uint16_t", "int32_t", "uint32_t", "int64_t", "uint64_t", "float", "double", "long double", "wf256_t", "wf512_t"};

	//redefinable C++ operators
	const char op[][4]={"+", "-", "*", "/", "=", "+=", "-=", "*=", "/=", "<", ">", "<=", ">=", "==", "!="};

	const char wf_size[][5] = {"", "", "", "", "", "", "", "", "", "", "", "", "256", "512"};

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
		fprintf(f, "\n%s::%s (){\n\twidefloat_ext_float%s_from_ieee754_binary64(&value, 0.0);\n}\n", types[wf_no], types[wf_no], wf_size[wf_no]);
		return;
	}

	//signed int
	if((arg_no<9 && arg_no%2==1 )||arg_no==0){
		fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_float64_t v2;\n\twidefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);\n\twidefloat_ext_convert_float64_to_float%s(&value, &v2);\n}\n", types[wf_no], types[wf_no], types[arg_no], wf_size[wf_no]);
		return;
	}
	//unsigned int
	if(arg_no<9 && arg_no%2==0){
		fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_float64_t v2;\n\twidefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);\n\twidefloat_ext_convert_float64_to_float%s(&value, &v2);\n}\n", types[wf_no], types[wf_no], types[arg_no], wf_size[wf_no]);
		return;
	}

	//float
	if(arg_no==9){
		fprintf(f, "\n%s::%s (const float & v){\n\twidefloat_ext_float%s_from_ieee754_binary32(&value, v);\n}\n", types[wf_no], types[wf_no], wf_size[wf_no]);
		return;
	}
	//double
	if(arg_no==10){
		fprintf(f, "\n%s::%s (const double & v){\n\twidefloat_ext_float%s_from_ieee754_binary64(&value, v);\n}\n", types[wf_no], types[wf_no], wf_size[wf_no]);
		return;
	}

	//long double
	if(arg_no==11){
		fprintf(f, "\n%s::%s (const long double & v){\n\twidefloat_ext_float%s_from_ieee754_binary64(&value, (double)v);\n}\n", types[wf_no], types[wf_no], wf_size[wf_no]);
		return;
	}

	//wf
	fprintf(f, "\n%s::%s (const %s & v){\n\twidefloat_ext_convert_float%s_to_float%s(&value, &(v.value));\n}\n", types[wf_no], types[wf_no], types[arg_no], wf_size[arg_no], wf_size[wf_no]);


}

void cast(FILE* f, int wf_no, int cpp_no){

	//signed integer
	if(cpp_no==0 || (cpp_no<9 && cpp_no%2==1)){
		fprintf(f, "\n%s::operator %s() const{\n\tint64_t res;\n\twidefloat_ext_convert_float%s_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);\n\treturn (%s)res;\n}\n", types[wf_no], types[cpp_no], wf_size[wf_no], types[cpp_no]);
		return;
	}

	//unsigned integer
	if(cpp_no<9 && cpp_no%2==0){
		fprintf(f, "\n%s::operator %s() const{\n\tuint64_t res;\n\twidefloat_ext_convert_float%s_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);\n\treturn (%s)res;\n}\n", types[wf_no], types[cpp_no], wf_size[wf_no], types[cpp_no]);
		return;
	}

	//float
	if(cpp_no==9){
		fprintf(f, "\n%s::operator float() const{\n\tfloat res;\n\twidefloat_ext_float%s_to_ieee754_binary32(&res, &value);\n\treturn res;\n}\n", types[wf_no], wf_size[wf_no]);
		return;
	}
	//double
	if(cpp_no==10){
		fprintf(f, "\n%s::operator double() const{\n\tdouble res;\n\twidefloat_ext_float%s_to_ieee754_binary64(&res, &value);\n\treturn res;\n}\n", types[wf_no], wf_size[wf_no]);
		return;
	}
	//long double
	fprintf(f, "\n%s::operator long double() const{\n\tdouble res;\n\twidefloat_ext_float%s_to_ieee754_binary64(&res, &value);\n\treturn (long double)res;\n}\n", types[wf_no], wf_size[wf_no]);
}

void arith(FILE* f, int arg1_no, int op_no, int arg2_no){

	if(arg1_no>arg2_no){//bigger type as returned type
		fprintf(f, "\n%s operator ", types[arg1_no]);
	}else{
		fprintf(f, "\n%s operator ", types[arg2_no]);
	}

	//sym
	switch(op_no){
		case ARITH :
			fprintf(f, "+ ");
			break;
		case ARITH+1 :
			fprintf(f, "- ");
			break;
		case ARITH+2 :
			fprintf(f, "* ");
			break;
		case ARITH+3 :
			fprintf(f, "/ ");
			break;
	}

	fprintf(f, "(const %s &op1, const %s &op2){\n\t", types[arg1_no], types[arg2_no]);

	if(arg1_no>arg2_no){//bigger type as returned type
		fprintf(f, "%s res;\n\t", types[arg1_no]);
	}else{
		fprintf(f, "%s res;\n\t", types[arg2_no]);
	}

	//cpp type
	if(arg1_no<WF_TYPE){
		fprintf(f, "%s op3 = op1;\n\twidefloat_ext_", types[arg2_no]);
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
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op2.value), &(op3.value));\n\treturn res;\n}\n", wf_size[arg2_no], wf_size[arg2_no], wf_size[arg2_no]);
		return;
	}

	if(arg2_no<WF_TYPE){
		fprintf(f, "%s op3 = op2;\n\twidefloat_ext_", types[arg1_no]);
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
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op1.value), &(op3.value));\n\treturn res;\n}\n", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
		return;
	}
	//wf type
	if(arg1_no<arg2_no){
		fprintf(f, "%s op3 = op1;\n\t", types[arg2_no]);
	}else{
		fprintf(f, "%s op3 = op2;\n\t", types[arg1_no]);
	}
	if(arg1_no>arg2_no){
		fprintf(f, "widefloat_ext_", types[arg1_no]);
	}else{
		fprintf(f, "widefloat_ext_", types[arg2_no]);
	}
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
	if(arg1_no>arg2_no){
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op1.value), &(op3.value));\n\treturn res;\n}\n", wf_size[arg1_no], wf_size[arg1_no], wf_size[arg1_no]);
	}else{
		fprintf(f, "_float%s_float%s_float%s(&(res.value), &(op3.value), &(op2.value));\n\treturn res;\n}\n", wf_size[arg2_no], wf_size[arg2_no], wf_size[arg2_no]);
	}

}
