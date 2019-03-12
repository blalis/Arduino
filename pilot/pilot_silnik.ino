#include <IRremote.h>
IRrecv irrecv(8);
decode_results signals;
long sygnal = 0;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); //Enable1
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
}
void loop() {
  if (sygnal != 0 || irrecv.decode(&signals)) {
    sygnal = signals.value;
    if (sygnal == 0xFF30CF)
    {
      while (sygnal == 0xFF30CF || sygnal == 0xFFFFFFFF)
      {
        if (irrecv.decode(&signals)) {
          sygnal = signals.value;
          irrecv.resume();
        }
        digitalWrite(6, 1);
        digitalWrite(7, 0);
      }
    }
    else if (sygnal == 0xFF18E7)
    {
      while (sygnal == 0xFF18E7 || sygnal == 0xFFFFFFFF)
      {
        if (irrecv.decode(&signals)) {
          sygnal = signals.value;
          irrecv.resume();
        }
        digitalWrite(6, 0);
        digitalWrite(7, 1);
      }
    }
    else
    {
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      sygnal = 0;
    }
    irrecv.resume();
  }
}

