#include "Lesson.h"

#define TESTS
int Tests();

int main()
{
#ifdef TESTS
    return Tests();
#else
    try {
        Lesson();
    } catch(const char* e) {
        std::cout << "Исключение: " << e << std::endl;
    }

    return 0;
#endif
}
