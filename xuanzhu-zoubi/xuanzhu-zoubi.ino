/*                                  XUANZHU-ZOUBI
 *  This program is open source and follows the GPL3.0 protocol.
 *  If you think this program is helpful to you, please star this project on GitHub.
 *  Program written by Fried on May 22, 2022.
 */

//------------------The following is the main body of the program------------------


#include<Arduino.h>

#define LED 6 // LED connected to pin 2
#define ILPS1 2 // Infrared line patrol sensor (turn on the led)
#define ILPS2 4 // Infrared line patrol sensor (turn off the led)

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT); // set the digital pin as output
  pinMode(ILPS1, INPUT); // set the digital pin as input
  pinMode(ILPS2, INPUT); // set the digital pin as input
  digitalWrite(LED, LOW); // the LED is off by default
}

void loop()
{
  if(digitalRead(ILPS2) and (not digitalRead(ILPS1)))
  {
    digitalWrite(LED, HIGH); // turn on the led
    delay(300); // delay for 500 ms
  }
  else if(digitalRead(ILPS1) and (not digitalRead(ILPS2)))
  {
    digitalWrite(LED, LOW); // turn off the led
    delay(300); // delay for 500 ms
  }
}
