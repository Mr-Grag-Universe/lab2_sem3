//
// Created by Stephan on 17.09.2022.
//

#ifndef LAB2_SEM3_TEST_CLASSES_H
#define LAB2_SEM3_TEST_CLASSES_H
#include "gtest/gtest.h"
#include "CN_graph/CN_graph.h"

class TestCN : public ::testing::Test
{
public:
    virtual void SetUp() {
        cn_plus_plus_small = CN_graph(2, 0.5, 1);
        cn_plus_minus_small = CN_graph(3, -0.5, 1);
        cn_minus_plus_small = CN_graph(-3, 2, 1);
        cn_minus_minus_small = CN_graph(-3, -2, 1);
    }
    virtual void TearDown() {

    }
protected:
    CN_graph cn_plus_plus_small;
    CN_graph cn_plus_minus_small;
    CN_graph cn_minus_plus_small;
    CN_graph cn_minus_minus_small;
    CN_graph cn_zero_zero;
    // CN_graph cn_zero_small1 = CN_graph(3, 0, 1);
    // CN_graph cn_zero_small2 = CN_graph(0, FLT_MAX, 1);
protected:
};

class SpecialCN : public  ::testing::Test {
public:
    SpecialCN() = default;
protected:
    CN_graph cn_vert_plus_small = CN_graph(3, 2000, 1);
    CN_graph cn_hor_plus_small = CN_graph(3, 0, 1);
};

#endif //LAB2_SEM3_TEST_CLASSES_H
