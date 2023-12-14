#include "driver_mode.h"
#include "gear.h"
#include "speed.h"
#include "types.h"
#include <stdio.h>

#pragma once

struct car_config {
  struct gear_pos gear_pos;
  struct speed speed;
  struct driver_mode driver_mode;
};

#define INTERNAL_BUFFER_SIZE 50

// Return 0 means parsing successfully
inline int car_config_parse(struct car_config *config, const char *filename) {
  FILE *configFile = fopen(filename, "r");
  if (configFile == NULL) {
    printf("Cannot open config file: %s\n", filename);
    return 1;
  }

  char buffer[INTERNAL_BUFFER_SIZE];

  while (fgets(buffer, INTERNAL_BUFFER_SIZE, configFile)) {
    config_value_t value;

    // Read speed
    value = 0;
    sscanf(buffer, "speed %u", &value);
    if (value)
      speed_set(&config->speed, value);

    // Read gear pos
    value = 0;
    sscanf(buffer, "gear %u", &value);
    if (value)
      gear_pos_set(&config->gear_pos, value);

    // Read driver mode
    value = 0;
    sscanf(buffer, "driverMode %u", &value);
    if (value)
      driver_mode_set(&config->driver_mode, value);
  }

  fclose(configFile);

  return 0;
}

#undef INTERNAL_BUFFER_SIZE

inline void car_config_process(struct car_config *config) {
  speed_process(&config->speed);
  gear_pos_process(&config->gear_pos);
  driver_mode_process(&config->driver_mode);
}
