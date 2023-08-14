#include "rad.hpp"

// #include <iostream>
// #include <unordered_map>
// #include <string>
// #include <stdexcept>
// #include <cmath>

// class Node;

// class NodeDict : public std::unordered_map<Node*, double> {
// public:
//     using std::unordered_map<Node*, double>::operator[];
//     using std::unordered_map<Node*, double>::count;

//     double& operator[](Node* key) {
//         if (dynamic_cast<Node*>(key)) {
//             return std::unordered_map<Node*, double>::operator[](key);
//         }
//         auto it = find(key);
//         if (it != end()) {
//             return it->second;
//         }
//         throw std::out_of_range("Key not found");
//     }

//     bool Contains(Node* key) const {
//         if (dynamic_cast<Node*>(key)) {
//             return std::unordered_map<Node*, double>::count(key) > 0;
//         }
//         return find(key) != end();
//     }

//     void Erase(Node* key) {
//         if (dynamic_cast<Node*>(key)) {
//             std::unordered_map<Node*, double>::erase(key);
//         } else {
//             auto it = find(key);
//             if (it != end()) {
//                 std::unordered_map<Node*, double>::erase(it);
//             } else {
//                 throw std::out_of_range("Key not found");
//             }
//         }
//     }
// };

// class Node {
// public:
//     std::string name;
//     double value;
//     std::vector<Node> inputs;
//     Op* op;
//     double const_attr;

//     Node(const std::string& name = "", double value = 0.0)
//         : name(name), value(value), op(nullptr), const_attr(0.0) {
//     }

//     Node operator+(const Node& other) const {
//         if (dynamic_cast<const Node*>(&other)) {
//             return add_op(*this, other);
//         } else {
//             return add_byconst_op(*this, other);
//         }
//     }

//     // Implement other operators similarly...

//     bool IsInstanceOf(const Node& other) const {
//         // Check if this node is an instance of the same class as 'other'.
//         return dynamic_cast<const Node*>(&other) != nullptr;
//     }

//     // Implement other member functions...
// };

// // Rest of the code remains unchanged...

// class Op {
// public:
//     virtual Node Call() {
//         Node new_node;
//         new_node.op = this;
//         return new_node;
//     }

//     virtual double Compute(const Node& node, const NodeDict& input_vals) const {
//         throw std::runtime_error("Compute function not implemented");
//     }

//     virtual NodeDict Gradient(const Node& node, double output_grad) const {
//         throw std::runtime_error("Gradient function not implemented");
//     }
// };

// class PlaceholderOp : public Op {
// public:
//     virtual Node Call() override {
//         Node new_node = Op::Call();
//         return new_node;
//     }

//     virtual NodeDict Gradient(const Node& node, double output_grad) const override {
//         return NodeDict(); // Placeholder nodes have no gradients
//     }
// };

// Node Variable(const std::string& name, double value) {
//     Node placeholder_node;
//     placeholder_node.op = new PlaceholderOp();
//     placeholder_node.name = name;
//     placeholder_node.value = value;
//     return placeholder_node;
// }

// int main() {
//     // Example usage
//     Node x = Variable("x", 2.0);
//     Node y = Variable("y", 3.0);
//     Node z = x + y;
//     NodeDict input_vals;
//     input_vals[x] = 2.0;
//     input_vals[y] = 3.0;
//     double result = z.op->Compute(z, input_vals);
//     std::cout << "Result: " << result << std::endl;
//     return 0;
// }
