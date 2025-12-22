#ifndef CALENDAR_EVENT_HPP
#define CALENDAR_EVENT_HPP

#include <string>

namespace calendar
{

struct Event
{
    Event(std::string name_, short day_, short month_, long long year_): name{name_}, day{day_}, month{month_}, year{year_} {};
    Event(const Event& other): name{other.name}, day{other.day}, month{other.month}, year{other.year} {};

    bool operator==(const Event &other) const noexcept;

    const std::string name{};
    const short day{};
    const short month{};
    const long long year{};
};

}

#endif
