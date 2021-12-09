#pragma once

#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook
{
public:
    PhoneBook() = default;
    PhoneBook(std::ifstream& ifs);

    friend std::ostream& operator<<(std::ostream& stream, const PhoneBook& p);

    void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& s);
    void ChangePhoneNumber(Person p, PhoneNumber pn);

private:
    std::vector<std::pair<Person, PhoneNumber>> peoples{};
};
