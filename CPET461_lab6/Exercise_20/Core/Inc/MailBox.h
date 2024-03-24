/*
 * MailBox.h
 *
 *  Created on: Mar 23, 2024
 *      Author: njv3788
 */

#ifndef INC_MAILBOX_H_
#define INC_MAILBOX_H_

typedef enum
{
   SYNC_1 = 111,
   SYNC_2 = 222
} mailBoxMessage_t;

void initMailBox(void);
void Post(mailBoxMessage_t message);
mailBoxMessage_t Pend(void);

#endif /* INC_MAILBOX_H_ */
