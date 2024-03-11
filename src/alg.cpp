// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) { //возведение числа в целую степень.
    double res = value;
    for (uint16_t i = 1; i < n; i++) {
        res *= res;
    }
    return res;
}

uint64_t fact(uint16_t n) { //вычисление факториала чила n.
    uint64_t result = 1;
    for (uint64_t i = n; i >= 1; i--) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) { //вычисление члена ряда.
    uint64_t res = pown(x, n) / fact(n); 
    return res;
}

double expn(double x, uint16_t count) { //вычисление значения функции exp(x) с суммированием count - членов ряда.
    uint64_t sum = 0;
    for (uint16_t i = 0; i <= count; i++) {
        sum += calcItem(x, i);
    }
    return sum;
}

double sinn(double x, uint16_t count) { //вычисление значения функции sin(x) с суммированием count - членов ряда.
    uint64_t sum = 0;
    for (uint16_t i = 0; i <= count; i++) {
        sum += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
    }
    return sum;
}

double cosn(double x, uint16_t count) { //вычисление значения функции cos(x) с суммированием count - членов ряда
    uint64_t sum = 0;
    for (uint16_t i = 0; i <= count; i++) {
        sum += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
    }
    return sum;
}
