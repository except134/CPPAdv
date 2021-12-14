#include "Lesson.h"

template<typename T>
void insert_sorted(std::vector<T>& vec, const T& val)
{
    auto ret = std::find_if(vec.begin(), vec.end(),[&val](const T& v) { return v >= val; });
    if(ret != vec.end())
        vec.insert(ret,val);
    else
        vec.emplace_back(val);
}

void PrintVector(const auto& l)
{
    std::for_each(l.begin(), l.end(), [](const auto& v){ std::cout << v << " "; });
    std::cout << std::endl;
}

void Task1()
{
    std::cout << "--------- insert_sorted ---------" << std::endl;

    std::vector<int> v{1, 2, 3, 4, 7, 8, 9};
    PrintVector(v);
    insert_sorted(v, 5);
    PrintVector(v);
    insert_sorted(v, 15);
    PrintVector(v);
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

void Task2()
{
    std::cout << "--------- Signals ---------" << std::endl;

    const size_t VECTOR_SIZE = 100;

    std::vector<double> analogSignal(VECTOR_SIZE);
    std::vector<int> digitalSignal(VECTOR_SIZE);
    std::vector<double> deltas(VECTOR_SIZE);

    std::generate(analogSignal.begin(), analogSignal.end(), []() { return GetRandom(-100.0, 100.0); });
    std::cout << "Analog signal: ";
    PrintVector(analogSignal);

    std::transform(analogSignal.begin(),analogSignal.end(),digitalSignal.begin(),[](double& v)->int {return static_cast<int>(v);});
    std::cout << "Digital signal: ";
    PrintVector(digitalSignal);

    std::transform(analogSignal.begin(),analogSignal.end(),digitalSignal.begin(),deltas.begin(),
        [](const double& as, const int &ds)->double {
        return static_cast<double>((as-ds)*(as-ds));
    });

    std::cout << "Deltas: ";
    PrintVector(deltas);

    std::cout << "Error: " << std::accumulate(deltas.begin(),deltas.end(),0.0) << std::endl;

}

void Lesson()
{
    Task1();
    Task2();
}

