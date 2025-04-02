#pragma once

#include <iostream>
#include <cstddef>

template <typename T>
void iter(T *array, size_t len, void (*func)(T &)) {

    for (size_t i = 0; i < len; i++)
        func(array[i]);
};

template <typename T>
void print(T &a) {
    std::cout << a << std::endl;
};