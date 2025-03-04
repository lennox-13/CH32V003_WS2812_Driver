// Sketchy WS2812 driver for CH32V003
// Clock HSI 48MHz
// IO_Drive_Mode  -> PC0 (IO)

#include "ch32v00x.h"

#define LED_Pin  1<<(0*1) //GPIO -> PC0
#define LED_Port GPIOC    //GPIOC

void GPIO_Config(void){
     RCC->APB2PCENR |= RCC_IOPCEN;     // Enable clock PortC

     LED_Port->CFGLR &= ~(0x0F << (0*4)); // Clear setting bit PC0
     LED_Port->CFGLR |= 1 << (0*4);       // Set PC0 out push-pull 10MHz
     LED_Port->BCR = LED_Pin;             // Reset
}

void WS2812_0(void){  // T0H - 400ns , T0L - 850ns
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
}

void WS2812_1(void){  // T1H - 800ns , T1L - 450ns
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BSHR = (LED_Pin & (uint32_t)0x0000FFFF);
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
    LED_Port->BCR  = LED_Pin;
}

void WS2812_Reset(void){
    LED_Port->BCR = LED_Pin;
    Delay_Us(300);
}

/*  MAIN **/
int main(void){
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config();

    while(1){
      /*  bit_7      bit_6      bit_5      bit_4      bit_3      bit_2      bit_1      bit_0     */
        WS2812_0();WS2812_0();WS2812_0();WS2812_1();WS2812_0();WS2812_0();WS2812_0();WS2812_0(); // G - Led
        WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0(); // R - Led
        WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0();WS2812_0(); // B - Led

        WS2812_Reset(); // Reset
    }
}
