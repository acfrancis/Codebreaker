// Author: Reggie Jean-Brice
// Date: 4/18/2014
// Objective: Very Basic code to get nX motor drivers up and running

#define EnablePin 8
#define dirpin 7
#define steppin 6 

long int StepsPerRotation = 3200; // Number of steps for a full rotation. at 1/16th micro stepping for our current motors its 3200 steps
int TimeDelay = 400; //sets the RPM
int StartDelay = 1000; //sets the delay before the motor turns after a reset
int NumOfCycles = 1; // number of cycles to run
int y = 0;

void setup() 
 {
    Serial.begin(9600);
    pinMode(dirpin,OUTPUT);
    pinMode(steppin,OUTPUT);
    pinMode(EnablePin,OUTPUT);
    
    digitalWrite(EnablePin, HIGH);   
}

void loop() 
{
  
  Serial.println("Calibration Started");
  delay(StartDelay);
  while (y < NumOfCycles)
  {
    Motor_Run();
    y++;
  }
  
  Serial.println("Calibration Done");
  

}

void Motor_Run()
{
  int x = 0;
  
  digitalWrite(EnablePin, LOW);
  digitalWrite(dirpin, LOW); //motor enabled low
  
  while (x <= StepsPerRotation)
  {
    digitalWrite(steppin, LOW);  
    digitalWrite(steppin, HIGH); 
   
    delayMicroseconds(TimeDelay);     
    x++;
  }
  
   digitalWrite(EnablePin, HIGH); //releases the motor  
   return;
}


 


