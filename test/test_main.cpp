//
// Created by Stephan on 08.09.2022.
//

#include <cmath>
#include "gtest/gtest.h"
#include "CN_graph/CN_graph.h"


class TestCN : public ::testing::Test
{
public:
    TestCN() = default;
protected:
    CN_graph cn_plus_plus_small = CN_graph(2, 0.5, 1);
    CN_graph cn_plus_minus_small = CN_graph(3, -0.5, 1);
    CN_graph cn_minus_plus_small = CN_graph(-3, 2, 1);
    CN_graph cn_minus_minus_small = CN_graph(-3, -2, 1);
    CN_graph cn_zero_zero = CN_graph(0, 0, 1);
    // CN_graph cn_zero_small1 = CN_graph(3, 0, 1);
    // CN_graph cn_zero_small2 = CN_graph(0, FLT_MAX, 1);
protected:
};

TEST(initial_funcs, construct) {
    CN_graph cn(0, 0, 0);
    EXPECT_EQ(cn.slope_coefficient(), 0.0);
    EXPECT_EQ(cn.free_member(), 0);
    EXPECT_EQ(cn.extra_radius(), 0);
}

TEST_F(TestCN, y_from_x) {
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.y_from_x(3), std::sqrt(2) * 4 + 1);
    EXPECT_DOUBLE_EQ(cn_plus_minus_small.y_from_x(3), std::sqrt(2) * 2 + 1);
    EXPECT_DOUBLE_EQ(cn_minus_plus_small.y_from_x(3), std::sqrt(2) * 3 + 1);
    EXPECT_DOUBLE_EQ(cn_minus_minus_small.y_from_x(3), std::sqrt(2) * 3 + 1);
}

TEST_F(TestCN, y_from_angle) {
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.y_from_angle(M_PI/4), std::sqrt(2) * 4 + 1);
    EXPECT_DOUBLE_EQ(cn_plus_minus_small.y_from_angle(M_PI/4), std::sqrt(2) * 2 + 1);
    EXPECT_DOUBLE_EQ(cn_minus_plus_small.y_from_angle(M_PI/4), std::sqrt(2) * 3 + 1);
    EXPECT_DOUBLE_EQ(cn_minus_minus_small.y_from_angle(M_PI/4), std::sqrt(2) * 3 + 1);
}

TEST_F(TestCN, radius_vector_angle) {
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.radius_vector(M_PI/4), std::sqrt(2) * 4 + 1);
    EXPECT_DOUBLE_EQ(cn_plus_minus_small.radius_vector(M_PI/4), std::sqrt(2) * 2 + 1);
    EXPECT_DOUBLE_EQ(cn_minus_plus_small.radius_vector(M_PI/4), std::sqrt(2) * 3 + 1);
    EXPECT_DOUBLE_EQ(cn_minus_minus_small.radius_vector(3*M_PI/4), std::sqrt(2) * 3 + 1);
}

TEST_F(TestCN, radius_vector_coords) {
    std::pair <double, double> coords(3, 4);
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.radius_vector(coords), 5);
}

TEST_F(TestCN, CR_in_CP_of_CN) {
    std::vector <std::pair<std::string, double>> v = cn_plus_plus_small.CR_in_CP_of_CN();
    EXPECT_DOUBLE_EQ(v[0].second, 1);
    EXPECT_DOUBLE_EQ(v[1].second, 1);
    EXPECT_DOUBLE_EQ(v[2].second, 1);
}

TEST_F(TestCN, loop_area) {
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.loop_area(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    initial_funcs_construct_Test();

    TestCN_y_from_x_Test();
    TestCN_y_from_angle_Test();

    TestCN_radius_vector_angle_Test();
    TestCN_radius_vector_coords_Test();

    TestCN_CR_in_CP_of_CN_Test();

    TestCN_loop_area_Test();

    return RUN_ALL_TESTS();
}