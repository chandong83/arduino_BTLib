#include "AsulBT.h"

AsulBT bt;
JOYSTICK_DATA joyData;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
    int ret = bt.update();
    
    if(ret < 0)
      return;
    
    switch(ret)
    {
      case CMD_JOYSTICK:
        if(bt.readJoystick(&joyData))
        {        
          Serial.print(joyData.xAxis);        
          Serial.print(",");        
          Serial.print(joyData.yAxis);      
          Serial.print(",");         
          Serial.println(joyData.btn);
        }
       break;
       default:
       break;
    }    
}
