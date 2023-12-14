#include "lib/config.h"

int main(void) {
  struct car_config cf;

  while (1) {
    car_config_parse(&cf, "config.txt");
    car_config_process(&cf);
  }
}
