void setup() {
  pinMode(6, OUTPUT); //Sygnał PWM silnika nr 1
  //Ustawiamy (na stałe) stan wysoki na pinie 6

  pinMode(7, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(8, OUTPUT);
  digitalWrite(7, LOW); //Silnik nr 1 - obroty w lewo
  digitalWrite(8, HIGH);
}

void loop()  {
  for (int i = 0; i < 256; i++) {
    analogWrite(6, i); 
    delay(25); 
    digitalWrite(7, LOW); //Silnik nr 1 - obroty w lewo
    digitalWrite(8, HIGH);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(6, i); 
    delay(25); 
    digitalWrite(7, HIGH); //Silnik nr 1 - obroty w lewo
    digitalWrite(8, LOW);
  }
}

