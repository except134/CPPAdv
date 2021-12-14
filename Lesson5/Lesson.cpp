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
    std::cout << "---------- Unique ----------" << std::endl;

    std::vector<std::string> s{"First", "second", "third", "second"};
    PrintUnique(s.begin(), s.end());

    std::vector<int> i{1, 2, 3, 3, 3, 4, 5, 5, 6};
    PrintUnique(i.begin(), i.end());

    std::list<std::string> sl{"First", "second", "third", "second"};
    PrintUnique(sl.begin(), sl.end());

    std::list<int> il{1, 2, 3, 3, 3, 4, 5, 5, 6};
    PrintUnique(il.begin(), il.end());
}

std::string GetUserInput()
{
    std::string line;

    while(true) {
        if (!getline(std::cin, line)) {
            throw "Критическая ошибка ввода!!!";
        } else
            break;
    }

    return line;
}

void Task2()
{
    std::cout << "---------- Sentences ----------" << std::endl;
    std::cout << "Вводите предложения.\nПо окончании ввода, нажмите Enter для ввода следующего предложения.\nНажмите Enter без ввода текста для завершения работы.\n" << std::endl;

    std::multimap<size_t, std::string, std::greater<size_t>> lines;

    while(true) {
        if(std::string line; !std::getline(std::cin, line)) {
            throw "Критическая ошибка ввода!!!";
        } else if(line.empty()) {
            break;
        } else
            lines.insert(std::make_pair(line.size(), line));
    }

    std::for_each(lines.begin(), lines.end(), [](const auto& v){ std::cout << v.first << ": " << v.second << "\n"; });
}

void Lesson()
{
    Task1();
    Task2();
}

