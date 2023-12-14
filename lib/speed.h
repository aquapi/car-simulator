#include "types.h"
#include <stdio.h>
#pragma once

#define HIGH_SPEED 120

struct speed {
  config_value_t value, prev;
};

inline void speed_set(struct speed *speed, config_value_t value) {
  if (speed->value == value)
    return;

  speed->prev = speed->value;
  speed->value = value;
}

inline void speed_process(struct speed *speed) {
  if (speed->value == speed->prev)
    return;

  printf("Current speed: %u km/h\n", speed->value);

  if (speed->value > HIGH_SPEED)
    printf("Warning: Driving too fast!\n");

  speed->prev = speed->value;
}
