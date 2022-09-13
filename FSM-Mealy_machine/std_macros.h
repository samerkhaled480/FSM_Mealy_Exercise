#ifndef std_macro_H_
#define std_macro_H_

#define SET_BIT(Value,bit) 		(Value |=  (1<<bit))
#define CLR_BIT(Value,bit)  	(Value &= ~(1<<bit))
#define TOG_BIT(Value,bit)  	(Value ^=  (1<<bit))
#define READ_BIT(Value,bit)		((Value>>bit)& 1)

#endif

