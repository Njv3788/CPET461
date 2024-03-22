/*
 * LED_flash_pool.c
 *
 *  Created on: Mar 21, 2024
 *      Author: njv3788
 */

#include "stdint.h"
#include "FreeRTOS.h"
#include "semphr.h"

#include "LED_flash_pool.h"

Flash_Rate_t FlashRate[10] = {500,50,100,150,200,250,300,350,400,450};

typedef struct  {
	Flash_Rate_t Green_LED;
	Flash_Rate_t Red_LED;
}LED_flash_pool_t;

LED_flash_pool_t LED_flash_pool;

SemaphoreHandle_t LED_flash_pool_sema;
void init_LED_flash_pool()
{
	LED_flash_pool.Green_LED = get_FlashRate(10);
	LED_flash_pool.Red_LED = get_FlashRate(1);
	LED_flash_pool_sema = xSemaphoreCreateBinary();
	xSemaphoreGive(LED_flash_pool_sema);
}


Flash_Rate_t get_FlashRate(uint32_t rate)
{
	rate = rate %10;
	return FlashRate[rate];
}

void setLED_flash_pool(LED_tasks_t LED,uint32_t rate)
{

  xSemaphoreTake(LED_flash_pool_sema,portMAX_DELAY);
  if(GREEN_LED == LED)
  {
	LED_flash_pool.Green_LED = get_FlashRate(rate);
  }
  else
  {
    LED_flash_pool.Red_LED = get_FlashRate(rate);
  }

  xSemaphoreGive(LED_flash_pool_sema);
  return;
}

Flash_Rate_t getLED_flash_pool(LED_tasks_t LED)
{
  Flash_Rate_t LED_Flash_rate;
  xSemaphoreTake(LED_flash_pool_sema,portMAX_DELAY);

  if(GREEN_LED == LED)
  {
    LED_Flash_rate = LED_flash_pool.Green_LED;
  }
  else
  {
    LED_Flash_rate = LED_flash_pool.Red_LED;
  }

  xSemaphoreGive(LED_flash_pool_sema);
  return LED_Flash_rate;
}


