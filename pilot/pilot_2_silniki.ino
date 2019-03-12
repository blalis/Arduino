#include <IRremote.h>
#define pilot 2
#define silnik1 7
#define silnik2 12
#define lewo1 6
#define prawo1 5
#define lewo2 9
#define prawo2 10
IRrecv irrecv(pilot);
decode_results signals;
long sygnal = 0;
long sygnal_prev = 0;
int pred = 150;
int pred_zmiana = 10;
int pred_min = 0;
float pred_maks = 255;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(silnik1, OUTPUT);
  pinMode(silnik2, OUTPUT);
  digitalWrite(silnik1, HIGH); //Enable1
  digitalWrite(silnik2, HIGH); //Enable2
  pinMode(prawo1, OUTPUT);
  pinMode(lewo1, OUTPUT);
  pinMode(prawo2, OUTPUT);
  pinMode(lewo2, OUTPUT);
  digitalWrite(prawo1, 0);
  digitalWrite(lewo1, 0);
  digitalWrite(prawo2, 0);
  digitalWrite(lewo2, 0);
}
void loop() {
  if (sygnal != 0 || irrecv.decode(&signals)) {
    sygnal = signals.value;
    if (sygnal == 0xFF30CF)
    {
      sygnal_prev = 0xFF30CF;
      while (sygnal == 0xFF30CF || sygnal == 0xFFFFFFFF)
      {
        if (irrecv.decode(&signals)) {
          sygnal = signals.value;
          irrecv.resume();
        }
        digitalWrite(prawo1, 0);
        analogWrite(lewo1, pred);
        digitalWrite(prawo2, 0);
        analogWrite(lewo2, pred);
      }
    }
    else if (sygnal == 0xFF18E7)
    {
      sygnal_prev = 0xFF18E7;
      while (sygnal == 0xFF18E7 || sygnal == 0xFFFFFFFF)
      {
        if (irrecv.decode(&signals)) {
          sygnal = signals.value;
          irrecv.resume();
        }
        analogWrite(prawo1, pred);
        digitalWrite(lewo1, 0);
        analogWrite(prawo2, pred);
        digitalWrite(lewo2, 0);
      }
    }
    else if (sygnal == 0xFF10EF)
    {
      if (pred >= pred_zmiana)
        pred -= pred_zmiana;
      signals.value = sygnal_prev;
    }
    else if (sygnal == 0xFF38C7)
    {
      if (pred <= 255 - pred_zmiana)
        pred += pred_zmiana;
      signals.value = sygnal_prev;
    }
    else if (sygnal == 0xFF42BD)
    {
      pred = pred_min;
      signals.value = sygnal_prev;
    }
    else if (sygnal == 0xFF4AB5)
    {
      pred = pred_maks;
      signals.value = sygnal_prev;
    }
    else
    {
      digitalWrite(prawo1, 0);
      digitalWrite(lewo1, 0);
      digitalWrite(prawo2, 0);
      digitalWrite(lewo2, 0);
      sygnal = 0;
      sygnal_prev = 0;
    }
    irrecv.resume();
  }
}



