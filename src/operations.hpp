#pragma once

#include "node.hpp"

#include <cmath>


struct operation {

    virtual ~operation() = default;

    virtual node_ptr operator()() = 0;

    virtual void gradient(const node_ptr& output, gradient_map& grad) = 0;

};


struct add_op : public operation {

    std::pair<node_ptr, node_ptr> operands;


    add_op(node_ptr operand1, node_ptr operand2) :
        operands{operand1, operand2} {}

    
    virtual node_ptr operator()() override {

        auto new_node = std::make_shared<node>();
        new_node->op = std::make_shared<add_op>(operands.first, operands.second);
        new_node->children.push_back(operands.first);
        new_node->children.push_back(operands.second);
        new_node->name = "(" + operands.first->name + "+" + operands.second->name + ")";
        new_node->value = operands.first->value + operands.second->value;
        return new_node;

    }

    virtual void gradient(const node_ptr& output, gradient_map& grad) override {
        grad[operands.first] += 1.0;
        grad[operands.second] += 1.0;
    }

};


struct mul_op : public operation {

    std::pair<node_ptr, node_ptr> operands;

    mul_op(node_ptr operand1, node_ptr operand2) :
        operands{operand1, operand2} {}

    virtual node_ptr operator()() override {
        auto new_node = std::make_shared<node>();
        new_node->op = std::make_shared<mul_op>(operands.first, operands.second);
        new_node->children.push_back(operands.first);
        new_node->children.push_back(operands.second);
        new_node->name = "(" + operands.first->name + "*" + operands.second->name + ")";
        new_node->value = operands.first->value * operands.second->value;
        return new_node;
    }

    virtual void gradient(const node_ptr& output, gradient_map& grad) override {
        grad[operands.first] += operands.second->value;
        grad[operands.second] += operands.first->value;
    }

};


struct neg_op : public operation {

    node_ptr operand;

    neg_op(node_ptr operand) :
        operand{operand} {}

    virtual node_ptr operator()() override {
        auto new_node = std::make_shared<node>();
        new_node->op = std::make_shared<neg_op>(operand);
        new_node->children.push_back(operand);
        new_node->name = "(-" + operand->name + ")";
        new_node->value = -operand->value;
        return new_node;
    }

    virtual void gradient(const node_ptr& output, gradient_map& grad) override {
        grad[operand] -= 1.0;
    }

};


struct sub_op : public operation {

    std::pair<node_ptr, node_ptr> operands;


    sub_op(node_ptr operand1, node_ptr operand2) :
        operands{operand1, operand2} {}

    
    virtual node_ptr operator()() override {

        auto new_node = std::make_shared<node>();
        new_node->op = std::make_shared<sub_op>(operands.first, operands.second);
        new_node->children.push_back(operands.first);
        new_node->children.push_back(operands.second);
        new_node->name = "(" + operands.first->name + "-" + operands.second->name + ")";
        new_node->value = operands.first->value - operands.second->value;
        return new_node;

    }

    virtual void gradient(const node_ptr& output, gradient_map& grad) override {
        grad[operands.first] += 1.0;
        grad[operands.second] -= 1.0;
    }

};


struct invert_op : public operation {

    node_ptr operand;

    invert_op(node_ptr operand) :
        operand{operand} {}

    virtual node_ptr operator()() override {
        auto new_node = std::make_shared<node>();
        new_node->op = std::make_shared<invert_op>(operand);
        new_node->children.push_back(operand);
        new_node->name = "(1/" + operand->name + ")";
        new_node->value = 1.0 / operand->value;
        return new_node;
    }

    virtual void gradient(const node_ptr& output, gradient_map& grad) override {
        grad[operand] -= 1.0 / std::pow(operand->value, 2);
    }

};


struct div_op : public operation {

    std::pair<node_ptr, node_ptr> operands;

    div_op(node_ptr operand1, node_ptr operand2) :
        operands{operand1, operand2} {}

    virtual node_ptr operator()() override {
        auto new_node = std::make_shared<node>();
        new_node->op = std::make_shared<div_op>(operands.first, operands.second);
        new_node->children.push_back(operands.first);
        new_node->children.push_back(operands.second);
        new_node->name = "(" + operands.first->name + "/" + operands.second->name + ")";
        new_node->value = operands.first->value / operands.second->value;
        return new_node;
    }

    virtual void gradient(const node_ptr& output, gradient_map& grad) override {
        grad[operands.first] += 1.0 / operands.second->value;
        grad[operands.second] -= operands.first->value / std::pow(operands.second->value, 2);
    }

};


struct power_op : public operation {

    node_ptr base;
    double exponent;

    power_op(node_ptr base, double exponent) :
        base{base}, exponent{exponent} {}

    virtual node_ptr operator()() override {
        auto new_node = std::make_shared<node>();
        new_node->op = std::make_shared<power_op>(base, exponent);
        new_node->children.push_back(base);
        new_node->name = "(" + base->name + "^" + std::to_string(exponent) + ")";
        new_node->value = std::pow(base->value, exponent);
        return new_node;
    }

    virtual void gradient(const node_ptr& output, gradient_map& grad) override {
        grad[base] += exponent * std::pow(base->value, exponent - 1);
    }

};
