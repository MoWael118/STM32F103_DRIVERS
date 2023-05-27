/*
 *@file		:	SSD_Private.h
 *@author	: 	Mohamed Wael
 *@brief	:	Main Private file for SSD
 */


#ifndef HAL_SSD_INC_SSD_PRIVATE_H_
#define HAL_SSD_INC_SSD_PRIVATE_H_

/*************************************************************
 * Static Functions Prototypes
 ************************************************************/
static void DisplayZero(void);
static void DisplayOne(void);
static void DisplayTwo(void);
static void DisplayThree(void);
static void DisplayFour(void);
static void DisplayFive(void);
static void DisplaySix(void);
static void DisplaySeven(void);
static void DisplayEight(void);
static void DisplayNine(void);


#define zero     (0x3F)
#define one      (0x06)
#define two      (0x5B)
#define three    (0x4F)
#define four     (0x66)
#define five     (0x6D)
#define six      (0x7D)
#define seven    (0x07)
#define eight    (0x7F)
#define nine     (0x6F)

#define SEV_MAX_NUM 	10


#endif /* HAL_SSD_INC_SSD_PRIVATE_H_ */
