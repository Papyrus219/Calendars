#include "./hebrew_month.hpp"
#include <stdexcept>

using namespace calendar;

Hebrew_year_type calendar::Get_hebrew_year_type_from_duration ( unsigned long duration, bool is_leap )
{
    if(is_leap)
    {
        if(duration == 383) return Hebrew_year_type::CHASER;
        if(duration == 384) return Hebrew_year_type::KESIDRAN;
        if(duration == 385) return Hebrew_year_type::MALE;

        throw std::invalid_argument{"No leap hebrew year have this duration!"};
    }
    else
    {
        if(duration == 353) return Hebrew_year_type::CHASER;
        if(duration == 354) return Hebrew_year_type::KESIDRAN;
        if(duration == 355) return Hebrew_year_type::MALE;

        throw std::invalid_argument{"No regular hebrew year have this duration!"};
    }
}

unsigned long long calendar::Get_hebrew_year_type_duration ( Hebrew_year_type type, bool is_leap )
{
    switch(type)
    {
        case Hebrew_year_type::CHASER: return (is_leap)? 383 : 353;
        case Hebrew_year_type::KESIDRAN: return (is_leap)? 384 : 354;
        case Hebrew_year_type::MALE: return (is_leap)? 385 : 355;
        default: return 0;
    }
}

unsigned short calendar::Get_hebrew_month_duration ( Hebrew_month month, Hebrew_year_type type, bool is_leap )
{
    switch(month)
    {
        case Hebrew_month::NISAN: return 30;
        case Hebrew_month::IJAR: return 29;
        case Hebrew_month::SIWAN: return 30;
        case Hebrew_month::TAMUZ: return 29;
        case Hebrew_month::AW: return 30;
        case Hebrew_month::ELUL: return 29;
        case Hebrew_month::TISZRI: return 30;
        case Hebrew_month::CHESZWAN: return (type == Hebrew_year_type::MALE)? 30 : 29;
        case Hebrew_month::KISLEW: return (type == Hebrew_year_type::CHASER)? 29 : 30;
        case Hebrew_month::TEWET: return 29;
        case Hebrew_month::SZWAT: return 30;
        case Hebrew_month::ADAR_I: return (is_leap)? 30 : 29;
        case Hebrew_month::ADAR_II: return (is_leap)? 29 : 0;
        default: return 0;
    }
}

std::string calendar::Get_hebrew_year_type_string ( Hebrew_year_type type )
{
    switch(type)
    {
        case Hebrew_year_type::CHASER: return "Chaser";
        case Hebrew_year_type::KESIDRAN: return "Kesidran";
        case Hebrew_year_type::MALE: return "Male";
        default: return "";
    }
}

std::string calendar::Get_hebrew_month_type_string ( Hebrew_month month, bool is_leap )
{
    switch(month)
    {
        case Hebrew_month::NISAN: return "Nisan";
        case Hebrew_month::IJAR: return "Ijar";
        case Hebrew_month::SIWAN: return "Siwan";
        case Hebrew_month::TAMUZ: return "Tamuz";
        case Hebrew_month::AW: return "Aw";
        case Hebrew_month::ELUL: return "Elul";
        case Hebrew_month::TISZRI: return "Tiszri";
        case Hebrew_month::CHESZWAN: return "Cheszwan";
        case Hebrew_month::KISLEW: return "Kislew";
        case Hebrew_month::TEWET: return "Tewet";
        case Hebrew_month::SZWAT: return "Szwat";
        case Hebrew_month::ADAR_I: return (is_leap)? "Adar I" : "Adar";
        case Hebrew_month::ADAR_II: return (is_leap)? "Adar II" : "";
        default: return "";
    }
}
