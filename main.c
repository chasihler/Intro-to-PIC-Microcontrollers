

/*
 * Project: 18F47Q10 Nano Board Test
 * Charles Ihler
 * http://iradan.com
 
 * v0.1 Test
 * Mostly automatically generated code by MCC
 * 
 * Replied w/ RX to TX
 * Button toggles LED blink frequency
 
 */

#include "mcc_generated_files/mcc.h"

    volatile uint8_t rxData;
        
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    //INTERRUPT_GlobalInterruptEnable();
    //INTERRUPT_GlobalInterruptDisable();
    //INTERRUPT_PeripheralInterruptEnable();
    //INTERRUPT_PeripheralInterruptDisable();

    EUSART1_Write("h");
    
    while (1)
    {
        // Add your application code
        
        if (!PORTEbits.RE2) { 

            LATEbits.LATE0 = 1;
            __delay_ms(250);     
            LATEbits.LATE0 = 0;
            __delay_ms(250);

        } else {

            LATEbits.LATE0 = 1;
            __delay_ms(25);     
            LATEbits.LATE0 = 0;
            __delay_ms(25);
     
        }
        
        // Logic to echo received data
            if(EUSART1_is_rx_ready())
            {
                rxData = EUSART1_Read();
                if(EUSART1_is_tx_ready())
                {
                    EUSART1_Write(rxData);
                }
            }
        
    }
}
/**
 End of File
*/