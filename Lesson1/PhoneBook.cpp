#include "Common.h"
#include "PhoneBook.h"

PhoneBook::PhoneBook(std::ifstream& ifs)
{
    if(!ifs.is_open())
        throw "Ошибка! Файл не найден.";

    for(std::string line; std::getline(ifs, line); ) {
        std::stringstream ss(line);
        std::string tok{};
        std::tuple tup{};
        int counter = 0;

        std::tuple<std::string, std::string, std::string, std::string, std::string> tup{};

        while(std::getline(ss, tok, ' ')) {
            if(counter == 0)
                std::get<0>(tup) = tok;
        }
        std::cout << std::endl;
    }
}
