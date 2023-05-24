/*
 * LCD_Program.c
 *
 *  Created on: May 13, 2023
 *      Author: mhmd wael
 */
#include <stdint.h>
#include "../../../Inc/ErrTypes.h"
#include "../../../Inc/BitMath.h"
#include "../Inc/LCD_Interface.h"

#include "../../../MCAL/RCC/Inc/RCC_Interface.h"
#include "../../../MCAL/GPIO/Inc/GPIO_Interface.h"
#include "../../../MCAL/SYSTICK/Inc/SYSTICK_Interface.h"

static GPIO_REG_t* LCD_PORT = GPIOB;

void LCD_voidSendCommand(uint8_t Command)
{
	uint8_t Command_Reversed =0;
	uint8_t Counter =0;
	uint32_t ODR_Value=0;
	uint8_t Bit=0;
	for (Counter=0;Counter<8;Counter++)
	{
		Bit = GET_BIT(Command,Counter);
		if(Bit==1)
			SET_BIT(Command_Reversed,(7-Counter));
		else if (Bit==0)
			CLR_BIT(Command_Reversed,(7-Counter));
	}

	/*SET RS to 0 to send Command*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_RS, LOW_V);

	/*Send Highest 4 bits of Command First*/
	LCD_PORT->ODR &= ~ ((LCD_MASK)<<12);

	ODR_Value = LCD_PORT->ODR | ((Command_Reversed&COMMAND_MASK)<<12);

	LCD_PORT->ODR =ODR_Value;

	/*Enable LCD To receive data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, HIGH_V);

	/*Waiting till data Sent*/
	SYSTICK_u8Delay_ms(2);

	/*Disable LCD After receiving data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, LOW_V);

	/*Send Lowest 4 bits of Command Secondly*/
	LCD_PORT->ODR &= ~ ((LCD_MASK)<<12);
	ODR_Value = LCD_PORT->ODR | (((Command_Reversed>>4)&COMMAND_MASK)<<12);

	LCD_PORT->ODR =ODR_Value;

	/*Enable LCD To receive data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, HIGH_V);

	/*Waiting till data Sent*/
	SYSTICK_u8Delay_ms(2);

	/*Disable LCD After receiving data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, LOW_V);

}

void LCD_voidSendData(uint8_t Data)
{
	uint8_t Command_Reversed =0;
	uint8_t Counter =0;
	uint32_t ODR_Value=0;
	uint8_t Bit=0;
	/*Reversing the counter to make it sustainable to blue bill */
	for (Counter=0;Counter<8;Counter++)
	{
		Bit = GET_BIT(Data,Counter);
		if(Bit==1)
			SET_BIT(Command_Reversed,(7-Counter));
		else if (Bit==0)
			CLR_BIT(Command_Reversed,(7-Counter));
	}

	/*SET RS to 1 to send Data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_RS, HIGH_V);

	/*Send Highest 4 bits of Command First*/
	LCD_PORT->ODR &= ~ ((LCD_MASK)<<12);
	ODR_Value = LCD_PORT->ODR | ((Command_Reversed&COMMAND_MASK)<<12);
	LCD_PORT->ODR =ODR_Value;

	/*Enable LCD To receive data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, HIGH_V);

	/*Waiting till data Sent*/
	SYSTICK_u8Delay_ms(2);

	/*Disable LCD After receiving data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, LOW_V);

	/*Send Lowest 4 bits of Command Secondly*/
	LCD_PORT->ODR &= ~ ((LCD_MASK)<<12);
	ODR_Value = LCD_PORT->ODR | (((Command_Reversed>>4)&COMMAND_MASK)<<12);

	LCD_PORT->ODR =ODR_Value;

	/*Enable LCD To receive data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, HIGH_V);

	/*Waiting till data Sent*/
	SYSTICK_u8Delay_ms(2);

	/*Disable LCD After receiving data*/
	GPIO_u8SetPinStatus(LCD_CTRL_PORT, LCD_PIN_EN, LOW_V);

}


void LCD_voidInit(void)
{
	/*Enable System tick and configure it*/
	SYSTICK_Configs_t Sysconfig={
				.INT_State = SYSTICK_INT_Disabled,
				.SYSTICK_Clock = AHB_DIRECT,
				.SYSTICK_State = SYSTICK_ENABLED
		};
		SYSTICK_u8SetConfigs(&Sysconfig);
	/*Enable GPIO Clock*/
	RCC_Set_APB2Peripheral_CLK(IOPA, ENABLED);
	RCC_Set_APB2Peripheral_CLK(IOPB, ENABLED);
	/*Initialize LCD pins as output push pull*/
	PinConfig_t LCD_Pins[6]={

			{ .Port_Num=LCD_CTRL_PORT, .Pin_Num=LCD_PIN_EN 	  , .Mode= OUTPUT_MSPEED,.Output_Type=GP_PUSH_PULL}
			,	{ .Port_Num=LCD_CTRL_PORT, .Pin_Num=LCD_PIN_RS    , .Mode= OUTPUT_MSPEED,.Output_Type=GP_PUSH_PULL}
			,	{ .Port_Num=LCD_DATA_PORT, .Pin_Num=LCD_DATA_PIN4 , .Mode= OUTPUT_MSPEED,.Output_Type=GP_PUSH_PULL}
			,	{ .Port_Num=LCD_DATA_PORT, .Pin_Num=LCD_DATA_PIN5 , .Mode= OUTPUT_MSPEED,.Output_Type=GP_PUSH_PULL}
			,	{ .Port_Num=LCD_DATA_PORT, .Pin_Num=LCD_DATA_PIN6 , .Mode= OUTPUT_MSPEED,.Output_Type=GP_PUSH_PULL}
			,	{ .Port_Num=LCD_DATA_PORT, .Pin_Num=LCD_DATA_PIN7 , .Mode= OUTPUT_MSPEED,.Output_Type=GP_PUSH_PULL}

	};
	uint8_t Counter=0;
	for(Counter=0;Counter<6;Counter++)
	{
		GPIO_u8PinInit(&LCD_Pins[Counter]);
	}
	/*Apply initializing sequence on LCD from data sheet*/

	SYSTICK_u8Delay_ms(35);
	LCD_voidSendCommand(0x33);
	LCD_voidSendCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_voidSendCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_voidSendCommand(0x0f);	/* Display on cursor Blinking */
	LCD_voidSendCommand(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_voidSendCommand(0x01);	/* Clear display screen */
}

uint8_t LCD_u8SendString(const char * String)
{
	uint8_t Local_u8ErrorState = OK;
	uint8_t	Counter=0;
	if (String != NULL)
	{
		while (String[Counter] != '\0')
		{
			/*If first line ended Skip the hidden blocks until u reach the second line blocks*/
			if(Counter==16)
			{
				for(int i =0;i<24;i++)
				{
					LCD_voidSendData(' ');
				}
			}
			LCD_voidSendData(String[Counter]);
			Counter++;
		}

	}
	else {
		Local_u8ErrorState = Null_Pointer;
	}
	return Local_u8ErrorState;
}

