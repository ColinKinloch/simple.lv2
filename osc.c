// Minimal LV2 oscillator plugin to produce osc wave

#include <stdlib.h>
#include "osc.h"

typedef struct {
  float* output;
  double sample_rate;
  double accumulator;
} Osc;

LV2_Handle osc_instantiate(const LV2_Descriptor* descriptor, double rate,
  const char* bundle_path, const LV2_Feature* const* features) {
  Osc* osc = (Osc*)malloc(sizeof(Osc));
  osc->sample_rate = rate;
  osc->accumulator = 0;
  return (LV2_Handle)osc;
}

void osc_connect_port(LV2_Handle instance, uint32_t port, void* data) {
  Osc* osc = (Osc*)instance;
  switch (port) {
    case 0: osc->output = (float*)data;
  }
}

void osc_run(LV2_Handle instance, uint32_t sample_count) {
  Osc* osc = (Osc*)instance;

  float* const output = osc->output;
  float d = 440. / osc->sample_rate;
  double a = osc->accumulator;
  uint32_t i;
  for (i = 0; i < sample_count; i++) {
    a += 2. * d;
    if (a > 1.) {
      a -= 2.;
    }
    output[i] = a;
  }
  osc->accumulator = a;
}

void osc_cleanup(LV2_Handle instance) {
  free(instance);
}

