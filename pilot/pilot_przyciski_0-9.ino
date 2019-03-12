#include <IRremote.h>
IRrecv irrecv(8);
decode_results signals;
long sygnal = 0;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {
  if (sygnal != 0 || irrecv.decode(&signals)) {
    sygnal = signals.value;
    przycisk(sygnal);
    irrecv.resume();
  }
}
void przycisk(long syg)
{
  long signal = syg;
  while (signal == syg || sygnal == 0xFFFFFFFF)
  {
    switch (signal)
    {
      case 0xFF30CF:
        Serial.println("1");
        break;
      case 0xFF18E7:
        Serial.println("2");
        break;
      case 0xFF7A85:
        Serial.println("3");
        break;
      case 0xFF10EF:
        Serial.println("4");
        break;
      case 0xFF38C7:
        Serial.println("5");
        break;
      case 0xFF5AA5:
        Serial.println("6");
        break;
      case 0xFF42BD:
        Serial.println("7");
        break;
      case 0xFF4AB5:
        Serial.println("8");
        break;
      case 0xFF52AD:
        Serial.println("9");
        break;
      default:
        sygnal = 0;
        break;
    }
    if (irrecv.decode(&signals)) {
      syg = signals.value;
      sygnal = signals.value;
      irrecv.resume();
    }
  }
}

