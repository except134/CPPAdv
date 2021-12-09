#include "Lesson.h"

int main()
{
    try {
        Lesson();
    } catch(const char* e) {
        std::cout << "Исключение: " << e << std::endl;
    }

    return 0;
}
