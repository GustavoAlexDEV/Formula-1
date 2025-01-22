SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) 

main: $(OBJ)
	cc -Wall $(OBJ) -o $@
	
%.o: %.c %.h
	cc -Wall -c $<

.PHONY: clean

clean:
	rm main $(OBJ)