#include <Servo.h>
int echoPin=2;
int trigPin=3;
int buzzerPin=13;
int lightPin=A1;
int servoPin=5;
int ledRed=11;
int ledBlue=10;
int ledGreen=9;
int tempPin=A2;
int red = 0;
int blue=0;
int green=0;
long duration; 
int distance=25;
Servo myservo; 
int pos = 0;
int shadow=0;
int temp=0;
float mv;
float cel;

void setup()
{ 
  myservo.attach(servoPin);
  myservo.write(pos);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(lightPin, INPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  Serial.begin(9600);
}

void colour(int r, int g, int b)
{
  red=r;
  green=g;
  blue=b;
}
void tempercheck() //Temperature to colour
  {
  temp=analogRead(tempPin);
   mv = ( temp/1024.0)*5000;
   cel = mv/10;
  if(cel>=40)
  {
    colour(0,255,255);                       
  }
  else if(cel>=30)
  {
   colour(0,0,255);
  }
  else if(cel<30)
  {
   colour(255,0,255);
  }
  }
          
          
  void distcheck()
          {
  digitalWrite(trigPin, LOW); //DISTANCE SENSOR START
  delay(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // DISTANCE SENSOR END
    
          }

  void servosweep()
          {
            myservo.write(180);
            delay(350);
             myservo.write(0);
            delay(350);
          }
 void loop()
{ colour(0,0,0);
   
  
 shadow=analogRead(lightPin);
 if(shadow>500)
 {
   colour(0,0,0);
   analogWrite(ledRed,red);
   analogWrite(ledGreen,green);
   analogWrite(ledBlue,blue);
   tone(13,3000);
   digitalWrite(ledRed,HIGH);
   
   delay(1000);
   digitalWrite(ledRed,LOW);
   
   noTone(13);
   delay(1000); 
   
 }
 distcheck();
 if(distance<20 && shadow<500)
 { tone(13,3000);
   servosweep();
   noTone(13);
   delay(350);
 }
 if(shadow<=500)
 { colour(0,0,0);
   tempercheck();
   analogWrite(ledRed,red);
   analogWrite(ledGreen,green);
   analogWrite(ledBlue,blue);
   
 }
 Serial.println(shadow);

}
