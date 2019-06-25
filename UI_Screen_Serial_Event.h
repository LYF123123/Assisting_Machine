// UI Screen use the Serial 0 On Arduino Mks Gen Mega2560
#pragma once
#include "Configuration.h"
// Because my UI Screen uses GB2313/GBK coding, So I have to use the GB2313/GBK coding in my program
// "STOP" in Chinese equals "停止"
// GB2313/GBK coding about "停止" = {0xCD, 0xA3, 0xD6, 0xB9};
const uint8_t STOP[4] = { 0xCD, 0xA3, 0xD6, 0xB9 };
// 设置
const uint8_t SETTING[4] = { 0xC9,0xE8,0xD6,0xC3 };
// 返回
const uint8_t RETURN[4] = { 0xB7,0xB5,0xBB,0xD8 };
// 启动
const uint8_t START[4] = { 0xC6,0xF4,0xB6,0xAF };
// 复位
const uint8_t RESET[4] = { 0xB8,0xB4,0xCE,0xBB };
// 年份
const uint8_t YEAR[4] = { 0xC4,0xEA,0xB7,0xDD };
// 月份
const uint8_t MONTH[4] = { 0xD4,0xC2,0xB7,0xDD };
// 日期
const uint8_t DAY[4] = {0xC8,0xD5,0xC6,0xDA};
// 小时
const uint8_t HOUR[4] = { 0xD0,0xA1,0xCA,0xB1 };
// 分钟
const uint8_t MINUTE[4] = { 0xB7,0xD6,0xD6,0xD3 };
// 秒数
const uint8_t SECOND[4] = { 0xC3,0xEB,0xCA,0xFD };
//音量
const uint8_t VOLUME[4] = { 0xD2,0xF4,0xC1,0xBF };
// NONE
const uint8_t NONE = 0;
// When you send message to the UI Screen through the Serial,
// you must add the "END" at the end of the sentence.
const unsigned char END[3] = { 0xff, 0xff, 0xff };
// Example:
// Serial.print("<The sentence> ");
// Serial.write(END, 3);
// Serial.print("hour.txt=\"你好\"");
// Serial.write(END, 3);


void Initialize_Event();

bool Screen_Step_Motor_Stop_Event(uint8_t buff[SIZE]);
// All the next functions used in the main loop().
void Screen_Get_Time();	// auto
// void Screen_Send_Message();  // GSM
// void Screen_Set_Message();	// GSM
void Screen_Set(uint8_t buff[SIZE]);