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
#include <stdio.h>
#include <stdlib.h>


int sample = 0;

char sample1[1000];


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    char uartBuffer[256];
    
    
   
    
    DMA_1_Start(&(SAR->CHAN_RESULT[0]),&sample);
    
    UART_1_Start();
  
    ADC_1_Start();
    ADC_1_StartConvert();
    
    initADCsample();
    
    UART_1_PutString("Hej");

    for(;;)
    {
          getADCsample(sample);
          UART_1_PutString("Sample er: ");
        
          itoa(sample,sample1,10);
          UART_1_PutString(sample1);
        /* Place your application code here. */
       
           
    CyDelay(500);
         
       // sprintf(uartBuffer, sizeof(uartBuffer), "Sample er: %i", sample);
    }
}

/* [] END OF FILE */
