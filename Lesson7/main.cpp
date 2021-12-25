#include "Lesson.h"

int main()
{
    try {
        Lesson();
    } catch(std::runtime_error& e) {
        std::cout << "Исключение: " << e.what() << std::endl;
    } catch(const char* e) {
        std::cout << "Исключение: " << e << std::endl;
    }

    return 0;
}
