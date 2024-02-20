/*
 * RTOS_Flags.h
 *
 *  Created on: Feb 20, 2024
 *      Author: njv3788
 */

#ifndef INC_INTERTHREADCOM_F_H_
#define INC_INTERTHREADCOM_F_H_

typedef enum {SET_F,RESET_F,DRESET_F,ERROR_F} InterThreadCom_F;
typedef enum
{
  BLUE2GREEN_ID,
  BLUE2RED_ID
} InterThreadCom_F_ID;

void Set_InterThreadCom_F (InterThreadCom_F_ID);
void Reset_InterThreadCom_F (InterThreadCom_F_ID);
InterThreadCom_F Check_InterThreadCom_F (InterThreadCom_F_ID);

#endif /* INC_INTERTHREADCOM_F_H_ */
