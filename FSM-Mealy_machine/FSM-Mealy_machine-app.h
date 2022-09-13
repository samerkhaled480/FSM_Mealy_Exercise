
#ifndef FSM_MEALY_MACHINE_APP_H_
#define FSM_MEALY_MACHINE_APP_H_


#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 16000000UL // set the frequency of MCU
#include <util/delay.h> // this header include all delay function like _delay_ms
#include <avr/interrupt.h> // this header is necessary when you deal with interrupt

#include "TIMER0.h"


#define DIM_VALUE 25
#define MID_VALUE 50
#define HIGH_VALUE 100

#define ON_BUTTON_PIN 0
#define OFF_BUTTON_PIN 1



/*****************************************************************************
* Function Name: StateHandler
* Purpose      : FSM transition mechanism implementation 
* Parameters   : input event (ON or OFF)
* Return value : void
*****************************************************************************/
void StateHandler(uint8_t _event);


#endif