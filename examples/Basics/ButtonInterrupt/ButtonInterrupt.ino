/*
 * Monitor button state using interrupts mechanism.
 *
 * App dashboard setup:
 *   LED on V1
 */

#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <BlynkSimpleEthernet.h>

void setup()
{
  Serial.begin(9600);
  Blynk.begin("YourAuthToken");

  // Make pin 2 HIGH by default
  pinMode(2, INPUT_PULLUP);
  // Attach INT to our handler
  attachInterrupt(0, checkPin, CHANGE);
}

void checkPin()
{
  // Invert state, since button is "Active LOW"
  int state = !digitalRead(2);
  Blynk.virtualWrite(1, state);
}

void loop()
{
  Blynk.run();
}
