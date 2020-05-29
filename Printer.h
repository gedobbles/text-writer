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

  bool chkBounds(float, float);

  const PChr pChars[256] = {
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //00
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //10
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},

    {"G0 X1 F4500",2.0f},                                                         //' '
    {"G0 Z-2;G0 Y-3.5;G0 Z2;G0 Y-1;G0 Z-2;G0 Y-0.5",1.0f},                  //'!'
    {"G0 Z-2;G0 Y-2;G0 Z2;G0 X1;G0 Z-2;G0 Y2",2.0f},                        //'"'
    {"G0 Y-5;G0 Z-2;G0 X0.5 Y5;G0 Z2;G0 X1.5;G0 Z-2;G0 X-0.5 Y-5;G0 Z2;" \
    "G0 X-2 Y1.75;G0 Z-2;G0 X2.5;G0 Z2;G0 Y1.5 X0.5;G0 Z-2;G0 X-2.5",3.5f}, //'#'
    {"G0 X1.1 Y-0.2;G0 Z-2;G0 Y-4.6;G0 Z2;G0 X-0.9 Y0.6;G0 Z-2;" \
    "G0 X0.9 Y-0.3;G0 X0.8 Y0.3;G0 X0.3 Y0.7;G0 X-0.4 Y0.7;G0 X-1.4 Y0.6;" \
    "G0 X-0.4 Y0.7;G0 X0.3 Y0.9;G0 X0.8 Y0.1;G0 X0.9 Y-0.3",2.9f},          //'$'
    {"G0 Y-0.8;G0 Z-2;G0 X0.2 Y-0.6;G0 X0.6 Y-0.2;G0 X0.6 Y0.2;" \
    "G0 X0.2 Y0.6;G0 X-0.2 Y0.6;G0 X-0.6 Y0.2;G0 X-0.6 Y-0.2;" \
    "G0 X-0.2 Y-0.6;G0 Z2;G0 X3 Y0.8;G0 Z-2;G0 X-3 Y-5;G0 Z2;" \
    "G0 X1.4 Y0.8;G0 Z-2;G0 X0.2 Y-0.6;G0 X0.6 Y-0.2;G0 X0.6 Y0.2;" \
    "G0 X0.2 Y0.6;G0 X-0.2 Y0.6;G0 X-0.6 Y0.2;G0 X-0.6 Y-0.2;" \
    "G0 X-0.2 Y-0.6",4.0f},                                                //'%'
    {"G0 X2.4 Y-4.2;G0 Z-2;G0 X-2.4 Y3.2;G0 X0.2 Y0.7;G0 X0.6 Y0.3;" \
    "G0 X0.6 Y-0.3;G0 X0.2 Y-0.5;G0 X-0.2 Y-0.8;G0 X-1.1 Y-1.4;" \
    "G0 X-0.3 Y-0.7;G0 X0.1 Y-0.7;G0 X0.5 Y-0.4;G0 X0.6;G0 X1.1 Y1.3",3.0f}, //'&'
    {"G0 Z-2;G0 Y-1.5",1.0f},                                               //'''
    {" ",0.0f}, {" ",0.0f}, {"G0 Z-2;G0 Y-1.5;G0 Z2;G0 X1 Y1.5",1.0f},      //'*' //TODO
    {"G0 Y-2.5;G0 Z-2;G0 X3;G0 Z2;G0 X-1.5 Y-1.5;G0 Z-2;G0 Y3",4.0f},       //'+'
    {"G0 Y-4.5;G0 Z-2;G0 X-0.5 Y-1",0.5f},                                  //','
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //2c
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //30
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},

    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //40
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //50
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},

    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //60
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //70
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f} /**,

    //probably dont need those
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //80
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},

    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},

    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},

    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
    {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}**/
  };

public:
  Printer (Serial*);
  virtual ~Printer ();
  void pChr(char);    //Print one Char
  bool pStr(const char*);   //Print a String
  bool seek(float, float);
  void newline();
};
