#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();



String mare;
String arat;
String mij;
String inel;
String mic;

  void setup() {
  Serial.begin(115200);
  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);

  delay(10);

  pwm.setPWM(0,0,260);
}

  void loop() {
    while(Serial.available()==0)
    {
        pinMode(LED_BUILTIN,OUTPUT);
    }

mare = Serial.readStringUntil('\r');
if(mare == "1")    
   {pwm.setPWM(0,0,260);
   digitalWrite(LED_BUILTIN,HIGH);}
if(mare == "0")    
   {pwm.setPWM(0,0,400);
    digitalWrite(LED_BUILTIN,LOW);}

arat  =  Serial.readStringUntil('\r');
if(arat == "1")    
   pwm.setPWM(4,0,150);
if(arat == "0")    
   pwm.setPWM(4,0,320);

mij  =  Serial.readStringUntil('\r');
if(mij == "1")    
   pwm.setPWM(3,0,210);
if(mij == "0")    
   pwm.setPWM(3,0,376);

inel  =  Serial.readStringUntil('\r');
if(inel == "1")    
   pwm.setPWM(2,0,200);
if(inel == "0")    
   pwm.setPWM(2,0,330);

mic  =  Serial.readStringUntil('\r');
if(mic == "1")    
   pwm.setPWM(1,0,310);
if(mic == "0")    
   pwm.setPWM(1,0,510);


  }




   



  