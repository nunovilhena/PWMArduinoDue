/*--------------------------------------------------------------------------------------------------------
  PWM_DUE EXAMPLE
  Authors: Nuno Vilhena
  https://github.com/nunovilhena
  This code is for an Arduino DUE with the aim of controlling its PWM channels.

  24/04/2018 v1.00
  new: started a new project.
  -------------------------------------------------------------------------------------------------------*/
/*Specifications:
  xxxx
  xxxx
  */

/*-------------------------------------------------------------------------------------------*/
//Includes libraries to perform specific tasks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pwm_due_lib.h"
/*-------------------------------------------------------------------------------------------
  ARDUINO DUE PIN CONNECTIONS
  D34 - PWM IGBT module 1 - TOP
  D35 - PWM IGBT module 1 - BOTTOM (complementary) (not activated)
  
  D36 - PWM IGBT module 2 - TOP
  D37 - PWM IGBT module 2 - BOTTOMP (complementary)
*/

//-------------------------------------------------------------------------------------------
#define PWM_FREQ 15000
#define N_CHANNELS 2

//variables
int PWM_MAX = 0; //PWM resolution
int PV_PWM_MAX = 0;
int PV_PWM_MIN = 0;
  
void setup() {
   
   SerialUSB.begin(9600);
   while(!SerialUSB);
    
  // put your setup code here, to run once:
  //set resolutions for analogue ports
  analogWriteResolution(12);  // set the analog output resolution to 12 bit (4096 levels)
  analogReadResolution(12);   // set the analog input resolution to 12 bit

  pinMode(13, OUTPUT);//Onboard LED
  digitalWrite(13, LOW);

  //setup PWM pins
  //2 pwm pins are activated, without sync functionality and 15kHz
  PWM_MAX = setup_pwm(N_CHANNELS , 0, PWM_FREQ);

  disable_comp(1); //complementary will be disable in module 1

  //define limits for PWM dutycycle
  PV_PWM_MAX = PWM_MAX*0.9;                  // the value for pwm duty cyle max = 90%
  PV_PWM_MIN = PWM_MAX*0.01;                  // the value for pwm duty cyle min = 10%

  Serial.print("Number of activated channels: ");
  Serial.println(N_CHANNELS);
  Serial.print("PWM FREQUENCY: ");
  Serial.println(PWM_FREQ);
  Serial.print("PWM MAX VALUE (100%)");
  Serial.println(PWM_MAX);
  Serial.println("************************************");
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  String s;
  int read_value;

  Serial.println("************************************");
  Serial.println("1 - Start PWM");
  Serial.println("2 - Stop PWM");
  Serial.println("3 - Update PWM CHANNEL 1");
  Serial.println("4 - Update PWM CHANNEL 2");
  Serial.println("************************************");
  
  while (!Serial.available()) {};
    s = Serial.readStringUntil(13);
    read_value = s.toInt();
    if (read_value == 1) {
      start_pwm(1);
      start_pwm(2);
      digitalWrite(13, HIGH);
    }else
    if (read_value == 2) {
      stop_pwm();
      digitalWrite(13, LOW);
    }else
    if (read_value == 3) {
        Serial.println("  PWM Duty-Cycle:");
        while (!Serial.available()) {};
        s = Serial.readStringUntil(13);
        read_value = s.toInt();
        
        updatePWM( 1, read_value);
    }else
    if (read_value == 4) {
        Serial.println("  PWM Duty-Cycle:");
        while (!Serial.available()) {};
        s = Serial.readStringUntil(13);
        read_value = s.toInt();
        
        updatePWM( 2, read_value);
    }
}
