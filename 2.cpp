#include <bits/stdc++.h>
using namespace std;

bool isNonterminal(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, string>> rules;
    string left, right;

    while (cin >> left >> right) {
        rules.push_back({left, right});
    }

    if (rules.empty()) return 0;

    set<char> reachable;

    // Стартовый символ — левая часть первого правила
    reachable.insert(rules[0].first[0]);

    bool changed = true;

    while (changed) {
        changed = false;

        for (auto &rule : rules) {
            char lhs = rule.first[0];

            if (!reachable.count(lhs)) continue;

            for (char c : rule.second) {
                if (isNonterminal(c) && !reachable.count(c)) {
                    reachable.insert(c);
                    changed = true;
                }
            }
        }
    }

    for (auto &rule : rules) {
        char lhs = rule.first[0];

        if (reachable.count(lhs)) {
            cout << rule.first << ' ' << rule.second << '\n';
        }
    }

    return 0;
}
