#include <iostream>
#include <string>

bool is_ok(const std::string& s) {
    bool second = false; 

    for (char c : s) {
        if (c == '3' || c == '4') {
            if (second) {
                return false; 
            }
        } else if (c == '1' || c == '2') {
            second = true;
        } else {
            return false; 
        }
    }

    return true;
}

int main() {
    std::string s;
    while (std::cin >> s) {
        if (is_ok(s)) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}
