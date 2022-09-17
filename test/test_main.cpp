//
// Created by Stephan on 08.09.2022.
//

#include <cmath>
#include "gtest/gtest.h"
#include "CN_graph/CN_graph.h"
#include "test_classes.h"


TEST(initial_funcs, construct) {
    CN_graph cn(0, 0, 0);
    EXPECT_EQ(cn.slope_coefficient(), 0.0);
    EXPECT_EQ(cn.free_member(), 0);
    EXPECT_EQ(cn.extra_radius(), 0);
}

TEST_F(TestCN, y_from_x) {
    CN_graph cn(3, 2000, 2);
    std::vector<std::pair<double, double>> ip = cn.inflection_points();
    EXPECT_DOUBLE_EQ(cn.y_from_x(4), 6.9282032302755088);
}

TEST_F(TestCN, y_from_angle) {
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.y_from_angle(M_PI/4), std::sqrt(2) * cn_plus_plus_small.extra_radius() / 2 + 4);
    EXPECT_DOUBLE_EQ(cn_plus_minus_small.y_from_angle(M_PI/4), std::sqrt(2) * cn_plus_plus_small.extra_radius() / 2 + 2);
    EXPECT_DOUBLE_EQ(cn_minus_plus_small.y_from_angle(M_PI/4), std::sqrt(2) * cn_plus_plus_small.extra_radius() / 2 + 3);
    EXPECT_DOUBLE_EQ(cn_minus_minus_small.y_from_angle(M_PI/4), std::sqrt(2) * cn_plus_plus_small.extra_radius() / 2 - 1);
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
    CN_graph cn(3, 3, 5);
    std::vector <std::pair<std::string, double>> v = cn.CR_in_CP_of_CN();
    EXPECT_DOUBLE_EQ(v[0].second, 12.8);
    EXPECT_DOUBLE_EQ(v[1].second, 0.8);
    EXPECT_DOUBLE_EQ(v[2].second, 3.3333333333333335);
}

TEST_F(TestCN, loop_area) {
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.loop_area(), 0);
}

TEST(just_test, inflection_points) {
    CN_graph cn(3, 2000, 2);
    std::vector<std::pair<double, double>> ip = cn.inflection_points();
    std::cout << ip.size();
    EXPECT_DOUBLE_EQ(ip[0].first, 4);
    EXPECT_DOUBLE_EQ(ip[0].second, 6.9282032302755088);
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

    just_test_inflection_points_Test();

    return RUN_ALL_TESTS();
}