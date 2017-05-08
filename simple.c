#include <stdlib.h>

#include "osc.h"
#include "sine.h"
#include "mult.h"

static const LV2_Descriptor osc_descriptor = {
  OSC_URI,
  osc_instantiate,
  osc_connect_port,
  NULL,
  osc_run,
  NULL,
  osc_cleanup
};
static const LV2_Descriptor sine_descriptor = {
  SINE_URI,
  sine_instantiate,
  sine_connect_port,
  NULL,
  sine_run,
  NULL,
  sine_cleanup
};
static const LV2_Descriptor mult_descriptor = {
  MULT_URI,
  mult_instantiate,
  mult_connect_port,
  NULL,
  mult_run,
  NULL,
  mult_cleanup
};

LV2_SYMBOL_EXPORT const LV2_Descriptor* lv2_descriptor (uint32_t index) {
  switch (index) {
    case 0: return &osc_descriptor;
    case 1: return &sine_descriptor;
    case 2: return &mult_descriptor;
    default: return NULL;
  }
}
