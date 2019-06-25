// Realize the functions in "Step_Motor_Group.h"
#pragma once
#include "Step_Motor_Group.h"
#include "UI_Screen_Serial_Event.h"
// private methods 
void Step_Motor_Group::Step_Motor_Open_Enable()
{
	digitalWrite(Step_Motor1_En, LOW);
	digitalWrite(Step_Motor2_En, LOW);
}
void Step_Motor_Group::Step_Motor_Close_Enable()
{
	digitalWrite(Step_Motor1_En, HIGH);
	digitalWrite(Step_Motor2_En, HIGH);
}
// public methods
Step_Motor_Group::Step_Motor_Group(const int initialize_dir1 = Step_Motor1_Initialize_Dir,
	const int work_dir1 = Step_Motor1_Work_Dir,
	const int initialize_dir2 = Step_Motor2_Initialize_Dir,
	const int work_dir2 = Step_Motor2_Work_Dir,
	const int64_t loop1 = Step_Motor1_Loop_Times,
	const int64_t loop2 = Step_Motor2_Loop_Times,
	const int high1_delayms = Step_Motor1_HIGH_Delayms,
	const int low1_delayms = Step_Motor1_LOW_Delayms,
	const int high2_delayms = Step_Motor2_HIGH_Delayms,
	const int low2_delayms = Step_Motor2_LOW_Delayms)
{
	this->m_step_motor1_initialize_dir = initialize_dir1;
	this->m_step_motor1_work_dir = work_dir1;
	this->m_step_motor2_initialize_dir = initialize_dir2;
	this->m_step_motor2_work_dir = work_dir2;
	this->m_step_motor1_loop_times = loop1;
	this->m_step_motor2_loop_times = loop2;
	this->m_step_motor1_high_delayms = high1_delayms;
	this->m_step_motor1_low_delayms = low1_delayms;
	this->m_step_motor2_high_delayms = high2_delayms;
	this->m_step_motor2_low_delayms = low2_delayms;
}
void Step_Motor_Group::Reset_Step_Motor()
{
	this->Step_Motor_Open_Enable();
	digitalWrite(Step_Motor1_Dir, m_step_motor1_work_dir);
	for (auto i = 0; i < Step_Motor1_Initialize_Loop_Times; ++i)
	{
		digitalWrite(Step_Motor1_Step, HIGH);
		delayMicroseconds(Step_Motor1_HIGH_Delayms);
		digitalWrite(Step_Motor1_Step, LOW);
		delayMicroseconds(Step_Motor1_LOW_Delayms);
	}
}

void Step_Motor_Group::Initialize_Step_Motor()
{
	bool stop = false;
	this->Step_Motor_Open_Enable();
	digitalWrite(Step_Motor2_Dir, m_step_motor2_initialize_dir);
	
	for (int64_t i = 0; i < Step_Motor2_Loop_Times; ++i)
	{
		if (digitalRead(Switch_Stop) == Switch_Stop_Trigger_State)
		{
			Serial.print("page pageMain");
			Serial.write(END, 3);
			Serial.print("page pageMain");
			Serial.write(END, 3);
			stop = true;
			break;
		}
		if (digitalRead(Limit_Switch2) == Limit_Switch2_Trigger_State)
		{
			Serial.print("page pageMain");
			Serial.write(END, 3);
			Serial.print("page pageMain");
			Serial.write(END, 3);
			stop = true;
			break;
		}
		while (Serial.available() > 0)
		{
			uint8_t buff[SIZE] = { 0 };
			Serial.readBytes(buff, SIZE);
			stop = Screen_Step_Motor_Stop_Event(buff);
			if (stop == true)
			{
				Serial.println("STOP");
				break;
			}
		}
		if (stop == true)
		{
			break;
		}
		digitalWrite(Step_Motor2_Step, HIGH);
		delayMicroseconds(Step_Motor2_HIGH_Delayms);
		digitalWrite(Step_Motor2_Step, LOW);
		delayMicroseconds(Step_Motor2_LOW_Delayms);
	}
}

void Step_Motor_Group::Step_Motor_Work()
{
	bool stop = false;
	this->Step_Motor_Open_Enable();
	digitalWrite(Step_Motor2_Dir, m_step_motor2_work_dir);
	for (int64_t i = 0; i < Step_Motor2_Loop_Times; ++i)
	{
		if (digitalRead(Switch_Stop) == Switch_Stop_Trigger_State)
		{
			Serial.print("page pageMain");
			Serial.write(END, 3);
			Serial.print("page pageMain");
			Serial.write(END, 3);
			stop = true;
			break;
		}
		while (Serial.available() > 0)
		{
			uint8_t buff[SIZE] = { 0 };
			Serial.readBytes(buff, SIZE);
			stop = Screen_Step_Motor_Stop_Event(buff);
			if (stop == true)
			{
				Serial.println("STOP");
				break;
			}
		}
		if (stop == true)
		{
			break;
		}
		digitalWrite(Step_Motor2_Step, HIGH);
		delayMicroseconds(Step_Motor2_HIGH_Delayms);
		digitalWrite(Step_Motor2_Step, LOW);
		delayMicroseconds(Step_Motor2_LOW_Delayms);
	}
}
