#ifndef CALENDAR_GREGORIAN_MONTH_HPP
#define CALENDAR_GREGORIAN_MONTH_HPP

#include <string>

namespace calendar
{

enum class Gregorian_month: unsigned short
{
    JANUARY=1,
    FEBRUARY=2,
    MARCH=3,
    APRIL=4,
    MAY=5,
    JUNE=6,
    JULY=7,
    AUGUST=8,
    SEPTEMBER=9,
    OCTOBER=10,
    NOVEMBER=11,
    DECEMBER=12
};

std::string Get_gregorian_month_name_string(Gregorian_month month);
unsigned short Get_gregorian_month_duration(Gregorian_month month, bool is_leap_year = false);

}

#endif
