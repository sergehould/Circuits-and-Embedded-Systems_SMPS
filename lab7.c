/****************************************************************************
 **		Lab7
 ** 
 **      Description: TO COMPLETE BY THE STUDENT
 ** 
 **  Author          Date                Description/Version
 ** 
 *****************************************************************************/

#include <xc.h>
#include "adc.h"
#include "initBoard.h"
#include "pwm.h"


int main(void){
    initOscillator();
    initIO();
    initOC();
    initADC1();
    initADC_pins();
	PWMSet(500);	// Sets PWM to 50% at pin 21
	while (1){
		/* Your code here */
    }  
}
