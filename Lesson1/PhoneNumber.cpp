#include "Common.h"
#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(const std::string& s, int auxn)
{
    SetNumber(s);
    auxNumber = auxn;
}

void PhoneNumber::SetNumber(const std::string& n)
{
    //std::regex re("^(\\+)?((\\d{2,3}) ?\\d|\\d)(([ -]?\\d)|( ?(\\d{2,3}) ?)){5,12}\\d$");
    std::regex re("^\\+(\\d+)\\((\\d+)\\)(\\d+)$");
    std::smatch match;
    if(std::regex_match(n, match, re)) {
        countryCode = std::atoi(match[1].str().c_str());
        cityCode = std::atoi(match[2].str().c_str());
        number = match[3].str();
    } else
        throw "Не известный формат номера телефона";
}

std::ostream& operator<<(std::ostream& stream, const PhoneNumber& p)
{
    stream << "+" << p.countryCode;
    stream << "(" << p.cityCode << ")";
    stream << p.number;

    if(p.auxNumber)
        stream << " " << p.auxNumber;

    return stream;
}

bool operator < (const PhoneNumber& p1, const PhoneNumber& p2)
{
    return std::tie(p1.countryCode, p1.cityCode, p1.number, p1.auxNumber)
           <
           std::tie(p2.countryCode, p2.cityCode, p2.number, p2.auxNumber);
}

bool operator == (const PhoneNumber& p1, const PhoneNumber& p2)
{
    return std::tie(p1.countryCode, p1.cityCode, p1.number, p1.auxNumber)
           ==
           std::tie(p2.countryCode, p2.cityCode, p2.number, p2.auxNumber);
}

