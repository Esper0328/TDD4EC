#include "LedDriver.h"

static uint16_t* ledsAdrress;
void LedDriver_Create(uint16_t* address) {
  ledsAdrress = address;
  *ledsAdrress = 0;
}

void LedDriver_TurnOn(int ledNumber) { *ledsAdrress = 1; }
void LedDriver_TurnOff(int ledNumber) { *ledsAdrress = 0; }
void LedDriver_Destroy(void) {}

