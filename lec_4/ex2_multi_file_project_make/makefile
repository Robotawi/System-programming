progy: myadd.o mymul.o mydiv.o mysub.o prog.o
	gcc myadd.o mymul.o mydiv.o mysub.o prog.o -o progy

myadd.o: myadd.c
	gcc -c myadd.c

mymul.o: myadd.c
	gcc -c mymul.c

mydiv.o: myadd.c
	gcc -c mydiv.c

mysub.o: myadd.c
	gcc -c mysub.c

prog.o: src/prog.c mymath.h
	gcc -c -I . src/prog.c

