// This file is used to set the parameters (eg: PIN,delay_time etc...).
//===================================================================================
// Warning: On Arduino Mega2560, some PINs are used for Serial communication.
// Serial<DEFAULT> PIN: 1(RX),2(TX)
// Serial<ONE> PIN: 19(RX),18(TX)
// Serial<TWO> PIN: 17(RX),16(TX)
// Serial<THREE> PIN: 15(RX),14(TX)
//===================================================================================
// On Mks Gen Mega2560, 42 Stepper Motor can use three kinds of motor drivers.  
// 1) DRV8825
//===================================================================================
//| 1  | 2  | 3  |                step mode
//-----------------------------------------------------------------------------------
//| 0  | 0  | 0	 | Full step (2-phase excitation) with 71% current  |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 0  |      1/2 step (1-2 phase excitation)             |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 0  |      1/4 step (W1-2 phase excitation)            |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 0  |         8 microsteps/step                        |
//-----------------------------------------------------------------------------------
//| 0  | 0  | 1  |         16 microsteps/step                       |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 1  |         32 microsteps/step                       |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 1  |         32 microsteps/step                       |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 1  |         32 microsteps/step                       |
//===================================================================================
// 2) A4988
//===================================================================================
//| 1  | 2  | 3  |                step mode                         |
//-----------------------------------------------------------------------------------
//| 0  | 0  | 0  |                Full step                         |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 0  |                1/2 step                          |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 0  |                1/4 step                          |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 0  |              8 microsteps/step                   |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 1  |              16 microsteps/step                  |
//===================================================================================
// 3) TMC 2208
//| 1  | 2  | 3  |                step mode                         |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 0  |                  2 step                          |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 0  |                  4 step                          |
//-----------------------------------------------------------------------------------
//| 0  | 0  | 0  |                  8 step                          |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 0  |                  16 step                         |
//===================================================================================
// More information can be found on https://reprap.org/wiki/MKS_GEN#Motor_Driver
//===================================================================================
// Thanks to the MKS.
// Writen down on 2019/3/28 by LYF
#pragma once
#include "Arduino.h"	// Arduino's Standard header file
#include <Wire.h>
#include <RTClib.h>
const RTC_DS1307 RTC;
// Set the PIN.
const int LED_ON_BOARD = 13;
// Set the ordinary switch
const int Switch_Stop = 4;
const int Switch_Stop_Trigger_State = LOW;	// Default Trigger State
// Set the Limit Switch
const int Limit_Switch1 = 45;	
const int Limit_Switch1_Trigger_State = HIGH;	// Default Trigger State
const int Limit_Switch2 = 3;
const int Limit_Switch2_Trigger_State = HIGH;	// Default Trigger State
// Step Motor 1.
const int Step_Motor1_En = 62;
const int Step_Motor1_Dir = 48;
const int Step_Motor1_Step = 46;
// Step Motor 2.
const int Step_Motor2_En = 38;
const int Step_Motor2_Dir = 55;
const int Step_Motor2_Step = 54;
// Set special global variable.
// Use the next Integer variables use for EEPROM address.
const int Volume_Address = 0;
// Use the next Integer variable to set the volume.(0-30).
const int Default_Volume = 15;
// Use the next integer variable to set the size of the Serial's buff.
const int SIZE = 64;
// Use the next two Bool variables to change the default Step Motor dir.
// true is forward direction, false is reverse direction.
const int Step_Motor1_Initialize_Dir = LOW;//?????????
const int Step_Motor1_Work_Dir = HIGH;
const int Step_Motor2_Initialize_Dir = LOW;
const int Step_Motor2_Work_Dir = HIGH;
// Use the next Integer variable to make sure the two Step Motor is Synchronization.
// Use the next two __int64 variables to set the loop times for the two Step Motor.
// In Full step, 42 Step Motor rotate a circle need 200 pulses, because each pulse provide 1.8бу rotation.
const int64_t Step_Motor1_Initialize_Loop_Times = 10000;
const int64_t Step_Motor1_Loop_Times = 14000;	// 1/4 loop
const int64_t Step_Motor2_Loop_Times = 37000;	// 33000 1/4 loop

// Set global variable.
// Use the next four Integer variables to control the High pulses and the low pulses.
const int Step_Motor1_HIGH_Delayms = 400;
const int Step_Motor1_LOW_Delayms = 400;
const int Step_Motor2_HIGH_Delayms = 400;
const int Step_Motor2_LOW_Delayms = 400;
inline void Initialize_PIN()
{
	pinMode(Limit_Switch1, INPUT_PULLUP);
	pinMode(Limit_Switch2, INPUT_PULLUP);
	pinMode(Switch_Stop, INPUT_PULLUP);

	pinMode(Step_Motor1_En, OUTPUT);
	pinMode(Step_Motor1_Dir, OUTPUT);
	pinMode(Step_Motor1_Step, OUTPUT);

	pinMode(Step_Motor2_En, OUTPUT);
	pinMode(Step_Motor2_Dir, OUTPUT);
	pinMode(Step_Motor2_Step, OUTPUT);

	pinMode(LED_ON_BOARD, OUTPUT);
}
