# arduino_BTLib
arduino_bluetooth libarary


HC-05 or 06 모듈 사용할때 사용하면 좋을듯 하여 만듬

통신패킷처리는 
https://github.com/oroca/oroca_rov/tree/master/Software/Arduino/RovMain_Leo
https://github.com/oroca/oroca_rov/blob/master/Software/Arduino/RovMain_Leo/RSP.cpp
가져다 사용

TX Test Code
<pre><code>
#include "AsulBT.h"

AsulBT bt;
JOYSTICK_DATA joyData;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   //read the joystick data
    int posX = analogRead(0);
    int posY = analogRead(1);
    
    joyData.xAxis = posX;     
    joyData.yAxis = posY;
    bt.writeJoystick(joyData);
    delay(10);
}
</code></pre>
