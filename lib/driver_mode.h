#pragma once

#include "types.h"
#include <stdio.h>
#define DRIVER_MODE_SIZE 4

struct driver_mode {
  config_value_t value, prev;
};

const char *driver_modes[DRIVER_MODE_SIZE] = {"Eco", "Normal", "Sport", "Snow"};

inline void driver_mode_set(struct driver_mode *mode, config_value_t value) {
  if (mode->value == value)
    return;

  mode->prev = mode->value;
  mode->value = value;
}

inline void driver_mode_process(struct driver_mode *mode) {
  if (mode->prev == mode->value)
    return;

  if (mode->value < DRIVER_MODE_SIZE) {
    printf("Current driver mode: %s\n", driver_modes[mode->value]);
    mode->prev = mode->value;

    return;
  }

  printf("Invalid driver mode: %u\n", mode->value);
}

#undef DRIVER_MODE_SIZE
