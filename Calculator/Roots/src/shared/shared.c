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

uint32_t ipow(uint32_t base, uint32_t exponent)
{
  uint32_t result = 1;
  while (exponent)
  {
    if (exponent & 1)
        result *= base;
    exponent >>= 1;
    base *= base;
  }

  return result;
}

void reverse(char *string, int length)
{
    int i = 0, j = length - 1, temp;
    while (i < j)
    {
        temp = string[i];
        string[i++] = string[j];
        string[j--] = temp;
    }
}

int ultoa(uint32_t value, char *string)
{
  int i = 0;
  while (value)
  {
      string[i++] = (value % 10) + '0';
      value = value / 10;
  }

  reverse(string, i);
  string[i] = '\0';
  return i;
}
