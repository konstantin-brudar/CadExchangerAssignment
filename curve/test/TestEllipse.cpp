#include "TestUtil.hpp"

#include <curve/Ellipse.hpp>
#include <curve/Vector.hpp>

#include <gtest/gtest.h>


TEST(TestEllipse, TestEllipse_Point_0)
{
    double t = 0;
    const auto ellipse = cadexchanger::Ellipse(1, 2);
    const auto p = ellipse.point(t);
    ASSERT_NEAR(1, p.x, EPS);
    ASSERT_NEAR(0, p.y, EPS);
    ASSERT_NEAR(0, p.z, EPS);
}

TEST(TestEllipse, TestEllipse_Point_PI_div_2)
{
    double t = PI / 2;
    const auto ellipse = cadexchanger::Ellipse(1, 2);
    const auto p = ellipse.point(t);
    ASSERT_NEAR(0, p.x, EPS);
    ASSERT_NEAR(2, p.y, EPS);
    ASSERT_NEAR(0, p.z, EPS);
}

