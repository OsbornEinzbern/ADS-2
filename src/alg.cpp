// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (uint16_t i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint64_t i = n; i >= 1; i--) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  uint64_t res = pown(x, n) / fact(n);
  return res;
}

double expn(double x, uint16_t count) {
  uint64_t sum = 0;
  for (uint16_t i = 0; i <= count; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  uint64_t sum = 0;
  for (uint16_t i = 0; i <= count; i++) {
    sum += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  uint64_t sum = 0;
  for (uint16_t i = 0; i <= count; i++) {
    sum += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
  }
  return sum;
}
