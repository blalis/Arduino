#include <IRremote.h>
IRrecv irrecv(8);
decode_results signals;
long sygnal;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {
  if (sygnal != 0 || irrecv.decode(&signals)) {
    sygnal = signals.value;
    if (sygnal == 16724175)
    {
      while (signals.value == 16724175 || signals.value == 0xFFFFFFFF)
      {
        Serial.println("1");
        if (irrecv.decode(&signals)) {
          sygnal = signals.value;
          irrecv.resume();
        }
      }
    }
    else if (signals.value == 0xFF18E7)
    {
      while (sygnal == 0xFF18E7 || signals.value == 0xFFFFFFFF)
      {
        Serial.println("2");
        if (irrecv.decode(&signals)) {
          sygnal = signals.value;
          irrecv.resume();
        }
      }
    }
    else
      sygnal = 0;
    irrecv.resume();
  }
}

