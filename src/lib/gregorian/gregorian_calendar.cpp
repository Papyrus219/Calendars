#include "gregorian_calendar.hpp"
#include "./gregorian_month.hpp"
#include <stdexcept>

using namespace calendar;

void calendar::Gregorian_calendar::Pass_day()
{
    current_day++;

    if(current_day > Get_gregorian_month_duration( Gregorian_month{current_month}, is_current_year_leap ))
    {
        current_month++;
        if(current_month > 12)
        {
            current_year++;
            current_month = 1;

            is_current_year_leap = Is_year_leap(current_year);
        }

        current_day = 1;
    }
}

void calendar::Gregorian_calendar::Set_date ( unsigned short day, unsigned short month, unsigned long long year )
{
    Date_valid_check(day, month, year);

    this->is_current_year_leap = Is_year_leap(year);
    this->current_day = day;
    this->current_month = month;
    this->current_year = year;
}

void calendar::Gregorian_calendar::Add_event ( std::string name, unsigned short day, unsigned short month, unsigned long long year )
{
    Date_valid_check(day, month, year);

    this->schudle_events.emplace_back( std::make_unique<Event>(name, day, month, year) );
}

std::string calendar::Gregorian_calendar::Get_date_string() const
{
    return {std::to_string(this->current_day) + " " + Get_gregorian_month_name_string( Gregorian_month{this->current_month} ) + " " + std::to_string(this->current_year) + "r." };
}

std::string calendar::Gregorian_calendar::Get_current_month_string() const
{
    return Get_gregorian_month_name_string( Gregorian_month{this->current_month} );
}

void calendar::Gregorian_calendar::Date_valid_check ( unsigned short day, unsigned short month, unsigned long long year )
{
    if(year == 0) throw std::invalid_argument{"Year 0 don't exist for gregorian calendar."};

    Gregorian_month greg_month{month};
    unsigned short max_day = Get_gregorian_month_duration(greg_month,Is_year_leap(year));

    if(month > 12 || month == 0) throw std::invalid_argument{"Invalid month for gregorian calendar."};
    if(day > max_day || day == 0) throw std::invalid_argument{"Invalid day for gregorian calendar. Day set: " + std::to_string(day) + "max for " + Get_gregorian_month_name_string(greg_month) + ": " + std::to_string(max_day)};
}

bool calendar::Gregorian_calendar::Is_year_leap ( unsigned long long year )
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
