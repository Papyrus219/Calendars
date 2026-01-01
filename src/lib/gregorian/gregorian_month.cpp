#include "./gregorian_month.hpp"

using namespace calendar;

std::string calendar::Get_gregorian_month_name_string ( Gregorian_month month )
{
    switch(month)
    {
        case Gregorian_month::JANUARY: return "January";
        case Gregorian_month::FEBRUARY: return "February";
        case Gregorian_month::MARCH: return "March";
        case Gregorian_month::APRIL: return "April";
        case Gregorian_month::MAY: return "May";
        case Gregorian_month::JUNE: return "June";
        case Gregorian_month::JULY: return "July";
        case Gregorian_month::AUGUST: return "August";
        case Gregorian_month::SEPTEMBER: return "September";
        case Gregorian_month::OCTOBER: return "October";
        case Gregorian_month::NOVEMBER: return "November";
        case Gregorian_month::DECEMBER: return "December";
        default: return "";
    }
}

unsigned short calendar::Get_gregorian_month_duration ( Gregorian_month month, bool is_leap_year )
{
    switch(month)
    {
        case Gregorian_month::JANUARY: return 31;
        case Gregorian_month::FEBRUARY: return (is_leap_year)? 29 : 28;
        case Gregorian_month::MARCH: return 31;
        case Gregorian_month::APRIL: return 30;
        case Gregorian_month::MAY: return 31;
        case Gregorian_month::JUNE: return 30;
        case Gregorian_month::JULY: return 31;
        case Gregorian_month::AUGUST: return 31;
        case Gregorian_month::SEPTEMBER: return 30;
        case Gregorian_month::OCTOBER: return 31;
        case Gregorian_month::NOVEMBER: return 30;
        case Gregorian_month::DECEMBER: return 31;
        default: return 0;
    }
}
