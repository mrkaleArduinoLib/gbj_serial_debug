<a id="library"></a>
# gbj\_serial\_debug
Library defines preprocessor macro functions for serial debugging and writing to the serial port.


<a id="constants"></a>
## Constants

- **GBJ\_SERIAL\_DEBUG\_VERSION**: Name and semantic version of the library.
- **SERIAL\_NODEBUG**: Defining this macro determines, that serial debugging should not be used.
- **SERIAL\_PREFIX**: Macro defines a string, that is prefixed to logging outputs with internally define separator, which is `::`. The macro is useful for debugging output in application libraries. In order to avoid compilation warnings about redefining this macro, it is usefull to undefine it right before defining it again for the desired prefix.

> The debugging macros should be defined before inclusion of the library header file in a sketch in order to take them into effect.

```cpp
//#define SERIAL_NODEBUG
#undef SERIAL_PREFIX
#define SERIAL_PREFIX "mylib"
...
#include "gbj_serial_debug.h"
```


<a id="interface"></a>
## Interface

- All macro functions can be called without trailing semicolon. However, to omit problems with formatters, it is recommended to use them.
- Macro functions with parameters are called as ordinary C functions with braces.
- Macro functions without parameters are called without braces like macro constants.


#### System macros
- **SERIAL\_BEGIN(b)**: Starts serial port with baud speed as a parameter, e.g., `SERIAL_BEGIN(9600)`.
- **SERIAL\_F(s)**: Places string to the flash memory if the platform allows it, e.g., `send(SERIAL_F("Text"));`.


#### Login macros
- **SERIAL\_LOG1(p1)**: Prints one parameter on the separate line with EOL (end of line), e.g., `SEND_LOG1(123)`.
- **SERIAL\_LOG2(p1, p2)**: Prints both parameters on one separate line with EOL after the very last parameter, e.g., `SEND_LOG2("T=", 123)`.
- **SERIAL\_LOG3(p1, p2, p3)**: ditto
- **SERIAL\_LOG4(p1, p2, p3, p4)**: ditto
- **SERIAL\_LOG4(p1, p2, p3, p4, p5)**: ditto
- **SERIAL\_LOG6(p1, p2, p3, p4, p5, p6)**: ditto


#### Chain macros
- **SERIAL\_CHAIN1(p1)**: Prints one parameter on current line without EOL, e.g., `SEND_CHAIN1(123)`, which enables chaining multiple strings with macro. After chaining all strings it is useful to use some of login macros.
- **SERIAL\_CHAIN2(p1, p2)**: Prints both parameters on current line without EOL, e.g., `SEND_CHAIN2("T=", 123)`.
- **SERIAL\_CHAIN3(p1, p2, p3)**: ditto
- **SERIAL\_CHAIN4(p1, p2, p3, p4)**: ditto
- **SERIAL\_CHAIN4(p1, p2, p3, p4, p5)**: ditto
- **SERIAL\_CHAIN6(p1, p2, p3, p4, p5, p6)**: ditto


#### Debug macros
- **SERIAL\_TITLE(s)**: Flashes input string and prints it on the separate line with EOL, e.g., `SEND_TITLE("Start")`.
- **SERIAL\_ACTION(s)**: Flashes input string and prints it on the separate line without EOL. It is useful when another printing on the same line is expected, e.g., by waiting on connection and signaling it by dots.
- **SERIAL\_ACTION\_END(s)**: Continues by flashing input string to the recent line without prefixing the string. It finishes an action.
- **SERIAL\_VALUE(k, v)**: Flashes and prints the first string parameter (key) and follows it with second parameter (value) with EOL, e.g., `SEND_VALUE("Value", 85)`. The macro adds colon and space after the first parameter and forms key-value pair output.
- **SERIAL\_VALUE\_UNIT(k, v, u)**: Flashes and prints the first string parameter (key), follows it with second parameter (value), and appends the third string parameter (unit) with EOL, e.g., `SEND_VALUE_UNIT("Value", 85, "degC")`. The macro adds colon and space after the first parameter, space before the last parameter, and forms key-value-unit output.


#### Decoration macros
- **SERIAL\_LINE**: Prints empty line with EOL separating printing sections.
- **SERIAL\_DELIM**: Flashes and prints three dashes as a delimiter line and EOL for visual separating printing sections.
- **SERIAL\_DOT**: Flashes and prints dot without EOL for mimicking waiting for long lasting actions.
