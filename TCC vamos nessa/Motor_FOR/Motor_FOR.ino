#include <Servo.h>

Servo servo1;
Servo servo2;
void setup()
{
  Serial.begin(9600);

  servo1.attach(6);
  servo2.attach(5);

  servo1.write(90);
}

void loop()
{
  for(int x = 0; x <= 80; x ++){
  	Serial.println(x);

    servo1.write(x);
    servo2.write(x);

    delay(10000);
  }
}