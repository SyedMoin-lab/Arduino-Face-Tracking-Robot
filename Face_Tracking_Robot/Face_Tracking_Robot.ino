// Arduino Face Tracking Robot
// Original Sketch Created By DFRobot.
// I modified the original sketch for this project.

/*
 * Choose communication mode define here:
 *    I2C_MODE    : I2C mode, default pin: MU_SDA <==> ARDUINO_SDA, MU_SCL <==> ARDUINO_SCL
 *    SERIAL_MODE : Serial mode, default pin: MU_TX <==> ARDUINO_PIN3, MU_RX <==> ARDUINO_PIN2
 */
#define I2C_MODE
//#define SERIAL_MODE

/*
 * Choose MU address here: 0x60, 0x61, 0x62, 0x63
 *        default address: 0x60
 */
#define MU_ADDRESS    0x60

#include <Arduino.h>
#include <MuVisionSensor.h>
#include <AFMotor.h>


#ifdef I2C_MODE
#include <Wire.h>
#endif
#ifdef SERIAL_MODE
#include <SoftwareSerial.h>
#define TX_PIN 2
#define RX_PIN 3
SoftwareSerial mySerial(RX_PIN, TX_PIN);
#endif
MuVisionSensor Mu(MU_ADDRESS);

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
  uint8_t err = 0;
#ifdef I2C_MODE
  Wire.begin();
  err = Mu.begin(&Wire);                                            // initialized MU on I2C port
#elif defined SERIAL_MODE
  mySerial.begin(9600);
  err = Mu.begin(&mySerial);                                        // initialized MU on soft serial port
#endif
  if (err == MU_OK) {
    Serial.println("MU initialized.");
  } else {
    do {
      Serial.println("fail to initialize MU! Please check protocol "
                     "version or make sure MU is working on the "
                     "correct port with correct mode.");
      delay(5000);
    } while (1);
  }
  // enable vision: body detect
  Mu.VisionBegin(VISION_BODY_DETECT);                         // enable vision body
}

void loop() {
  // put your main code here, to run repeatedly:
  long time_start = millis();

  // read result
  if (Mu.GetValue(VISION_BODY_DETECT, kStatus)) {                   // update vision result and get status, 0: undetected, other: detected
    Serial.println("vision body detected:");
    Serial.print("x = ");
    Serial.println(Mu.GetValue(VISION_BODY_DETECT, kXValue));       // get vision result: x axes value
    Serial.print("y = ");
    Serial.println(Mu.GetValue(VISION_BODY_DETECT, kYValue));       // get vision result: y axes value
    Serial.print("width = ");
    Serial.println(Mu.GetValue(VISION_BODY_DETECT, kWidthValue));   // get vision result: width value
    Serial.print("height = ");
    Serial.println(Mu.GetValue(VISION_BODY_DETECT, kHeightValue));  // get vision result: height value
 
    
    int xAxis = (Mu.GetValue(VISION_BODY_DETECT, kXValue));
    int yAxis = (Mu.GetValue(VISION_BODY_DETECT, kYValue));
    int distance = (Mu.GetValue(VISION_BODY_DETECT, kHeightValue));
    

    Serial.print("xAxis");
    Serial.println(xAxis);
    Serial.print("yAxis");
    Serial.println(yAxis);
    Serial.print("distance");
    Serial.println(distance);
   
    if (xAxis < 35) {
      motor1.setSpeed(140);
      motor1.run(FORWARD);
      motor2.setSpeed(140);
      motor2.run(BACKWARD);
      motor3.setSpeed(140);
      motor3.run(FORWARD);
      motor4.setSpeed(140);
      motor4.run(BACKWARD);
      //delay(10);
      
    }else if (xAxis > 65) {
      motor1.setSpeed(140);
      motor1.run(BACKWARD);
      motor2.setSpeed(140);
      motor2.run(FORWARD);
      motor3.setSpeed(140);
      motor3.run(BACKWARD);
      motor4.setSpeed(140);
      motor4.run(FORWARD);
      //delay(10);
      
    }else if (distance < 30) {
      motor1.setSpeed(130);
      motor1.run(FORWARD);
      motor2.setSpeed(130);
      motor2.run(FORWARD);
      motor3.setSpeed(130);
      motor3.run(FORWARD);
      motor4.setSpeed(130);
      motor4.run(FORWARD);
      //delay(10);

    }else if (distance > 60) {
      motor1.setSpeed(130);
      motor1.run(BACKWARD);
      motor2.setSpeed(130);
      motor2.run(BACKWARD);
      motor3.setSpeed(130);
      motor3.run(BACKWARD);
      motor4.setSpeed(130);
      motor4.run(BACKWARD);
      //delay(10);

    }else{
      motor1.setSpeed(0);
      motor1.run(RELEASE);
      motor2.setSpeed(0);
      motor2.run(RELEASE);
      motor3.setSpeed(0);
      motor3.run(RELEASE);
      motor4.setSpeed(0);
      motor4.run(RELEASE);
    }
  
    
  } else {
    Serial.println("vision body undetected.");
     motor1.setSpeed(0);
      motor1.run(RELEASE);
      motor2.setSpeed(0);
      motor2.run(RELEASE);
      motor3.setSpeed(0);
      motor3.run(RELEASE);
      motor4.setSpeed(0);
      motor4.run(RELEASE);
  }
  Serial.print("fps = ");
  Serial.println(1000/(millis()-time_start));
  Serial.println();
 //delay(500);
}
