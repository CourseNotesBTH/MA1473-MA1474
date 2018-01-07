#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <debug.h>
#include <keypadc.h>

#ifndef SHARED
#define  SHARED
  #define CHARACTER_WIDTH 26
  #define CHARACTER_HEIGHT 9
  #define square(x) (x * x)
  /* 6 characters = 999'999. 2^24 / 2 = 8388608. 999'999 < 8388608. 7 - 1(null) = 6 */
  #define INPUT_SIZE 7

  uint8_t print(int8_t row, int8_t column, const char *text);
  uint8_t printLine(int8_t row, const char *text);
  void clearFromLeft(uint8_t rows, const char* clearString);
  int ipow(int base, int exp);
#endif
