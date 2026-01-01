#ifndef CALENDAR_GREGORIAN_CALENDAR_HPP
#define CALENDAR_GREGORIAN_CALENDAR_HPP

#include "../calendar.hpp"

namespace calendar
{

/**
 * @todo write docs
 */
class Gregorian_calendar : public Calendar
{
public:
    void Pass_day() override;
    void Set_date ( unsigned short day, unsigned short month, unsigned long long year ) override;
    void Add_event ( std::string name, unsigned short day, unsigned short month, unsigned long long year ) override;

    std::string Get_date_string() const override;
    std::string Get_current_month_string() const override;

private:
    void Date_valid_check( unsigned short day, unsigned short month, unsigned long long year );
    bool Is_year_leap ( unsigned long long year ) override;
};

}

#endif // CALENDAR_GREGORIAN_CALENDAR_HPP
