/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "adcsample.h"


int sample = 0;


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    char uartBuffer[256];
    
   
    
    DMA_1_Start(&(SAR->CHAN_RESULT[0]),&sample);
    
    UART_1_Start();
  
    ADC_1_Start();
    ADC_1_StartConvert();
    
    UART_1_PutString("Hej");

    for(;;)
    {
          UART_1_PutString("Hej");
        /* Place your application code here. */
       initADCsample();
       
        
        snprintf(uartBuffer, sizeof(uartBuffer), "Sample er: %i", sample);
    }
}

/* [] END OF FILE */
