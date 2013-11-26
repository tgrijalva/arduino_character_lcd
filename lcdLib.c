#include "globals.h"
#include "lcdLib.h"

void lcdInit() {
	LCD_DATA_DIRECTION_REGISTER = 0xFF;
	sbi(CTL_DATA_DIRECTION_REGISTER, RS_DDR_PIN);
	sbi(CTL_DATA_DIRECTION_REGISTER, RW_DDR_PIN);
	sbi(CTL_DATA_DIRECTION_REGISTER, EN_DDR_PIN);
	_delay_ms(50);
	lcdCmd(0x01); // clear lcd
	_delay_us(3300);
	lcdCmd(0x3F); // function set
	_delay_us(100);
	lcdCmd(0x0F); // display on/off
	_delay_us(100);
	lcdCmd(0x06); // entry mode set
}

void lcdWrite(u08 c) {
	// clear control signals
	sbi(CTLREG, RS);
	CTLREG &= 0xF9;
	// set enable
	sbi(CTLREG, EN);
	LCD_DATA = c;
	_delay_us(1);
	cbi(CTLREG, EN);
	cbi(CTLREG, RS);
	_delay_us(50);
}

void lcdWriteString(char *str) {
	while(*str != 0) {
		lcdWrite(*str++);	
	}
}

void lcdCmd(u08 c) {
	// clear control signals
	// dont effect PB3
	CTLREG &= 0xF8;
	// turn on enable
	sbi(CTLREG, EN);
	LCD_DATA = c;
	_delay_us(50);
	// clear control signals
	// dont effect PB3
	cbi(CTLREG, EN);
	_delay_us(100);
}

void lcdClear() {
	lcdCmd(0x01);
	_delay_us(3300);
}

void lcdHome() {
	lcdCmd(0x80);
	_delay_us(3300);
}

void lcdRowTwoHome() {
	lcdCmd(0xC0);
	_delay_us(3300);
}

void lcdCursorStyle(bool on, bool blink) {
	u08 cmd = 0x0C;
	if (on) {
		cmd |= 0x02;
	}
	if (blink) {
		cmd |= 0x01;
	}
	lcdCmd(cmd);
}

void lcdIncrementCursor() {
	lcdCmd(0x14);
}

void lcdDecrementCursor() {
	lcdCmd(0x10);
}

void lcdShiftTextRight() {
	lcdCmd(0x1C);
}

void lcdShiftTextLeft() {
	lcdCmd(0x18);
}

void lcdSetCursor(u08 loc) {
	u08 cmd = 0x80;
	if (loc & 0x10) {	// add 0x40 for row 2
		cmd |= 0x40;
	}
	cmd += (0x0F & loc);
	lcdCmd(cmd);
}