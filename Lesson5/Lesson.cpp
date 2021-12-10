#include "Lesson.h"

void PrintVector(const auto& l)
{
    std::for_each(l.begin(), l.end(), [](const auto& v){ std::cout << v << " "; });
    std::cout << std::endl;
}

template<typename T>
void PrintUnique(T ib, T ie)
{
    std::set<typename T::value_type> u(ib, ie);
    PrintVector(u);
}

void Task1()
{
    std::vector<std::string> s{"First", "second", "third", "second"};
    PrintUnique(s.begin(), s.end());

    std::vector<int> i{1, 2, 3, 3, 3, 4, 5, 5, 6};
    PrintUnique(i.begin(), i.end());
}

void Lesson()
{
    Task1();
}

