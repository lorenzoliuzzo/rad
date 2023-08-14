#pragma once

#include "node.hpp"
#include "operations.hpp"


node_ptr operator+(const node& x, const node& y) {
    return add_op(std::make_shared<node>(x), std::make_shared<node>(y))();
}

node_ptr operator+(const node_ptr& x, const node& y) {
    return add_op(x, std::make_shared<node>(y))();
}

node_ptr operator+(const node& x, const node_ptr& y) {
    return add_op(std::make_shared<node>(x), y)();
}

node_ptr operator+(const node_ptr& x, const node_ptr& y) {
    return add_op(x, y)();
}


node_ptr operator*(const node& x, const node& y) {
    return mul_op(std::make_shared<node>(x), std::make_shared<node>(y))();
}

node_ptr operator*(const node_ptr& x, const node& y) {
    return mul_op(x, std::make_shared<node>(y))();
}

node_ptr operator*(const node& x, const node_ptr& y) {
    return mul_op(std::make_shared<node>(x), y)();
}

node_ptr operator*(const node_ptr& x, const node_ptr& y) {
    return mul_op(x, y)();
}


node_ptr operator-(const node& x) {
    return neg_op(std::make_shared<node>(x))();
}

node_ptr operator-(const node_ptr& x) {
    return neg_op(x)();
}


node_ptr operator-(const node& x, const node& y) {
    return sub_op(std::make_shared<node>(x), std::make_shared<node>(y))();
}

node_ptr operator-(const node_ptr& x, const node& y) {
    return sub_op(x, std::make_shared<node>(y))();
}

node_ptr operator-(const node& x, const node_ptr& y) {
    return sub_op(std::make_shared<node>(x), y)();
}

node_ptr operator-(const node_ptr& x, const node_ptr& y) {
    return sub_op(x, y)();
}


node_ptr invert(const node& x) {
    return invert_op(std::make_shared<node>(x))();
}

node_ptr invert(const node_ptr& x) {
    return invert_op(x)();
}

node_ptr operator/(const node& x, const node& y) {
    return div_op(std::make_shared<node>(x), std::make_shared<node>(y))();
}

node_ptr operator/(const node_ptr& x, const node& y) {
    return div_op(x, std::make_shared<node>(y))();
}

node_ptr operator/(const node& x, const node_ptr& y) {
    return div_op(std::make_shared<node>(x), y)();
}

node_ptr operator/(const node_ptr& x, const node_ptr& y) {
    return div_op(x, y)();
}


node_ptr operator^(const node& x, double exponent) {
    return power_op(std::make_shared<node>(x), exponent)();
}

node_ptr operator^(const node_ptr& x, double exponent) {
    return power_op(x, exponent)();
}