#ifndef SENSORS_H__
#define SENSORS_H__

#include "driver/i2c_master.h"

typedef struct {
  i2c_master_dev_handle_t bmeDev;
} SensorConfig;

typedef struct {
  struct {
    float temperature;
    float pressure;
    float humidity;
  } bme;
} SensorData;

void sensors_init(SensorConfig* config);

void sensors_update(SensorData* data);

#endif  // SENSORS_H__