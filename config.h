#ifndef CONFIG_H
#define CONFIG_H

#define TEXT_START_CHAR   ':'
#define NEWLINE_CHAR      ';'
#define CONFIG_CHAR       '!'

//Printer:configure field constants
#define CONFIG_FIELD_NONE 0
#define CONFIG_FIELD_XMIN 1
#define CONFIG_FIELD_YMIN 2
#define CONFIG_FIELD_XMAX 3
#define CONFIG_FIELD_YMAX 4
#define CONFIG_FIELD_ZTRAVEL 5
#define CONFIG_FIELD_ZWRITE 6
#define CONFIG_FIELD_X 7
#define CONFIG_FIELD_Y 8

//configuration field strings
#define CONFIG_FIELD_NONE_STR ""  //not needed
#define CONFIG_FIELD_XMIN_STR "XMIN"
#define CONFIG_FIELD_YMIN_STR "YMIN"
#define CONFIG_FIELD_XMAX_STR "XMAX"
#define CONFIG_FIELD_YMAX_STR "YMAX"
#define CONFIG_FIELD_ZTRAVEL_STR "ZMOVE"
#define CONFIG_FIELD_ZWRITE_STR "ZWRITE"
#define CONFIG_FIELD_X_STR "X"
#define CONFIG_FIELD_Y_STR "Y"

#endif
