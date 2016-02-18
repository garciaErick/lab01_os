#All the dependencies for this project
TARGET  = egarcia_argtok   # executable
HEADERS = egarcia_argtok.h # headers with signatures
OBJECTS = egarcia_argtok.o # All the object files
CC      = gcc              # Compiler
#Compilation Flags
CFLAGS  = -c -Wno-deprecated-declarations

#Make all will target the default target which is the executable
#declared above
default: $(TARGET)
all: default

#Compiling our executable in this case egarcia_argtok
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

#Compiling the object files that our executable is dependent on 
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)
#Removing all of the files except the .c
clean:
	-rm -f *.o
	-rm -f $(TARGET)

