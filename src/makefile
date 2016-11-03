CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic
EXEC=test.out
SOURCES=main.cpp Andand.cpp Command.cpp Oror.cpp Semicolon.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXEC)
    
$(EXEC): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@
	
clean: 
	rm -f $(EXEC) $(OBJECTS)