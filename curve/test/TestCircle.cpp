#include "TestUtil.hpp"

#include <curve/Circle.hpp>
#include <curve/Vector.hpp>

#include <gtest/gtest.h>


TEST(TestCircle, TestCircle_Point_0)
{
    double t = 0;
    const auto circle = cadexchanger::Circle(1);
    const auto p = circle.point(t);
    ASSERT_NEAR(1, p.x, EPS);
    ASSERT_NEAR(0, p.y, EPS);
    ASSERT_NEAR(0, p.z, EPS);
}

TEST(TestCircle, TestCircle_Point_PI)
{
    double t = PI;
    const auto circle = cadexchanger::Circle(1);
    const auto p = circle.point(t);
    ASSERT_NEAR(-1, p.x, EPS);
    ASSERT_NEAR(0, p.y, EPS);
    ASSERT_NEAR(0, p.z, EPS);
}

TEST(TestCircle, TestCircle_Point_2PI)
{
    double t = 2 * PI;
    const auto circle = cadexchanger::Circle(1);
    const auto p = circle.point(t);
    ASSERT_NEAR(1, p.x, EPS);
    ASSERT_NEAR(0, p.y, EPS);
    ASSERT_NEAR(0, p.z, EPS);
}

TEST(TestCircle, TestCircle_Derivative_0)
{
    double t = 0;
    const auto circle = cadexchanger::Circle(1);
    const auto d = circle.derivative(t);
    ASSERT_NEAR(0, d.x, EPS);
    ASSERT_NEAR(1, d.y, EPS);
    ASSERT_NEAR(0, d.z, EPS);
}

TEST(TestCircle, TestCircle_Derivative_PI)
{
    double t = PI;
    const auto circle = cadexchanger::Circle(1);
    const auto d = circle.derivative(t);
    ASSERT_NEAR(0, d.x, EPS);
    ASSERT_NEAR(-1, d.y, EPS);
    ASSERT_NEAR(0, d.z, EPS);
}

TEST(TestCircle, TestCircle_Derivative_2PI)
{
    double t = 2 * PI;
    const auto circle = cadexchanger::Circle(1);
    const auto d = circle.derivative(t);
    ASSERT_NEAR(0, d.x, EPS);
    ASSERT_NEAR(1, d.y, EPS);
    ASSERT_NEAR(0, d.z, EPS);
}

