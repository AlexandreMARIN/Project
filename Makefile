
CFLAGS = -Wall -O3
CXXFLAGS = -Wall -g
EXEC = create_header create_cpp create_test test_horner interp_lag interp
MODE = c#c or cpp
CMODE = 2#1 or 2
WF = widefloat_float.o wf_classes.o#wf_classes.o if MODE=cpp, widefloat_float.o wf_classes.o if MODE=c

all: create_header create_cpp create_test
ifeq ($(MODE), c)
ifeq ($(CMODE), 1)
	@echo "c mode 1\n"
else
	@echo "c mode 2\n"
endif
else
	@echo "c++ mode\n"
endif
	@./create_header
	@./create_cpp $(CMODE)
	@./create_test
	@clear
	@echo "files \"wf_classes.cpp\", \"wf_classes.hpp\" and \"wf_test.cpp\" have just been generated"
	@make test_use
	@make wf_test
	@clear
	@echo "\nThat program tests all functions :\n"
	@./wf_test


#program which uses wf types
wf_test: wf_test.o $(WF)
	@g++ $(CXXFLAGS) -o wf_test wf_test.o $(WF)

wf_test.o: wf_test.cpp
	@g++ $(CXXFLAGS) -c wf_test.cpp


#wf C-library
ifeq ($(CMODE), 1)
widefloat_float.o: widefloat_float.c widefloat_float.h
	@clear
	@echo "widefloat_float.c is being compiled"
	@gcc $(CFLAGS) -c widefloat_float.c -o widefloat_float.o
else
widefloat_float.o: widefloat_float_library.c
	@clear
	@echo "widefloat_float_library.c is being compiled"
	@gcc $(CFLAGS) -c widefloat_float_library.c -o widefloat_float.o
endif

#binding
wf_classes.o: wf_classes.cpp
	@g++ $(CXXFLAGS) -O3 -c wf_classes.cpp


#for generating test
create_test: create_test.c
	@gcc -o create_test create_test.c


#for generating header file and cpp file
ifeq ($(MODE), c)
ifeq ($(CMODE), 1)
generation.o: generation_ext.c
	@gcc -c generation_ext.c -o generation.o
else
generation.o: generation.c
	@gcc -c generation.c -o generation.o
endif
else
generation.o: generation.c
	@gcc -c generation.c -o generation.o
endif

create_header.o: create_header.c
	@gcc -c create_header.c -o create_header.o

ifeq ($(MODE), c)
create_cpp.o: create_cpp_ext.c
	@gcc -c create_cpp_ext.c -o create_cpp.o
else
create_cpp.o: create_cpp.c
	@gcc -c create_cpp.c -o create_cpp.o
endif

create_header: create_header.o generation.o
	@gcc create_header.o generation.o -o create_header

create_cpp: create_cpp.o generation.o
	@gcc create_cpp.o generation.o -o create_cpp


#test
test_use:
	make interp
	make interp_lag
	@./interp > poly.txt
	@gnuplot --persist -e 'plot [-1:16] [0:3] "poly.txt" using 1:2 with lines title "Fonction", "poly.txt" using 1:3 with lines title "Interpolation";'
	@./interp_lag > polylag.txt
	@gnuplot --persist -e 'set label "Interpolation de Lagrange" at screen 0.4, 0.98 font "Arial, 12"; plot [-10:10] [-10:12] "polylag.txt" using 1:2 with lines title columnhead(1);'


#horner :
test_horner: horner.o main.o $(WF)
	@g++ $(CXXFLAGS) -o test_horner horner.o main.o $(WF)

horner.o: horner.h horner.cpp
	@g++ $(CXXFLAGS) -c -o horner.o horner.cpp

main.o: main.cpp horner.h
	@g++ $(CXXFLAGS) -c -o main.o main.cpp


#interpolation
interp: interp.o horner.o test_interp.o lu.o matrice.o $(WF)
	@g++ $(CXXFLAGS) -o interp interp.o horner.o test_interp.o lu.o matrice.o $(WF) -lm

test_interp.o: test_interp.cpp interp.h
	@g++ $(CXXFLAGS) -c test_interp.cpp -o test_interp.o

#Lagrange's interpolation
interp_lag: interp.o horner.o test_interp_lag.o lu.o matrice.o $(WF)
	@g++ $(CXXFLAGS) -o interp_lag interp.o horner.o test_interp_lag.o lu.o matrice.o $(WF) -lm

test_interp_lag.o: test_interp_lag.cpp interp.h
	@g++ $(CXXFLAGS) -c test_interp_lag.cpp -o test_interp_lag.o

interp.o: interp.cpp interp.h
	@g++ $(CXXFLAGS) -D'F(x)=exp(cos(((double)(x))))' -D'C=0.0' -D'K=21' -D'pas=0.01' -D'A=0.0' -D'B=(5.0*M_PI)' -c interp.cpp -o interp.o -lm


#matrices with floating point values / lower-upper shape
matrice.o: matrice.cpp
	@g++ $(CXXFLAGS) -c matrice.cpp -o matrice.o

lu.o: lu.cpp
	@g++ $(CXXFLAGS) -c lu.cpp -o lu.o


#test of the efficiency
gather_measures: gather_measures.c
	gcc gather_measures.c -o gather_measures

gather_durations: gather_durations.c
	gcc gather_durations.c -o gather_durations
#use these programs with a parameter : 'c' or 'cpp'



clean:
	rm -f *.o $(EXEC)


.PHONY: all clean

