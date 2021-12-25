#include "Lesson.h"

/////////////////// Task 1 /////////////////////

class pcout
{
public:
    pcout() : ulock(std::unique_lock<std::mutex>(mutex))
    {
    }

    template <typename T>
    pcout& operator<<(const T& data)
    {
        std::cout << data;
        return *this;
    }

    pcout& operator<<(std::ostream& (*os)(std::ostream&))
    {
        std::cout << os;
        return *this;
    }

private:
    static std::mutex mutex;
    std::unique_lock<std::mutex> ulock;
};

std::mutex pcout::mutex{};

void Task1()
{
    std::cout << "---------- pcout ----------" << std::endl;

    std::vector<std::jthread> pcout_threads;
    size_t threads(std::jthread::hardware_concurrency());

    for (size_t i = 0; i < threads; ++i) {
        pcout_threads.emplace_back([&]
            {
                pcout() << "pcout test in thread " << std::this_thread::get_id() << std::endl;
            });
    }
}

/////////////////// Task 2 /////////////////////

bool IsPrime(int64_t val)
{
    int64_t finish = std::sqrt(std::abs(val));
    for (int64_t i = 2; i <= finish; i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

int64_t GetSimpleNumber(int64_t limit)
{
    int64_t counter{0};
    int64_t index{2};

    for(index = 2, counter = 0; counter < limit; index++) {
        if(IsPrime(index)) {
            ++counter;
        }
    }

    return index;
}

void Task2()
{
    std::cout << "---------- N-th prime ----------" << std::endl;

    int64_t lim = 1000000;
    int64_t result{0};

    Timer timer("Primes");

    std::jthread t([&]{ result = GetSimpleNumber(lim); });
    t.join();
    std::cout << "Result: " << result << std::endl;

    timer.print();
}

/////////////////// Task 3 /////////////////////

void PrintVector(const auto& l)
{
    std::for_each(l.begin(), l.end(), [](const auto& v){ std::cout << v << " "; });
    std::cout << std::endl;
    std::cout << std::endl;
}

template<typename T>
T GetRandom(T minVal, T maxVal)
{
    std::random_device rd;
    static std::mt19937 ms(rd());
    if(std::is_floating_point_v<T>) {
        std::uniform_real_distribution<> uid(minVal, maxVal);
        return uid(ms);
    }

    std::uniform_int_distribution<> uid(minVal, maxVal);
    return uid(ms);
}

std::mutex storeMutex;

void HostPutToStore(std::vector<int>& store)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));

    int item = GetRandom(1, 1000);
    std::lock_guard<std::mutex> lock(storeMutex);
    store.emplace_back(item);
    std::cout << "Хозяин кладет на склад " << item << std::endl;

    std::cout << "Содержимое склада: ";
    PrintVector(store);
}

void ThiefGetFromStore(std::vector<int>& store)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    auto maxItem{std::max_element(std::execution::par, store.begin(), store.end())};
    if(maxItem != store.end()) {
        int item{*maxItem};
        std::lock_guard<std::mutex> lock(storeMutex);
        store.erase(maxItem);
        std::cout << "Вор крадет со склада " << item << std::endl;
    }

    std::cout << "Содержимое склада: ";
    PrintVector(store);
}

void Task3()
{
    std::vector<int> store{};

    for (size_t j{}; j < 30; ++j) {
        store.emplace_back(GetRandom(1, 1000));
    }

    for (size_t i{}; i < std::thread::hardware_concurrency(); ++i) {
        std::jthread host{HostPutToStore, std::ref(store)};
        std::jthread thief{ThiefGetFromStore, std::ref(store)};
    }
}

void Lesson()
{
    Task1();
    Task2();
    Task3();
}

