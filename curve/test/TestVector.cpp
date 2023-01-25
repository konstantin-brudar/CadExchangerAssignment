#include "TestUtil.hpp"

#include <curve/Vector.hpp>

#include <gtest/gtest.h>


TEST(TestVector, TestVector_Init)
{
    const auto v = cadexchanger::Vector(1, 2.5, 3.987);
    ASSERT_NEAR(1, v.x, EPS);
    ASSERT_NEAR(2.5, v.y, EPS);
    ASSERT_NEAR(3.987, v.z, EPS);
}

