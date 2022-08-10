#include"Ma_Year.h"

int Ma_Year::fnLeapYear(int nNum)
/*
此函数传入的整数型年份做判断,判断是平年还是闰年
参数1 : 传入的整型年份
返回值 : 值为1时,表示闰年,为0时表示平年
*开发者 : 马志强
*开发日期:2022.4.28
*维护者 : 马志强
*维护日期:2022.4.28
*/
{
	if ((nNum % 4 == 0 && nNum % 100 != 0) || nNum % 400 == 0)
	{
		return 1;
	}
	return 0;
}

int Ma_Year::fnYearStart(int nYear, int nMonth, int nDay)
/*
此函数传入年份、月份及日期,判断日期是当年的哪一天(当天计算)
参数1 : 传入的年份
参数2 : 传入的月份
参数3 : 传入的日期
返回值 : 返回星期几,值为-1时,表示输入有误
*开发者 : 马志强
*开发日期:2022.4.29
*维护者 : 马志强
*维护日期:2022.4.29
*/
{
	int nNum[13] = { 31,28,31,30,31,30,31,31,30,31,30,31,0 };
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		nNum[1] = 29;
	}
	if (nMonth > 12 || (nNum[nMonth - 1] < nDay) || nYear < 0 || nMonth < 1 || nDay < 1)
	{
		return -1;
	}
	for (int i = 1; i < nMonth; i++)
	{
		nNum[12] += nNum[i - 1];
	}
	return nNum[12] += nDay;
}

int Ma_Year::fnYearEnd(int nYear, int nMonth, int nDay)
/*
此函数传入年份、月份及日期,判断日期距离年尾还有几天(当天不计算)
参数1 : 传入的年份
参数2 : 传入的月份
参数3 : 传入的日期
返回值 : 返回星期几,值为-1时,表示输入有误
*开发者 : 马志强
*开发日期:2022.4.29
*维护者 : 马志强
*维护日期:2022.4.29
*/
{
	int nNum[13] = { 31,28,31,30,31,30,31,31,30,31,30,31,0 };
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		nNum[1] = 29;
	}
	if (nMonth > 12 || (nNum[nMonth - 1] < nDay) || nYear < 0 || nMonth < 1 || nDay < 1)
	{
		return -1;
	}
	for (int i = nMonth; i < 12; i++)
	{
		nNum[12] += nNum[i - 1];
	}
	return nNum[12] += (nNum[nMonth - 1] - nDay);
}

int Ma_Year::fnWhatday(int nYear, int nMonth, int nDay)
/*
此函数传入年份、月份及日期,判断传入的日期为星期几
参数1 : 传入的年份
参数2 : 传入的月份
参数3 : 传入的日期
返回值 : 返回星期几,为-1时,表示计算失败
*开发者 : 马志强
*开发日期:2022.5.1
*维护者 : 马志强
*维护日期:2022.5.1
*/
{
	if (nMonth == 1 || nMonth == 2)
	{
		nMonth += 12;
		nYear--;
	}
	int nNum = -1;
	nNum = (nDay + 2 * nMonth + 3 * (nMonth + 1) / 5 + nYear + nYear / 4 - nYear / 100 + nYear / 400) % 7 + 1;
	return nNum;
}
