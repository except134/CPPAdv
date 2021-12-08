#include "Common.h"
#include "PhoneNumber.h"

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

