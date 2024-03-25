/*
 * Deferred_Sever.c
 *
 *  Created on: Mar 25, 2024
 *      Author: njv3788
 */

#include "FreeRTOS.h"
#include "semphr.h"
#include "Deferred_Sever.h"

SemaphoreHandle_t EFSema;

void InitEFSema(void)
{
  EFSema = xSemaphoreCreateBinary();
};

void SetEFSema(void)
{
  xSemaphoreGiveFromISR(EFSema,NULL);
};

void WaitEFSema(void)
{
  xSemaphoreTake(EFSema,portMAX_DELAY);
};
