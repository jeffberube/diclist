CC = g++
OBJ = main.o dictionary.o 

diclist: $(OBJ)
	$(CC) $(OBJ) -std=c++11 -g -o $@

.cpp.o:
	$(CC) -std=c++11 -g -c $<

clean:
	rm *.o diclist
