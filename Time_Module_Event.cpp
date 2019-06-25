#include "Time_Module_Event.h"
void Set_Year(uint8_t year1,uint8_t year2)
{
	int y1 = year1 - ZERO;
	int y2 = year2 - ZERO;
	int year;
	if (y2 < 0)
	{
		y2 = 0;
		year = y1;
	}
	else
	{
		year = y1 * 10 + y2;
	}
		Serial.println(year);
	RTC.set(RTC_YEAR, year);
}
void Set_Month(uint8_t month1, uint8_t month2)
{
	int m1 = month1 - ZERO;
	int m2 = month2 - ZERO;
	int month;
	if (m2 < 0)
	{
		m2 = 0;
		month = m1;
	}
	else
	{
		month = m1 * 10 + m2;
	}
		Serial.println(month);
	RTC.set(RTC_MONTH, month);
}
void Set_Day(uint8_t day1, uint8_t day2)
{
	int d1 = day1 - ZERO;
	int d2 = day2 - ZERO;
	int day;
	if (d2 < 0)
	{
		d2 = 0;
		day = d1;
	}
	else
	{
		day = d1 * 10 + d2;
	}
		Serial.println(day);
	RTC.set(RTC_DAY, day);
}
void Set_Hour(uint8_t hour1, uint8_t hour2)
{
	int h1 = hour1 - ZERO;
	int h2 = hour2 - ZERO;
	int hour;
	if (h2 < 0)
	{
		h2 = 0;
		hour = h1;
	}
	else
	{
		hour = h1 * 10 + h2;
	}
		Serial.println(hour);
	RTC.set(RTC_HOUR,hour);
}
void Set_Minute(uint8_t minute1, uint8_t minute2)
{
	int m1 = minute1 - ZERO;
	int m2 = minute2 - ZERO;
	int minute;
	if (m2 < 0)
	{
		m2 = 0;
		minute = m1;
	}
	else
	{
		minute = m1 * 10 + m2;
	}
		Serial.println(minute);
	RTC.set(RTC_MINUTE, minute);
}
void Set_Second(uint8_t second1, uint8_t second2)
{
	int s1 = second1 - ZERO;
	int s2 = second2 - ZERO;
	int second;
	if (s2 < 0)
	{
		s2 = 0;
		second = s1;
	}
	else
	{
		second = s1 * 10 + s2;
	}
		Serial.println(second);
	RTC.set(RTC_SECOND, second);
}