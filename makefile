OBJ = text_writer.o

all: text_writer

text_writer: $(OBJ)
	gcc -o $@ $<

%.o: %.c
	gcc -c -o $@ $<
