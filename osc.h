#ifndef OSC_H
#define OSC_H

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"

#define OSC_URI "http://colin.kinlo.ch/lv2/simple/osc"

LV2_Handle osc_instantiate(const LV2_Descriptor* descriptor, double rate,
  const char* bundle_path, const LV2_Feature* const* features);

void osc_connect_port(LV2_Handle instance, uint32_t port, void* data);

void osc_run(LV2_Handle instance, uint32_t sample_count);

void osc_cleanup(LV2_Handle instance);

#endif // OSC_H
