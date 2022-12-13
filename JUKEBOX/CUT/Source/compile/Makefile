##########################################################
# Created by: rtarkunde                                  #
# Created on: Friday 02 December 2022 02:06:54 PM IST #
##########################################################


SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
CFLAGS = -c -g -Wall -I${INCLUDEDIR}


all:
	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/musicplay.c -o ${OBJDIR}/musicplay.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/musicplay.o -o ${BINDIR}/album.bin


clean:

	rm ${OBJDIR}/main.o ${BINDIR}/album.bin


#################### End of Makefile #####################
