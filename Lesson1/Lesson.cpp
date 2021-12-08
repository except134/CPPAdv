#include "Lesson.h"

void Lesson()
{
    std::string fname="./PhoneBook.txt";

    if(fname.empty())
        throw "Ошибка! Укажите имя файла.";

    std::ifstream ifs(fname);
    PhoneBook pb(ifs);
}

