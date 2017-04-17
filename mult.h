#ifndef MULT_H
#define MULT_H

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"

#define MULT_URI "http://colin.kinlo.ch/lv2/simple/mult"

LV2_Handle mult_instantiate(const LV2_Descriptor* descriptor, double rate,
  const char* bundle_path, const LV2_Feature* const* features);

void mult_connect_port(LV2_Handle instance, uint32_t port, void* data);

void mult_run(LV2_Handle instance, uint32_t sample_count);

void mult_cleanup(LV2_Handle instance);

#endif // MULT_H
