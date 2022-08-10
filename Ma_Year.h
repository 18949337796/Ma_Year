#pragma once
#include<iostream>
using namespace std;


class Ma_Year
{
public:
	//闰年判断
	int fnLeapYear(int nNum);
	//年初到日期有几天
	int fnYearStart(int nYear, int nMonth, int nDay);
	//日期到年尾有几天
	int fnYearEnd(int nYear, int nMonth, int nDay);
	//某天是星期几
	int fnWhatday(int nYear, int nMonth, int nDay);
};
