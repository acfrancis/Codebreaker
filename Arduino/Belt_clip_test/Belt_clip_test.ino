// Author: Reggie Jean-Brice
// Date: 4/18/2014
// Co Creator- Anthony Francis 
// Objective: Run a motor at relativly high speeds. Reduce the rpm to maker the motor complete a step faster. Change the step
// per rotation to add more full steps (3200=1 step)

#define EnablePin 8
#define dirpin 7
#define steppin 6 

long int StepsPerRotation = 3200*2; // Number of steps for a full rotation. at 1/16th micro stepping for our current motors its 3200 steps
int TimeDelay = 50; //sets the RPM
int StartDelay = 1000; //sets the delay before the motor turns after a reset
long int NumOfCycles = 100000; // number of cycles to run
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
    Motor_Run_Front();
    delayMicroseconds(100);
    Motor_Run_Back();
    y++;
  }

  Serial.println("Calibration Done");


}

void Motor_Run_Front()
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

void Motor_Run_Back()
{
  int x = 0;

  digitalWrite(EnablePin, LOW);
  digitalWrite(dirpin, HIGH); //motor enabled high

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





