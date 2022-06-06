/*
 * barLed.c
 *
 *  Created on: Feb 24, 2022
 *      Author: Zegar
 */

#include "main.h"
#include "button.h" // Our buttons library
#include "barLed.h"	// Our bar LED library

// BAR_LED Init
void BarLedInit(TBar *Bar, GPIO_TypeDef *GpioPort, uint16_t GpioPin, uint16_t BarWidth)
{
	Bar->currentLed = 0; //	First LED

	Bar->GpioPort = GpioPort; // Remember GPIO Port for the bar
	Bar->GpioPin = GpioPin; // Remember GPIO Pin for the bar

	Bar->BarWidth = BarWidth; // LED number
}

void BarClear(TBar *Bar)	// Turn off all LEDs
{
	Bar->currentLed = Bar->BarWidth;
	while (Bar->currentLed > 0)
	{
		BarDown(Bar);
	}
}

void BarDown(TBar *Bar)	// Reset upper LED
{
	if (Bar->currentLed > 0)	//If possible
	{
		Bar->currentLed--;
		HAL_GPIO_WritePin(Bar->GpioPort, 1 << Bar->currentLed, GPIO_PIN_RESET);
	}
}

void BarUp(TBar *Bar)	// Set next LED
{
	if (Bar->currentLed < Bar->BarWidth)	//If possible
	{
		HAL_GPIO_WritePin(Bar->GpioPort, 1 << Bar->currentLed, GPIO_PIN_SET);
		Bar->currentLed++;
	}
}
