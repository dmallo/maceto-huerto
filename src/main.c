#include <freertos/FreeRTOS.h>
#include "comms.h"
#include "pump.h"
#include "scanneri2c.h"
#include "sensors.h"
#include "system.h"

void app_main() {

  vTaskDelay(pdMS_TO_TICKS(3000));

  SystemDevs* sysDevs = system_init();

  SensorConfig sensorConfig;
  sensorConfig.bmeDev = sysDevs->bme;
  sensors_init(&sensorConfig);

  SensorData data;
  for (;;) {

    sensors_update(&data);

    printf("Temperature: %.2f ºC, Pressure: %.2f hPa, Humidity: %.2f%%\n", data.bme.temperature, data.bme.pressure,
           data.bme.humidity);
    // code to decide when to send data and activate pump

    comms_sendData();

    pump_activate();

    system_sleep();

    vTaskDelay(pdMS_TO_TICKS(200));
  }
}