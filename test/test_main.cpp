//
// Created by Stephan on 08.09.2022.
//

#include "gtest/gtest.h"
#include "CN_graph/CN_graph.h"


class TestCN : public ::testing::Test
{
public:
    TestCN() = default;
protected:
    CN_graph cn_plus_plus_small = CN_graph(3, 2, 1);
    CN_graph cn_plus_minus_small = CN_graph(3, -2, 1);
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


TEST_F(TestCN, radius_vector_angle) {
    EXPECT_DOUBLE_EQ(cn_plus_plus_small.radius_vector(1), 1);
    EXPECT_DOUBLE_EQ(cn_plus_minus_small.radius_vector(1), 1);
    EXPECT_DOUBLE_EQ(cn_minus_plus_small.radius_vector(1), 1);
    EXPECT_DOUBLE_EQ(cn_minus_minus_small.radius_vector(1), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    initial_funcs_construct_Test();
    TestCN_radius_vector_angle_Test();
    return RUN_ALL_TESTS();
}