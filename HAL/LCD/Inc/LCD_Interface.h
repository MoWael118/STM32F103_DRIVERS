/*
 * LCD_Interface.h
 *
 *  Created on: May 13, 2023
 *      Author: mhmd wael
 */

#ifndef HAL_LCD_INC_LCD_INTERFACE_H_
#define HAL_LCD_INC_LCD_INTERFACE_H_

#include "LCD_Config.h"
#include "LCD_Private.h"

void LCD_voidInit(void);

void LCD_voidSendCommand(uint8_t Command);

void LCD_voidSendData(uint8_t Data);

uint8_t LCD_u8SendString(const char * String);

uint8_t LCD_u8SendNumber(uint8_t Char);


#endif /* HAL_LCD_INC_LCD_INTERFACE_H_ */
