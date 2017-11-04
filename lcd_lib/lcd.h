/*******************************************************************************
*
* 1. NAME
*       lcd.h
*
* 2. DESCRIPTION
*
*
*******************************************************************************/
#ifndef LCD_H_
#define LCD_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

/*******************************************************************************
*   GLOBAL VARIABLES                                                           *
*******************************************************************************/
/* ports and pins for LCD */
#define EN PINB0
#define RW PINB3
#define RS PINB2
#define DATA_LINES PORTD
#define CONTROL_LINES PORTB
#define DATA_DIRECTION DDRD
#define CONTROL_DIRECTION DDRB

#define ROWS 4
#define COLUMNS 16
#define FIRST_ROW_POSITION 0
#define SECOND_ROW_POSITION 64
#define THIRD_ROW_POSITION 32
#define FOURTH_ROW_POSITION 128

#define DECIMAL_SYSTEM 10 /* for itoa */

/* LCD commands */
#define CLEAR_DISPLAY 0x01
#define SET_4_BIT 0x28
#define SET_8_BIT 0x38
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_BLINK 0x0F

/* memory addresses for LCD cursor position */
#define FIRST_LINE_ADDRESS 0x80
#define SECOND_LINE_ADDRESS 0xC0
#define THIRD_LINE_ADDRESS 0x94
#define FOURTH_LINE_ADDRESS 0xD4

#define LCD_DELAY_AFTER_VDD 15 /* delay after power on */
#define LCD_DELAY_MS 2 /* defined in the LCD manual */
#define LCD_DELAY_US 40 /* defined in the LCD manual */

#ifndef NOP
#define NOP asm volatile("nop") /* no operation for 1 clock cycle */
#endif

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

/***************************************************************************//**
@brief Sends a character when LCD is available.
@param Character to send
@return void
*******************************************************************************/
void lcd_send_character(char const character);


/***************************************************************************//**
@brief Sends string to given position in LCD.
@details Moves LCD cursor to given position. Sends string one character at time.
@param X & Y -coordinates, String to send
@return void
*******************************************************************************/
void lcd_send_string(uint8_t const x, uint8_t const y,
                     char const *string);


/***************************************************************************//**
@brief Converts given integer to string, then sends to given location.
@details Moves LCD cursor to given position. Converts integer to string,
so it can be sent to the LCD. String is sent one character at time.
@param X & Y -coordinates, Integer to display
@return void
*******************************************************************************/
void lcd_send_int(uint8_t const x, uint8_t const y,
                  int32_t *const int_to_display);
       

/***************************************************************************//**
@brief Sets 4/8-bit mode and control lines to desirable port.
@param void
@return void
*******************************************************************************/
void lcd_init(void);


#endif /* LCD_H_ */
