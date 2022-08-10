#include"Ma_Year.h"

int Ma_Year::fnLeapYear(int nNum)
/*
�˺��������������������ж�,�ж���ƽ�껹������
����1 : ������������
����ֵ : ֵΪ1ʱ,��ʾ����,Ϊ0ʱ��ʾƽ��
*������ : ��־ǿ
*��������:2022.4.28
*ά���� : ��־ǿ
*ά������:2022.4.28
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
�˺���������ݡ��·ݼ�����,�ж������ǵ������һ��(�������)
����1 : ��������
����2 : ������·�
����3 : ���������
����ֵ : �������ڼ�,ֵΪ-1ʱ,��ʾ��������
*������ : ��־ǿ
*��������:2022.4.29
*ά���� : ��־ǿ
*ά������:2022.4.29
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
�˺���������ݡ��·ݼ�����,�ж����ھ�����β���м���(���첻����)
����1 : ��������
����2 : ������·�
����3 : ���������
����ֵ : �������ڼ�,ֵΪ-1ʱ,��ʾ��������
*������ : ��־ǿ
*��������:2022.4.29
*ά���� : ��־ǿ
*ά������:2022.4.29
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
�˺���������ݡ��·ݼ�����,�жϴ��������Ϊ���ڼ�
����1 : ��������
����2 : ������·�
����3 : ���������
����ֵ : �������ڼ�,Ϊ-1ʱ,��ʾ����ʧ��
*������ : ��־ǿ
*��������:2022.5.1
*ά���� : ��־ǿ
*ά������:2022.5.1
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
