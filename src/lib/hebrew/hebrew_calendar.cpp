#include "hebrew_calendar.hpp"
#include <stdexcept>

using namespace calendar;

void calendar::Hebrew_calendar::Pass_day()
{
    current_day++;

    if(current_day > Get_hebrew_month_duration(Hebrew_month{current_month}, current_year_type, is_current_year_leap))
    {
        current_month++;
        if(current_month > ((is_current_year_leap)? 13 : 12) )
        {
           current_year++;
           current_month = 1;

           current_year_type = Get_hebrew_year_type_from_duration( Calculate_rosh_hashana(current_year+1) - Calculate_rosh_hashana(current_year) );
           is_current_year_leap = Is_year_leap(current_year);
        }

        current_day = 1;
    }
}

void calendar::Hebrew_calendar::Set_date ( unsigned short day, unsigned short month, unsigned long long year )
{
    Date_valid_check(day, month, year);

    this->is_current_year_leap = Is_year_leap(year);
    this->current_year_type = Get_hebrew_year_type_from_duration( Calculate_rosh_hashana(year+1) - Calculate_rosh_hashana(year) );
    this->current_month = month;
    this->current_day = day;
}

void calendar::Hebrew_calendar::Add_event ( std::string name, unsigned short day, unsigned short month, unsigned long long year )
{
    Date_valid_check(day,month,year);

    this->schudle_events.emplace_back( std::make_unique<Event>(name, day, month, year) );
}

std::string calendar::Hebrew_calendar::Get_date_string() const
{
    return std::to_string(current_day) + " " + Get_hebrew_month_type_string(Hebrew_month{current_month}) + " " + std::to_string(current_year) + " AM";
}

void calendar::Hebrew_calendar::Date_valid_check ( unsigned short day, unsigned short month, unsigned long long year )
{
    if(year == 0) throw std::invalid_argument{"There is no year 0 in hebrew calendar."};

    Hebrew_year_type year_type = Get_hebrew_year_type_from_duration( Calculate_rosh_hashana(year+1) - Calculate_rosh_hashana(year) );
    bool is_year_leap = Is_year_leap(year);
    Hebrew_month hebrew_month = Hebrew_month{month};
    unsigned short max_month_durration = Get_hebrew_month_duration(hebrew_month,year_type,is_year_leap);

    if(is_year_leap)
    {
        if(month == 0 || month > 13) throw std::invalid_argument{"Incorrect month for hebrew calendar (leap year)."};
    }
    else
    {
        if(month == 0 || month > 13) throw std::invalid_argument{"Incorrect month for hebrew calendar (regular year)."};
    }

    if(day == 0 || day > max_month_durration )
    {
        throw std::invalid_argument{"Invalid day for hebrew calendar. Day set: " + std::to_string(day) + ". Max: " + std::to_string(max_month_durration) + " for " + Get_hebrew_month_type_string(hebrew_month,is_year_leap) + ". Year type: " + Get_hebrew_year_type_string(year_type) + "." };
    }
}

std::string calendar::Hebrew_calendar::Get_current_month_string() const
{
    return Get_hebrew_month_type_string( Hebrew_month{this->current_month} );
}

unsigned int calendar::Hebrew_calendar::Calculate_rosh_hashana ( unsigned long long year )
{
    unsigned short rosh_hashana{};

    unsigned long months = 12*(year-1) + ( ( 7*(year-1) + 1 ) / 19 );
    unsigned long chalakim = 204 + 793 * months;
    unsigned long hour = 5 + 12*months + (chalakim / hour_in_chalakim_durration);
    unsigned long day = 1 + 29*months + (hour/24);

    rosh_hashana = day;

    hour %= 24;
    chalakim %= hour_in_chalakim_durration;

    if(hour >= 18) rosh_hashana++;

    //Lo ADU Rosh
    unsigned short day_of_week = rosh_hashana % 7;
    if(day_of_week == 0 || day_of_week == 3 || day_of_week == 5) rosh_hashana++;

    //GaTRaD
    if(!Is_year_leap(year) && day_of_week == 2 && (hour * hour_in_chalakim_durration + chalakim) >= (9 * hour_in_chalakim_durration + 204)) rosh_hashana++;
    //BeTuTaKPaT
    if(Is_year_leap(year-1) && day_of_week == 1 && (hour * hour_in_chalakim_durration + chalakim) >= (15 * hour_in_chalakim_durration + 589)) rosh_hashana++;

    return rosh_hashana;
}

constexpr bool calendar::Hebrew_calendar::Is_year_leap ( unsigned long long year )
{
    int r = year % 19;
    for(auto it = meton_cycle.begin(); it!= meton_cycle.end(); it++)
    {
        if(r == *it) return true;
    }

    return false;
}
