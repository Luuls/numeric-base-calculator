CC = g++
CFLAGS = -g -Wall
OBJ = main.o Calculator.o

all: calculator

calculator: $(OBJ)
	$(CC) $(CFLAGS) -o calculator $(OBJ)

main.o: main.cpp Calculator.h

Calculator.o: Calculator.cpp Calculator.h

clean: 
	rm calculator $(OBJ)
