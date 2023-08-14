/**
 * @file    node.hpp
 * @author  Lorenzo Liuzzo (lorenzoliuzzo@outlook.com)
 * @brief   This file contains the definition of the node structure.
 * @date    2023-08-13
 * 
 * @copyright Copyright (c) 2023
 */


#pragma once

#include <iostream>
#include <memory> 
#include <string>
#include <unordered_map>
#include <vector>


// forward declarations
struct operation;

template <typename T>
struct node; 

// aliases
template <typename T>
using node_ptr = std::shared_ptr<node<T>>;

template <typename T>
using gradient_map = std::unordered_map<node_ptr<T>, double>;


/// @brief Node structure representing a variable
template <typename T>
struct node {

    T value;
    std::string name; 

    std::vector<std::shared_ptr<node>> children;
    std::shared_ptr<operation> op;


    constexpr node() noexcept : value{}, name{}, children{}, op{} {}

    constexpr node(T value, const std::string& name = "") noexcept : 
        value{value}, name{name}, children{}, op{} {}


    constexpr operator std::shared_ptr<node>() {
        return std::make_shared<node>(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const node& n) {

        if (n.name.empty()) 
            return os << n.value;
        else 
            os << n.name << " = " << std::to_string(n.value);

        return os;

    }

    friend std::ostream& operator<<(std::ostream& os, const node_ptr<T>& n) {
        return os << *n;
    }

};


template <typename T>
constexpr node_ptr<T> variable(const std::string& name, T value) {
    return std::make_shared<node<T>>(value, name);
}

template <typename T>
constexpr node_ptr<T> constant(T value) {
    return std::make_shared<node<T>>(value);
}