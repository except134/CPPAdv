#include "Lesson.h"

const std::string VOWEL_LETTERS = "аАеЕёЁиИоОуУэЭыЫюЮяЯ";

void CountIfAndCount(const std::string& s)
{
    Timer timer("------ Count_if and count ------");

    std::cout << std::endl << "Гласных букв: " <<
        std::count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            return std::count(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), currentChar);
        }) << std::endl;

    timer.print();
}

void CountIfAndFind(const std::string& s)
{
    Timer timer("------ Count_if and find ------");

    std::cout << std::endl << "Гласных букв: " <<
        std::count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            return std::find(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), currentChar) != VOWEL_LETTERS.end();
        }) << std::endl;

    timer.print();
}

void CountIfAndFor(const std::string& s)
{
    Timer timer("------ Count_if and for ------");

    std::cout << std::endl << "Гласных букв: " <<
        std::count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            for(auto i: VOWEL_LETTERS) {
                if(i == currentChar)
                    return true;
            }
            return false;
        }) << std::endl;

    timer.print();
}

void ForAndFind(const std::string& s)
{
    Timer timer("------ For and find ------");

    std::cout << std::endl << "Гласных букв: ";

    int cnt = 0;
    for(auto i: s) {
        if(std::find(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), i) != VOWEL_LETTERS.end())
            cnt++;
    }

    std::cout << cnt << std::endl;

    timer.print();
}

void ForAndFor(const std::string& s)
{
    Timer timer("------ For and for ------");

    std::cout << std::endl << "Гласных букв: ";

    int cnt = 0;
    for(auto tc: s) {
        for(auto vc: VOWEL_LETTERS) {
            if (tc == vc) {
                cnt++;
                break;
            }
        }
    }

    std::cout << cnt << std::endl;

    timer.print();
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

    CountIfAndCount(wap);
    CountIfAndFind(wap);
    CountIfAndFor(wap);
    ForAndFind(wap);
    ForAndFor(wap);

}

