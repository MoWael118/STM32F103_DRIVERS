/*******************************************************************/
/*******************************************************************/
/********* OWNER     : Mohamed Wael				      **************/
/********* DATE      : 10/4/2023				  	  **************/
/********* FILE NAME : RCC_Register.h				  **************/
/********* Version   : V1.0                           **************/
/*******************************************************************/
/*******************************************************************/
#ifndef MCAL_RCC_INC_RCC_REGISTER_H_
#define MCAL_RCC_INC_RCC_REGISTER_H_

typedef struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
}RCC_REG_t;

static RCC_REG_t * const RCC = (RCC_REG_t*)0x40021000;


#endif /* MCAL_RCC_INC_RCC_REGISTER_H_ */
