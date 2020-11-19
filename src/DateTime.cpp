#include "DateTime.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string.h>

string lowRegister(char* buf)
{
    char buf2[50] = { '\0' };
    for (int i = 0; i < strlen(buf); i++)
        if (buf[i] >= 'A' && buf[i] <= 'Z')
            buf2[i] = buf[i] + 32;
        else
            buf2[i] = buf[i];
    return buf2;
}

string DateTime::getToday() const
{
    char buf[50];
    time_t now;
    time(&now);
    tm* t_info = localtime(&now);
    mktime(t_info);
    strftime(buf, 50, "%d %B %Y, %A", t_info);
    return lowRegister(buf);
}

string DateTime::getYesterday() const
{
    return getPast(1);
}

string DateTime::getTomorrow() const
{
    return getFuture(1);
}

string DateTime::getFuture(u_int N) const
{
    char buf[50];
    tm t_info = date;
    t_info.tm_mday = t_info.tm_mday + N;
    mktime(&t_info);
    strftime(buf, 50, "%d %B %Y, %A", &t_info);
    return lowRegister(buf);
}

string DateTime::getPast(u_int N) const
{
    char buf[50];
    tm t_info = date;
    t_info.tm_mday = t_info.tm_mday - N;
    mktime(&t_info);
    strftime(buf, 50, "%d %B %Y, %A", &t_info);
    return lowRegister(buf);
}

int DateTime::getDifference(DateTime& another) 
{
    u_int diff = abs(mktime(&another.date) - mktime(&date));
    return int(diff / (24 * 60 * 60));
}

DateTime::DateTime(u_int day, u_int month, u_int year)
{
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    date.tm_sec = 0;
    date.tm_min = 0;
    date.tm_hour = 0;
    mktime(&date);
}

DateTime::DateTime()
{
    time_t now;
    time(&now);
    tm* t_info = localtime(&now);
    date = *t_info;
    mktime(&date);
}
DateTime::DateTime(DateTime& another)
{
    date = another.date;
}
