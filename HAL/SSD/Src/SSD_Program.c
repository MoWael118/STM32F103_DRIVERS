/*
 *@file		:	SSD_Program.c
 *@author	: 	Mohamed Wael
 *@brief	:	Main Program for Seven Segment Display
 */


/*************************************************************
 * Required Includes
 ************************************************************/
#include <stdint.h>
#include "../../../Inc/ErrTypes.h"
#include "../../../MCAL/GPIO/Inc/GPIO_Interface.h"
#include "../../../MCAL/SYSTICK/Inc/SYSTICK_Interface.h"
#include "../Inc/SSD_Interface.h"

/*************************************************************
 * Static Array of Pointers to functions initialized with the previous static functions
 ************************************************************/
static  void (* DisplayNum[10])(void) = {
		&DisplayZero,&DisplayOne,&DisplayTwo,&DisplayThree,&DisplayFour,&DisplayFive,&DisplaySix,
		&DisplaySeven,&DisplayEight,&DisplayNine
};

/*******************************************************************************************/
/*									 A
 * 							 -------------------
 * 							|                   |
 * 						F	|                   |  B
 * 							|                   |
 * 							|					|
 * 							 -------------------
 * 							|                   |
 * 							|                   |
 * 						E	|                   |	C
 * 							|                   |
 * 							|					|
 * 							 -------------------
 * 									D
 */

/***********************************
 * @function 		:	SSD1_voidInit
 * @brief			:	Initialization for SSD 1
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD1_voidInit(void)
{
	PinConfig_t COM1 ={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = COM1_PORT,
			.Pin_Num = COM1_PIN,
	};
	PinConfig_t	A={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = A_PORT,
			.Pin_Num = A_PIN,
	};
	PinConfig_t	B={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = B_PORT,
			.Pin_Num = B_PIN,
	};
	PinConfig_t	C={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = C_PORT,
			.Pin_Num = C_PIN,

	};
	PinConfig_t	D={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = D_PORT,
			.Pin_Num = D_PIN,

	};
	PinConfig_t	E={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = E_PORT,
			.Pin_Num = E_PIN,

	};
	PinConfig_t	F={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = F_PORT,
			.Pin_Num = F_PIN,

	};
	PinConfig_t	G={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = G_PORT,
			.Pin_Num = G_PIN,

	};
	PinConfig_t	DOT={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = DOT_PORT,
			.Pin_Num = DOT_PIN,
	};
	GPIO_u8PinInit(&COM1);
	GPIO_u8PinInit(&A);
	GPIO_u8PinInit(&B);
	GPIO_u8PinInit(&C);
	GPIO_u8PinInit(&D);
	GPIO_u8PinInit(&E);
	GPIO_u8PinInit(&F);
	GPIO_u8PinInit(&G);
	GPIO_u8PinInit(&DOT);

}
/***********************************
 * @function 		:	SSD2_voidInit
 * @brief			:	Initialization for SSD 2
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD2_voidInit(void)
{
	PinConfig_t COM2 ={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = COM2_PORT,
			.Pin_Num = COM2_PIN,
	};
	PinConfig_t	A={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = A_PORT,
			.Pin_Num = A_PIN,
	};
	PinConfig_t	B={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = B_PORT,
			.Pin_Num = B_PIN,
	};
	PinConfig_t	C={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = C_PORT,
			.Pin_Num = C_PIN,

	};
	PinConfig_t	D={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = D_PORT,
			.Pin_Num = D_PIN,

	};
	PinConfig_t	E={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = E_PORT,
			.Pin_Num = E_PIN,

	};
	PinConfig_t	F={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = F_PORT,
			.Pin_Num = F_PIN,

	};
	PinConfig_t	G={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = G_PORT,
			.Pin_Num = G_PIN,

	};
	PinConfig_t	DOT={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = DOT_PORT,
			.Pin_Num = DOT_PIN,
	};
	GPIO_u8PinInit(&COM2);
	GPIO_u8PinInit(&A);
	GPIO_u8PinInit(&B);
	GPIO_u8PinInit(&C);
	GPIO_u8PinInit(&D);
	GPIO_u8PinInit(&E);
	GPIO_u8PinInit(&F);
	GPIO_u8PinInit(&G);
	GPIO_u8PinInit(&DOT);
}
/***********************************
 * @function 		:	SSD3_voidInit
 * @brief			:	Initialization for SSD 3
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD3_voidInit(void)
{
	PinConfig_t COM3 ={
			.Mode = INPUT,
			.Input_Type = PULLUPDOWN_INPUT,
			.Port_Num = COM3_PORT,
			.Pin_Num = COM3_PIN,
			.PullType = PULLUP
	};
	PinConfig_t	A={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = A_PORT,
			.Pin_Num = A_PIN,
	};
	PinConfig_t	B={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = B_PORT,
			.Pin_Num = B_PIN,
	};
	PinConfig_t	C={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = C_PORT,
			.Pin_Num = C_PIN,

	};
	PinConfig_t	D={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = D_PORT,
			.Pin_Num = D_PIN,

	};
	PinConfig_t	E={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = E_PORT,
			.Pin_Num = E_PIN,

	};
	PinConfig_t	F={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = F_PORT,
			.Pin_Num = F_PIN,

	};
	PinConfig_t	G={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = G_PORT,
			.Pin_Num = G_PIN,

	};
	PinConfig_t	DOT={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = DOT_PORT,
			.Pin_Num = DOT_PIN,
	};
	GPIO_u8PinInit(&COM3);
	GPIO_u8PinInit(&A);
	GPIO_u8PinInit(&B);
	GPIO_u8PinInit(&C);
	GPIO_u8PinInit(&D);
	GPIO_u8PinInit(&E);
	GPIO_u8PinInit(&F);
	GPIO_u8PinInit(&G);
	GPIO_u8PinInit(&DOT);
}
/***********************************
 * @function 		:	SSD_voidInitMultiblexing
 * @brief			:	Initialization for All 3 SSDs to work in multiblexing way
 * @parameter[in]	:	void
 * @retval			:	void
 */
void SSD_voidInitMultiblexing(void)
{
	PinConfig_t COM1 ={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = COM1_PORT,
			.Pin_Num = COM1_PIN,
	};
	PinConfig_t COM2 ={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = COM2_PORT,
			.Pin_Num = COM2_PIN,
	};
	PinConfig_t COM3 ={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = COM3_PORT,
			.Pin_Num = COM3_PIN,
	};
	PinConfig_t	A={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = A_PORT,
			.Pin_Num = A_PIN,
	};
	PinConfig_t	B={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = B_PORT,
			.Pin_Num = B_PIN,
	};
	PinConfig_t	C={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = C_PORT,
			.Pin_Num = C_PIN,

	};
	PinConfig_t	D={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = D_PORT,
			.Pin_Num = D_PIN,

	};
	PinConfig_t	E={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = E_PORT,
			.Pin_Num = E_PIN,

	};
	PinConfig_t	F={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = F_PORT,
			.Pin_Num = F_PIN,

	};
	PinConfig_t	G={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = G_PORT,
			.Pin_Num = G_PIN,

	};
	PinConfig_t	DOT={
			.Mode = OUTPUT_MSPEED,
			.Output_Type = GP_PUSH_PULL,
			.Port_Num = DOT_PORT,
			.Pin_Num = DOT_PIN,
	};
	GPIO_u8PinInit(&COM1);
	GPIO_u8PinInit(&COM2);
	GPIO_u8PinInit(&COM3);
	GPIO_u8PinInit(&A);
	GPIO_u8PinInit(&B);
	GPIO_u8PinInit(&C);
	GPIO_u8PinInit(&D);
	GPIO_u8PinInit(&E);
	GPIO_u8PinInit(&F);
	GPIO_u8PinInit(&G);
	GPIO_u8PinInit(&DOT);
}
/***********************************
 * @function 		:	SSD1_voidDisplayNumber
 * @brief			:	Function to display number on SS 1
 * @parameter[in]	:	uint8_t Number
 * @retval			:	Error State
 */
uint8_t SSD1_voidDisplayNumber(uint8_t Number)
{
	uint8_t Local_u8ErrorState=OK;
	if (Number <10)
	{
		GPIO_u8SetPinStatus(COM1_PORT,COM1_PIN, HIGH_V);

		DisplayNum[Number]();
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
/***********************************
 * @function 		:	SSD2_voidDisplayNumber
 * @brief			:	Function to display number on SS 2
 * @parameter[in]	:	uint8_t Number
 * @retval			:	Error State
 */
uint8_t SSD2_voidDisplayNumber(uint8_t Number)
{
	uint8_t Local_u8ErrorState=OK;
	if (Number <10)
	{
		GPIO_u8SetPinStatus(COM2_PORT,COM2_PIN, HIGH_V);

		DisplayNum[Number]();
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/***********************************
 * @function 		:	SSD3_voidDisplayNumber
 * @brief			:	Function to display number on SS 3
 * @parameter[in]	:	uint8_t Number
 * @retval			:	Error State
 */
uint8_t SSD3_voidDisplayNumber(uint8_t Number)
{
	uint8_t Local_u8ErrorState=OK;
	if (Number <10)
	{
		GPIO_u8SetPinStatus(PORTB,PIN3, HIGH_V);

		DisplayNum[Number]();
	}
	else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
/***********************************
 * @function 		:	SSDMUX_VoidDisplayNumber
 * @brief			:	Display Number on 3 Multiblexed SSDs
 * @parameter[in]	:	uint16_t Number
 * @retval			:	Error State
 */
uint8_t SSDMUX_VoidDisplayNumber(uint16_t Number)
{
	uint8_t	Local_u8ErrorState=OK;
	uint8_t Digit1=0;
	uint8_t Digit2=0;
	uint8_t Digit3=0;

	if (Number<=999)
	{
		Digit1 = Number%10;
		Digit2 = (Number/10)%10;
		Digit3 = Number/100;



		DisplayNum[Digit3]();
		GPIO_u8SetPinStatus(COM1_PORT, COM1_PIN, HIGH_V);
		SYSTICK_u8Delay_ms(1);
		GPIO_u8SetPinStatus(COM1_PORT, COM1_PIN, LOW_V);
		SYSTICK_u8Delay_ms(1);


		DisplayNum[Digit2]();
		GPIO_u8SetPinStatus(COM2_PORT, COM2_PIN, HIGH_V);
		SYSTICK_u8Delay_ms(1);
		GPIO_u8SetPinStatus(COM2_PORT, COM2_PIN, LOW_V);
		SYSTICK_u8Delay_ms(1);

		DisplayNum[Digit1]();
		GPIO_u8SetPinStatus(COM3_PORT, COM3_PIN, HIGH_V);
		SYSTICK_u8Delay_ms(1);
		GPIO_u8SetPinStatus(COM3_PORT, COM3_PIN, LOW_V);
		SYSTICK_u8Delay_ms(1);


	}
	else {
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;

}



/************************************************
 *		static Functions (Needed only in this file) definitions
 *		Those Functions used to control SSD (Display numbers)
 ************************************************/
static void DisplayZero(void)
{
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, HIGH_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, HIGH_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, HIGH_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, LOW_V);
}
static void DisplayOne(void)
{
	GPIO_u8SetPinStatus(A_PORT, A_PIN, LOW_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, LOW_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, LOW_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, LOW_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, LOW_V);

}
static void DisplayTwo(void)
{
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, LOW_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, HIGH_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, HIGH_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, LOW_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, HIGH_V);

}
static void DisplayThree(void)
{
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, HIGH_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, LOW_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, LOW_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, HIGH_V);

}
static void DisplayFour(void)
{
	GPIO_u8SetPinStatus(A_PORT, A_PIN, LOW_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, LOW_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, LOW_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, HIGH_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, HIGH_V);

}
static void DisplayFive(void){
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, LOW_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, HIGH_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, LOW_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, HIGH_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, HIGH_V);

}
static void DisplaySix(void){
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, LOW_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, HIGH_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, HIGH_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, HIGH_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, HIGH_V);

}
static void DisplaySeven(void)
{
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, LOW_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, LOW_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, LOW_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, LOW_V);

}
static void DisplayEight(void){
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, HIGH_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, HIGH_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, HIGH_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, HIGH_V);

}
static void DisplayNine(void)
{
	GPIO_u8SetPinStatus(A_PORT, A_PIN, HIGH_V);
	GPIO_u8SetPinStatus(B_PORT, B_PIN, HIGH_V);
	GPIO_u8SetPinStatus(C_PORT, C_PIN, HIGH_V);
	GPIO_u8SetPinStatus(D_PORT, D_PIN, HIGH_V);
	GPIO_u8SetPinStatus(E_PORT, E_PIN, LOW_V);
	GPIO_u8SetPinStatus(F_PORT, F_PIN, HIGH_V);
	GPIO_u8SetPinStatus(G_PORT, G_PIN, HIGH_V);

}
