#include "time.h"
#include <iostream>
// using namespace Time;

Time operator+(const Time &add1, const Time &add2) {
  int total_seconds = add1.seconds + add2.seconds;
  int total_minutes = add1.minutes + add2.minutes;
  int total_hours = add1.hours + add2.hours;
  int total_days = add1.days + add2.days;

  if (total_seconds >= 60) {
    total_minutes += total_seconds / 60;
    total_seconds = total_seconds % 60;
  }
  if (total_minutes >= 60) {
    total_hours += total_minutes / 60;
    total_minutes = total_minutes % 60;
  }
  if (total_hours >= 24) {
    total_days += total_hours / 24;
    total_hours = total_hours % 24;
  }
  return Time(total_days, total_hours, total_minutes, total_seconds);
}

Time Time::operator+=(const Time &add1) {
  int total_seconds = add1.seconds + seconds;
  int total_minutes = add1.minutes + minutes;
  int total_hours = add1.hours + hours;
  int total_days = add1.days + days;

  if (total_seconds >= 60) {
    total_minutes += total_seconds / 60;
    total_seconds = total_seconds % 60;
  }
  if (total_minutes >= 60) {
    total_hours += total_minutes / 60;
    total_minutes = total_minutes % 60;
  }
  if (total_hours >= 24) {
    total_days += total_hours / 24;
    total_hours = total_hours % 24;
  }

  seconds = total_seconds;
  minutes = total_minutes;
  hours = total_hours;
  days = total_days;
  return Time(days, hours, minutes, seconds);
}

Time operator-(const Time &add1, const Time &add2) {
  int total_seconds = add1.seconds - add2.seconds;
  int total_minutes = add1.minutes - add2.minutes;
  int total_hours = add1.hours - add2.hours;
  int total_days = add1.days - add2.days;

  if (total_seconds >= 60) {
    total_minutes -= total_seconds / 60;
    total_seconds = total_seconds % 60;
  }
  if (total_minutes >= 60) {
    total_hours -= total_minutes / 60;
    total_minutes = total_minutes % 60;
  }
  if (total_hours >= 24) {
    total_days -= total_hours / 24;
    total_hours = total_hours % 24;
  }
  return Time(total_days, total_hours, total_minutes, total_seconds);
}

Time Time::operator-=(const Time &add1) {
  int total_seconds = add1.seconds - seconds;
  int total_minutes = add1.minutes - minutes;
  int total_hours = add1.hours - hours;
  int total_days = add1.days - days;

  if (total_seconds >= 60) {
    total_minutes -= total_seconds / 60;
    total_seconds = total_seconds % 60;
  }
  if (total_minutes >= 60) {
    total_hours -= total_minutes / 60;
    total_minutes = total_minutes % 60;
  }
  if (total_hours >= 24) {
    total_days -= total_hours / 24;
    total_hours = total_hours % 24;
  }

  seconds = total_seconds;
  minutes = total_minutes;
  hours = total_hours;
  days = total_days;
  return Time(days, hours, minutes, seconds);
}

// TIME +- INT
Time operator+(const Time &t1, const int seconds_to_add) {
  Time result;
  int added_seconds = t1.seconds + seconds_to_add;
  if (added_seconds >= 60) {
    result.minutes += added_seconds / 60;
    result.seconds = added_seconds % 60;
  } else {
    result.seconds = added_seconds;
  }
  if (t1.minutes >= 60) {
    result.hours += t1.minutes / 60;
    result.minutes = t1.minutes % 60;
  }
  if (t1.hours >= 24) {
    result.days += t1.hours / 24;
    result.hours = t1.hours % 24;
  }
  return Time(result.days, result.hours, result.minutes, result.seconds);
}

Time operator-(const Time &t1, const int seconds_to_sub) {
  Time result;
  int added_seconds = t1.seconds + seconds_to_sub;
  if (added_seconds >= 60) {
    result.minutes -= added_seconds / 60;
    result.seconds = added_seconds % 60;
  } else {
    result.seconds = added_seconds;
  }
  if (t1.minutes >= 60) {
    result.hours -= t1.minutes / 60;
    result.minutes = t1.minutes % 60;
  }
  if (t1.hours >= 24) {
    result.days -= t1.hours / 24;
    result.hours = t1.hours % 24;
  }
  return Time(result.days, result.hours, result.minutes, result.seconds);
}

std::ostream &operator<<(std::ostream &os, const Time &t) {
  os << t.days << "d " << t.hours << "h " << t.minutes << "m " << t.seconds
     << "s";
  return os;
}