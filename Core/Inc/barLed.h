/*
 * barLed.h
 *
 *  Created on: Feb 24, 2022
 *      Author: Zegar
 */

#ifndef INC_BARLED_H_
#define INC_BARLED_H_

// Struct for BAR_LED
typedef struct
{

	GPIO_TypeDef *GpioPort; // GPIO Port for a BAR_LED
	uint16_t GpioPin; // GPIO Pin for a BAR_LED
	uint16_t BarWidth; // number of LEDs
	uint16_t currentLed; //

} TBar; // BAR_LED_t

// Public functions
void BarLedInit(TBar *Bar, GPIO_TypeDef *GpioPort, uint16_t GpioPin, uint16_t BarWidth);
void BarClear(TBar *Bar);
void BarDown(TBar *Bar);
void BarUp(TBar *Bar);

#endif /* INC_BARLED_H_ */
