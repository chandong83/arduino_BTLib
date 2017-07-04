#include "AsulBT.h"
//for joystick
#define TOLERANCE   10
#define CENTER_POS  510
#define IS_CENTER(x) ((x >= (CENTER_POS-TOLERANCE))&&(x <= (CENTER_POS+TOLERANCE)))

AsulBT bt;
JOYSTICK_DATA joyData;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
    if(bt.update() == CMD_JOYSTICK)
    {
      if(bt.readJoystick(&joyData))
      {        
        Serial.print(joyData.xAxis);        
        Serial.print(",");        
        Serial.print(joyData.yAxis);      
        Serial.print(",");         
        Serial.println(joyData.btn);
      }
    }    
}
