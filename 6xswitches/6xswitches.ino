// Six switches to MIDI: breaking the connection triggers a sound
// To connect to Max/MSP

int switches[] = {0, 0, 0, 0, 0, 0};
#include <MIDIUSB.h>
MIDIEvent e;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(i + 2, INPUT_PULLUP);
  }
}

void loop() {
  for (int i=0; i < 6; i++) {
    int value = digitalRead(i + 2);
    
    // uncomment the line below to invert the values
    // int value = 1 - digitalRead(i + 2);
    
    if (value != switches[i]){
      Serial.print("switch");
      Serial.print( i);
      Serial.print(" ");
      Serial.println(value);
      switches[i] = value;

      e.m1 = 176; //label as cc, channel 1
      e.m2 = i; //cc lane from sensor index number   
      e.m3 = switches[i]; //set the value from the sensor
      e.type = 11; 
                      
      MIDIUSB.write(e);
      
    }
    
  }

}
