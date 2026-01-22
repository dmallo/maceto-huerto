#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "comms.h"
#include "pump.h"
#include "scanneri2c.h"
#include "sensors.h"
#include "system.h"

void app_main() {

  while (1) {
    scanner_I2C();
    vTaskDelay(pdMS_TO_TICKS(100));
  }

  system_init();

  sensors_init();

  for (;;) {

    sensors_update();

    // code to decide when to send data and activate pump

    comms_sendData();

    pump_activate();

    system_sleep();
  }
}