#include "encrypt.h"

#include "../shared/shared.h"

void handleEncrypt() {
  char input[INPUT_SIZE];

  /* key, message, modulo */
  uint24_t e, m, n;

  os_GetStringInput("Enter message m: ", input, sizeof input);
  m = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter key e: ", input, sizeof input);
  e = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter mod n: ", input, sizeof input);
  n = atoi(input);
  os_ClrHome();

  moduloExponent(m, e, n);
}
