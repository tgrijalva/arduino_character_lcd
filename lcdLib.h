#ifndef LCDLIB_H
#define LCDLIB_H

// LCD CTRL REGISTERS AND PINS
#define CTLREG PORTB
#define CTL_DATA_DIRECTION_REGISTER DDRB
#define RS_DDR_PIN DDB0
#define RW_DDR_PIN DDB1
#define EN_DDR_PIN DDB2

#define RS PORTB0
#define RW PORTB1
#define EN PORTB2

// LCD DATA REGISTERS AND PINS
#define LCD_DATA_DIRECTION_REGISTER DDRD
#define LCD_DATA PORTD

#define SCREEN_WIDTH 16

// SPECIAL CHARACTERS
#define RIGHT_ARROW  0x7E
#define LEFT_ARROW   0x7F
#define START_FRAME  0xA2
#define END_FRAME    0xA3
#define SEPARATOR    0xA5
#define EMPTY_BOX    0xDB
#define ALPHA        0xE0
#define BETA         0xE2
#define EPSILON      0xE3
#define MU           0xE4
#define SMALL_SIGMA  0xE5
#define RHO          0xE6
#define SQRT_SYMBOL  0xE8
#define CENT_SYMBOL  0xEC
#define THETA        0xF2
#define INFINITY_    0xF3
#define OMEGA        0xF4
#define BIG_SIGMA    0xF6
#define PI_SYMBOL    0xF7
#define X_BAR        0xF8
#define DIVISION     0xFD
#define BLACK_SQUARE 0xFF

// init functions
void lcdInit();

// read/write functions
void lcdWrite(u08 c);
void lcdWriteString(char *str);
// void lcdRead(int &x);

// command functions
void lcdCmd(u08 c);
void lcdClear();
void lcdHome();
void lcdRowTwoHome();
void lcdCursorStyle(bool on, bool blink);
void lcdIncrementCursor();
void lcdDecrementCursor();
void lcdShiftTextRight();
void lcdShiftTextLeft();
void lcdSetCursor(u08 loc); // use bit 4 to denote row and bits 3 ~ 0 to denote col

#endif //ifndef LCDLIB_H