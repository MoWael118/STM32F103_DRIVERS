/*
 *@file		:	SSD_Interface.h
 *@author	: 	Mohamed Wael
 *@brief	:	Main Functions for SSD
 */


#ifndef HAL_SSD_INC_SSD_INTERFACE_H_
#define HAL_SSD_INC_SSD_INTERFACE_H_

#include "SSD_Private.h"
#include "SSD_Config.h"


/***********************************
 * @function 		:	SSD1_voidInit
 * @brief			:	Initialization for SSD 1
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD1_voidInit(void);


/***********************************
 * @function 		:	SSD2_voidInit
 * @brief			:	Initialization for SSD 2
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD2_voidInit(void);


/***********************************
 * @function 		:	SSD3_voidInit
 * @brief			:	Initialization for SSD 3
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD3_voidInit(void);


/***********************************
 * @function 		:	SSD_voidInitMultiblexing
 * @brief			:	Initialization for All 3 SSDs to work in multiblexing way
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD_voidInitMultiblexing(void);


/***********************************
 * @function 		:	SSD1_voidDisplayNumber
 * @brief			:	Function to display number on SS 1
 * @parameter[in]	:	uint8_t Number
 * @retval			:	Error State
 */
uint8_t SSD1_voidDisplayNumber(uint8_t Number);


/***********************************
 * @function 		:	SSD2_voidDisplayNumber
 * @brief			:	Function to display number on SS 2
 * @parameter[in]	:	uint8_t Number
 * @retval			:	Error State
 */
uint8_t SSD2_voidDisplayNumber(uint8_t Number);


/***********************************
 * @function 		:	SSD3_voidDisplayNumber
 * @brief			:	Function to display number on SS 3
 * @parameter[in]	:	uint8_t Number
 * @retval			:	Error State
 */
uint8_t SSD3_voidDisplayNumber(uint8_t Number);


/***********************************
 * @function 		:	SSDMUX_VoidDisplayNumber
 * @brief			:	Display Number on 3 Multiblexed SSDs
 * @parameter[in]	:	uint16_t Number
 * @retval			:	Error State
 */
uint8_t SSDMUX_VoidDisplayNumber(uint16_t Number);

#endif /* HAL_SSD_INC_SSD_INTERFACE_H_ */
