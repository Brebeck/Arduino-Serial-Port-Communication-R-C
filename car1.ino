#include <AFMotor.h>
#include <Servo.h>

Servo left;
Servo right;
Servo steer;
int buff;
int SPEED = 125;
long lastMotor = 0;

AF_DCMotor motors[4] = {
  AF_DCMotor (1),
  AF_DCMotor (2),
  AF_DCMotor (3),
  AF_DCMotor (4)
  };


  void setup(){
   // Serial.begin(115200);
    Serial1.begin(9600);

    steer.attach(40);
    for(int x = 0; x < 4; x++) motors[x].setSpeed(SPEED);
    Serial.print("Initialized");
  }

void loop(){
  if(Serial1.available()) buff = Serial1.read();
  else buff = 0;
  if(buff == 'w'){
    for(int x = 0; x < 4; x++) motors[x].run(FORWARD);
  }
  else if(buff == 's'){
    //Serial.println("BACKWARD");
    for(int x = 0; x < 4; x++) motors[x].run(BACKWARD);
  }
  else if(buff == 'z'){
    for(int x = 0; x < 4; x++) motors[x].run(RELEASE);
  }
  if(buff == 'a'){
    //Serial.println("LEFT");
    if(steer.read()!= 60) steer.write(60);
  }  
  else if(buff == 'd'){
   // Serial.println("RIGHT");
    if(steer.read()!= 120) steer.write(120);
  }
  else if(buff == 'z'){
    if(steer.read() != 90) steer.write(90);
  }
  else if(buff == 'c'){
    if(SPEED != 145 && SPEED < 145){
      SPEED += 10;
      for(int x = 0; x < 4; x++) motors[x].setSpeed(SPEED);
    }
  }
   else if(buff == 'x'){
     if(SPEED != 5 && SPEED > 5){
       SPEED -= 10;
       for(int x = 0; x < 4; x++) motors[x].setSpeed(SPEED);
     }
   }
}
