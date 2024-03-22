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
typedef struct{
   uint32_t period;
   Flash_Rate_t rate;
}LED_Flash_t;

void init_LED_flash_pool();
Flash_Rate_t get_FlashRate(uint32_t rate);
void setLED_flash_pool(LED_tasks_t LED,uint32_t rate);
Flash_Rate_t getLED_flash_pool(LED_tasks_t LED);

#endif /* INC_LED_FLASH_POOL_H_ */
