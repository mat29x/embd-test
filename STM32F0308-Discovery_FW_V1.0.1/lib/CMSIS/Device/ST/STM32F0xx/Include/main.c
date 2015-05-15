#include "stm32f0xx.h"
#include "stm32f0308_discovery.h"

void main (void) {
  STM_EVAL_LEDInit(LED3);

  while(1) {
    STM_EVAL_LEDOn(LED3);
  }
}