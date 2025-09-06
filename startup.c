#include <stdint.h>
#include "include/system_stm32f4xx.h" 

__attribute__((weak)) void SystemInit(void) {}

extern uint32_t _estack;
extern const uint32_t _sidata;   
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Default_Handler(void)
{
    while (1);
}

void Reset_Handler(void)
{
  const uint32_t *psrc = &_sidata;
  uint32_t *pdst = &_sdata;

  while (pdst < &_edata) { *pdst++ = *psrc++; }

  pdst = &_sbss;
  while (pdst < &_ebss) { *pdst++ = 0u; }

  SystemInit();
  main();
  while (1);
}

#include <stddef.h>

__attribute__((section(".isr_vector"), used))
const uintptr_t vector_table[] =
{
  (uintptr_t)&_estack,
  (uintptr_t)&Reset_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  0,
  0,
  0,
  0,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  0,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler,
  0,
  (uintptr_t)&Default_Handler,
  (uintptr_t)&Default_Handler
};
