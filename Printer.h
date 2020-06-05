#pragma once

#include <boost/algorithm/string.hpp>

#include <string>
#include <vector>

#include "Serial.h"

struct PChr {
  string moves;
  float length;
};


class Printer {
private:
  float X_MIN = 0.0; //Writing area dims
  float X_MAX = 140.0;
  float Y_MIN = 90.0;
  float Y_MAX = 195.0;
  float Z_WRITE = 6.0;
  float Z_MOVE  = 9.0;
  float x, y, z;          //Position of printhead
  float px, py;           //Position on paper

  Serial* s;

  bool chkBounds(float, float);                 //Check if still on paper

  //because its very long...
  #include "Printer_chars.h"

public:
  Printer (Serial*);
  virtual ~Printer ();
  void pChr(char);                              //Print one Char
  bool pStr(const char*);                       //Print a String
  bool seek(float, float);                      //Seek to a position on the paper
  void setBounds(float, float, float, float);   //Set paper bounds
  void newline(char);                               //Make a newline
};
