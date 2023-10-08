/*
 ============================================================================
 Name        : GPIO_Example.c
 Author      : Kareem Abd El-Moneam
 Description : Test the GPIO Driver
 Date        : 8/10/2023
 ============================================================================
 */

#include "gpio.h"
#include <util/delay.h> /* To use the delay functions */

typedef enum
{
	OFF,CW,ACW
}DC_Motor_State;

int main(void)
{
	DC_Motor_State motor1 = OFF;
	GPIO_setupPinDirection(PORTA_ID,PIN0_ID,PIN_INPUT);  /* PA0 Input Pin */
	GPIO_setupPinDirection(PORTA_ID,PIN1_ID,PIN_INPUT);  /* PA1 Input Pin */
	GPIO_setupPinDirection(PORTA_ID,PIN2_ID,PIN_INPUT);  /* PA2 Input Pin */

	GPIO_setupPinDirection(PORTC_ID, PIN0_ID, PIN_OUTPUT); /* PC0 Output Pin */
	GPIO_setupPinDirection(PORTC_ID, PIN1_ID, PIN_OUTPUT); /* PC0 Output Pin */

	/* Turn off the motor */
	GPIO_writePin(PORTC_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_LOW);

	GPIO_setupPortDirection(PORTD_ID,PORT_OUTPUT); /* All PORTD pins are o/p pins */
	GPIO_writePort(PORTD_ID,0x00); /* Turn OFF all LEDS */

	while(1)
	{
		/* Read PA0 Pin Value */
		if(GPIO_readPin(PORTA_ID,PIN0_ID) == LOGIC_HIGH)
		{
			/* Toggle All Even LEDS*/
			GPIO_writePort(PORTD_ID,0x55);
			_delay_ms(500);
			GPIO_writePort(PORTD_ID,0x00);
			_delay_ms(500);
		}
		/* Read PA1 Pin Value */
		else if(GPIO_readPin(PORTA_ID,PIN1_ID) == LOGIC_HIGH)
		{
			/* Toggle All Odd LEDS*/
			GPIO_writePort(PORTD_ID,0xAA);
			_delay_ms(500);
			GPIO_writePort(PORTD_ID,0x00);
			_delay_ms(500);
		}
		/* Read PA2 Pin Value */
		else if(GPIO_readPin(PORTA_ID,PIN2_ID) == LOGIC_HIGH)
		{
			switch(motor1)
			{
			case OFF:
				/* Rotates the motor CW */
				GPIO_writePin(PORTC_ID, PIN0_ID, LOGIC_LOW);
				GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_HIGH);
				motor1 = CW;
				break;
			case CW:
				/* Rotates the motor A-CW */
				GPIO_writePin(PORTC_ID, PIN0_ID, LOGIC_HIGH);
				GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_LOW);
				motor1 = ACW;
				break;
			case ACW:
				/* Stop the motor */
				GPIO_writePin(PORTC_ID, PIN0_ID, LOGIC_LOW);
				GPIO_writePin(PORTC_ID, PIN1_ID, LOGIC_LOW);
				motor1 = OFF;
				break;
			default:
				/* Do Nothing */
				break;
			}
			/* update the motor state only once every button press */
			while(GPIO_readPin(PORTA_ID,PIN2_ID) == LOGIC_HIGH);
		}
		else
		{
			/* Do Nothing */
		}
	}
}


