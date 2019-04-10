#include <xc.h>
#include <stdint.h>

// Voir p300 datasheet  et fin du fichier p33FJ128GP802.h  ou  
_FGS(GSS_OFF & GWRP_OFF);				// Code protect OFF &  Write protect OFF
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF);		//P141 datasheet:  Fast RC oscillator w/ divide and PLL. 7.37 MHz oscillator with postscaler. FRC divide by 1 (default) & Start-up device with user-selected oscillator source
_FOSC(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMD_NONE);  //Clock switching is disabled, Fail-Safe Clock Monitor is disabled & This sets I-O on OSC2 pin & Primary oscillator disabled
_FWDT(FWDTEN_OFF);

void initOscillator(void){
	//Fosc=7.37* 32/(2*4) = 4*7.37MHz
    // Fcy = 2*7.37 MHz =14.74MHz
    CLKDIVbits.PLLPRE = 0;  // N1 factor = 2
	PLLFBDbits.PLLDIV = 30;  // M factor = 32
	CLKDIVbits.PLLPOST = 1;  // N2 factor = 4
    RCONbits.SWDTEN = 0; // Software Disable of the Watchdog Timer
}



void initIO(void){
        //I/Os
    	// OUTPUT SELECTION FOR REMAPPABLE PIN
	_RP10R=0b10010; //  RP10 (pin21)  tied to Output Compare 1. see #define _RP10R RPOR5bits.RP10R in p33FJ128GP802.h. 
        //	Configuration de la broche  AN0 en mode analogue
	
    _TRISB12=0; //LED	
}

