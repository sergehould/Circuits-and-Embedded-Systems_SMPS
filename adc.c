#include <xc.h>
#include <stdint.h>
void initADC1(void) {
  	AD1CON1bits.ADON = 0;   // turn off ADC (changing setting while ADON is not allowed)
	AD1CON1 = 0x00E0	 ;  // ADC_CLK_AUTO et ADC_AUTO_SAMPLING_OFF
	AD1CON1bits.AD12B = 1;  // 12 bits
	AD1CON3 = 0x8000  | 0x1f00;  // DC_CONV_CLK_INTERNAL_RC  et 31 TAD
	AD1CON2 = 0x8000;  // ADC_VREF_AVDD_AVSS
	AD1CHS0 = 	0 ;			//ADC_CH0_NEG_SAMPLEA_VREFN | canal 0;
  	AD1CON1bits.ADON = 1;   //turn on the ADC
}

inline int readADC(int ch) {
  AD1CHS0 = ch;
  AD1CON1bits.SAMP=1 ;   //start sampling
  while(AD1CON1bits.DONE==0);  //wait for conversion to finish
  return(ADC1BUF0);
}


void initADC_pins(void){
 //	Configuration de la broche  AN0 en mode analogue
	_CN2PUE = 0;	// Pull broche  CN2 #2 désactivé
	_TRISA0 = 1;	
	_PCFG0=0; // AN0:  broche  RA0 #2 en mode AD 
    
	//	Configuration de la broche  AN1 en mode analogue
	_CN3PUE = 0;	// Pull broche  CN2 #2 désactivé
	_TRISA1 = 1;	
	_PCFG1=0; // AN0:  broche  RA0 #2 en mode AD 
	// en mode interruption
	//_AD1IE =1;
}


