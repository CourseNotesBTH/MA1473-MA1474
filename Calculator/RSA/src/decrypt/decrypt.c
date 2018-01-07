#include "decrypt.h"

#include "../shared/shared.h"

void handleDecrypt() {
  char input[INPUT_SIZE];

  /* key, message, modulo */
  uint24_t d, m, n;

  os_GetStringInput("Enter message m: ", input, sizeof input);
  m = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter key d: ", input, sizeof input);
  d = atoi(input);
  os_ClrHome();
  os_GetStringInput("Enter mod n: ", input, sizeof input);
  n = atoi(input);
  os_ClrHome();

  moduloExponent(m, d, n);
}
