#include "TestUtil.hpp"

#include <curve/Helix.hpp>
#include <curve/Vector.hpp>

#include <gtest/gtest.h>


TEST(TestHelix, TestHelix_Step)
{
    const double step = 15;
    const double t0 = 7;
    const double t1 = t0 + 2 * PI;
    const auto helix = cadexchanger::Helix(1, step);
    const auto p0 = helix.point(t0);
    const auto p1 = helix.point(t1);
    ASSERT_NEAR(p0.x, p1.x, EPS);
    ASSERT_NEAR(p0.y, p1.y, EPS);
    ASSERT_NEAR(p0.z + step, p1.z, EPS);
}

