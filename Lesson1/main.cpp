#include "Lesson.h"

int main()
{
    try {
        Lesson();
    } catch(std::exception& e) {
        std::cout << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
