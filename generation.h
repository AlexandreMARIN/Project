#include <string.h>
#include <stdio.h>
#ifndef GENERATION_H

#define GENERATION_H

	//C++ types and new widefloat wf..._t
	enum domain {CPP_TYPE, WF_TYPE = 13, TYPE_NB = 29};
	enum op_type {ARITH, ASSIGN = 4, COMP = 9, OP_NB = 15};
	//for creating function prototypes
	void function_sign(char* dest, char* prefix, char* returned_type, char* name, int arg_nb, char** arg_types, char* suffix);

	void constructor(FILE* f, int wf_no, int arg_no);//writes a constructor

	void cast(FILE* f, int wf_no, int cpp_no);

	void arith(FILE* f, int arg1_no, int op_no, int arg2_no);

	void comp(FILE* f, int arg1_no, int op_no, int arg2_no);

	void assign(FILE* f, int wf_no, int arg_no);

	void ext_assign(FILE* f, int arg1_no, int op_no, int arg2_no);

	void plus(FILE* f, int wf_no);

	void minus(FILE* f, int wf_no);

	void wf_sqrt(FILE* f, int wf_in, int wf_out);

	void wf_fma(FILE* f, int wf_in, int wf_out);
#endif
