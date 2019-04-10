/* 
 * File:   adc.h
 * Author: sh
 *
 * Created on December 14, 2018, 2:39 PM
 */

#ifndef ADC_H
#define	ADC_H

void initADC1(void);
inline int readADC(int ch);
void initADC_pins(void);

#endif	/* ADC_H */

