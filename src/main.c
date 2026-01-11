#include "comms.h"
#include "pump.h"
#include "sensors.h"
#include "system.h"

void app_main() {

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