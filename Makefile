# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -Iinclude tells the directory where the headers live
CFLAGS  = -g -Wall -Iinclude

# the build target executable:
TARGET = bin/rogue

# the source to be compiled
SRC = src/*.cpp

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	$(RM) $(TARGET)
