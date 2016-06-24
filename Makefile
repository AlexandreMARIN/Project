
CFLAGS = -Wall -O3
CXXFLAGS = -Wall -g -O0
EXEC = create_header create_cpp create_test test_horner interp_lag interp

all: create_header create_cpp create_test
	@./create_header
	@./create_cpp
	@./create_test
	@echo "files \"wf_classes.cpp\", \"wf_classes.hpp\" and \"wf_test.cpp\" have just been generated"
	@make test_use
	@make wf_test
	@echo "\nThat program tests all functions :\n"
	@./wf_test


#program which uses wf types
wf_test: wf_test.o widefloat_float.o wf_classes.o
	@g++ $(CXXFLAGS) -o wf_test wf_test.o widefloat_float.o wf_classes.o

wf_test.o: wf_test.cpp
	@g++ $(CXXFLAGS) -c wf_test.cpp


#wf C-library
widefloat_float.o: widefloat_float.c
	@echo "widefloat_float.c is being compiled"
	@gcc $(CFLAGS) -c widefloat_float.c


#binding
wf_classes.o: wf_classes.cpp
	@g++ $(CXXFLAGS) -c wf_classes.cpp


#for generating test
create_test: create_test.c
	@gcc -o create_test create_test.c


#for generating header file and cpp file
generation.o: generation.c
	@gcc -c generation.c -o generation.o

create_header.o: create_header.c
	@gcc -c create_header.c -o create_header.o

create_cpp.o: create_cpp.c
	@gcc -c create_cpp.c -o create_cpp.o

create_header: create_header.o generation.o
	@gcc create_header.o generation.o -o create_header

create_cpp: create_cpp.o generation.o
	@gcc create_cpp.o generation.o -o create_cpp


#illustration
test_use:
	make interp
	make interp_lag
	@./interp > poly.txt
	@gnuplot --persist -e 'plot [-1:16] [0:3] "poly.txt" using 1:2 with lines title "Fonction", "poly.txt" using 1:3 with lines title "Interpolation";'
	@./interp_lag > polylag.txt
	@gnuplot --persist -e 'set label "Interpolation de Lagrange" at screen 0.4, 0.98 font "Arial, 12"; plot [-10:10] [-10:12] "polylag.txt" using 1:2 with lines title columnhead(1);'


#horner :
test_horner: horner.o main.o widefloat_float.o wf_classes.o
	@g++ -o test_horner horner.o main.o widefloat_float.o wf_classes.o

horner.o: horner.h horner.cpp
	@g++ -c -o horner.o horner.cpp

main.o: main.cpp horner.h
	@g++ -c -o main.o main.cpp


#interpolation
interp: interp.o horner.o test_interp.o lu.o matrice.o wf_classes.o widefloat_float.o
	@g++ -o interp interp.o horner.o test_interp.o lu.o matrice.o wf_classes.o widefloat_float.o -lm

test_interp.o: test_interp.cpp interp.h
	@g++ -c test_interp.cpp -o test_interp.o

#Lagrange's interpolation
interp_lag: interp.o horner.o test_interp_lag.o lu.o matrice.o wf_classes.o widefloat_float.o
	@g++ -o interp_lag interp.o horner.o test_interp_lag.o lu.o matrice.o wf_classes.o widefloat_float.o -lm

test_interp_lag.o: test_interp_lag.cpp interp.h
	@g++ -c test_interp_lag.cpp -o test_interp_lag.o

interp.o: interp.cpp interp.h
	@g++ -D'F(x)=exp(cos(x))' -D'C=0.0' -D'K=21' -D'pas=0.01' -D'A=0.0' -D'B=(5.0*M_PI)' -c interp.cpp -o interp.o -lm


#matrices with floating point values / lower-upper shape
matrice.o: matrice.cpp
	@g++ -c matrice.cpp -o matrice.o

lu.o: lu.cpp
	@g++ -c lu.cpp -o lu.o


clean:
	rm -f *.o $(EXEC)


.PHONY: all clean

