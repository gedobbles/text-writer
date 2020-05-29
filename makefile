SRC = Serial.cpp text_writer.cpp

all: text_writer

text_writer: $(SRC)
	g++ -o $@ $(SRC)
