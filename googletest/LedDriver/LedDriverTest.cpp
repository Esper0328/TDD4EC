#include <stdint.h>

extern "C" {
#include "LedDriver.h"
}

#include <gtest/gtest.h>

class LedDriverTest : public ::testing::Test {
    protected:
        uint16_t virtualleds;
        virtual void SetUp() { LedDriver_Create(&virtualleds); }
};

TEST_F(LedDriverTest, LedsOffAfterCreate) {
    virtualleds = 0xffff;
    LedDriver_Create(&virtualleds);
    ASSERT_EQ(0, virtualleds);
}

TEST_F(LedDriverTest, TurnOnLedOne) {
    LedDriver_TurnOn(1);
    ASSERT_EQ(1, virtualleds);
}

TEST_F(LedDriverTest, TurnOffLedOne) {
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    ASSERT_EQ(0, virtualleds);
}

TEST_F(LedDriverTest, TurnOnMultipleLeds) {
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    ASSERT_EQ(0x180, virtualleds);
}

TEST_F(LedDriverTest, TurnOffMultipleLeds) {
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(15);
    LedDriver_TurnOff(9);
    LedDriver_TurnOff(15);
    ASSERT_EQ(0x80, virtualleds);
}
