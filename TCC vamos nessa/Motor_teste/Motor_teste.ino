#include <Servo.h>

Servo servo1;
Servo servo2;
void setup()
{
  servo2.attach(6);
  servo1.attach(5);
}

void loop()
{
 delay(3000);
 servo2.write(0);
 servo1.write(0);

 delay(3000);
 servo2.write(90);
 servo1.write(90);
   
 delay(3000); 
 servo2.write(180);
 servo1.write(180);
}