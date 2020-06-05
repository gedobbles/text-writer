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

//configuration field strings
#define CONFIG_FIELD_NONE_STR ""  //not needed
#define CONFIG_FIELD_XMIN_STR "XMIN"
#define CONFIG_FIELD_YMIN_STR "YMIN"
#define CONFIG_FIELD_XMAX_STR "XMAX"
#define CONFIG_FIELD_YMAX_STR "YMAX"

#endif
