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
/* 5 characters = 99'999. 2^24 / 2 = 8388608. 99'999 < 8388608. 6 - 1(null) = 5 */
#define INPUT_SIZE 6

void print(int8_t row, const char *text);

void main(void) {
  const char str[CHARACTER_WIDTH];
  char input[INPUT_SIZE];

  int8_t row = 0;

  int24_t a = 359;
  int24_t b = 43;

  int24_t u1 = 1;
  int24_t u2 = 0;
  int24_t u3 = a;
  int24_t v1 = 0;
  int24_t v2 = 1;
  int24_t v3 = b;
  int24_t q = 0;

  int24_t temp = 0;
  uint8_t steps = 1;

  int24_t gcd = 0;
  int24_t m = 0;
  int24_t n = 0;

  int24_t prev = a;

  os_ClrHome();

  os_GetStringInput("Enter A: ", input, sizeof input);
  a = atoi(input);


  os_GetStringInput("Enter B: ", input, sizeof input);
  b = atoi(input);

  if (b > a) {
    temp = b;
    b = a;
    a = temp;
  }

  u3 = a;
  prev = a;
  v3 = b;

  os_ClrHome();

  if (a % b == 0) {
    sprintf(str, "%d=%d*%d+0", a, b, (a / b));
    print(row++, str);
    /* Wait for a key to be pressed */
    while (!os_GetCSC());
    return;
  }

  while (v3 != 0) {
    q = u3 / v3;

    temp = v1;
    v1 = u1 - q * v1;
    u1 = temp;

    temp = v2;
    v2 = u2 - q * v2;
    u2 = temp;

    temp = v3;
    v3 = u3 - q * v3;
    u3 = temp;

    sprintf(str, "%d=%d*%d+%d", prev, u3, q, v3);
    print(row++, str);

    prev = u3;

    if (steps++ % (CHARACTER_HEIGHT - 1) == 0) {
      print(CHARACTER_HEIGHT, "Continue...");
      /* Wait for a key to be pressed */
      while (!os_GetCSC());
      row = 0;
      os_ClrHome();
    }
  }

	gcd = u3;
	m = u1;
	n = (gcd - m*a) / b;

  sprintf(str, "GCD: %d", gcd);
  print(row++, str);

  sprintf(str, "%d=%d(%d)+%d(%d)", gcd, a, m, b, n);
  print(row++, str);

  /* Wait for a key to be pressed */
  while (!os_GetCSC());
}

void print(int8_t row, const char *text) {
  os_SetCursorPos(row, 0);
  os_PutStrFull(text);
}
