#include <xc.h>
void initOC(void){

	// Initialize Output Compare Module
	OC1CONbits.OCM = 0b000; // Disable Output Compare Module
	OC1R = 20; // Write the duty cycle for the first PWM pulse
	OC1RS = 100; // Write the duty cycle for the second PWM pulse
	OC1CONbits.OCTSEL = 0; // Select Timer 2 as output compare time base
	OC1CONbits.OCM = 0b110; // Select the Output Compare mode

	// Initialize and enable Timer2
	// f timer2 = fcy /prescaler/(PR2+1)=
	T2CONbits.TON = 0; // Disable Timer
	T2CONbits.TCS = 0; // Select internal instruction cycle clock
	T2CONbits.TGATE = 0; // Disable Gated Timer mode
	T2CONbits.TCKPS = 0b00; // Select Prescaler 1:1
	TMR2 = 0x00; // Clear timer register
    // Load the period value for fpwm = 14.74MHz / (PRE*(PR2+1))
    // fpwm = 14.74MHz / (1*1000)=  14.74kHz
	PR2 = 1000-1; 
	IPC1bits.T2IP = 0x01; // Set Timer 2 Interrupt Priority Level
	IFS0bits.T2IF = 0; // Clear Timer 2 Interrupt Flag
//	IEC0bits.T2IE = 1; // Enable Timer 2 interrupt
	T2CONbits.TON = 1; // Start Timer
    
}

inline void PWMSet(int pdc){
		OC1RS = pdc;			
}
