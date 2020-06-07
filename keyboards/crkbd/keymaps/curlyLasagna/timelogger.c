#include <stdio.h>
#include "../../crkbd.h"

char timelog_str[24] = {};
int last_time = 0;
int elapsed_time = 0;

void set_timelog(void) {
  elapsed_time = timer_elapsed(last_time)/10000;
  last_time = timer_read()/10000;
  snprintf(timelog_str, sizeof(timelog_str), "lt:%3d, et:%3d", last_time, elapsed_time);
}

const char *read_timelog(void) {
  return timelog_str;
}
