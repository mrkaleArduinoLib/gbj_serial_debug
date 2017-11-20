/*
  NAME:
  gbj_serial_debug

  DESCRIPTION:
  Library defines preprocessor macro functions for serial debugging.

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the license GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
  (related to original code) and MIT License (MIT) for added code.

  CREDENTIALS:
  Author: Libor Gabaj
  GitHub: https://github.com/mrkaleArduinoLib/gbj_serial_debug.git
 */
#ifndef GBJ_SERIAL_DEBUG_H
#define GBJ_SERIAL_DEBUG_H
#define GBJ_SERIAL_DEBUG_VERSION "GBJ_SERIAL_DEBUG_1.0.0"

#if defined(__AVR__)
  #if ARDUINO >= 100
    #include <Arduino.h>
  #else
    #include <WProgram.h>
  #endif
  #include <inttypes.h>
  #define SERIAL_F(s) F(s)
#elif defined(PARTICLE)
  #include <Particle.h>
  #define SERIAL_F(s) s
#else
  #define SERIAL_F(s) s
#endif

#if defined(SERIAL_DEBUG) || !defined(SERIAL_NODEBUG)
  #define SERIAL_LOG1(p1)                     { Serial.println(p1); }
  #define SERIAL_LOG2(p1, p2)                 { Serial.print(p1); Serial.println(p2); }
  #define SERIAL_LOG3(p1, p2, p3)             { Serial.print(p1); Serial.print(p2); Serial.println(p3); }
  #define SERIAL_LOG4(p1, p2, p3, p4)         { Serial.print(p1); Serial.print(p2); Serial.print(p3); Serial.println(p4); }
  #define SERIAL_LOG5(p1, p2, p3, p4, p5)     { Serial.print(p1); Serial.print(p2); Serial.print(p3); Serial.print(p4); Serial.println(p5); }
  #define SERIAL_LOG6(p1, p2, p3, p4, p5, p6) { Serial.print(p1); Serial.print(p2); Serial.print(p3); Serial.print(p4); Serial.print(p5); Serial.println(p6); }
  //
  #define SERIAL_LINE                         { Serial.println(); }
  #define SERIAL_BEGIN(b)                     { Serial.begin(b); while(!Serial) { }; SERIAL_LINE }
  #define SERIAL_TITLE(s)                     { SERIAL_LOG1(SERIAL_F(s)) }
  #define SERIAL_VALUE(k, v)                  { SERIAL_LOG3(SERIAL_F(k),SERIAL_F(": "), v) }
  #define SERIAL_DELIM                        { SERIAL_TITLE("---") }
  #define SERIAL_ACTION(s)                    { Serial.print(SERIAL_F(s)); }
  #define SERIAL_DOT                          { Serial.print(SERIAL_F(".")); }
#else
  #define SERIAL_LOG1(p1)
  #define SERIAL_LOG2(p1, p2)
  #define SERIAL_LOG3(p1, p2, p3)
  #define SERIAL_LOG4(p1, p2, p3, p4)
  #define SERIAL_LOG5(p1, p2, p3, p4, p5)
  #define SERIAL_LOG6(p1, p2, p3, p4, p5, p6)
  //
  #define SERIAL_LINE
  #define SERIAL_BEGIN(b)
  #define SERIAL_TITLE(s)
  #define SERIAL_VALUE(k, v)
  #define SERIAL_DELIM
  #define SERIAL_ACTION(s)
  #define SERIAL_DOT
#endif

#endif
