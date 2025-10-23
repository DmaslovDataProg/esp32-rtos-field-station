/*
 * ESP32-Dev: Field station
 * 
 *
 * Wiring:
 *
 * Access:
 *
 * Author: Dmytro Maslov, Porto, Portugal
 */
#include <Arduino.h>
#include <cstdint>
#include "SensorTask.h"
#include "LoggerTask.h"

void setup() {
    Serial.begin(115200);

    startSensorTask();
    startLoggerTask();
}

void loop() {
    // main loop empty — all work done in tasks
}
