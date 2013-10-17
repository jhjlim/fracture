#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
//#include <SPI.h>

TMRpcm tmrpcm;   // create an object for use in this sketch
int Flag = 0;
int sampleCycle = 0;
void setup(){

  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  //tmrpcm.play("01.WAV"); //the sound file "music" will play each time the arduino powers up, or is reset

  pinMode(2, INPUT);
}



void loop(){  
  if((digitalRead(2) == HIGH) && (Flag == 0)){
    Flag = 1;
    if(sampleCycle == 0){
    tmrpcm.play("01.WAV");
    }else if(sampleCycle == 1){
      tmrpcm.play("02.WAV");
    }else if(sampleCycle == 2){
      tmrpcm.play("03.WAV");
    }
    
  }
  if((digitalRead(2) == LOW) && (Flag == 1)){
    sampleCycle = sampleCycle++;
    if(sampleCycle > 2){
      sampleCycle = 0;
    }
    Flag = 0;
  }
}
