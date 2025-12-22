#include "./event.hpp"

using namespace calendar;

bool calendar::Event::operator== ( const Event &other ) const noexcept
{
    return this->name == other.name;
}
