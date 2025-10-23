#include <Arduino.h>
#include <freertos/queue.h>
#include "SensorData.h"

QueueHandle_t dataQueue = nullptr;

static void SensorTaskFunction(void* pvParameters) {
    SensorData sd;
    for (;;) {
        // Read actual sensors here
        sd.temperature = 25.0f + (random(-50, 50) / 100.0f);
        sd.humidity    = 50.0f;
        sd.pressure    = 1013.25f;
        sd.timestamp   = millis() / 1000;

        xQueueSend(dataQueue, &sd, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void startSensorTask() {
    if (dataQueue == nullptr) {
        dataQueue = xQueueCreate(8, sizeof(SensorData));
    }
    xTaskCreatePinnedToCore(
        SensorTaskFunction,
        "SensorTask",
        4096,
        nullptr,
        2,
        nullptr,
        1
    );
}
