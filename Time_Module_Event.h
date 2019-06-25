// Time module use I2C On Arduino Mks Gen Mega2560
#pragma once
#include "Configuration.h"

// 1 means the Left 8 bits, 2 means the right 8 bits
const uint8_t ZERO = 0x30;
void Get_Time();
void Set_Year(uint8_t year1,uint8_t year2);
void Set_Month(uint8_t month1,uint8_t month2);
void Set_Day(uint8_t day1,uint8_t day2);
void Set_Hour(uint8_t hour1,uint8_t hour2);
void Set_Minute(uint8_t minute1,uint8_t minute2);
void Set_Second(uint8_t second1,uint8_t second2);