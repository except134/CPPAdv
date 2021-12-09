#include "Lesson.h"

const std::vector<char16_t> GLASS_LETTERS{'а','А','е','Е','ё','Ё','и','И','о','О','у','У','э','Э','ы','Ы','ю','Ю','я','Я'};

void CountIfAndFind(const std::string& s)
{

}

void Lesson()
{
    std::cout << "--------- SortPointers ---------" << std::endl;
    int v1 = 3, v2 = 1, v3 = 20, v4 = 12, v5 = 11;
    std::vector v{&v1,&v2,&v3,&v4,&v5};
    PrintPointers(v);
    SortPointers(v);
    PrintPointers(v);

    std::cout << "--------- SwapPointers ---------" << std::endl;
    SwapPointers(v[1], v[3]);
    PrintPointers(v);

    std::ifstream ifs{"./WarAndPeace.txt"};
    if(!ifs.is_open())
        throw "Ошибка открытия файла";

    std::string wap{};
    std::getline(ifs, wap, '\0');


}

