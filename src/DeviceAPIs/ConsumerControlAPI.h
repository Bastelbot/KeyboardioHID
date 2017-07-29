/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

#include <Arduino.h>
#include "PluggableUSB.h"
#include "HID.h"
#include "HID-Settings.h"
#include "DescriptorPrimitives.h"

#define DESCRIPTOR_CONSUMER_CONTROL_KEYS   \
  /* 4 Media Keys */   \
  D_LOGICAL_MINIMUM, 0x00, 								/* logical minimum */   \
  D_MULTIBYTE(D_LOGICAL_MAXIMUM), 0xFF, 0x03, 							/* logical maximum (3ff) */   \
  D_USAGE_MINIMUM, 0x00, 								/* usage minimum (0) */   \
  D_MULTIBYTE(D_USAGE_MAXIMUM), 0xFF, 0x03, 							/* usage maximum (3ff) */   \
  D_REPORT_COUNT, 0x04, 								/* report count (4) */   \
  D_REPORT_SIZE, 0x10, 								/* report size (16) */   \
  D_INPUT, 0x00, 								/* input */  
   

typedef union {
  // Every usable Consumer key possible, up to 4 keys presses possible
  uint16_t keys[4];
  struct {
    uint16_t key1;
    uint16_t key2;
    uint16_t key3;
    uint16_t key4;
  };
} HID_ConsumerControlReport_Data_t;


class ConsumerControlAPI {
 public:
  inline ConsumerControlAPI(void);
  inline void begin(void);
  inline void end(void);
  inline void write(uint16_t m);
  inline void press(uint16_t m);
  inline void release(uint16_t m);
  inline void releaseAll(void);

  // Sending is public in the base class for advanced users.
  virtual void sendReport(void* data, int length);


 protected:
  HID_ConsumerControlReport_Data_t _report;
};

#include "ConsumerControlAPI.hpp"
