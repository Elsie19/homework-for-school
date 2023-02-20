#pragma once
#include <iostream>
class Time {
public:
	Time(int input_days, int input_hours, int input_minutes, int input_seconds) {
		days = input_days;
		hours = input_hours;
		minutes = input_minutes;
		seconds = input_seconds;
	}

	Time() {}
	
	int days = 0;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;

	Time operator+=(const Time &add1);
	Time operator-=(const Time &add1);
};

std::ostream &operator<<(std::ostream &os, const Time &t);
Time operator+(const Time &add1, const Time	&add2);
Time operator-(const Time &add1, const Time	&add2);

Time operator+(const Time &add1, const int seconds_to_add);
Time operator-(const Time &t1, const int seconds_to_sub);
