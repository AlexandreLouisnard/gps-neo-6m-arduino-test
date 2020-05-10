/**
 * 1. WIRING
 *  * Arduino Nano :
 *    - Neo-6M
 *     - Vcc : Arduino +5V
 *      - GND : Arduino GND
 *     - RXD : Arduino D2
 *     - TXD : Arduino D3 (WARNING : logical level for Neo-6M should be 3V, not 5V. Otherwise do not connect)
 *  * STM32duino :
 *   - Neo-6M
 *     - Vcc : STM32 +3.3V
 *     - GND : STM32 GND
 *     - RXD : STM32 A9
 *     - TXD : STM32 A10
 * 
 * 2. Uncomment the correct platform in platform.ini
 * 3. Uncomment the correct define below
 */
// #define ARDUINO_NANO
#define STM32


#include <Arduino.h>
#ifdef ARDUINO_NANO
#include <SoftwareSerial.h>
#endif

#ifdef ARDUINO_NANO
SoftwareSerial gpsSerial(2, 3); // create gps sensor connection
#endif

void setup()
{
  Serial.begin(9600);
  delay(3000);
  Serial.println("setup start");

#ifdef ARDUINO_NANO
  gpsSerial.begin(9600);
#endif

#ifdef STM32
  Serial1.begin(9600);
#endif

  Serial.println("setup end");
}

void loop()
{
#ifdef ARDUINO_NANO
  while (gpsSerial.available() > 0)
  {
    // get the byte data from the GPS
    byte gpsData = gpsSerial.read();
    Serial.write(gpsData);
  }
#endif

#ifdef STM32
  while (Serial1.available() > 0)
  {
    // get the byte data from the GPS
    byte gpsData = Serial1.read();
    Serial.write(gpsData);
  }
#endif
}