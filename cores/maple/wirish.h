/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @brief Main include file for the Wirish core.
 *
 * Includes most of Wirish, and (transitively or otherwise)
 * substantial pieces of libmaple proper.
 */

#ifndef _WIRISH_WIRISH_H_
#define _WIRISH_WIRISH_H_

/* 
 * 20141030. Roger Clark
   Added the block of includes up to avr/interrupt so that stdlib functions like memcpy would be included and could be used.
 */
#include <stdlib.h>
#include <stdio.h>


#include <string.h>
#include <WString.h>
#include <avr/dtostrf.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include <libmaple/stm32.h>

#include <boards.h>
#include <io.h>
#include <bit_constants.h>
#include <pwm.h>
#include <ext_interrupts.h>
#include <wirish_debug.h>
#include <wirish_math.h>
#include <wirish_time.h>
#include <wirish_constants.h>

#if STM32_MCU_SERIES == STM32_SERIES_F1 /* FIXME [0.0.13?] port to F2 */
//#include <HardwareSPI.h>
#endif

#include <HardwareSerial.h>
#include <HardwareTimer.h>
#include <usb_serial.h>
#include <wirish_types.h>

#include <libmaple/libmaple.h>

#include <stdint.h>

#warning these are just here to get SPI to compile they need to be changed and moved!
#define SS (1)
#define MOSI 2
#define MISO 3
#define SCK 4

typedef unsigned int word;
// typedef uint16 word;// definition from Arduino website, now appears to be incorrect for 32 bit devices

/* Wiring macros and bit defines */

#define true 0x1
#define false 0x0

#define lowByte(w)                     ((w) & 0xFF)
#define highByte(w)                    (((w) >> 8) & 0xFF)
#define bitRead(value, bit)            (((value) >> (bit)) & 0x01)
#define bitSet(value, bit)             ((value) |= (1UL << (bit)))
#define bitClear(value, bit)           ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : \
                                                   bitClear(value, bit))
#define bit(b)                         (1UL << (b))

#endif

