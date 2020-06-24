#include "Printer.h"
#include "config.h"


Printer::Printer(Serial* s){
  this->s = s;
  s->wln("G28");
  z = 0.0;
  seek(0.0f,0.0f);
}

Printer::~Printer(){

}

bool Printer::chkBounds(float sx, float sy){
  if(sx < 0 || sx > X_MAX - X_MIN || sy < 0 || sy > Y_MAX - Y_MIN){
    printf("chkBounds failed: %f %f\n",sx,sy);
    return false;
  }
  return true;
}

void Printer::configure(int field, string value){
  switch (field) {
    case CONFIG_FIELD_XMIN :
      this->X_MIN = stof(value);
      break;
    case CONFIG_FIELD_XMAX :
      this->X_MAX = stof(value);
      break;
    case CONFIG_FIELD_YMIN :
      this->Y_MIN = stof(value);
      break;
    case CONFIG_FIELD_YMAX :
      this->Y_MAX = stof(value);
      break;
    case CONFIG_FIELD_ZTRAVEL :
      this->Z_MOVE = stof(value);
      break;
    case CONFIG_FIELD_ZWRITE :
      this->Z_WRITE = stof(value);
      break;
    case CONFIG_FIELD_X :
      this->px = stof(value);
      break;
    case CONFIG_FIELD_Y :
      this->py = stof(value);
      break;
  }
  this->seek(this->px, this->py);
}

bool Printer::seek(float sx, float sy){
  if(!chkBounds(sx, sy)){
    return false;
  }
  s->wln("G90");  //absolute Positioning, just in Case
  px = sx;
  py = sy;
  x = X_MIN + px;
  y = Y_MAX - py;
  s->wln("G0 Z"+std::to_string(Z_MOVE));
  s->wln("G0 X"+std::to_string(x)+" Y"+std::to_string(y)+" F4500");
  return true;
}

bool Printer::pStr(const char* msg) {
  float len = 0.0f;
  char txt[100];
  strcpy(txt, msg);
  for (int i = 1; txt[i] != 0; i++) {
    len += pChars[msg[i]].length;
  }
  if((px + len) > X_MAX){
    return false;
  }
  for (int i = 1; txt[i] != 0; i++) {
    pChr(msg[i]);
  }
  return true;
}

void Printer::pChr(char c){
  x += pChars[c].length;
  s->wln("G0 Z"+std::to_string(Z_WRITE+2)+" F1400");
  s->wln("G91");
  std::string text = pChars[c].moves;
  std::vector<std::string> results;
  boost::split(results, text, [](char c){return c == ';';});
  for (string move : results) {
    printf("%s\n", move.c_str());
    s->wln(move);
  }
  s->wln("G90");
  s->wln("G0 Z"+std::to_string(Z_MOVE));
  s->wln("G0 X"+std::to_string(x)+" Y"+std::to_string(y)+" F3000");
}

void Printer::newline(char anz){
  seek(0,py+7.5*anz);
}
