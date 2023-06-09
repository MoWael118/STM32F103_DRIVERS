/*
 *@file		:	SSD_Config.h
 *@author	: 	Mohamed Wael
 *@brief	:	Main Configurations for SSD
 */


#ifndef HAL_SSD_INC_SSD_CONFIG_H_
#define HAL_SSD_INC_SSD_CONFIG_H_

#include "../../../MCAL/GPIO/Inc/GPIO_Interface.h"

/*************************************************************
 Configure Each Segment of the SSD to it's PIN
 ************************************************************/
#define   A_PIN                     PIN11
#define   B_PIN                     PIN8
#define   C_PIN                     PIN15
#define   D_PIN                     PIN14
#define   E_PIN                     PIN13
#define   F_PIN                     PIN12
#define   G_PIN                     PIN12
#define   DOT_PIN                   PIN15

/*************************************************************
 Configure Each Segment of the SSD to it's PORT
 ************************************************************/
#define   A_PORT                     PORTA
#define   B_PORT                     PORTA
#define   C_PORT                     PORTB
#define   D_PORT                     PORTB
#define   E_PORT                     PORTB
#define   F_PORT                     PORTB
#define   G_PORT                     PORTA
#define   DOT_PORT                   PORTA

/*************************************************************
 Configure Common of SSD1 PIN and PORT
 ************************************************************/
#define 	COM1_PORT				 	PORTB
#define 	COM1_PIN				 	PIN8

/*************************************************************
 Configure Common of SSD2 PIN and PORT
 ************************************************************/
#define 	COM2_PORT				 	PORTB
#define 	COM2_PIN				 	PIN9

/*************************************************************
 Configure Common of SSD3 PIN and PORT
 ************************************************************/
#define 	COM3_PORT				 	PORTB
#define 	COM3_PIN				 	PIN3


#endif /* HAL_SSD_INC_SSD_CONFIG_H_ */
