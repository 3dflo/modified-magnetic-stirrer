/*
   RPM Informations: http://www.arduinotutorialonline.com/2017/12/a-simple-guide-to-using-hall-sensor.html
   Modbus https://github.com/Mrdayday/Online-submerged-photometer/blob/master/Software/Photometer.ino
   BlinkWithoutDelay from Arduino IDE
*/

#include <ModbusRtu.h>   // Modbus Package by smarmengol(Github)
#include <Servo.h> //Servo Package
Servo myServo;
// assign the Arduino pin that must be connected to RE-DE RS485 transceiver
#define TXEN  4  // Pinnumber for Modbus


Modbus slave(2, 0, TXEN); //Modbus object, Information about: Slave adress, Bus System (1=RS485), Connected PIN
uint16_t rotordata[3] = {0, 0, 0}; //Array for Modbus
/* Two currently used values and one free/blank
   rotordata[0]= Given speed by Master
   rotordata[1]= Current speed
   rotordata[2]= Availability Check; 0 -> standalone version
*/

// Fixed Falues
const unsigned long calculationTime = 6000; //Time between two RPM calculations

int potVal = 0;
int newpotVal = 0;
int angle;
long previousMillis = 0;        // will store last time LED was updated
//long calculationTime = 6000;           // calculationTime at which to blink (milliseconds)

//RPM Detection
const int hallSensorPin = 2;                      // connect the hall effect sensor on pin 2
int rpmDetected = 0;
int count = 0;
boolean countFlag = LOW;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); //defines output for Servo (9 and 10 available at Arduino)
  slave.begin(19200);
  Serial.begin(9600); //connection to console with Baud-number of 9600
  Serial.print("Please type in a number between 0 to 7! \"Kein Zeilenende\" has to be activated\n");
}

void loop() { //Main code
  unsigned long currentMillis = millis(); //Milliseconds for timer for specific actions
  slave.poll(rotordata, 3); //write and recive data
  if (digitalRead(hallSensorPin) == HIGH) //Hall Sensor is not near a magnet
  {
    countFlag = HIGH;
  }
  if (digitalRead(hallSensorPin) == LOW && countFlag == HIGH) // Hall Sensor is near a magnet after no magnet
  {
    count++;
    countFlag = LOW;
  }

  potVal = setRPM(&newpotVal); //New rpm setting

  //RPM calculation and sending to servo://
  if (currentMillis - previousMillis >= calculationTime) {
    // save the last time
    previousMillis = currentMillis;
    rpmDetected = int(60000 / float(calculationTime)) * count; //Calculation of RPM
    showRPM(rpmDetected);
    count = 0;
    if ((rpmDetected > potVal + 20 ) || (rpmDetected < potVal - 20)) {
      newpotVal = changeSpeed(rpmDetected, potVal, newpotVal);
    }
    potVal = newpotVal;
    angle = map(potVal, 700, 0, 0, 179); // Speed to Angle in the servo controller
    myServo.write(angle);
  }
}

int setRPM(int* newpotVal) {
  if (rotordata[2] != 0) //Availability Check
  {
    potVal = rotordata[1]; //Angle of the array rotordata[1]
    if (potVal == 0) { //If rpm set to 0 go to 0 direclty
      *newpotVal = 0;
      //Serial.print("new set RPM to 0= ");//for testing
      //Serial.print(*newpotVal);//for testing
    }
    return potVal;
  }
  else if (Serial.available() > 0) {
    potVal = Serial.read() - 48;
    if (potVal > 7 || potVal < 0) {
      Serial.print("Please type in a number between 0 to 7! \"Kein Zeilenende\" has to be activated\n");
    } else
    {
      if (potVal == 0) { //If rpm set to 0 go to 0 direclty
        *newpotVal = 0;
        //Serial.print("new set RPM to 0= ");//for testing
        //Serial.print(*newpotVal);//for testing
      }
      Serial.println((String)"RPM set to: " + potVal + "00");
      return potVal * 100;
    }
  }

  //Possible alternatives for different standalone version could be a potentiometer or a small keypad directly attached to the arduino
}

void showRPM(int rpm) // For debugging and checking the speed
{
  Serial.print("RPM = ");
  Serial.print(rpm);
  Serial.print("\n ");
}

//RPM change depending on real RPM//
int changeSpeed(int rpmDetected, int potVal, int newpotVal) {
  if (newpotVal < 700) {
    if (rpmDetected  < potVal) { //RPM is to low and needs to be higher
      potVal = newpotVal + 20;
      //Serial.print("new set RPM in backgroud= "); // For debugging and checking the speed
      //Serial.print(potVal);// For debugging and checking the speed
      //Serial.print("\n ");// For debugging and checking the speed
      return potVal;
    }
  }
  if (newpotVal > 0) {
    if (rpmDetected  > potVal) {
      potVal = newpotVal - 10; //RPM is to high and needs to be lower
      //Serial.print("new set RPM in backgroud= ");// For debugging and checking the speed
      //Serial.print(potVal);// For debugging and checking the speed
      //Serial.print("\n ");// For debugging and checking the speed
      return potVal;
    }
  }
}
