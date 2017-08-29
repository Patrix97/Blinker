#include <DmxSimple.h>

uint8_t universe[512];
void setup(){
  Serial.begin(9600);
  DmxSimple.usePin(1); //To be changed, as soon as an Arduino is Available
}

void loop(){
  while(Serial.available()){
    for(int i = 0; i < 512; i++){
      universe[i] = Serial.read();
    }
    break;
  }

  for(int j = 0; j < 512; j++){
    DmxSimple.write(j+1, universe[j]);
  }
}

