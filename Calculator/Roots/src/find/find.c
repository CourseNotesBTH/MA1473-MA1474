#include "find.h"

#include "../shared/shared.h"

void handleFind() {
  const char str[CHARACTER_WIDTH];
  char input[INPUT_SIZE];

  /* current number to test, room, exponent, found "roots" */
  uint24_t x = 0, n = 0, k = 1, ones = 0;
  uint32_t temp1 = 0, temp2 = 0;

  uint8_t row = 0;

  os_GetStringInput("Enter room to test n: ", input, sizeof input);
  n = atoi(input);
  os_ClrHome();

  for (x = 2; x <= n; x++) {
    for (k = 1; k <= n; k++) {
      temp1 = ipow(x, k);
      temp2 = temp1 % n;
      if (temp2 == 1)
        ones++;
    }

    if (ones == 1) {
      sprintf(str, "%u is a root in Z%u", x, n);
      row = printLine(row, str);
    }
    ones = 0;
  }
}
