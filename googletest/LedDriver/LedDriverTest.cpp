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
    EXPECT_EQ(0, virtualleds);
}

