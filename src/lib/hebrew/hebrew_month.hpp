#ifndef CALENDAR_HEBREW_MONTH_HPP
#define CALENDAR_HEBREW_MONTH_HPP

#include <string>

namespace calendar
{

enum class Hebrew_year_type
{
    CHASER,
    KESIDRAN,
    MALE
};

enum class Hebrew_month
{
    NISAN=1,
    IJAR=2,
    SIWAN=3,
    TAMUZ=4,
    AW=5,
    ELUL=6,
    TISZRI=7,
    CHESZWAN=8,
    KISLEW=9,
    TEWET=10,
    SZWAT=11,
    ADAR_I=12,
    ADAR_II=13
};

Hebrew_year_type Get_hebrew_year_type_from_duration(unsigned long duration, bool is_leap = false);

unsigned long long Get_hebrew_year_type_duration(Hebrew_year_type type, bool is_leap = false);
unsigned short Get_hebrew_month_duration(Hebrew_month month, Hebrew_year_type type = Hebrew_year_type::KESIDRAN, bool is_leap = false);

std::string Get_hebrew_year_type_string(Hebrew_year_type type);
std::string Get_hebrew_month_type_string(Hebrew_month month, bool is_leap = false);

}

#endif
