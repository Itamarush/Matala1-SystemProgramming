#ShortCuts for a simpler code

basNrec = basicClassification.o advancedClassificationRecursion.o
basNloop = basicClassification.o advancedClassificationLoop.o
FLAGS = -Wall -g -fPIC
#------------------------------------------------------------------------



libclassloops.a: $(basNloop)
	ar -rcs libclassloops.a $(basNloop)

libclassrec.a: $(basNrec)
	ar -rcs libclassrec.a $(basNrec)

libclassrec.so: $(basNrec)
	gcc $(FLAGS) -shared -o libclassrec.so $(basNrec)

libclassloops.so: $(basNloop)
	gcc $(FLAGS) -shared -o libclassloops.so $(basNloop)

main.o: main.c NumClass.h
	gcc -c main.c NumClass.h

basicClassification.o: basicClassification.c
	gcc -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -c advancedClassificationRecursion.c

#static library for the basic+loop functions
loops: libclassloops.a
	
#static library for the basic+recursive functions
recursives: libclassrec.a

#dynamic library for the basic+recursive functions
recursived: libclassrec.so

#dynamic library for the basic+loop functions
loopd: libclassloops.so

mains: main.o libclassrec.a
	gcc -Wall -g main.o libclassrec.a -o mains

maindloop: main.o libclassloops.so
	gcc -Wall -g main.c ./libclassloops.so -o maindloop
	
maindrec: main.o libclassrec.so
	gcc $(FLAGS) main.o ./libclassrec.so -o maindrec

all: main.o mains maindrec maindloop loops

clean: 
	rm maindrec mains maindloop *o *so *a *gch *out

	