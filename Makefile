
CFLAGS = -Wall -O3
CXXFLAGS = -Wall -g -O0
EXEC = create_header create_cpp

all: $(EXEC)


#test
wf_test: wf_test.o widefloat_float.o wf_classes.o
	g++ $(CXXFLAGS) -o wf_test wf_test.o widefloat_float.o wf_classes.o

#program which uses wf types
wf_test.o: wf_test.cpp
	g++ $(CXXFLAGS) -c wf_test.cpp

#wf C-library
widefloat_float.o: widefloat_float.c
	gcc $(CFLAGS) -c widefloat_float.c

#binding
wf_classes.o: wf_classes.cpp
	g++ $(CXXFLAGS) -c wf_classes.cpp


#for generating header file and cpp file
generation.o: generation.c
	gcc -c generation.c -o generation.o

create_header.o: create_header.c
	gcc -c create_header.c -o create_header.o

create_cpp.o: create_cpp.c
	gcc -c create_cpp.c -o create_cpp.o

create_header: create_header.o generation.o
	gcc create_header.o generation.o -o create_header

create_cpp: create_cpp.o generation.o
	gcc create_cpp.o generation.o -o create_cpp



clean:
	rm -f *.o $(EXEC)


.PHONY: all clean

