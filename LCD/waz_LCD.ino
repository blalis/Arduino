#include <LiquidCrystal.h>
LiquidCrystal wys(13,12,11,10,9,8);
byte wazogon[8] = {
  B00000,
  B00000,
  B00000,
  B01111,
  B11111,
  B01111,
  B00000,
  B00000,
};
byte waz[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
};
byte wazglowa[8] = {
  B00000,
  B00000,
  B11100,
  B10110,
  B11111,
  B10110,
  B11100,
  B00000,
};
byte wejscie[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
};
byte wejscie2[8] = {
  B11111,
  B00000,
  B11100,
  B10110,
  B11110,
  B10110,
  B11100,
  B11111,
};
byte wejscie3[8] = {
  B11111,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B00000,
  B11111,
};
byte wejscie4[8] = {
  B11111,
  B00000,
  B00000,
  B01111,
  B11111,
  B01111,
  B00000,
  B11111,
};
byte pelny[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};
void setup() {
  wys.clear();
  wys.createChar(0,wazogon);
  wys.createChar(1,waz);
  wys.createChar(2,wazglowa);
  wys.createChar(3,wejscie);
  wys.createChar(4,pelny);
  wys.createChar(5,wejscie2);
  wys.createChar(6,wejscie3);
  wys.createChar(7,wejscie4);
  wys.begin(16,2);
  wys.setCursor(8,1);
  wys.write(byte(3));
  for(int i=9;i<16;i++){
    wys.setCursor(i,1);
    wys.write(byte(3));
  }

}
void loop() {int dl=6,kryj=8;
for(int i=1;i<=32-dl+1;i++){ 
  
  for(int j=0;j<dl;j++){
  if(i+j<17) wys.setCursor(i+j-1,0);
  else wys.setCursor(i+j-17,1);
  if(i+j<26 && j==0) wys.write(byte(0));
  else if(i+j<26 && j>0 && j<dl-1)
  wys.write(byte(1));
  else if(i+j<26 && j==dl-1) wys.write(byte(2));
  else if(i+j>=26 && j==0){ wys.write(byte(7));
  if(i+j>=27){
  wys.setCursor(i+j-18,1); wys.write(byte(3));}}
  else if(i+j>=26 && j>0 && j<dl-1)
  wys.write(byte(6));
  else if(i+j>=26 && j==dl-1) wys.write(byte(5));
  } delay(300); czysc(dl,i);}
  
/*  for(int i =0;i<=10;i++){
    wys.setCursor(i,1);
    wys.print(i);}   */
    
}
void snake(int znak,int dl){

  for(int i=0;i<dl;i++){
    if(znak+i<=16 && znak+i>0)
      wys.setCursor(znak+i-1,0);
    else if(znak<=32)
      wys.setCursor(znak+i-17,1);
    if(i==0)
      wys.write(byte(0));
    else if(i<dl-1)
      wys.write(byte(1));
    else
      wys.write(byte(2));
  }
} 
void snake2(int znak,int dl){
  for(int i=0;i<dl;i++){
    if(znak+i<=16 && znak+i>0)
      wys.setCursor(znak+i-1,0);
    else if(znak<=32)
      wys.setCursor(znak+i-17,1);
    if(i==0)
      wys.write(byte(0));
    else if(i<dl-1)
      wys.write(byte(1));
    else
      wys.write(byte(2));
  }

}
void czysc(int dlugosc,int licz){
  for(int i=0;i<16;i++){
    for(int j=0;j<2;j++){
      if(j==0 || (j==1 && i<=8 && licz<32-dlugosc+1))
        wys.setCursor(i,j);
      wys.print(" ");
    }
  }
}





