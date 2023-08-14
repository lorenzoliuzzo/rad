/**
 * @file    node.cpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the test of the node structure.
 * @date    2023-08-13
 * k
 * @copyright Copyright (c) 2023
 */


#include <gtest/gtest.h>

#include "ctda/ctda.hpp"

#include "node.hpp"

#include <array>
#include <complex>


TEST(Node, Constructors) {

    node<double> n0;

    EXPECT_EQ(n0.value, 0.0);
    EXPECT_EQ(n0.name, "");
    EXPECT_EQ(n0.children.size(), 0);
    EXPECT_EQ(n0.op, nullptr);


    node<double> n1{1.0, "n1"};

    EXPECT_EQ(n1.value, 1.0);
    EXPECT_EQ(n1.name, "n1");
    EXPECT_EQ(n1.children.size(), 0);
    EXPECT_EQ(n1.op, nullptr);


    node<std::array<double, 3>> n2;

    EXPECT_EQ(n2.value, (std::array<double, 3>{0.0, 0.0, 0.0}));
    EXPECT_EQ(n2.name, "");
    EXPECT_EQ(n2.children.size(), 0);
    EXPECT_EQ(n2.op, nullptr);


    node<std::complex<double>> n3({1.0, 1.0}, "n3");

    EXPECT_EQ(n3.value, (std::complex<double>{1.0, 1.0}));
    EXPECT_EQ(n3.name, "n3");
    EXPECT_EQ(n3.children.size(), 0);
    EXPECT_EQ(n3.op, nullptr);


}


int main(int argc, char** argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}