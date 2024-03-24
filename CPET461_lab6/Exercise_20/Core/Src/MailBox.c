
#include "MailBox.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "cmsis_os.h"

osMessageQId MessageQueHandle;

SemaphoreHandle_t MailBoxMutex;
SemaphoreHandle_t Post_Semaphore;
SemaphoreHandle_t Pend_Semaphore;

void initMailBox(void)
{
  osMessageQDef(MessageQue,1,uint16_t);
  MessageQueHandle = osMessageCreate(osMessageQ(MessageQue), NULL);

  MailBoxMutex = xSemaphoreCreateMutex();
  xSemaphoreGive(MailBoxMutex);

  Post_Semaphore = xSemaphoreCreateBinary();

  Pend_Semaphore = xSemaphoreCreateBinary();
}

void Post(mailBoxMessage_t message)
{
   	xSemaphoreTake(MailBoxMutex,osWaitForever);
	osMessagePut(MessageQueHandle, (uint32_t) message, 0);
	xSemaphoreGive(MailBoxMutex);

   	xSemaphoreGive(Post_Semaphore);
   	xSemaphoreTake(Pend_Semaphore,osWaitForever);
}

mailBoxMessage_t Pend(void)
{
	osEvent QueRead;

	xSemaphoreGive(Pend_Semaphore);
	xSemaphoreTake(Post_Semaphore,osWaitForever);

	xSemaphoreTake(MailBoxMutex,osWaitForever);
   	QueRead = osMessageGet(MessageQueHandle, 0);
	xSemaphoreGive(MailBoxMutex);

	return (mailBoxMessage_t) QueRead.value.v;
}
