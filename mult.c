// out = x*in

#include <stdlib.h>
#include <math.h>
#include "mult.h"

typedef struct {
  float* output;
  const float* input;
  const float* coefficient;
} Mult;

LV2_Handle mult_instantiate(const LV2_Descriptor* descriptor, double rate,
  const char* bundle_path, const LV2_Feature* const* features) {
  Mult* mult = (Mult*)malloc(sizeof(Mult));
  return (LV2_Handle)mult;
}

void mult_connect_port(LV2_Handle instance, uint32_t port, void* data) {
  Mult* mult = (Mult*)instance;
  switch (port) {
    case 0: mult->output = (float*)data; break;
    case 1: mult->input = (const float*)data; break;
    case 2: mult->coefficient = (const float*)data; break;
  }
}

void mult_run(LV2_Handle instance, uint32_t sample_count) {
  Mult* mult = (Mult*)instance;

  float* const output = mult->output;
  const float* const input = mult->input;
  const float coefficient = *(mult->coefficient);
  uint32_t i;
  for (i = 0; i < sample_count; i++) {
    output[i] = input[i] * coefficient;
  }
}

void mult_cleanup(LV2_Handle instance) {
  free(instance);
}
