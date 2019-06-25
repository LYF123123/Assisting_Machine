/*
 Name:		Living_Assisting_Machine.ino
 Created:	2019/3/27 20:38:17
 Author:	Luyifeng
 E-mail:    luyifeng3@163.com
*/
//===========================================================================
// Special thanks to MKS and my work group.
// Hardware designed by other member in my group.
//===========================================================================
#pragma once
#include "Step_Motor_Group.h"
#include "UI_Screen_Serial_Event.h"
Step_Motor_Group *step_motor_group = new Step_Motor_Group();
// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin(115200);
	Wire.begin();
	RTC.begin();
	Initialize_PIN();
	//step_motor_group->Reset_Step_Motor();	// Initialize Step_Motor ?!
}

// the loop function runs over and over again until power down or reset
void loop()
{
	while (Serial.available() > 0)
	{
		uint8_t buff_out[SIZE] = { 0 };
		Serial.readBytes(buff_out, SIZE);
		// Check State ?!
	
		// if RESET
		if ((buff_out[0] == RESET[0]) && (buff_out[1]==RESET[1]) && (buff_out[2]==RESET[2]) && (buff_out[3]==RESET[3]) && (buff_out[4]==NONE))
		{
			Serial.println("RESET");
			buff_out[SIZE] = { 0 };
			step_motor_group->Initialize_Step_Motor();
			break;
		}
		// if START
		if ((buff_out[0]==START[0]) && (buff_out[1]==START[1]) && (buff_out[2]==START[2]) && (buff_out[3]==START[3]) && (buff_out[4]==NONE))
		{
			Serial.println("START");
			buff_out[SIZE] = { 0 };
			step_motor_group->Step_Motor_Work();
			break;
		}
		// if SETTING
		if ((buff_out[0]==SETTING[0]) && (buff_out[1]==SETTING[1]) && (buff_out[2]==SETTING[2]) && (buff_out[3]==SETTING[3]) && (buff_out[4]==NONE))
		{
			bool flag = false;
			Serial.println("SETTING");
			while (true)
			{
				while (Serial.available()>0)
				{
					uint8_t buff_inside[SIZE] = { 0 };
					Serial.readBytes(buff_inside, SIZE);
					if ((buff_inside[0] == RETURN[0]) && (buff_inside[1] == RETURN[1]) && (buff_inside[2] == RETURN[2]) && (buff_inside[3] == RETURN[3]) && (buff_inside[4] == NONE))
					{
						Serial.println("RETURN");
						flag = true;
						break;
					}
					Screen_Set(buff_inside);
				}
				if (flag == true)
				{
					break;
				}
			}
			Serial.println("OUTLOOP");
			buff_out[SIZE] = { 0 };
		}
	}
	Screen_Get_Time();//Auto Refresh Time from the "DS1307" 
}
