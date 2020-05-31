#include "Serial.h"

#include <stdio.h>
#include <string>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <unistd.h> // write(), read(), close()
#include <stropts.h>
#include <asm/termios.h>


using std::string;

Serial::Serial(string device, int baud){
  serial_port = open(device.c_str(), O_RDWR);

  memset(&tty, 0, sizeof tty);

  if(ioctl(serial_port, TCGETS2, &tty) != 0) {
      printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }

  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
  tty.c_cflag |= CS8; // 8 bits per byte (most common)
  tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
  tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

  tty.c_lflag = 0;
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

  tty.c_oflag = 0;

  tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
  tty.c_cc[VMIN] = 0;

  // Set in/out baud rate
  //cfsetispeed(&tty, baud);
  //cfsetospeed(&tty, baud);
  tty.c_cflag &= ~CBAUD;
  tty.c_cflag |= BOTHER;
  tty.c_ispeed = baud;
  tty.c_ospeed = baud;

  // Save tty settings, also checking for error
  if (ioctl(serial_port, TCSETS2, &tty) != 0) {
      printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
  }
  write(serial_port,"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",100);
  w("\n");
  sleep(6);     //wait for reboot
  read(serial_port, &read_buf, sizeof(read_buf)); //empty text
}

Serial::~Serial(){
  close(serial_port);
}

void Serial::w(string msg){
  write(serial_port, msg.c_str(), msg.size());
}

void Serial::wln(string msg){
  printf("%s   \t", msg.c_str());
  w(msg + "\n");                //Send the command

  //Check for response
  sleep(0.05);  //but wait before
  memset(&read_buf, '\0', sizeof(read_buf));
  int num_bytes;
  num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
  printf("%s", read_buf);
  //we need an "ok" here
  while(((string) read_buf).find("ok") == string::npos){  //while no ok in response
    if (((string) read_buf).find("k\n") != string::npos) {  //this also counts
      printf("\n!!! Bad ok !!!  ");
      break;
    }

    //try to get next line
    int i = 20;
    while((num_bytes = read(serial_port, &read_buf, sizeof(read_buf)))==0){
      i--;
      if(i == 0){
        break;
      }
      sleep(0.05);
      printf(".");
    }
    if(num_bytes <= 0){
      printf("! Read error. Please check connection");
    }else{
      printf("%s", read_buf);
    }
  }
}
