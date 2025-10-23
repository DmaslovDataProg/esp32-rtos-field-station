#ifndef LOGGERTASK_H
#define LOGGERTASK_H

#include <freertos/queue.h>


extern QueueHandle_t dataQueue;

void startLoggerTask();

#endif // LOGGERTASK_H
