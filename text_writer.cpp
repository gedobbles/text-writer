// C library headers
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <unistd.h> // write(), read(), close()

#include "Serial.h"
#include "Printer.h"
#include "config.h"

#define DBG 1    //Comment out to switch debug output of

int main(int argc, char const *argv[]) {
  printf("3D Printer plot writer by gedobbles.\nx to exit\ndevice?[/dev/ttyUSB0] ");

  string input, device;
  //which device to use, Standard: /dev/ttyUSB0
  getline (std::cin, input);
  if(input == ""){
    device = "/dev/ttyUSB0";
  }else{
    device = input;
  }
  printf("Waiting for the printer to come online...\n");
  //create Serial
  Serial* s = new Serial(device,250000);
  //say something to get attention
  //s->wln("M117 ...");
  s->wln("M117 Ready to plot!");

  Printer* p = NULL;

  printf(">");
  getline (std::cin, input);
  while (input != "x") {

    //If its a G/M/T-Code just pass it on
    if(input.c_str()[0] == 'G' || input.c_str()[0] == 'M' || input.c_str()[0] == 'T'){
      s->wln(input);
    }

    //If preceded by TEXT_START_CHAR, print as text
    if(input.c_str()[0] == TEXT_START_CHAR){
      if(p == NULL){  //create Printer Obj on first occurrance
        p = new Printer(s);
      }
      p->pStr(input.c_str());
    }

    //If NEWLINE_CHAR make newline
    if(input.c_str()[0] == NEWLINE_CHAR){
      if(p == NULL){  //create Printer Obj on first occurrance
        p = new Printer(s);
      }
      char c1 = input.c_str()[1];
      if(c1 > '0' && c1 <= '9'){
        p->newline(c1-'0');
      }else{
        p->newline(1);
      }
    }

    //If CONFIG_CHAR seen do config things
    if(input.c_str()[0] == CONFIG_CHAR){
      if(p == NULL){  //create Printer Obj on first occurrance
        p = new Printer(s);
      }

      //strip preceding CONFIG_CHAR
      char config[strlen(input.c_str())+1];
      int i;
      for(i = 0;input.c_str()[i] != '\0'; i++) {
        config[i] = input.c_str()[i+1];
      }
      config[i] = '\0';
      string configstr(config);

      //split config fields
      std::vector<std::string> configfields;
      boost::split(configfields, configstr, [](char c){return c == ' ';});
      for (int i = 0; i < configfields.size(); i+=2) {
        //do configure fields
        int fieldnr = CONFIG_FIELD_NONE;
        //check what it is
        if(configfields[i] == CONFIG_FIELD_XMIN_STR){
          fieldnr = CONFIG_FIELD_XMIN;
        }
        if(configfields[i] == CONFIG_FIELD_XMAX_STR){
          fieldnr = CONFIG_FIELD_XMAX;
        }
        if(configfields[i] == CONFIG_FIELD_YMIN_STR){
          fieldnr = CONFIG_FIELD_YMIN;
        }
        if(configfields[i] == CONFIG_FIELD_YMAX_STR){
          fieldnr = CONFIG_FIELD_YMAX;
        }
        if(configfields[i] == CONFIG_FIELD_ZTRAVEL_STR){
          fieldnr = CONFIG_FIELD_ZTRAVEL;
        }
        if(configfields[i] == CONFIG_FIELD_ZWRITE_STR){
          fieldnr = CONFIG_FIELD_ZWRITE;
        }
        if(configfields[i] == CONFIG_FIELD_X_STR){
          fieldnr = CONFIG_FIELD_X;
        }
        if(configfields[i] == CONFIG_FIELD_Y_STR){
          fieldnr = CONFIG_FIELD_Y;
        }

        #ifdef DBG
        printf("Config: %d %s\n", fieldnr, configfields[i+1].c_str());
        #endif

        if(fieldnr != CONFIG_FIELD_NONE){
          p->configure(fieldnr, configfields[i+1]);
        }
      }
    }

    printf(">");
    getline (std::cin, input);
  }
  s->wln("M117 Bye!");
  return 0;
}
