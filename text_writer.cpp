// C library headers
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

#include "Serial.h"

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
  //create Serial
  Serial* s = new Serial(device,250000);
  //say something to get attention
  s->wln("M117 Ready to plot!");

  getline (std::cin, input);
  while (input != "x") {
    if(input.c_str()[0] == 'G' || input.c_str()[0] == 'M' || input.c_str()[0] == 'T'){
      s->wln(input);
    }
    if(input.c_str()[0] == ':'){
      ;//printer.w(input);
    }
    getline (std::cin, input);
  }
  s->wln("M117 Bye!");
  return 0;
}
