#include <iostream>
#include <string>
#include <exception>

class Printer {
    std::string s;

public:
    explicit Printer(const std::string& str) : s(str) {}

    ~Printer() {
        std::cout << s << '\n';
    }
};

void solve() {
    std::string s;
    if (!(std::cin >> s)) {
        throw 1;
    }

    Printer p(s);
    solve();
}

int main() {
    try {
        solve();
    } catch (...) {
    }
    return 0;
}
