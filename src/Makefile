CC:=g++
CFLAGS:=-std=c++14 -Wall

BUILD_DIR:=./build

EXEC:=./tp1
TARGET:=tp1

$(EXEC): ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp -o ${BUILD_DIR}/main.o

clean:
	rm -f ${BUILD_DIR}/*