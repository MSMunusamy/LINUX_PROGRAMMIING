ask: src1.o src_lib1.o src_lib2.o
	gcc src1.o src_lib1.o src_lib2.o -o ask
src1.o:src1.c  header_lib.h 
	gcc -c src1.c
src_lib1.o:src_lib1.c header_lib.h 
	gcc -c src_lib1.c
src_lib2.o:src_lib2.c header_lib.h 
	gcc -c src_lib2.c
