CC := g++
CFLAGS := -std=c++20 -Wall -pedantic
SOURCES := main.cpp

ifeq (${OS},Windows_NT)
	TARGET := .\main.exe
	RM := del
else
	TARGET := ./main
	RM := rm
endif

all:
	$(CC) ${CFLAGS} -o ${TARGET} ${SOURCES}

clean:
	${RM} ${TARGET}

run: all
	$(TARGET)