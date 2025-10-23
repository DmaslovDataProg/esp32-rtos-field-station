#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <freertos/queue.h>
#include <cstdint>

struct SensorData {
    float temperature;
    float humidity;
    float pressure;
    uint32_t timestamp;
};

#endif // SENSORDATA_H
