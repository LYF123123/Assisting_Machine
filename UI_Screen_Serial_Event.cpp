#pragma once
#include "UI_Screen_Serial_Event.h"
#include "Time_Module_Event.h"


bool Screen_Step_Motor_Stop_Event(uint8_t buff[SIZE])
{

	if ((buff[0] == STOP[0]) && (buff[1] == STOP[1]) && (buff[2] == STOP[2]) && (buff[3] == STOP[3]) && (buff[4] == NONE))
	{
		//Serial.println("789789");
		digitalWrite(LED_ON_BOARD, HIGH);
		delay(3000);
		digitalWrite(LED_ON_BOARD, LOW);
		delay(3000);
		return true;
	}
	else
	{
		return false;
	}
}
void Screen_Get_Time()
{
	DateTime now = RTC.now();
	String year(now.year());
	Serial.print("pageMain.timeyear.txt=\"" + year + "年\"");
	Serial.write(END, 3);
	Serial.print("pageMain.vayear.val=");
	Serial.print(now.year());
	Serial.write(END, 3);

	String month(now.month());
	Serial.print("pageMain.timemonth.txt=\"" + month + "月\"");
	Serial.write(END, 3);
	Serial.print("pageMain.vamonth.val=");
	Serial.print(now.month());
	Serial.write(END, 3);

	String day(now.day());
	Serial.print("pageMain.timeday.txt=\"" + day + "日\"");
	Serial.write(END, 3);
	Serial.print("pageMain.vaday.val=");
	Serial.print(now.day());
	Serial.write(END, 3);
	// Weekday is automatic setting
	String weekday;
	switch (now.dayOfWeek())
	{
	case 0:
		weekday = String("天");
		break;
	case 1:
		weekday = String("一");
		break;
	case 2:
		weekday = String("二");
		break;
	case 3:
		weekday = String("三");
		break;
	case 4:
		weekday = String("四");
		break;
	case 5:
		weekday = String("五");
		break;
	case 6:
		weekday = String("六");
		break;
	default:
		// Error!!
		break;
	}



	Serial.print("pageMain.timeweekday.txt=\"星期" + weekday + "\"");
	Serial.write(END, 3);

	String hour(now.hour());
	Serial.print("pageMain.timehour.txt=\"" + hour + "时\"");
	Serial.write(END, 3);
	Serial.print("pageMain.vahour.val=");
	Serial.print(now.hour());
	Serial.write(END, 3);

	String minute(now.minute());
	Serial.print("pageMain.timeminute.txt=\"" + minute + "分\"");
	Serial.write(END, 3);
	Serial.print("pageMain.vaminute.val=");
	Serial.print(now.minute());
	Serial.write(END, 3);

	String second(now.second());
	Serial.print("pageMain.timesecond.txt=\"" + second + "秒\"");
	Serial.write(END, 3);
	Serial.print("pageMain.vasecond.val=");
	Serial.print(now.second());
	Serial.write(END, 3);
	delay(1000);
}

void Screen_Set(uint8_t buff[SIZE])
{
	if ((buff[0]==YEAR[0])&&(buff[1]==YEAR[1])&&(buff[2]==YEAR[2])&&(buff[3]==YEAR[3]))
	{
		Set_Year(buff[4],buff[5]);
	}
	if ((buff[0] == MONTH[0]) && (buff[1] == MONTH[1]) && (buff[2] == MONTH[2]) && (buff[3] == MONTH[3]))
	{
		Set_Month(buff[4], buff[5]);
	}
	if ((buff[0] == DAY[0]) && (buff[1] == DAY[1]) && (buff[2] == DAY[2]) && (buff[3] == DAY[3]))
	{
		Set_Day(buff[4], buff[5]);
	}
	if ((buff[0] == HOUR[0]) && (buff[1] == HOUR[1]) && (buff[2] == HOUR[2]) && (buff[3] == HOUR[3]))
	{
		Set_Hour(buff[4], buff[5]);
	}
	if ((buff[0] == MINUTE[0]) && (buff[1] == MINUTE[1]) && (buff[2] == MINUTE[2]) && (buff[3] == MINUTE[3]))
	{
		Set_Minute(buff[4],buff[5]);
	}
	if ((buff[0] == SECOND[0]) && (buff[1] = SECOND[1]) && (buff[2] == SECOND[2]) && (buff[3] == SECOND[3]))
	{
		Set_Second(buff[4], buff[5]);
	}
}