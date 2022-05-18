#Makefile to run the target files
BIN = bin/
OBJ = obj/
INC = include/
SRC = src/
CFLAG = -c
OFLAG = -o
all :  build-server build-client 
build-server:createOBJ 
	g++ ${OFLAG} ${BIN}server26 ${SRC}server.cpp ${OBJ}func.o
createOBJ:
	g++ ${CFLAG} ${OFLAG} ${OBJ}func.o ${SRC}func.cpp

build-client:
	g++ ${OFLAG} ${BIN}client26 ${SRC}client.cpp

startingserver:
	./${BIN}server26
startingclient:
	./${BIN}client26

clean:
	rm ${OBJ}func.o 
	rm ${BIN}client26 
	rm ${BIN}server26


