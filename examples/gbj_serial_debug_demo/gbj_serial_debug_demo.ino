/*
  NAME:
  Demonstration usage of gbjSerialDebug library.

  DESCRIPTION:
  The sketch writes to the serial monitor with help of debugging macros.

  LICENSE:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the MIT License (MIT).

  CREDENTIALS:
  Author: Libor Gabaj
*/
#define SKETCH "GBJ_SERIAL_DEBUG_DEMO 1.0.0"

// #define SERIAL_NODEBUG
#include "gbj_serial_debug.h"

void setup()
{
  SERIAL_BEGIN(9600)
  SERIAL_TITLE(SKETCH)
  SERIAL_TITLE("Libraries:")
  SERIAL_TITLE(GBJ_SERIAL_DEBUG_VERSION)
  SERIAL_DELIM
}

void loop()
{
  SERIAL_TITLE("TEST - Value pairs")
  for (byte i = 1; i <= 5; i++)
  {
    SERIAL_VALUE("Round", i)
    SERIAL_VALUE_UNIT("Length", i, "m")
    delay(1000);
  }
  //
  SERIAL_ACTION("TEST - Long action")
  for (byte i = 0; i < 5; i++)
  {
    SERIAL_DOT
    delay(500);
  }
  SERIAL_TITLE("completed")
  //
  SERIAL_TITLE("TEST - Chaining")
  SERIAL_CHAIN4(1, "/", 2, "/")
  SERIAL_TITLE("3")
  SERIAL_LINE
}
