#ifndef SENSORTASK_H
#define SENSORTASK_H

#include "SensorData.h"
#include <freertos/queue.h>

extern QueueHandle_t dataQueue;

void startSensorTask();

#endif // SENSORTASK_H
