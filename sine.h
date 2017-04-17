#ifndef SINE_H
#define SINE_H

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"

#define SINE_URI "http://colin.kinlo.ch/lv2/simple/sine"

LV2_Handle sine_instantiate(const LV2_Descriptor* descriptor, double rate,
  const char* bundle_path, const LV2_Feature* const* features);

void sine_connect_port(LV2_Handle instance, uint32_t port, void* data);

void sine_run(LV2_Handle instance, uint32_t sample_count);

void sine_cleanup(LV2_Handle instance);

#endif // SINE_H
