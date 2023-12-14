#pragma once

#include "types.h"
#include <stdio.h>
#define GEAR_MODE_SIZE 3

struct gear_pos {
  config_value_t value, prev;
};

char gear_mode_pos[GEAR_MODE_SIZE] = {'P', 'D', 'R'};

inline void gear_pos_set(struct gear_pos *gear, config_value_t value) {
  if (gear->value == value)
    return;

  gear->prev = gear->value;
  gear->value = value;
}

inline void gear_pos_process(struct gear_pos *gear) {
  if (gear->prev == gear->value)
    return;

  if (gear->value < GEAR_MODE_SIZE) {
    printf("Current gear mode: %c\n", gear_mode_pos[gear->value]);
    gear->prev = gear->value;

    return;
  }

  printf("Invalid gear mode: %u\n", gear->value);
}

#undef GEAR_MODE_SIZE
