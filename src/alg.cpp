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
  uint64_t factor = 1;
  if (n == 0 || n == 1) {
    return factor;
  } else {
    for (uint16_t j = 1; j < n + 1; j++) {
      factor *= j;
    }
    return factor;
  }
}

double calcItem(double x, uint16_t n) { return (pown(x, n) / fact(n)); }

double expn(double x, uint16_t count) {
  double summ = 0;
  for (uint16_t a = 0; a < count + 1; a++) {
    summ += calcItem(x, a);
  }
  return summ;
}

double sinn(double x, uint16_t count) {
  double summ = 0;
  for (uint16_t a = 1; a < count + 1; a++) {
    summ += pown(-1, a - 1) * calcItem(x, 2 * a - 1);
  }
  return summ;
}

double cosn(double x, uint16_t count) {
  double summ = 0;
  for (uint16_t a = 1; a < count + 1; a++) {
    summ += pown(-1, a - 1) * calcItem(x, 2 * a - 2);
  }
  return summ;
}
