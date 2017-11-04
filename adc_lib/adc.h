/*******************************************************************************
*
* 1. NAME
*       adc.h
*
* 2. DESCRIPTION
*
*
*******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include <avr/io.h>
#include <stdint.h>

/*******************************************************************************
*   GLOBAL VARIABLES                                                           *
*******************************************************************************/

/*******************************************************************************
*   FUNCTION PROTOTYPES                                                        *
*****************************************************************************///

/***************************************************************************//**
@brief Sets ADC register values.
@details Sets reference voltage and input clock to the ADC.
@param void
@return void
*******************************************************************************/
void adc_init(void);


/***************************************************************************//**
@brief Starts ADC, waits until it's done, then turns pin ADSC LOW.
@details Conversion is done in single conversion mode; each conversion has to
be called.
@param Analog input pin
@return 10-bit ADC value
*******************************************************************************/
uint16_t adc_read(uint8_t const analog_channel);


#endif /* ADC_H_ */
