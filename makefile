#All the dependencies for this project
TARGET  = egarcia_argtok   # executable
HEADERS = egarcia_argtok.h # headers with signatures
OBJECTS = egarcia_lab1.c egarcia_argtok.o # All the object files
CC      = gcc              # Compiler
CFLAGS  = -c 						   #Compiler flags

#Make all will target the default target which is the executable
#declared above
default: $(TARGET)
all: default

#Compiling our executable in this case egarcia_argtok
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

#Compiling all the object files that our executable is dependent on:
#egarcia_argtok.c and egarcia_lab1.c with the header egarcia_argtok.h
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

#Run make run to execute the target
run: $(TARGET)
	./$(TARGET)

#Removing all of the files except the .c
clean:
	-rm -f *.o
	-rm -f $(TARGET)
