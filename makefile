SRC = Serial.cpp Printer.cpp text_writer.cpp

all: text_writer

text_writer: $(SRC)
	g++ -o $@ $(SRC)

debug: $(SRC)
	g++ -g -o text_writer.dbg $(SRC)
