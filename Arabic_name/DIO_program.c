

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
/*****************************< Function Implementations *****************************/
void DIO_vInit(void)
{
	/**< Configure the data direction registers (DDRx) */ 
    DIO_DDRA_R = Conc(DIO_PA7_INITIAL_DIRECTION, DIO_PA6_INITIAL_DIRECTION, DIO_PA5_INITIAL_DIRECTION, DIO_PA4_INITIAL_DIRECTION,
                      DIO_PA3_INITIAL_DIRECTION, DIO_PA2_INITIAL_DIRECTION, DIO_PA1_INITIAL_DIRECTION, DIO_PA0_INITIAL_DIRECTION);

    DIO_DDRB_R = Conc(DIO_PB7_INITIAL_DIRECTION, DIO_PB6_INITIAL_DIRECTION, DIO_PB5_INITIAL_DIRECTION, DIO_PB4_INITIAL_DIRECTION,
                      DIO_PB3_INITIAL_DIRECTION, DIO_PB2_INITIAL_DIRECTION, DIO_PB1_INITIAL_DIRECTION, DIO_PB0_INITIAL_DIRECTION);

    DIO_DDRC_R = Conc(DIO_PC7_INITIAL_DIRECTION, DIO_PC6_INITIAL_DIRECTION, DIO_PC5_INITIAL_DIRECTION, DIO_PC4_INITIAL_DIRECTION,
                      DIO_PC3_INITIAL_DIRECTION, DIO_PC2_INITIAL_DIRECTION, DIO_PC1_INITIAL_DIRECTION, DIO_PC0_INITIAL_DIRECTION);

    DIO_DDRD_R = Conc(DIO_PD7_INITIAL_DIRECTION, DIO_PD6_INITIAL_DIRECTION, DIO_PD5_INITIAL_DIRECTION, DIO_PD4_INITIAL_DIRECTION,
                      DIO_PD3_INITIAL_DIRECTION, DIO_PD2_INITIAL_DIRECTION, DIO_PD1_INITIAL_DIRECTION, DIO_PD0_INITIAL_DIRECTION);
    
    /**< Set the initial output values for the ports */
    DIO_PORTA_R = Conc(DIO_PA7_INITIAL_VALUE, DIO_PA6_INITIAL_VALUE, DIO_PA5_INITIAL_VALUE, DIO_PA4_INITIAL_VALUE,
                       DIO_PA3_INITIAL_VALUE, DIO_PA2_INITIAL_VALUE, DIO_PA1_INITIAL_VALUE, DIO_PA0_INITIAL_VALUE);

    DIO_PORTB_R = Conc(DIO_PB7_INITIAL_VALUE, DIO_PB6_INITIAL_VALUE, DIO_PB5_INITIAL_VALUE, DIO_PB4_INITIAL_VALUE,
                       DIO_PB3_INITIAL_VALUE, DIO_PB2_INITIAL_VALUE, DIO_PB1_INITIAL_VALUE, DIO_PB0_INITIAL_VALUE);

    DIO_PORTC_R = Conc(DIO_PC7_INITIAL_VALUE, DIO_PC6_INITIAL_VALUE, DIO_PC5_INITIAL_VALUE, DIO_PC4_INITIAL_VALUE,
                       DIO_PC3_INITIAL_VALUE, DIO_PC2_INITIAL_VALUE, DIO_PC1_INITIAL_VALUE, DIO_PC0_INITIAL_VALUE);

    DIO_PORTD_R = Conc(DIO_PD7_INITIAL_VALUE, DIO_PD6_INITIAL_VALUE, DIO_PD5_INITIAL_VALUE, DIO_PD4_INITIAL_VALUE,
                       DIO_PD3_INITIAL_VALUE, DIO_PD2_INITIAL_VALUE, DIO_PD1_INITIAL_VALUE, DIO_PD0_INITIAL_VALUE);
    
}

Std_ReturnType DIO_SetPinDirection(u8 PortId, u8 PinId,u8 PinDirection)
{
	Std_ReturnType Local_FunctionStatus = E_OK;

	if(((PortId < 4) && (PinId < 8)) && ((PinDirection == DIO_OUTPUT) || (PinDirection == DIO_INPUT)))
	{
		switch (PortId)
		{
			case DIO_PORTA:
				switch (PinDirection)
				{
					case DIO_OUTPUT: SET_BIT(DIO_DDRA_R, PinId);break;
					case DIO_INPUT : CLR_BIT(DIO_DDRA_R, PinId);break;
					default : Local_FunctionStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTB:
				switch (PinDirection)
				{
					case DIO_OUTPUT:SET_BIT(DIO_DDRB_R, PinId);break;
					case DIO_INPUT :CLR_BIT(DIO_DDRB_R, PinId);break;
					default : Local_FunctionStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTC:
				switch (PinDirection)
				{
					case DIO_OUTPUT:SET_BIT(DIO_DDRC_R, PinId);break;
					case DIO_INPUT :CLR_BIT(DIO_DDRC_R, PinId);break;
					Local_FunctionStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTD:
				switch (PinDirection)
				{
					case DIO_OUTPUT:SET_BIT(DIO_DDRD_R, PinId);break;
					case DIO_INPUT :CLR_BIT(DIO_DDRD_R, PinId);break;
					Local_FunctionStatus = E_NOT_OK;
				}
				break;
		}
	}
	else
	{
		Local_FunctionStatus = E_NOT_OK;
	}

	return Local_FunctionStatus;
	
}

Std_ReturnType DIO_SetPinValue(u8 PortId, u8 PinId,u8 PinValue)
{
	Std_ReturnType Local_FunctionStatus = E_OK;

	if(PinId < 8)
	{
		switch (PortId)
		{
			case DIO_PORTA:
				switch(PinValue)
				{	
					case DIO_HIGH: SET_BIT(DIO_PORTA_R, PinId);break;
					case DIO_LOW : CLR_BIT(DIO_PORTA_R, PinId);break;
					default: Local_FunctionStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTB:
				switch(PinValue)
				{
					case DIO_HIGH: SET_BIT(DIO_PORTB_R, PinId);break;
					case DIO_LOW : CLR_BIT(DIO_PORTB_R, PinId);break;
					default: Local_FunctionStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTC:
				switch(PinValue)
				{
					case DIO_HIGH: SET_BIT(DIO_PORTC_R, PinId);break;
					case DIO_LOW : CLR_BIT(DIO_PORTC_R, PinId);break;
					default: Local_FunctionStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTD:
				switch(PinValue)
				{
					case DIO_HIGH: SET_BIT(DIO_PORTD_R, PinId);break;
					case DIO_LOW : CLR_BIT(DIO_PORTD_R, PinId);break;
					default: Local_FunctionStatus = E_NOT_OK;
				}
				break;
			default:
				Local_FunctionStatus = E_NOT_OK;
				break;
		}
	}
	else
	{
		Local_FunctionStatus = E_NOT_OK;
	}

	return Local_FunctionStatus;
}

Std_ReturnType DIO_GetPinValue(u8 PortId, u8 PinId,u8 *ReturnedPinValue)
{
	Std_ReturnType Local_FunctionStatus = E_OK;

	if((PortId < 8) && (NULL != ReturnedPinValue))
	{
		switch (PortId)
		{
			case DIO_PORTA: *ReturnedPinValue = GET_BIT(DIO_PINA_R, PinId);
				if(*ReturnedPinValue == 0)
				{
					*ReturnedPinValue = DIO_LOW;
				}
				else
				{
					*ReturnedPinValue = DIO_HIGH;
				}
				break;
			case DIO_PORTB: *ReturnedPinValue = GET_BIT(DIO_PINB_R, PinId);
				if(*ReturnedPinValue == 0)
				{
					*ReturnedPinValue = DIO_LOW;
				}
				else
				{
					*ReturnedPinValue = DIO_HIGH;
				}
				break;
			case DIO_PORTC: *ReturnedPinValue = GET_BIT(DIO_PINC_R, PinId);
				if(*ReturnedPinValue == 0)
				{
					*ReturnedPinValue = DIO_LOW;
				}
				else
				{
					*ReturnedPinValue = DIO_HIGH;
				}
				break;
			case DIO_PORTD: *ReturnedPinValue = GET_BIT(DIO_PIND_R, PinId);
			if(*ReturnedPinValue == 0)
			{
				*ReturnedPinValue = DIO_LOW;
			}
			else
			{
				*ReturnedPinValue = DIO_HIGH;
			}
			break;
			default:
				Local_FunctionStatus = E_NOT_OK;
				break;
		}
	}
	else
	{
		Local_FunctionStatus  =E_NOT_OK;
	}

	return Local_FunctionStatus;
}

Std_ReturnType DIO_SetPortDirection(u8 PortId, u8 PortDirection)
{
	Std_ReturnType Local_FunctionStatus = E_OK;

	if(PortDirection == DIO_OUTPUT || PortDirection == DIO_INPUT)
	{
		switch(PortId)
		{
			case DIO_PORTA:
				switch(PortDirection)
				{
					case DIO_OUTPUT:DIO_DDRA_R = 0XFF; break;
					case DIO_INPUT :DIO_DDRA_R = 0X00; break;
					default: Local_FunctionStatus = E_NOT_OK; break;
				}
				break;
			case DIO_PORTB:
				switch(PortDirection)
				{
					case DIO_OUTPUT:DIO_DDRB_R = 0XFF; break;
					case DIO_INPUT :DIO_DDRB_R = 0X00; break;
					default: Local_FunctionStatus = E_NOT_OK; break;
				}
				break;
			case DIO_PORTC:
				switch(PortDirection)
				{
					case DIO_OUTPUT:DIO_DDRC_R = 0XFF; break;
					case DIO_INPUT :DIO_DDRC_R = 0X00; break;
					default: Local_FunctionStatus = E_NOT_OK; break;
				}
				break;
			case DIO_PORTD:
				switch(PortDirection)
				{
					case DIO_OUTPUT:DIO_DDRD_R = 0XFF; break;
					case DIO_INPUT :DIO_DDRD_R = 0X00; break;
					default: Local_FunctionStatus = E_NOT_OK; break;
				}
				break;
			default: Local_FunctionStatus = E_NOT_OK; break;
		}
	}
	else
	{
		Local_FunctionStatus = E_NOT_OK;
	}

	return Local_FunctionStatus;
}

Std_ReturnType DIO_SetPortValue(u8 PortId, u8 PortValue)
{
	Std_ReturnType Local_FunctionStatus = E_OK;
	switch(PortId)
	{
		case DIO_PORTA: DIO_PORTA_R = PortValue; break;
		case DIO_PORTB: DIO_PORTB_R = PortValue; break;
		case DIO_PORTC: DIO_PORTC_R = PortValue; break;
		case DIO_PORTD: DIO_PORTD_R = PortValue; break;
		default: Local_FunctionStatus = E_NOT_OK; break;
	}

	return Local_FunctionStatus;
}

Std_ReturnType DIO_GetPortValue(u8 Copy_u8portId, u8 *ReturnedPortValue)
{
	Std_ReturnType Local_FunctionStatus = E_OK;

	if(NULL != ReturnedPortValue)
	{
		switch(Copy_u8portId)
		{
			case DIO_PORTA: *ReturnedPortValue = DIO_PINA_R; break;
			case DIO_PORTB: *ReturnedPortValue = DIO_PINB_R; break;
			case DIO_PORTC: *ReturnedPortValue = DIO_PINC_R; break;
			case DIO_PORTD: *ReturnedPortValue = DIO_PIND_R; break;
			default: Local_FunctionStatus = E_NOT_OK;
		}
	}
	else
	{
		Local_FunctionStatus = E_NOT_OK;
	}
	
	return Local_FunctionStatus;
}
