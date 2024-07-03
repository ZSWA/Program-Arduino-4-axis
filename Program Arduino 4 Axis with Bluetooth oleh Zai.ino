#include <Servo.h>

#define servo1 6
#define servo2 3
#define servo3 10
#define servo4 5

Servo mservo1, mservo2, mservo3, mservo4;

int pos = 0;
char Incoming_value = 0;
char usechar = "0";

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  mservo1.attach(servo1); // 170-50
  mservo2.attach(servo2); // 0-60-180
  mservo3.attach(servo3); // 50-180
  mservo4.attach(servo4); // 0-150

  //default servo position
  mservo1.write(100); //up-down
  mservo2.write(60); //left-right
  mservo3.write(80); //forward-back
  mservo4.write(150); //clamp
}

int srv1 = 100;
int srv2 = 60;
int srv3 = 80;
int srv4 = 150;

void loop() 
{

  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();
    Serial.println(Incoming_value);
    usechar = Incoming_value;
  }

  if(usechar=='0')
  {
    
  }
  
  if(usechar=='A')
  {
    if(srv1<180)
    {
      srv1++;
      mservo1.write(srv1);
      
      delay(10);
     }
  }
  
  if(usechar=='B')
  {
    if(srv1>50)
    {
      srv1--;
      mservo1.write(srv1);
      
      delay(10);
     }
  }

  if(usechar=='C')
  {
    if(srv2<180)
    {
      srv2++;
      mservo2.write(srv2);
      
      delay(10);
     }
  }

  if(usechar=='D')
  {
    if(srv2>0)
    {
      srv2--;
      mservo2.write(srv2);
      
      delay(10);
     }
  }

  if(usechar=='G')
  {
    if(srv3<190)
    {
      srv3++;
      mservo3.write(srv3);
      
      delay(10);
     }
   }
   
   if(usechar=='J')
   {
    if(srv3>60)
    {
      srv3--;
      mservo3.write(srv3);
      
      delay(10);
     }
   }

   //-----

   if(usechar=='F')
  {
    if(srv4<160)
    {
      srv4++;
      mservo4.write(srv4);
      
      delay(10);
     }
   }
   
   if(usechar=='I')
   {
    if(srv4>0)
    {
      srv4--;
      mservo4.write(srv4);
      
      delay(10);
     }
   }

   
      
}