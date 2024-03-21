/*
 * LED_flash_pool.h
 *
 *  Created on: Mar 21, 2024
 *      Author: njv3788
 */

#ifndef INC_LED_FLASH_POOL_H_
#define INC_LED_FLASH_POOL_H_

typedef uint32_t Flash_Rate_t;
typedef enum {GREEN_LED,RED_LED} LED_tasks_t;

void setLED_flash_pool(LED_tasks_t LED,uint32_t rate);
void getLED_flash_pool(LED_tasks_t LED);

#endif /* INC_LED_FLASH_POOL_H_ */
