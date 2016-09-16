#ifndef VAR_H
#define VAR_H

	/* This file enables us to use these variables in stand-alone sources AND in linked sources */


	const char types[][25]={"char", "signed char", "unsigned char", "short int", "unsigned short int", "int", "unsigned int", "long int", "unsigned long int", "long long int", "unsigned long long int", "float", "double", "wf32_t", "wf64_t", "wf96_t", "wf128_t", "wf160_t", "wf192_t", "wf224_t", "wf256_t", "wf288_t", "wf320_t", "wf352_t", "wf384_t", "wf416_t", "wf448_t", "wf480_t", "wf512_t"};

	//redefinable C++ operators
	const char op[][4]={"+", "-", "*", "/", "=", "+=", "-=", "*=", "/=", "<", ">", "<=", ">=", "==", "!="};

	const char wf_size[][5] = {"", "", "", "", "", "", "", "", "", "", "", "", "", "32", "64", "96", "128", "160", "192", "224", "256", "288", "320", "352", "384", "416", "448", "480", "512"};

	const char range[][2][15] = {{"CHAR_MIN", "CHAR_MAX"}, {"SCHAR_MIN", "SCHAR_MAX"}, {"0", "UCHAR_MAX"}, {"SHRT_MIN", "SHRT_MAX"}, {"0", "USHRT_MAX"}, {"INT_MIN", "INT_MAX"}, {"0", "UINT_MAX"}, {"LONG_MIN", "LONG_MAX"}, {"0", "ULONG_MAX"}};

#endif
