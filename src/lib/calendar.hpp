#ifndef CALENDER_CALENDAR_HPP
#define CALENDER_CALENDAR_HPP

#include <string>
#include <vector>
#include <memory>
#include "./event.hpp"

namespace calendar
{

/**
 * @todo write docs
 */
class Calendar
{
public:
    virtual void Pass_day() = 0;

    virtual void Set_date(unsigned short day, unsigned short month, unsigned long long year) = 0;

    virtual void Add_event(std::string name, unsigned short day, unsigned short month, unsigned long long year) = 0;
    void Remove_event(const std::string &name);

    unsigned short Get_current_day() const {return this->current_day;};
    unsigned short Get_current_month() const {return this->current_month;};
    unsigned long long Get_current_year() const {return this->current_year;};

    std::string Get_current_day_string() const {return std::to_string(this->current_day);};
    virtual std::string Get_current_month_string() const = 0;
    std::string Get_current_year_string() const {return std::to_string(this->current_year);};

    virtual std::string Get_date_string() const = 0;

    bool Get_is_current_yeat_leap() const {return this->is_current_year_leap;};

protected:

    virtual constexpr bool Is_year_leap(unsigned long long year) = 0;

    unsigned short current_day{1};
    unsigned short current_month{1};
    unsigned long long current_year{2012};

    std::vector< std::unique_ptr<Event> > schudle_events{};

    bool is_current_year_leap{};
};

}

#endif //CALENDER_CALENDAR_HPP
