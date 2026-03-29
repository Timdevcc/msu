#include <iostream>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <class C, class Pred> C myfilter (const C &c, Pred pred) {
    typename C result {};
    auto it = c.begin();
    while (it != c.end()) {
        if (pred(*it)) {
            result.push_back(*it);
        }
        it++;
    }
    return result;
}

int main() {
    
    
    
}
    

