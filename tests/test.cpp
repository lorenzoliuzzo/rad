#include "node.hpp"
#include "operations.hpp"
#include "operators.hpp"
#include "gradients.hpp"


int main() {
    
    auto x = variable("x", 2.0);
    std::cout << x << '\n';

    auto y = variable("y", 3.0);
    std::cout << y << '\n';

    auto add = add_op(x, y);
    std::cout << add.operands.first->name << '\n';
    std::cout << add.operands.second->name << '\n';

    auto z = add();
    std::cout << '\n' << z << '\n';

    auto grad = gradients(z, wrt(x, y)); 
    std::cout << "grad[x] = " << grad[x] << '\n';
    std::cout << "grad[y] = " << grad[y] << '\n';


    auto w = x * y; 
    std::cout << '\n' << w << '\n';

    grad = gradients(w, wrt(x, y));
    std::cout << "grad[x] = " << grad[x] << '\n';
    std::cout << "grad[y] = " << grad[y] << '\n';


    auto k = invert_op(x)();
    std::cout << '\n' << k << '\n';

    grad = gradients(k, wrt(x, y));
    std::cout << grad[x] << '\n';
    std::cout << grad[y] << '\n';


    grad = gradients(x^2, wrt(x, y));
    std::cout << grad[x] << '\n';
    std::cout << grad[y] << '\n';


    std::cout << *constant(20) << '\n';


    return 0;
}