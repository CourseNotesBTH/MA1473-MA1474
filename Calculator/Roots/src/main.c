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
#include "test/test.h"
#include "find/find.h"

#define MENU_CHOICES 2
const char *menu[] = {"root test", "find roots"};

void main(void) {
  const char str[CHARACTER_WIDTH];
  char input[INPUT_SIZE];
  kb_key_t key, previousKey;

  bool menuVisible = true;

  int8_t row = 0;
  int8_t menuChoice = 0;

  os_ClrHome();
  /* print menu */
  for (row = 0; row < MENU_CHOICES; row++)
    print(row, 2, menu[row]);
  /* print menu choice */
  print(menuChoice, 0, ">");

  do {
    kb_Scan();

    key = kb_Data[7];

    if (key && key != previousKey) {
      if (key == kb_Up) {
        if (menuChoice > 0)
          menuChoice--;
        else if (menuChoice == 0)
          menuChoice = MENU_CHOICES - 1;
        clearFromLeft(MENU_CHOICES, " ");
        print(menuChoice, 0, ">");
      } else if (key == kb_Down) {
        if (menuChoice < MENU_CHOICES - 1)
          menuChoice++;
        else if (menuChoice == MENU_CHOICES - 1)
          menuChoice = 0;
        clearFromLeft(MENU_CHOICES, " ");
        print(menuChoice, 0, ">");
      }
    }
    previousKey = key;

    if (kb_Data[6] == kb_Enter && menuVisible) {
      menuVisible = false;
      os_ClrHome();
      if (menuChoice == 0)
        handleTest();
      else if (menuChoice == 1)
        handleFind();
    }
  } while (kb_Data[1] != kb_2nd);
}
