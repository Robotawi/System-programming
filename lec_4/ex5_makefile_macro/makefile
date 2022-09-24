all: progy #by convention, the first target name is all
#define the macros here 
CC = gcc #compiler to use 
CLAGS = -std=c11 -O0 -Wall -g
INCLUDES = . 
LIBS = -lc
OBJS = myadd.o mymul.o mydiv.o mysub.o prog.o ./mod/mymod.o
INSTDIR = /usr/bin

progy: $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o progy

myadd.o: myadd.c
	$(CC) -c myadd.c $(CLAGS)

mymul.o: myadd.c
	$(CC) -c mymul.c $(CLAGS)

mydiv.o: myadd.c
	$(CC) -c mydiv.c $(CLAGS)

mysub.o: myadd.c
	$(CC) -c mysub.c $(CLAGS) 

prog.o: src/prog.c mymath.h ./mod/mymod.h
	$(CC) -c -I $(INCLUDES) -I ./mod src/prog.c $(CLAGS)

include: ./mod/makefile

clean: 
	rm -f $(OBJS) 

# install: progy
# 	@cp progy $(INSTDIR)
# 	@chmod a+x $(INSTDIR)/progy
# 	@chmod og-w $(INSTDIR)/progy
# 	@echo "progy sucessfully installed in $(INSTDIR)"

install: progy 
#add if condition to check id the directory exists 
	@if [ -d $(INSTDIR) ]; \
	then \
		cp progy $(INSTDIR) && \
		chmod a+x $(INSTDIR)/progy && \
		chmod og-w $(INSTDIR)/progy && \
		echo "progy sucessfully installed in $(INSTDIR)"; \
	fi

uninstall:
	@rm -f $(INSTDIR)/progy
	@echo "progy successfully un-installed from $(INSTDIR)"
