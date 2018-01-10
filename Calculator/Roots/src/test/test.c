#include "test.h"

#include "../shared/shared.h"

void handleTest() {
  char str[CHARACTER_WIDTH];
  char input[INPUT_SIZE];

  /* number to test, room, exponent, found "roots" */
  uint24_t x = 0, n = 0, k = 1, ones = 0, temp1 = 0;

  uint8_t row = 0;

  os_GetStringInput("Enter number to test x: ", input, sizeof input);
  x = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter room to test n: ", input, sizeof input);
  n = atoi(input);
  os_ClrHome();

  for (k = 1; k <= n; k++) {
    temp1 = moduloExponent(x, k, n);
    if (temp1 == 1)
      ones++;
    sprintf(str, "%u^%u=...=%u", x, k, temp1);
    row = printLine(row, str);
  }

  if (ones == 1) {
    sprintf(str, "%u is a root in Z%u", x, n);
    row = printLine(row, str);
  } else {
    sprintf(str, "%u is not a root in Z%u", x, n);
    row = printLine(row, str);
  }
}
