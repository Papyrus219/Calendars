#include "calendar.hpp"

using namespace calendar;

void calendar::Calendar::Remove_event (const std::string &name )
{
    for(auto it = schudle_events.begin(); it != schudle_events.end(); ++it)
    {
        if((*it)->name == name)
        {
            this->schudle_events.erase(it);
            return;
        }
    }
}
