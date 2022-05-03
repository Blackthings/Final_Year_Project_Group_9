#include <XBOXUSB.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXUSB Xbox(&Usb);

// Initialising variables

//int RF_IN1 = 42;
//int RF_IN2 = 40;
int RF_pwm = 10; ////////////////////////

//int RB_IN1 = 42;
//int RB_IN2 = 40;
int RB_pwm = 11; /////////////////////

//int LF_IN1 = 42;
//int LF_IN2 = 40;
int LF_pwm = 12; //////////////////////////

//int LB_IN1 = 42;
//int LB_IN2 = 40;
int LB_pwm = 13;  ////////////////////

int weed_motor_pwm = 9; /////////////////////////
int weed_motor_spd = 50;

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXBOX USB Library Started"));

//pinMode(RF_IN1, OUTPUT);  
//pinMode(RF_IN2, OUTPUT);
pinMode(RF_pwm, OUTPUT);

//pinMode(RB_IN1, OUTPUT);  
//pinMode(RB_IN2, OUTPUT);
pinMode(RB_pwm, OUTPUT);

//pinMode(LF_IN1, OUTPUT);  
//pinMode(LF_IN2, OUTPUT);
pinMode(LF_pwm, OUTPUT);

//pinMode(LB_IN1, OUTPUT);  
//pinMode(LB_IN2, OUTPUT);
pinMode(LB_pwm, OUTPUT);

pinMode(7, OUTPUT); // Linear Actuator
pinMode(8, OUTPUT);

}


void loop() {
  Usb.Task();
  if (Xbox.Xbox360Connected) {
    if (Xbox.getButtonPress(L2)) 
    {
      Serial.print("L2: ");
      Serial.print(Xbox.getButtonPress(L2));
      weed_motor_spd = map(Xbox.getButtonPress(L2), 0, 255, 0, 80); ////////////////////////////
      weed_motor(weed_motor_spd, 1); //////////////////////////////////////////
      
      //Xbox.setRumbleOn(Xbox.getButtonPress(L2));
    } 
    
    else
      Xbox.setRumbleOn(0, 0);

     if( Xbox.getButtonPress(R2))
     {
      Serial.print("\tR2: ");
      Serial.println(Xbox.getButtonPress(R2));
      //Xbox.setRumbleOn(Xbox.getButtonPress(R2));
     }

    if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500 || Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500 || Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500 || Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
      if (Xbox.getAnalogHat(LeftHatX) > 7500 || Xbox.getAnalogHat(LeftHatX) < -7500) {
        Serial.print(F("LeftHatX: "));
        Serial.print(Xbox.getAnalogHat(LeftHatX));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500) {
        Serial.print(F("LeftHatY: "));
        Serial.print(Xbox.getAnalogHat(LeftHatY));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(RightHatX) > 7500 || Xbox.getAnalogHat(RightHatX) < -7500) {
        Serial.print(F("RightHatX: "));
        Serial.print(Xbox.getAnalogHat(RightHatX));
        Serial.print("\t");
      }
      if (Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
        Serial.print(F("RightHatY: "));
        Serial.print(Xbox.getAnalogHat(RightHatY));
      }
      Serial.println();
    }

    if (Xbox.getButtonClick(UP)) 
    {
      Xbox.setLedOn(LED1);
      Serial.println(F("Up"));
      front(80,1);
    }
    
    if (Xbox.getButtonClick(DOWN)) {
      Xbox.setLedOn(LED4);
      Serial.println(F("Down"));
      stop_bot();
    }
    if (Xbox.getButtonClick(LEFT)) 
    {
      Xbox.setLedOn(LED3);
      Serial.println(F("Left"));
      left(80,1);
    }
    if (Xbox.getButtonClick(RIGHT)) 
    {
      Xbox.setLedOn(LED2);
      Serial.println(F("Right"));
      right(80,1);
    }

    if (Xbox.getButtonClick(START)) {
      Xbox.setLedMode(ALTERNATING);
      Serial.println(F("Start"));
    }
    if (Xbox.getButtonClick(BACK)) {
      Xbox.setLedBlink(ALL);
      Serial.println(F("Back"));
    }
    if (Xbox.getButtonClick(L3))
      Serial.println(F("L3"));
    if (Xbox.getButtonClick(R3))
      Serial.println(F("R3"));

    if (Xbox.getButtonClick(L1))
      Serial.println(F("L1"));
    if (Xbox.getButtonClick(R1))
      Serial.println(F("R1"));
    if (Xbox.getButtonClick(XBOX)) {
      Xbox.setLedMode(ROTATING);
      Serial.println(F("Xbox"));
    }

    if (Xbox.getButtonClick(A))
      Serial.println(F("A"));
    if (Xbox.getButtonClick(B))
      Serial.println(F("B"));
    
    
    if (Xbox.getButtonClick(X))
    {
      Serial.println(F("X"));
       // Extend Linear Actuator
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
    }
    if (Xbox.getButtonClick(Y))
    {
      Serial.println(F("Y"));
        // Retracts Linear Actuator
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
    }
  }
  delay(1);
}
