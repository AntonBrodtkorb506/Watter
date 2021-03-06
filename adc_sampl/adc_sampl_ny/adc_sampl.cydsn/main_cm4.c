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


int16 sample = 0;

char buff[8];

void SysInt_ISR(void){
    
    UART_1_PutString("sample er: ");
        
        sprintf(buff,"%d \n\r",sample);
        UART_1_PutString(buff);
    
    Cy_DMA_Channel_ClearInterrupt(DMA_1_HW,0);
        
    }

int main(void)
{
   
    DMA_1_Start(&(SAR->CHAN_RESULT[0]),(void *)&sample);
    
    Cy_DMA_Channel_SetInterruptMask(DMA_1_HW,0,CY_DMA_INTR_MASK);
    
    UART_1_Start();
    
    ADC_1_Start();
    ADC_1_StartConvert();
    
    
    __enable_irq(); /* Enable global interrupts. */  
    Cy_SysInt_Init(&SysInt_1_cfg,SysInt_ISR);
    NVIC_ClearPendingIRQ(SysInt_1_cfg.intrSrc);
    NVIC_EnableIRQ(SysInt_1_cfg.intrSrc);
    
    
    
    for(;;)
    {
    }
}

/* [] END OF FILE */
