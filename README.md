<a id="library"></a>
# gbjSerialDebug
Library defines preprocessor macro functions for serial debugging and writing to the serial port.


<a id="constants"></a>
## Constants
- **GBJ\_SERIAL\_DEBUG\_VERSION**: Name and semantic version of the library.
- **SERIAL\_DEBUG**: Defined this debugging macro determines, whether serial debugging should be used.
- **SERIAL\_NODEBUG**: Defined this debugging macro determines, that serial debugging should not be used. Definition of the previous macro constant has precedence.

*The debugging macros should be defined before inclusion of the library header file in a sketch in order to take them into effect.*

Those concept of debugging constants ensures that by default the debugging is active if none of those constants is defined. Exact debugging mode can be defined by defining respective macro.

Remaining constants are listed in the library include file. They are used mostly internally.


<a id="interface"></a>
## Interface
- All macro functions are called without trailing semicolon.
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
- **SERIAL\_VALUE(k, v)**: Flashes and prints the first string parameter and follows it with second parameter with EOL, e.g., `SEND_VALUE("Value", 85)`. The macro adds colon and space after the first parameter and forms key-value pair output.

#### Decoration macros
- **SERIAL\_LINE**: Prints empty line with EOL separating printing sections, e.g., `SERIAL_LINE`.
- **SERIAL\_DELIM**: Flashes and prints three dashes as a delimiter line and EOL for visual separating printing sections.
- **SERIAL\_DOT**: Flashes and prints dot without EOL for mimicking waiting for long lasting actions.
