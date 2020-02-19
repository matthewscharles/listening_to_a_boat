int switches[] = {0, 0, 0, 0, 0, 0};
#include <MIDIUSB.h>
MIDIEvent e;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(i + 2, INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i < 6; i++) {
    int value = digitalRead(i + 2);
//    uncomment the line below to invert the values
//    int value = 1 - digitalRead(i + 2);
    if (value != switches[i]){
      Serial.print("switch");
      Serial.print( i);
      Serial.print(" ");
      Serial.println(value);
      switches[i] = value;

        e.m1 = 176; //label as cc, channel 1
        e.m2 = i; //cc lane from sensor index number   
        e.m3 = switches[i]; //set the value from the sensor
        e.type = 8; //what is this again? I'm rusty
                      
        MIDIUSB.write(e);

      
    }
    
    
  }
  
  
  
}
