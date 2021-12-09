#pragma once

#include <iostream>
#include <cmath>
#include <cstdint>
#include <tuple>
#include <map>
#include <utility>
#include <fstream>
#include <string>
#include <optional>
#include <sstream>
#include <regex>
#include <chrono>

#include "Timer.h"

template<typename T>
inline void SwapPointers(T*& p1, T*& p2)
{
    T* t = p1;
    p1 = p2;
    p2 = t;
}

template<typename T>
inline void SortPointers(std::vector<T*>& v)
{
    std::sort(v.begin(), v.end(), [](const T* p1, const T* p2) {return *p1 < *p2; });
}

template<typename T>
inline void PrintPointers(const std::vector<T*>& v)
{
    std::for_each(v.begin(), v.end(), [](const T* p){ std::cout << *p << " "; });
    std::cout << std::endl;
}
