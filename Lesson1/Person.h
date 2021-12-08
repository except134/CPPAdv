#pragma once

class Person
{
public:
    Person() = default;
    Person(const std::string& sn, const std::string& n, const std::string& p = "") :
            surname(sn),
            name(n),
            patronymic(p)
    {}

    friend std::ostream& operator<<(std::ostream& stream, const Person& p);
    friend bool operator < (const Person& p1, const Person& p2);
    friend bool operator == (const Person& p1, const Person& p2);

private:
    std::string surname{};
    std::string name{};
    std::string patronymic{};
};
