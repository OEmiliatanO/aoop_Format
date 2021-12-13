CC:=g++

all: main.o Form.o
	$(CC) -o main main.o Form.o
dep: main.cpp src/Form.cpp
	$(CC) -c -W main.cpp
	$(CC) -c -W src/Form.cpp
clean:
	rm *.o
