#include <stdint.h>

#define RCC_AHB1ENR   (*(volatile uint32_t *)0x40023830UL)

#define GPIOA_BASE    0x40020000UL
#define GPIOA_MODER   (*(volatile uint32_t *)(GPIOA_BASE + 0x00)) 
#define GPIOA_ODR     (*(volatile uint32_t *)(GPIOA_BASE + 0x14)) 

static void delay(volatile uint32_t count) {
    while (count--) __asm__ volatile ("nop");
}

int main(void)
{

    RCC_AHB1ENR |= (1u << 0);  

    GPIOA_MODER &= ~(0x3u << (5 * 2));  
    GPIOA_MODER |=  (0x1u << (5 * 2)); 

    for (;;) {

        GPIOA_ODR ^= (1u << 5);

        delay(300000);
    }
}
