// out = sine(in)

#include <stdlib.h>
#include <math.h>
#include "sine.h"

typedef struct {
  const float* input;
  float* output;
} Sine;

LV2_Handle sine_instantiate(const LV2_Descriptor* descriptor, double rate,
  const char* bundle_path, const LV2_Feature* const* features) {
  Sine* sine = (Sine*)malloc(sizeof(Sine));
  return (LV2_Handle)sine;
}

void sine_connect_port(LV2_Handle instance, uint32_t port, void* data) {
  Sine* sine = (Sine*)instance;
  switch (port) {
    case 0: sine->output = (float*)data;
    case 1: sine->input = (const float*)data;
  }
}

void sine_run(LV2_Handle instance, uint32_t sample_count) {
  Sine* sine = (Sine*)instance;

  float* const output = sine->output;
  const float* input = sine->input;
  uint32_t i;
  for (i = 0; i < sample_count; i++) {
    output[i] = sin(input[i]);
  }
}

void sine_cleanup(LV2_Handle instance) {
  free(instance);
}
