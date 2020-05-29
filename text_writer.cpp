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
  getline (std::cin, input);
  if(input == ""){
    device = "/dev/ttyUSB0";
  }else{
    device = input;
  }

  Serial* s = new Serial(device,250000);

  getline (std::cin, input);
  while (input != "x") {
    s->wln(input);
    getline (std::cin, input);
  }

  return 0;
}
