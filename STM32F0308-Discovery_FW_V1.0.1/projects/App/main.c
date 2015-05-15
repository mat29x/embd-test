/******************** (C) COPYRIGHT 2012 STMicroelectronics ********************
* File Name          : main.c
* Author             : MCD Tools development Team
* Date First Issued  : January 2012
* Description        : This code is used for MB1034 board test
********************************************************************************
* History:
**
*
********************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_conf.h"

#define MS_DELAY_HSI (1000)
#define SECOND_DELAY (1000*MS_DELAY_HSI)
uint32_t TickValue=0;

void Init_GPIO(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOC | RCC_AHBPeriph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void TimingDelay_Decrement(void)
{
  TickValue--;
}

void delay(uint32_t counts)
{
  while(counts-- != 0);
}

void delay_ms(uint32_t n_ms)
{
  SysTick_Config(8000*PLL_MUL_X - 30);
  TickValue = n_ms;
  
  while(TickValue == n_ms);
  SysTick_Config(8000*PLL_MUL_X);

  while(TickValue != 0) ;
}

int main(void)
{
  Init_GPIO();
  while(1)
  {
    GPIOC->ODR = 0x0300;
    delay_ms(1000);
    GPIOC->ODR = 0x0000;
    delay_ms(1000);
  }
}