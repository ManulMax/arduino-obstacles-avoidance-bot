#define lmf 11  //left motor forward digital pin11
#define lmb 10 //left motor backword digi pin 10
#define rmf 9  //right motor forward
#define rmb 6  //right motor backword

#define trigFront 5
#define echoFront 7 

#define trigLeft 4
#define echoLeft 3

#define trigRight 12
#define echoRight 8

long dis1,dis2,dis3,disF,disL,disR;

void setup() {
  Serial.begin(9600);
  pinMode(trigFront , OUTPUT);
  pinMode(trigLeft , OUTPUT);
  pinMode(trigRight , OUTPUT);
  pinMode(echoFront , INPUT);
  pinMode(echoLeft , INPUT);
  pinMode(echoRight , INPUT);

  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);

}

void loop() {
  digitalWrite(trigFront , LOW);
  delay(2);
  digitalWrite(trigFront , HIGH);
  delay(10);
  digitalWrite(trigFront , LOW);
  dis1=pulseIn(echoFront , HIGH);
  disF=cmconvert(dis1);
  
  digitalWrite(trigLeft , LOW);
  delay(2);
  digitalWrite(trigLeft , HIGH);
  delay(10);
  digitalWrite(trigLeft , LOW);
  dis2=pulseIn(echoLeft , HIGH);
  disL=cmconvert(dis2);
  
  digitalWrite(trigRight , LOW);
  delay(2);
  digitalWrite(trigRight , HIGH);   
  delay(10);
  digitalWrite (trigRight , LOW);
  dis3=pulseIn(echoRight , HIGH);
  disR=cmconvert(dis3);
 
delay(500);
  Serial.print("FRONT= ");
  Serial.println(disF);
  Serial.print("LEFT= ");
  Serial.println(disL);
  Serial.print("RIGHT= ");
  Serial.println(disR);


if(disF<10){
  stopbot();
  delay(10);
  if(disL<disR){
    turnright();
    delay(10);
    }
  else{
    turnleft();
    delay(10);
    }  
  }
else{
  forward();
  }
}

long cmconvert(long dis)
{
  return dis/29/2;
}

void stopbot(){
 analogWrite(rmf , 0);  
 analogWrite(rmb , 0); 
 analogWrite(lmb , 0); 
 analogWrite(lmf , 0); 
}

void turnleft()
{
     analogWrite(rmf , 200);  
     analogWrite(rmb , 0); 
     analogWrite(lmf , 0); 
     analogWrite(lmb , 200);  
     delay(100);
}

void turnright()
{
     analogWrite(rmf , 0);  
     analogWrite(rmb , 200); 
     analogWrite(lmf , 200); 
     analogWrite(lmb , 0);
     delay(100);  
}

void forward()
{
     analogWrite(rmf , 200);  
     analogWrite(rmb , 0); 
     analogWrite(lmf , 200); 
     analogWrite(lmb , 0);    
}
