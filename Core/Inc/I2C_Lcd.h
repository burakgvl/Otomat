/*
 * I2C_Lcd.h
 *
 *  Created on: 13 Şub 2021
 *      Author: Asus
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "stm32f4xx_hal.h"


void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_clear (void);



#endif /* INC_I2C_LCD_H_ */
