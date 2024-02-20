/*
 * InterThreadCom_F.c
 *
 *  Created on: Feb 20, 2024
 *      Author: njv3788
 */
#include "InterThreadCom_F.h"

InterThreadCom_F BLUE2GREEN_F = RESET_F;
InterThreadCom_F BLUE2RED_F = RESET_F;

void Set_InterThreadCom_F (InterThreadCom_F_ID id)
{
   switch(id)
   {
      case BLUE2GREEN_ID:
    	  BLUE2GREEN_F = SET_F;
    	  break;
      case BLUE2RED_ID:
    	  BLUE2RED_F = SET_F;
    	  break;
   }
};
void Reset_InterThreadCom_F (InterThreadCom_F_ID id)
{
    switch(id)
    {
	   case BLUE2GREEN_ID:
	       BLUE2GREEN_F = RESET_F;
	       break;
	   case BLUE2RED_ID:
	       BLUE2RED_F = RESET_F;
	       break;
    }
};
InterThreadCom_F Check_InterThreadCom_F (InterThreadCom_F_ID id)
{
    switch(id)
    {
       case BLUE2GREEN_ID:
           return BLUE2GREEN_F;
       case BLUE2RED_ID:
           return BLUE2RED_F;
    }

    return ERROR_F;
};




