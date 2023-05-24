/*
 * LCD_Config.h
 *
 *  Created on: May 13, 2023
 *      Author: mhmd wael
 */

#ifndef HAL_LCD_INC_LCD_CONFIG_H_
#define HAL_LCD_INC_LCD_CONFIG_H_

#include "../../../MCAL/GPIO/Inc/GPIO_Interface.h"

#define LCD_DATA_PORT		PORTB

#define LCD_DATA_PIN0		PIN8
#define LCD_DATA_PIN1       PIN9
#define LCD_DATA_PIN2       PIN10
#define LCD_DATA_PIN3       PIN11

#define LCD_DATA_PIN4       PIN15
#define LCD_DATA_PIN5       PIN14
#define LCD_DATA_PIN6       PIN13
#define LCD_DATA_PIN7       PIN12


#define LCD_CTRL_PORT		PORTA

#define LCD_PIN_RS			PIN11
#define LCD_PIN_EN			PIN8


#endif /* HAL_LCD_INC_LCD_CONFIG_H_ */
