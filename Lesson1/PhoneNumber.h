#pragma once

class PhoneNumber
{
public:
    PhoneNumber() = default;
    PhoneNumber(int country, int city, const std::string& num, int aux = 0) :
        countryCode(country),
        cityCode(city),
        number(num),
        auxNumber(aux)
    {}

    friend std::ostream& operator<<(std::ostream& stream, const PhoneNumber& p);
    friend bool operator < (const PhoneNumber& p1, const PhoneNumber& p2);
    friend bool operator == (const PhoneNumber& p1, const PhoneNumber& p2);

private:
    int countryCode{0};
    int cityCode{0};
    std::string number;
    int auxNumber{0};
};

