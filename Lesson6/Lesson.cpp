#include "Lesson.h"

bool IsPrime(int64_t val)
{
    int64_t finish = std::sqrt(std::abs(val));
    for (int64_t i = 2; i <= val; i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

int64_t GetSimpleNumber(int64_t limit)
{
    int64_t counter=0;

    if(limit == 0)
        return 0;

    if(limit == 1)
        return 1;

    int64_t ret{0};

    for(int64_t i{1}; i <= 4 * limit; ++i) {
        if(IsPrime(i)) {
            ++counter;
            if (counter == limit) {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

void Task1() {
    std::cout << "---------- pcout ----------" << std::endl;

    int tCount = std::thread::hardware_concurrency();
    int64_t lim = 100;

    std::thread *arr;
    arr = new std::thread[tCount];

    Timer timer("Primes");

    for (int64_t i = 1; i < lim; i++) {
        int64_t result{};
        std::thread t([&result](int idx) { result = GetSimpleNumber(idx); }, i);
        t.join();
        std::cout << "Threads: " << tCount << " Result: " << result << std::endl;
    }

    timer.print();

    delete [] arr;
}

void Lesson()
{
    Task1();
}

