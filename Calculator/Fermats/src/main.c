#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <debug.h>

#define CHARACTER_WIDTH 26
#define CHARACTER_HEIGHT 9
#define square(x) (x * x)
/* 6 characters = 999'999. 2^24 / 2 = 8388608. 999'999 < 8388608. 7 - 1(null) = 6 */
#define INPUT_SIZE 7

void print(int8_t row, const char *text);

void main(void) {
  const char str[CHARACTER_WIDTH];
  char input[INPUT_SIZE];

  int8_t row = 0;

  int24_t n = 119;
  uint16_t steps = 1;
  uint24_t a = 18 + 1;
  uint24_t b2 = 0;
  uint24_t b = 0;

  os_ClrHome();

  os_GetStringInput("Enter N: ", input, sizeof input);
  n = atoi(input);

  os_ClrHome();

  a = ceil(sqrt(n));
  b2 = square(a) - n;

  while(sqrt(b2) != floor(sqrt(b2)) && !os_GetCSC()) {
    a++;
    b2 = square(a) - n;
  }

  b = sqrt(b2);

  sprintf(str, "%d=%d*%d", n, a - b, n / (a - b));
  print(row++, str);

  sprintf(str, "%d tries", a);
  print(row++, str);

  /* Wait for a key to be pressed */
  while (!os_GetCSC());
}

void print(int8_t row, const char *text) {
  os_SetCursorPos(row, 0);
  os_PutStrFull(text);
}
