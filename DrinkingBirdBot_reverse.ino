//#include <Stepper.h>

#include <AccelStepper.h>

AccelStepper stepper(1, 9, 8);
int pos = 90;


void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(3000);
  stepper.setAcceleration(1000);
}

void loop() {
  
    Serial.println(-pos);
  if (stepper.distanceToGo() == 0)
  {
    if (pos > 0)
       delay(5000);
    else
       delay(1000);

    
    pos = -pos;
    if (pos > 0)
    {
      
      stepper.setMaxSpeed(60);
      stepper.setAcceleration(100);
    }
    else
    {
      
        stepper.setMaxSpeed(200);
        stepper.setAcceleration(100);
    }
    
    
    stepper.moveTo(40 + (2 * -pos));
  }
  stepper.run();
}
