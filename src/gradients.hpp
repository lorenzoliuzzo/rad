#pragma once

#include "node.hpp"
#include <tuple>


// Define the wrt function to create a tuple of nodes to differentiate with respect to
template <typename... Args>
auto wrt(const Args&... vars) {
    return std::make_tuple(vars...);
}


// Define the gradients function to compute derivatives for multiple input nodes
template <typename... Args>
gradient_map gradients(const node_ptr& output, const std::tuple<Args...>& vars) {
    gradient_map grad;
    output->op->gradient(output, grad);
    return grad;
}