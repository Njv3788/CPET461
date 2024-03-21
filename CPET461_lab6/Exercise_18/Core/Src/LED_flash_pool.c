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

Flash_Rate_t FlashRate[10] = {50,100,150,200,250,300,350,400,450,500};

typedef struct  {
	Flash_Rate_t Green_LED;
	Flash_Rate_t Red_LED;
}LED_flash_pool_t;

LED_flash_pool_t LED_flash_pool = {FlashRate[1],FlashRate[10]};

void setLED_flash_pool(LED_tasks_t LED,uint32_t rate)
{
	rate %= 10;

	if(GREEN_LED == LED)
	{
		LED_flash_pool.Green_LED = FlashRate[rate];
	}
	else
	{
		LED_flash_pool.Red_LED = FlashRate[rate];
	}

}

Flash_Rate_t getLED_flash_pool(LED_tasks_t LED)
{
	rate %= 10;

	if(GREEN_LED == LED)
	{
		return LED_flash_pool.Green_LED;
	}

	return LED_flash_pool.Red_LED;
}


