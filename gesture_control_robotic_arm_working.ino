#include <Servo.h>
const int trigl = 7;
const int echol = 6;
const int trigr = 12;
const int echor = 11;

long durl;
int distl;
long durr;
int distr;
Servo base;
Servo mid;
Servo fr;
int psb = 0;    
int psm = 0;
int psf = 0;
int c =0;
void setup() {
  pinMode(trigl, OUTPUT); // Sets the trigPin as an Output
pinMode(echol, INPUT); // Sets the echoPin as an Input
pinMode(trigr, OUTPUT); // Sets the trigPin as an Output
pinMode(echor, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);
base.attach(3);
mid.attach(9);
fr.attach(10);//pwm pins

}
void loop()
{
  //base.write(90);
  left();
  right(); 
  delay(500);
  if(distl<40 && distr>100)//left
  {
    /*for(psb=90;psb<=166;psb=psb+2)//reset the angles if required.
    {
      base.write(psb);
      delay(30);
      
    }*/
    base.write(45);
    Serial.println("left");
  }
  else if(distl>100 && distr<40)//right
  {
    /* for(psb=90;psb>=14;psb=psb-2)
    {
      base.write(psb);
      delay(30);
    }*/
    base.write(135);
     Serial.println("right");
  }
  else if(distl<40 && distr<40)
  {
    c++;
    if(c==1 || c==2)
    {
      Serial.println("down");
      
    }
    else if(c==3 || c==4)
    {
      Serial.println("capture");
    }
    else if(c==5 || c==6)
    {
      Serial.println("up");
    }
    else if(c==7 || c==8)
    {
      Serial.println("release");
    }
  }
  if(c==9)
  {
    c=0;
  }
 /* else
  {
    base.write(90);//default position of the base 
  }*/
}
void left()
{
  digitalWrite(trigl, LOW);
  delayMicroseconds(2);

 digitalWrite(trigl, HIGH);
delayMicroseconds(10);
digitalWrite(trigl, LOW);
durl = pulseIn(echol, HIGH);
delayMicroseconds(2);
distl= (durl/2)/29.1;
delayMicroseconds(2);
//Serial.print("Distance:left ");
//Serial.println(distl);
}
void right()
{
   digitalWrite(trigr, LOW);
  delayMicroseconds(2);
  digitalWrite(trigr, HIGH);
delayMicroseconds(10);
digitalWrite(trigr, LOW);
durr = pulseIn(echor, HIGH);
delayMicroseconds(2);
distr= (durr/2)/29.1;
delayMicroseconds(2);
//Serial.print("Distance:right ");
//Serial.println(distr);

}

