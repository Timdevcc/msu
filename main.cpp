#include <iostream>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <class C> typename C::value_type process (const C &c) {
    typename C::value_type result {};

    auto it = c.rbegin();
    int k = 0;
    while (it != c.rend() && k != 3) {
        result += *it;
        std::cout <<*it<< " ";
        it++;
        if (it != c.rend()) {
            it++;
            k++;
        } else {
            break;
        }
    }

    return result;
}

int main() {
    
    
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << "\nsum = " << process(v1) << "\n"; // 5 3 1 -> 9

    std::vector<int> v2 = {10, 20, 30, 40, 50, 60};
    std::cout << "\nsum = " << process(v2) << "\n"; // 60 40 20 -> 120

    std::vector<int> v3 = {7};
    std::cout << "\nsum = " << process(v3) << "\n"; // 7 -> 7

    std::vector<int> v4 = {};
    std::cout << "\nsum = " << process(v4) << "\n"; // 0
}
    

