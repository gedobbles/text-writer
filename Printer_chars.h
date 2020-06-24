const PChr pChars[256] = {
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //00
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, //10
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},
  {" ",0.0f}, {" ",0.0f}, {" ",0.0f}, {" ",0.0f},

  {"G0 X1 F4500",2.0f},                                                   //' '
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
  "G0 X-0.2 Y-0.6",4.0f},                                                 //'%'
  {"G0 X2.4 Y-4.5;G0 Z-2;G0 X-2.4 Y3.5;G0 X0.2 Y0.7;G0 X0.6 Y0.3;" \
  "G0 X0.6 Y-0.3;G0 X0.2 Y-0.5;G0 X-0.2 Y-0.8;G0 X-1.1 Y-1.4;" \
  "G0 X-0.3 Y-0.7;G0 X0.1 Y-0.7;G0 X0.5 Y-0.4;G0 X0.6;G0 X1.1 Y1.3",3.0f},//'&'
  {"G0 Z-2;G0 Y-1.5",1.0f},                                               //'''
  {"G0 X0.6;G0 Z-2;G0 X-0.4 Y-1.3;G0 X-0.2 Y-1.2;G0 X0.2 Y-1.2;" \
  "G0 X0.4 Y-1.3",1.4f},                                                  //'('
  {"G0 Z-2;G0 X0.4 Y-1.3;G0 X0.2 Y-1.2;G0 X-0.2 Y-1.2;" \
  "G0 X-0.4 Y-1.3",1.4f},                                                  //')'
  {"G0 X1;G0 Z-2;G0 Y-2;G0 Z2;G0 X-1 Y1.6;G0 Z-2;G0 X2 Y-1.2;G0 Z2;" \
  "G0 X-2;G0 Z-2;G0 X2 Y1.2",2.9f},                                       //'*'
  {"G0 Y-2.5;G0 Z-2;G0 X3;G0 Z2;G0 X-1.5 Y-1.5;G0 Z-2;G0 Y3",4.0f},       //'+'
  {"G0 Y-4.5;G0 Z-2;G0 X-0.5 Y-1",1.0f},                                  //','
  {"G0 Y-2.5;G0 Z-2;G0 X2.5",3.0f},                                       //'-'
  {"G0 Y-4.5;G0 Z-2;G0 Y-0.5",1.0f},                                      //'.'
  {"G0 X1.2;G0 Z-2;G0 X-1.2 Y-5",1.5f},                                   //'/'
  {"G0 X1.3;G0 Z-2;G0 X-0.6 Y-0.2;G0 X-0.4 Y-0.6;G0 X-0.3 Y-1.9;" \
  "G0 X0.2 Y-1.6;G0 X0.3 Y-0.5;G0 X0.7 Y-0.2;G0 X0.6 Y0.2;G0 X0.3 Y0.5;" \
  "G0 X0.3 Y1.7;G0 X-0.1 Y1.7;G0 X-0.4 Y0.7;G0 X-0.5 Y0.2", 3.0f},        //'0'
  {"G0 Y-1.7;G0 Z-2;G0 X1.1 Y1.7;G0 Y-5", 2.2f},                          //'1'
  {"G0 Y-1.3;G0 Z-2;G0 X0.4 Y0.9;G0 X0.8 Y0.4;G0 X0.8 Y-0.4;" \
  "G0 X0.3 Y-0.7;G0 X-0.1 Y-0.8;G0 X-0.3 Y-0.5;G0 X-1.9 Y-2.6;" \
  "G0 X2.3", 2.9f},                                                       //'2'
  {"G0 Y-0.8;G0 Z-2;G0 X0.4 Y0.6;G0 X0.8 Y0.2;G0 X0.8 Y-0.4;" \
  "G0 X0.3 Y-0.7;G0 X-0.1 Y-0.8;G0 X-0.4 Y-0.6;G0 X-1;G0 Z2;G0 X1 Y-0.1;" \
  "G0 Z-2;G0 X0.4 Y-0.6;G0 X0.1 Y-0.7;G0 X-0.3 Y-0.8;G0 X-0.8 Y-0.3;" \
  "G0 X-0.8 Y0.2;G0 X-0.4 Y0.4", 2.9f},                                   //'3'
  {"G0 X0.6;G0 Z-2;G0 X-0.6 Y-2.8;G0 X2.1 Y0.1;G0 Z2;G0 X-1 Y1.2;G0 Z-2;" \
  "G0 Y-3.5", 2.7f},                                                      //'4'
  {"G0 X2;G0 Z-2;G0 X-2;G0 Y-2.5;G0 X1 Y0.2;G0 X0.8 Y-0.4;G0 X0.2 Y-0.9;" \
  "G0 X-0.2 Y-1.1;G0 X-0.9 Y-0.3;G0 X-0.9 Y0.3", 2.7f},                   //'5'
  {"G0 X2.1;G0 Z-2;G0 X-0.9 Y-0.1;G0 X-0.8 Y-0.6;G0 X-0.4 Y-1.6;" \
  "G0 X0.1 Y-1.9;G0 X0.4 Y-0.6;G0 X0.9 Y-0.2;G0 X0.8 Y0.4;G0 X0.1 Y0.9;" \
  "G0 X-0.2 Y0.8;G0 X-1 Y0.3;G0 X-1 Y-0.5", 2.8f},                        //'6'
  {"G0 Z-2;G0 X1.7;G0 X-1.4 Y-5;G0 Z2;G0 Y2.6;G0 Z-2;G0 X1.3", 2.3f},     //'7'
  {"G0 X1.1;G0 Z-2;G0 X-0.6 Y-0.3;G0 X-0.4 Y-0.9;G0 X0.2 Y-0.8;" \
  "G0 X0.8 Y-0.4;G0 X0.9 Y-0.6;G0 X0.3 Y-0.8;G0 X-0.3 Y-0.9;" \
  "G0 X-0.8 Y-0.3;G0 X-0.8 Y0.3;G0 X-0.4 Y0.9;G0 X0.3 Y0.8;G0 X0.9 Y0.6;" \
  "G0 X0.8 Y0.4;G0 X0.2 Y0.8;G0 X-0.4 Y0.9;G0 X-0.6 Y0.3", 2.7f},         //'8'
  {"G0 X2.1 Y-2.4;G0 Z-2;G0 Y1.1;G0 X-0.3 Y0.9;G0 X-0.7 Y0.4;G0 X-0.8 Y-0.3;" \
  "G0 X-0.3 Y-1;G0 X0.2 Y-1;G0 X0.8 Y-0.5;G0 X1.1 Y0.3;G0 Y-1.4;" \
  "G0 X-0.3 Y-0.8;G0 X-0.8 Y-0.3;G0 X-0.9 Y0.2", 2.7f},                   //'9'
  {"G0 Y-1.5;G0 Z-2;G0 Y-0.5;G0 Z2;G0 Y-2.5;G0 Z-2;G0 Y-0.5",1.0f},       //':'
  {"G0 Y-1.5;G0 Z-2;G0 Y-0.5;G0 Z2;G0 Y-2.5;G0 Z-2;G0 X-0.5 Y-1",1.0f},   //';'
  {"G0 X2 Y-1;G0 Z-2;G0 X-2 Y-1.5;G0 X2 Y-1.5",3.0f},                     //'<'
  {"G0 Y-1.8;G0 Z-2;G0 X2;G0 Z2;G0 Y-1.4;G0 Z-2;G0 X-2",3.0f},            //'='
  {"G0 Y-1;G0 Z-2;G0 X2 Y-1.5;G0 X-2 Y-1.5",3.0f},                        //'>'
  {"G0 Y-1;G0 Z-2;G0 X0.5 Y0.6;G0 X0.7 Y0.4;G0 X0.8 Y-0.4;G0 X0.4 Y-0.9;" \
  "G0 X-0.4 Y-0.8;G0 X-0.8 Y-0.4;G0 Y-1;G0 Z2;G0 Y-1;G0 Z-2;" \
  "G0 Y-0.5", 3.0f},                                                      //'?'
  {"G0 X2.5 Y-1.8;G0 Z-2;G0 X-0.7 Y0.2;G0 X-0.9 Y-0.3;G0 X-0.3 Y-1;" \
  "G0 X0.5 Y-0.8;G0 X0.8 Y-0.3;G0 X0.7 Y0.3;G0 Y2.7;G0 X-0.6 Y0.6;G0 X-1.1;" \
  "G0 X-0.7 Y-0.7;G0 X-0.2 Y-1.6;G0 X0.3 Y-1.6;G0 X0.8 Y-0.7;G0 X0.9;" \
  "G0 X0.6 Y0.4", 3.2f},                                                  //'@'
  {"G0 Y-5;G0 Z-2;G0 X1 Y5;G0 X1.1 Y-5;G0 Z2;G0 X-1.7 Y1.9;G0 Z-2;" \
  "G0 X1.2", 3.2f},                                                       //'A'
  {"G0 Y-5;G0 Z-2;G0 Y5;G0 X1.2;G0 X0.8 Y-0.5;G0 Y-1.2;G0 X-0.5 Y-0.6;" \
  "G0 X-1.4;G0 Z2;G0 X1.4 Y-0.1;G0 Z-2;G0 X0.7 Y-0.6;G0 Y-1.5;" \
  "G0 X-0.6 Y-0.5;G0 X-1.5", 2.8f},                                       //'B'
  {"G0 X2 Y-0.3;G0 Z-2;G0 X-0.5 Y0.3;G0 X-0.8;G0 X-0.5 Y-0.6;G0 X-0.2 Y-1.9;" \
  "G0 X0.2 Y-1.9;G0 X0.5 Y-0.6;G0 X0.8;G0 X0.5 Y0.3", 3.1f},              //'C'
  {"G0 Z-2;G0 X1.2;G0 X0.5 Y-0.6;G0 X0.3 Y-2.1;G0 X-0.2 Y-1.9;" \
  "G0 X-0.5 Y-0.4;G0 X-1.3;G0 Y4.9", 3.1f},                               //'D'
  {"G0 X2;G0 Z-2;G0 X-2;G0 Y-5;G0 X2;G0 Z2;G0 X-1.9 Y2.5;G0 Z-2;" \
  "G0 X1.1", 3.1f},                                                       //'E'
  {"G0 X2;G0 Z-2;G0 X-2;G0 Y-5;G0 Z2;G0 X0.1 Y2.5;G0 Z-2;G0 X1.1", 2.7f}, //'F'
  {"G0 X2.2 Y-0.4;G0 Z-2;G0 X-0.6 Y0.4;G0 X-1;G0 X-0.4 Y-0.5;G0 X-0.2 Y-2.2;" \
  "G0 X0.3 Y-2;G0 X0.5 Y-0.3;G0 X0.6;G0 X0.5 Y0.3;G0 X0.3 Y1;G0 Y0.7;" \
  "G0 X-0.9", 3.3f},                                                      //'G'
  {"G0 Z-2;G0 Y-5;G0 Z2;G0 X2 Y5;G0 Z-2;G0 Y-5;G0 Z2;G0 X-1.9 Y2.3;" \
  "G0 Z-2;G0 X1.8", 3.1f},                                                //'H'
  {"G0 Z-2;G0 Y-5", 1.0f},                                                //'I'
  {"G0 Z-2;G0 X1.9;G0 Y-3.8;G0 X-0.2 Y-0.9;G0 X-0.7 Y-0.3;G0 X-0.7 Y0.3;" \
  "G0 X-0.3 Y0.7", 3.0f},                                                 //'J'
  {"G0 Z-2;G0 Y-5;G0 Z2;G0 X1.5 Y5;G0 Z-2;G0 X-1.4 Y-2.5;" \
  "G0 X1.5 Y-2.5", 2.7f},                                                 //'K'
  {"G0 Z-2;G0 Y-5;G0 X1.6", 2.7f},                                        //'L'
  {"G0 Y-5;G0 Z-2;G0 X0.4 Y5;G0 X1 Y-2;G0 X0.9 Y2;G0 X0.4 Y-5", 3.8f},    //'M'
  {"G0 Y-5;G0 Z-2;G0 Y5;G0 X1.8 Y-5;G0 Y5", 2.9f},                        //'N'
  {"G0 X0.7;G0 Z-2;G0 X-0.7 Y-1;G0 Y-3.2;G0 X0.7 Y-0.8;G0 X1.3;G0 X0.7 Y0.8;" \
  "G0 Y3.2;G0 X-0.7 Y1;G0 X-1.2", 3.8f},                                  //'O'
  {"G0 Y-5;G0 Z-2;G0 Y5;G0 X1.3;G0 X0.7 Y-0.4;G0 Y-1.3;G0 X-0.6 Y-0.4;" \
  "G0 X-1.3", 3.1f},                                                      //'P'
  {"G0 X0.7;G0 Z-2;G0 X-0.7 Y-1;G0 Y-3.2;G0 X0.7 Y-0.8;G0 X1.3;G0 X0.7 Y0.8;" \
  "G0 Y3.2;G0 X-0.7 Y1;G0 X-1.2;G0 Z2;G0 X1.1 Y-4.1;G0 Z-2;" \
  "G0 X0.8 Y-0.9", 3.8f},                                                 //'Q'
  {"G0 Y-5;G0 Z-2;G0 Y5;G0 X1.3;G0 X0.7 Y-0.4;G0 Y-1.3;G0 X-0.6 Y-0.4;" \
  "G0 X-1.3;G0 X1.9 Y-2.9", 3.1f},                                        //'R'
  {"G0 X2.6;G0 Z-2;G0 X-1.8;G0 X-0.8 Y-0.7;G0 Y-1.4;G0 X0.6 Y-0.5;G0 X1.3;" \
  "G0 X0.7 Y-0.6;G0 Y-1.2;G0 X-0.8 Y-0.6;G0 X-1.8", 3.7f},                //'S'
  {"G0 Z-2;G0 X2;G0 Z2;G0 X-1 Y-5;G0 Z-2;G0 Y4.9", 3.1f},                 //'T'
  {"G0 Z-2;G0 Y-4.3;G0 X0.6 Y-0.7;G0 X1;G0 X0.5 Y0.7;G0 Y4.3", 3.2f},     //'U'
  {"G0 Z-2;G0 X1.2 Y-5;G0 X0.9 Y5", 3.2f},                                //'V'
  {"G0 Z-2;G0 X0.5 Y-5;G0 X0.9 Y1.8;G0 X0.8 Y-1.8;G0 X0.5 Y5", 3.8f},     //'W'
  {"G0 Z-2;G0 X2.1 Y-5;G0 Z2;G0 X-2.1;G0 Z-2;G0 X2.1 Y5", 3.2f},          //'X'
  {"G0 Z-2;G0 X1.2 Y-2.6;G0 Z2;G0 X-0.7 Y-2.4;G0 Z-2;G0 X1.6 Y5", 3.2f},  //'Y'
  {"G0 Z-2;G0 X2.1;G0 X-2.1 Y-5;G0 X2.1", 3.2f},                          //'Z'
  {" ",0.0f},
  {" ",0.0f},
  {" ",0.0f},
  {" ",0.0f},
  {" ",0.0f},

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
