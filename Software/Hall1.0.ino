const int hallSensorPin = 2;                      // connect the hall effect sensor on pin 2
const unsigned long calculationTime = 6000;
int rpmMaximum = 0;

void setup() 
{
  pinMode(hallSensorPin,INPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{
  int rpm = getRPM();
  displayRPM(rpm);
}
 
int getRPM()
{
  int count = 0;
  boolean countFlag = LOW;
  unsigned long currentTime = 0;
  unsigned long startTime = millis();
  while (currentTime <= calculationTime)
  {
    if (digitalRead(hallSensorPin) == HIGH)
    {
      countFlag = HIGH;
    }
    if (digitalRead(hallSensorPin) == LOW && countFlag == HIGH)
    {
      count++;
      countFlag=LOW;
    }
    currentTime = millis() - startTime;
  }
  int countRpm = int(60000/float(calculationTime))*count;
  return countRpm;
}
    
void displayRPM(int rpm) 
{
  Serial.print("RPM = ");
  Serial.print(rpm);
 Serial.print("\n ");  
}
