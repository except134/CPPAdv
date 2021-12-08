#pragma once

#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook
{
public:
    PhoneBook() = default;
    PhoneBook(std::ifstream& ifs);

private:
    std::map<Person, PhoneNumber> peoples{};
};
