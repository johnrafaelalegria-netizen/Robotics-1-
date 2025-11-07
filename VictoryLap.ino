//lap arouiund the table
//declaring values
const int AIN1 = 7; //directon Motor A
const int BIN1 = 8; //direction Motor B
const int PWMA = 5; //speed for Motor A
const int PWMB = 6; //speed for Motor B
const int STNDBY = 3; //standby ON or OFF

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(AIN1,OUTPUT);//digital AIN1
pinMode(BIN1,OUTPUT);//digital BIN1
pinMode(PWMA,OUTPUT);//analog PWMA
pinMode(PWMB,OUTPUT);//analog PWMB
pinMode(STNDBY,OUTPUT);//digital standby
}

void loop() {
  // put your main code here, to run repeatedly:
forward(100);
delay(10000);
stop();
delay(1000);
right(100);
delay(300);
forward(100);
delay(4000);
stop();
delay(1000);
right(100);
delay(400);
}

//forward function
void forward(byte speed){
digitalWrite(7,1);//AIN1 forward
digitalWrite(8,1);//BIN1 forward
analogWrite(PWMA,speed);//PWMA speed max
analogWrite(PWMB,speed);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//stop function
void stop(){
digitalWrite(AIN1,1);//AIN1 forward
digitalWrite(BIN1,1);//BIN1 forward
analogWrite(PWMA,0);//PWMA speed max
analogWrite(PWMB,0);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//backward function
void backward(byte speed){
digitalWrite(AIN1,0);//AIN1 forward
digitalWrite(BIN1,0);//BIN1 forward
analogWrite(PWMA,speed);//PWMA speed max
analogWrite(PWMB,speed);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//left function
void left(byte speed){
digitalWrite(AIN1,1);//AIN1 forward
digitalWrite(BIN1,0);//BIN1 forward
analogWrite(PWMA,speed);//PWMA speed max
analogWrite(PWMB,speed);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//right function
void right(byte speed){
digitalWrite(AIN1,0);//AIN1 forward
digitalWrite(BIN1,1);//BIN1 forward
analogWrite(PWMA,speed);//PWMA speed max
analogWrite(PWMB,speed);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//left forward function
void leftForward(byte speed){
digitalWrite(AIN1,1);//AIN1 forward
digitalWrite(BIN1,1);//BIN1 forward
analogWrite(PWMA,speed);//PWMA speed max
analogWrite(PWMB,speed/2);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//right forward function
void rightForward(byte speed){
digitalWrite(AIN1,1);//AIN1 forward
digitalWrite(BIN1,1);//BIN1 forward
analogWrite(PWMA,speed/2);//PWMA speed max
analogWrite(PWMB,speed);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//left backward
void leftBackward(byte speed){
digitalWrite(AIN1,0);//AIN1 forward
digitalWrite(BIN1,0);//BIN1 forward
analogWrite(PWMA,speed);//PWMA speed max
analogWrite(PWMB,speed/2);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}

//right backwards
void rightBackward(byte speed){
digitalWrite(AIN1,0);//AIN1 forward
digitalWrite(BIN1,0);//BIN1 forward
analogWrite(PWMA,speed/2);//PWMA speed max
analogWrite(PWMB,speed);//PWMB speed max
digitalWrite(STNDBY,1);//standby ON
}
