basNrec = basicClassification.o advancedClassificationRecursion.o
basNloop = basicClassification.o advancedClassificationLoop.o
FLAGS = -Wall -g -fPIC
	
#static library for the basic+loop functions
loops: $(basNloop)
	ar -rcs libclassloops.a $(basNloop)
	
#static library for the basic+recursive functions
recursives: $(basNrec)
	ar -rcs libclassrec.a $(basNrec)

#dynamic library for the basic+recursive functions
recursived: $(basNrec)
	gcc -shared -o libclassrec.so $(basNrec)

#dynamic library for the basic+loop functions
loopd: $(basNloop)
	gcc -shared -o libclassloops.so $(basNloop)

mains: main.o libclassrec.a
	gcc $(FLAGS) main.o libclassrec.a -o mains

maindloop: main.o libclassloops.so
	gcc $(FLAGS) main.o libclassloops.so -o maindloop
	
maindrec: main.o libclassrec.so
	gcc $(FLAGS) main.o libclassrec.so -o maindrec

all: main.o libclassrec.a libclassloops.a  libclassloops.so libclassrec.so
	gcc $(FLAGS) main.o libclassrec.a libclassloops.a  libclassloops.so libclassrec.so

clean: 
	rm maindrec mains maindloop *o *so *a *gch *out 

libclassloops.a: $(basNloop)
	ar -rcs libclassloops.a $(basNloop)

libclassrec.a: $(basNrec)
	ar -rcs libclassrec.a $(basNrec)

libclassrec.so: $(basNrec)
	gcc -shared -o libclassrec.so $(basNrec)

libclassloops.so: $(basNloop)
	gcc -shared -o libclassloops.so $(basNloop)

main.o: main.c NumClass.h
	gcc -c main.c NumClass.h

basicClassification.o: basicClassification.c
	gcc -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -c advancedClassificationRecursion.c

	