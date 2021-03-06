/*******************************************************************************
*
* 1. NAME
*       main.c
*
* 2. DESCRIPTION
*       Main file
*
*******************************************************************************/

/*******************************************************************************
*   HEADER FILES                                                               *
*******************************************************************************/
#include "main.h"


/*******************************************************************************
*   MAIN PROGRAM                                                               *
*******************************************************************************/
void main(void)
{
    struct sensor temperature;
    char *const ptr_celsius = temperature.celsius;
    char *const ptr_fahrenheit = temperature.fahrenheit;
    char *const ptr_kelvin = temperature.kelvin;

    int32_t average;

    /* set clock division factor to 1 */
    CLKPR = (1 << CLKPCE);
    CLKPR &= ~0xFF;

    /* init sequence */
    adc_init();
    sensor_init();
    lcd_init();
    sleep_ms(DELAY); /* sleep needed between LCD operations */

    /* initialize lcd screen with text */
    lcd_send_string(SIXTH_COLUMN, FIRST_ROW, DEGREE_SIGN "C");
    lcd_send_string(FOURTEENTH_COLUMN, FIRST_ROW, DEGREE_SIGN "F");
    lcd_send_string(SIXTH_COLUMN, SECOND_ROW, DEGREE_SIGN "K");

    while(1) {
        /* read sensor values */
        average = sensor_read();

        /* convert sensor readings to celsius, fahrenheit and kelvin */
        convert_to_temperature(&temperature, &average);

        /* handle strings with magic numbers */
        shift_digit(ptr_celsius, 2, 3);
        shift_digit(ptr_fahrenheit, 2, 3);
        shift_digit(ptr_kelvin, 3, 4);

        /* print values */
        lcd_send_string(SECOND_COLUMN, FIRST_ROW, ptr_celsius);
        lcd_send_string(TENTH_COLUMN, FIRST_ROW, ptr_fahrenheit);
        lcd_send_string(FIRST_COLUMN, SECOND_ROW, ptr_kelvin);

        sleep_ms(DELAY);
        wdt_reset();
    }
}


#ifdef BOOT_DEBUG
void get_mcusr(void)
{
    mcusr_mirror = MCUSR;
    MCUSR = 0;
    wdt_disable();
}
#endif
