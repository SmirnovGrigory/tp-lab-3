#include "DateTime.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	DateTime a;
	DateTime b(31, 12, 2020);
	cout << b.getTomorrow()<<endl<<a.getPast(400)<<endl<<a.getYesterday();
}