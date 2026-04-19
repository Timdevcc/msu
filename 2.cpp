#include <iostream>
#include <string>
using namespace std;

bool ok(const string& s) {
    int n = s.size(), i = 0;

    while (i < n && s[i] == '0') i++;
    int k = i;
    while (i < n && s[i] == '1') i++;
    int len = i;

    if (k == 0 || len == k) return false; 
    if (n % len != 0) return false;

    string block = s.substr(0, len);

    for (int j = 0; j < n; j += len)
        if (s.substr(j, len) != block)
            return false;

    return true;
}

int main() {
    string s;
    while (cin >> s)
        cout << ok(s) << '\n';
}
