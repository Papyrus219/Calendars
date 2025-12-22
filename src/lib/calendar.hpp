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
    virtual void Set_date(short day, short month, long long year) = 0;
    virtual void Set_date(long long year, short month, short day) = 0;

    virtual void Add_event(std::string name, short day, short month, long long year) = 0;
    void Remove_event(const std::string &name);

    short Get_day() {return this->current_day;};
    short Get_month() {return this->current_month;};
    long long Get_year() {return this->current_year;};
    virtual std::string Get_date_string() = 0;

    virtual void Pass_day() = 0;
protected:
    short current_day{};
    short current_month{};
    long long current_year{};

    std::vector< std::unique_ptr<Event> > schudle_events{};

    bool leap_year{};
};

}

#endif //CALENDER_CALENDAR_HPP
