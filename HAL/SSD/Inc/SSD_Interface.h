/*
 * SSD_Interface.h
 *
 *  Created on: May 12, 2023
 *      Author: mhmd wael
 */

#ifndef HAL_SSD_INC_SSD_INTERFACE_H_
#define HAL_SSD_INC_SSD_INTERFACE_H_

#include "SSD_Private.h"
#include "SSD_Config.h"

void SSD1_voidInit(void);

void SSD2_voidInit(void);

void SSD3_voidInit(void);

void SSD_voidInitMultiblexing(void);

uint8_t SSD1_voidDisplayNumber(uint8_t Number);

uint8_t SSD2_voidDisplayNumber(uint8_t Number);

uint8_t SSD3_voidDisplayNumber(uint8_t Number);

uint8_t SSDMUX_VoidDisplayNumber(uint16_t Number);

#endif /* HAL_SSD_INC_SSD_INTERFACE_H_ */
