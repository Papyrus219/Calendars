#ifndef CALENDAR_HEBREW_CALENDAR_HPP
#define CALENDAR_HEBREW_CALENDAR_HPP

#include <array>
#include "../calendar.hpp"
#include "./hebrew_month.hpp"

namespace calendar
{

/**
 * @todo write docs
 */
class Hebrew_calendar : public Calendar
{
public:
    void Pass_day() override;
    void Set_date ( unsigned short day, unsigned short month, unsigned long long year ) override;
    void Add_event ( std::string name, unsigned short day, unsigned short month, unsigned long long year ) override;

    Hebrew_year_type Get_current_year_type() const  {return this->current_year_type;};
    std::string Get_current_year_type_string() const {return Get_hebrew_year_type_string(this->current_year_type);};

    std::string Get_date_string() const override;
    std::string Get_current_month_string() const override;

private:
    void Date_valid_check(unsigned short day, unsigned short month, unsigned long long year);
    unsigned int Calculate_rosh_hashana(unsigned long long year);
    constexpr bool Is_year_leap(unsigned long long year) override;

    static constexpr std::array<unsigned short,7> meton_cycle{0,3,6,8,11,14,17};
    static constexpr unsigned int hour_in_chalakim_durration{1080};

    Hebrew_year_type current_year_type{};
};

}

#endif // CALENDAR_HEBREW_CALENDAR_HPP
