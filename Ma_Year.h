#pragma once
#include<iostream>
using namespace std;


class Ma_Year
{
public:
	//�����ж�
	int fnLeapYear(int nNum);
	//����������м���
	int fnYearStart(int nYear, int nMonth, int nDay);
	//���ڵ���β�м���
	int fnYearEnd(int nYear, int nMonth, int nDay);
	//ĳ�������ڼ�
	int fnWhatday(int nYear, int nMonth, int nDay);
};
