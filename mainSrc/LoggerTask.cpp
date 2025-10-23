#include <Arduino.h>
#include <freertos/queue.h>

#include "LoggerTask.h"
#include "SensorData.h"

extern QueueHandle_t dataQueue;

static void LoggerTaskFunction(void* pvParameters) {
    SensorData sd;
    for (;;) {
        if (xQueueReceive(dataQueue, &sd, portMAX_DELAY) == pdTRUE) {
            Serial.printf(
                "T: %.2f C  H: %.2f %%  P: %.2f hPa  @%u s\n",
                sd.temperature, sd.humidity, sd.pressure, sd.timestamp
            );
            // TODO: later add SD / flash logging code here
        }
    }
}

void startLoggerTask() {
    xTaskCreatePinnedToCore(
        LoggerTaskFunction,
        "LoggerTask",
        4096,
        nullptr,
        1,
        nullptr,
        1
    );
}
