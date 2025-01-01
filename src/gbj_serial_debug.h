/*
  NAME:
  gbj_serial_debug

  DESCRIPTION:
  Library defines preprocessor macro functions for serial debugging.

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the license GNU GPL v3
  http://www.gnu.org/licenses/gpl-3.0.html (related to original code) and MIT
  License (MIT) for added code.

  CREDENTIALS:
  Author: Libor Gabaj
  GitHub: https://github.com/mrkaleArduinoLib/gbj_serial_debug.git
 */
#ifndef GBJ_SERIAL_DEBUG_H
#define GBJ_SERIAL_DEBUG_H

#if defined(__AVR__)
  #include <Arduino.h>
  #include <inttypes.h>
  #define SERIAL_F(s) F(s)
#elif defined(ESP8266) || defined(ESP32)
  #include <Arduino.h>
  #define SERIAL_F(s) F(s)
#elif defined(PARTICLE)
  #include <Particle.h>
  #define SERIAL_F(s) s
#else
  #define SERIAL_F(s) s
#endif

#if !defined(SERIAL_NODEBUG)

  #ifdef SERIAL_PREFIX
    #define SERIAL_SEPAR_H SERIAL_F("::")
  #else
    #define SERIAL_PREFIX ""
    #define SERIAL_SEPAR_H ""
  #endif
  #define SERIAL_SEPAR_V SERIAL_F(": ")

  #define SERIAL_PRINTLN(p)                                                    \
    {                                                                          \
      Serial.println(p);                                                       \
    }
  #if defined(ESP32)
    #define SERIAL_PRINTLN_FMT(p, f)                                           \
      {                                                                        \
        Serial.println(p, f);                                                  \
      }
  #endif

  #define SERIAL_LOG1(p1)                                                      \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.println(p1);                                                      \
    }
  #if defined(ESP32)
    #define SERIAL_LOG1_FMT(p1, f)                                             \
      {                                                                        \
        Serial.print(SERIAL_F(SERIAL_PREFIX));                                 \
        Serial.print(SERIAL_SEPAR_H);                                          \
        Serial.println(p1, f);                                                 \
      }
  #endif
  #define SERIAL_LOG2(p1, p2)                                                  \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.print(p1);                                                        \
      Serial.println(p2);                                                      \
    }
  #define SERIAL_LOG3(p1, p2, p3)                                              \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.println(p3);                                                      \
    }
  #define SERIAL_LOG4(p1, p2, p3, p4)                                          \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.print(p3);                                                        \
      Serial.println(p4);                                                      \
    }
  #define SERIAL_LOG5(p1, p2, p3, p4, p5)                                      \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.print(p3);                                                        \
      Serial.print(p4);                                                        \
      Serial.println(p5);                                                      \
    }
  #define SERIAL_LOG6(p1, p2, p3, p4, p5, p6)                                  \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.print(p3);                                                        \
      Serial.print(p4);                                                        \
      Serial.print(p5);                                                        \
      Serial.println(p6);                                                      \
    }
  //
  #define SERIAL_CHAIN1(p1)                                                    \
    {                                                                          \
      Serial.print(p1);                                                        \
    }
  #define SERIAL_CHAIN2(p1, p2)                                                \
    {                                                                          \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
    }
  #define SERIAL_CHAIN3(p1, p2, p3)                                            \
    {                                                                          \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.print(p3);                                                        \
    }
  #define SERIAL_CHAIN4(p1, p2, p3, p4)                                        \
    {                                                                          \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.print(p3);                                                        \
      Serial.print(p4);                                                        \
    }
  #define SERIAL_CHAIN5(p1, p2, p3, p4, p5)                                    \
    {                                                                          \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.print(p3);                                                        \
      Serial.print(p4);                                                        \
      Serial.print(p5);                                                        \
    }
  #define SERIAL_CHAIN6(p1, p2, p3, p4, p5, p6)                                \
    {                                                                          \
      Serial.print(p1);                                                        \
      Serial.print(p2);                                                        \
      Serial.print(p3);                                                        \
      Serial.print(p4);                                                        \
      Serial.print(p5);                                                        \
      Serial.print(p6);                                                        \
    }
  //
  #define SERIAL_LINE                                                          \
    {                                                                          \
      Serial.println();                                                        \
    }
  #define SERIAL_BEGIN(b)                                                      \
    {                                                                          \
      Serial.begin(b);                                                         \
      while (!Serial)                                                          \
      {                                                                        \
      };                                                                       \
      SERIAL_LINE                                                              \
    }
  #define SERIAL_TITLE(s) { SERIAL_LOG1(SERIAL_F(s)) }
  #define SERIAL_VALUE(k, v) { SERIAL_LOG3(SERIAL_F(k), SERIAL_SEPAR_V, v) }
  #if defined(ESP32)
    #define SERIAL_VALUE_FMT(k, v, f)                                          \
      {                                                                        \
        Serial.print(SERIAL_F(SERIAL_PREFIX));                                 \
        Serial.print(SERIAL_SEPAR_H);                                          \
        Serial.print(SERIAL_F(k));                                             \
        Serial.print(SERIAL_SEPAR_V);                                          \
        Serial.println(v, f);                                                  \
      }
  #endif
  #define SERIAL_VALUE_UNIT(k, v, u)                                           \
    { SERIAL_LOG5(SERIAL_F(k), SERIAL_SEPAR_V, v, SERIAL_F(" "), SERIAL_F(u)) }
  #define SERIAL_VALUE_INDEX(i, k, v)                                          \
    { SERIAL_LOG5(i, SERIAL_F(". "), SERIAL_F(k), SERIAL_SEPAR_V, v) }
  #define SERIAL_VALUE_TELEPLOT(k, v)                                          \
    { SERIAL_CHAIN4(SERIAL_F(">"), SERIAL_F(k), SERIAL_F(":"), v) SERIAL_LINE }
  #define SERIAL_CHANGE(k, o, n)                                               \
    { SERIAL_LOG5(SERIAL_F(k), SERIAL_SEPAR_V, o, SERIAL_F(" -> "), n) }
  #define SERIAL_ACTION(s)                                                     \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.print(SERIAL_F(s));                                               \
    }
  #define SERIAL_ACTION_VALUE(s)                                               \
    {                                                                          \
      Serial.print(SERIAL_F(SERIAL_PREFIX));                                   \
      Serial.print(SERIAL_SEPAR_H);                                            \
      Serial.print(SERIAL_F(s));                                               \
      Serial.print(SERIAL_SEPAR_V);                                            \
    }
  #define SERIAL_ACTION_END(s)                                                 \
    {                                                                          \
      Serial.println(SERIAL_F(s));                                             \
    }
  #define SERIAL_ACTION_END_CHAIN(s)                                           \
    {                                                                          \
      Serial.print(SERIAL_F(s));                                               \
    }
  #define SERIAL_DELIM                                                         \
    {                                                                          \
      Serial.println(SERIAL_F("---"));                                         \
    }
  #define SERIAL_DOT                                                           \
    {                                                                          \
      Serial.print(SERIAL_F("."));                                             \
    }
#else
  #define SERIAL_SEPAR_V
  #define SERIAL_PRINTLN(p)
  #if defined(ESP32)
    #define SERIAL_PRINTLN_FMT(p, f)
  #endif
  //
  #define SERIAL_LOG1(p1)
  #if defined(ESP32)
    #define SERIAL_LOG1_FMT(p1, f)
  #endif
  #define SERIAL_LOG2(p1, p2)
  #define SERIAL_LOG3(p1, p2, p3)
  #define SERIAL_LOG4(p1, p2, p3, p4)
  #define SERIAL_LOG5(p1, p2, p3, p4, p5)
  #define SERIAL_LOG6(p1, p2, p3, p4, p5, p6)
  //
  #define SERIAL_CHAIN1(p1)
  #define SERIAL_CHAIN2(p1, p2)
  #define SERIAL_CHAIN3(p1, p2, p3)
  #define SERIAL_CHAIN4(p1, p2, p3, p4)
  #define SERIAL_CHAIN5(p1, p2, p3, p4, p5)
  #define SERIAL_CHAIN6(p1, p2, p3, p4, p5, p6)
  //
  #define SERIAL_LINE
  #define SERIAL_BEGIN(b)
  #define SERIAL_TITLE(s)
  #define SERIAL_VALUE(k, v)
  #if defined(ESP32)
    #define SERIAL_VALUE_FMT(k, v, f)
  #endif
  #define SERIAL_VALUE_UNIT(k, v, u)
  #define SERIAL_VALUE_TELEPLOT(k, v)
  #define SERIAL_CHANGE(k, o, n)
  #define SERIAL_ACTION(s)
  #define SERIAL_ACTION_VALUE(s)
  #define SERIAL_VALUE_INDEX(i, k, v)
  #define SERIAL_ACTION_END(s)
  #define SERIAL_ACTION_END_CHAIN(s)
  #define SERIAL_DELIM
  #define SERIAL_DOT
#endif

#endif
