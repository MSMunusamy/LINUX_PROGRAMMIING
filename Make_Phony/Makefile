ask: Main.o Addition.o Subtract.o
	gcc Main.o Addition.o Subtract.o -o ask
Main.o:Main.c header_lib.h 
	gcc -c Main.c
Addition.o:Addition.c header_lib.h 
	gcc -c Addition.c
Subtract.o:Subtract.c header_lib.h 
	gcc -c Subtract.c
.PHONY: clean
clean: 
	rm *o ask
