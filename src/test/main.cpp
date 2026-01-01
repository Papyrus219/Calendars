#include <iostream>
#include <Calendars/calendars.hpp>

int main()
{
    calendar::Hebrew_calendar cal{};

    cal.Set_date(15,1,2448);

    for(int i=0; i<calendar::Get_hebrew_year_type_duration(cal.Get_current_year_type());i++)
    {
        std::cout << cal.Get_date_string() << '\n';
        cal.Pass_day();
    }

    std::cout << cal.Get_date_string() << '\n';

    return EXIT_SUCCESS;
}
