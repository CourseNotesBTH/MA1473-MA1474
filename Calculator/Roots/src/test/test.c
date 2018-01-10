#include "test.h"

#include "../shared/shared.h"

void handleTest() {
  char str[CHARACTER_WIDTH];
  char str1[CHARACTER_WIDTH];
  char input[INPUT_SIZE];

  /* number to test, room, exponent, found "roots" */
  uint24_t x = 0, n = 0, k = 1, ones = 0;
  uint32_t temp1 = 0, temp2 = 0;

  uint8_t row = 0;

  os_GetStringInput("Enter number to test x: ", input, sizeof input);
  x = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter room to test n: ", input, sizeof input);
  n = atoi(input);
  os_ClrHome();

  for (k = 1; k <= n; k++) {
    temp1 = ipow(x, k);
    temp2 = temp1 % n;
    if (temp2 == 1)
      ones++;
    sprintf(str, "%u^%u=", x, k);
    ultoa(temp1, str1);
    strcat(str, str1);
    sprintf(str1, "=%u", temp2);
    strcat(str, str1);
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
