#include "Common.h"
#include "PhoneBook.h"

PhoneBook::PhoneBook(std::ifstream& ifs)
{
    if(!ifs.is_open())
        throw "Ошибка! Файл не найден.";

    for(std::string line; std::getline(ifs, line); ) {
        std::stringstream ss(line);
        std::string tok{};
        int counter = 0;

        std::tuple<std::string, std::string, std::string, std::string, std::string> tup{};

        Person p;
        PhoneNumber pn;

        while(std::getline(ss, tok, ' ')) {
            if(counter == 0) {
                p.surname = tok;
                std::get<0>(tup) = tok;
                counter++;
                continue;
            }
            if(counter == 1) {
                p.name = tok;
                std::get<1>(tup) = tok;
                counter++;
                continue;
            }
            if(counter == 2) {
                if(tok[0]=='+') {
                    counter++;
                    pn.SetNumber(tok);
                    std::get<3>(tup) = tok;
                    counter++;
                } else {
                    p.patronymic = tok;
                    std::get<2>(tup) = tok;
                    counter++;
                }
                continue;
            }
            if(counter == 3) {
                pn.SetNumber(tok);
                std::get<3>(tup) = tok;
                counter++;
                continue;
            }
            if(counter == 4) {
                pn.SetAuxNumber(tok);
                std::get<4>(tup) = tok;
                counter++;
                continue;
            }
        }

        peoples.emplace_back(std::pair{p, pn});
    }
}
