#pragma once

#include <stdio.h>
#include <string>
#include <string.h>
// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <asm/termios.h>
#include <unistd.h> // write(), read(), close()


using std::string;

class Serial {
private:
  int serial_port;
  struct termios2 tty;
  char read_buf [256];

public:
  Serial (string, int);
  virtual ~Serial ();
  void w (string);
  void wln (string);
};
