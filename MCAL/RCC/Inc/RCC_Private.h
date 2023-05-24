/*******************************************************************/
/*******************************************************************/
/********* OWNER     : Mohamed Wael				      **************/
/********* DATE      : 10/4/2023				  	  **************/
/********* FILE NAME : RCC_Private.h				  **************/
/********* Version   : V1.0                           **************/
/*******************************************************************/
/*******************************************************************/
#ifndef MCAL_RCC_INC_RCC_PRIVATE_H_
#define MCAL_RCC_INC_RCC_PRIVATE_H_

enum ClockTypes 		{HSE,HSI,LSE,LSI,PLL};
enum ClockStatus 		{ON,OFF};

#define TIME_OUT 		10000

#define HSE_DivideBy2 	1
#define HSE_DivideBy1 	0

#define ENABLED			1
#define DISABLED		0



enum PLL_MUL
{
	BY_2,
	BY_3,
	BY_4,
	BY_5,
	BY_6,
	BY_7,
	BY_8,
	BY_9,
	BY_10,
	BY_11,
	BY_12,
	BY_13,
	BY_14,
	BY_15,
	BY_16
};

enum AHB_Periphrals {
	DMA1,
	DMA2,
	SRAM,
	FLITF=4,
	CRC=6,
	FSMC=8,
	SDIO=10
};


enum APB2_Periphrals {
	AFIO,
	IOPA=2,
	IOPB,
	IOPC,
	IOPD,
	IOPE,
	IOPF,
	IOPG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART1,
	ADC3,
	TIM9=19,
	TIM10,
	TIM11

};



enum APB1_Periphrals{
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG=11,
	SPI2=14,
	SPI3,
	USART2=17,
	USART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	USB,
	CAN=25,
	BKP=27,
	PWR,
	DAC
};


#endif /* MCAL_RCC_INC_RCC_PRIVATE_H_ */
