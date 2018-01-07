#include "shared.h"

uint8_t print(int8_t row, int8_t column, const char *text) {
  os_SetCursorPos(row, column);
  os_PutStrFull(text);

  if (row++ == CHARACTER_HEIGHT - 1) {
    os_SetCursorPos(CHARACTER_HEIGHT, 0);
    os_PutStrFull("Continue...");
    /* Wait for a key to be pressed */
    while (!os_GetCSC());
    row = 0;
    os_ClrHome();
  }

  return row;
}

uint8_t printLine(int8_t row, const char *text) {
  return print(row, 0, text);
}

void clearFromLeft(uint8_t rows, const char* clearString) {
  uint8_t row = 0;

  for (row = 0; row < rows; row++)
    print(row, 0, clearString);
}

int ipow(int base, int exp)
{
  int result = 1;
  while (exp)
  {
    if (exp & 1)
        result *= base;
    exp >>= 1;
    base *= base;
  }

  return result;
}
