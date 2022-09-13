
#include "FSM-Mealy_machine-app.h"

//define events
enum input_event{
	OFF,
	ON
};

//define states
typedef enum {
	LED_OFF,
	LED_DIM,
	LED_MID,
	LED_HIGH
} Light_state;


uint8_t Timer0_Init_Flag = 0; // flag to optimize use of PWM initialization  

Light_state CurrentState = LED_OFF; // initialize machine to OFF state

int main(void)
{
	CLR_BIT(DDRC,ON_BUTTON_PIN);		//set pin as input
	CLR_BIT(DDRC,OFF_BUTTON_PIN);		//set pin as input
	
	SET_BIT(PORTC,ON_BUTTON_PIN);		//set pin as pull up
	SET_BIT(PORTC,OFF_BUTTON_PIN);		//set pin as pull up

    while (1) 
    {	
		if(READ_BIT(PINC,ON_BUTTON_PIN)==0)
		{	
			while(READ_BIT(PINC,ON_BUTTON_PIN) == 0);
			StateHandler(ON);
		}
		
		if(READ_BIT(PINC,OFF_BUTTON_PIN)==0)
		{
			while(READ_BIT(PINC,OFF_BUTTON_PIN) == 0);
			StateHandler(OFF);
		}
    }
}


void StateHandler(uint8_t _event)
{	
	switch(CurrentState)
	{
		case LED_OFF:
		{
			switch(_event)
			{
				case ON:
				{
					//LED is DIM
					if(Timer0_Init_Flag == 0)
					{
						 TIMER0_PWM_OC0_init(1);
						 Timer0_Init_Flag = 1;
					}
					TIMER0_PWM_OC0_duty(DIM_VALUE);
					CurrentState = LED_DIM;
					
				}break;
				case OFF:
				{
					//ignore 
				}break;
			}
		}break;
		case LED_DIM:
		{
			switch(_event)
			{
				case ON:
				{
					// make led light medium 
					TIMER0_PWM_OC0_duty(MID_VALUE);
					CurrentState = LED_MID;
					
				}break;
				case OFF:
				{
					// make led off 
					Timer0_stop();
					Timer0_Init_Flag = 0;
					CurrentState = LED_OFF;
				}break;
			}			
		}break;
		case LED_MID:
		{
			switch(_event)
			{
				case ON:
				{
					// make led light medium
					TIMER0_PWM_OC0_duty(HIGH_VALUE);
					CurrentState = LED_HIGH;
					
				}break;
				case OFF:
				{
					// make led off
					Timer0_stop();
					Timer0_Init_Flag = 0;
					CurrentState = LED_OFF;
				}break;
			}
		}break;
		case LED_HIGH:
		{
			switch(_event)
			{
				case ON:
				{
					// make led light medium
					TIMER0_PWM_OC0_duty(DIM_VALUE);
					CurrentState = LED_DIM;
					
				}break;
				case OFF:
				{
					// make led off
					Timer0_stop();
					Timer0_Init_Flag = 0;
					CurrentState = LED_OFF;
				}break;
			}
		}break;
	}
	
};

