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

#include "shared/shared.h"

void main(void) {
  const char str[CHARACTER_WIDTH];
  char input[INPUT_SIZE];

  /* base, exponent, modulo room */
  uint24_t a, b, n;

  uint8_t row = 0;

  os_ClrHome();
  os_GetStringInput("Enter base a: ", input, sizeof input);
  a = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter exponent b: ", input, sizeof input);
  b = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter modulo n: ", input, sizeof input);
  n = atoi(input);
  os_ClrHome();

  moduloExponent(a, b, n);

  /* Wait for a key to be pressed */
  while (!os_GetCSC());
}
