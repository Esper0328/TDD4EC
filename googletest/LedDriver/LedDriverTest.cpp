#include <stdint.h>

extern "C"
{
#include "LedDriver.h"
}

#include <gtest/gtest.h>

TEST(LedDriver, LedsOffAfterCreate)
{
    uint16_t virtualleds = 0xffff;
    LedDriver_Create(&virtualleds);
    ASSERT_EQ(0, virtualleds);
}

TEST(LedDriver, TurnOnLedOne)
{
    uint16_t virtualleds = 0;
    LedDriver_Create(&virtualleds);
    LedDriver_TurnOn(1);
    ASSERT_EQ(1, virtualleds);
}
