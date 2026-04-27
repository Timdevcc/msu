#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<pair<string, char>, string> go;

    string cur;
    while (cin >> cur) {
        if (cur == "END") break;

        string ch, nxt;
        cin >> ch >> nxt;

        go[{cur, ch[0]}] = nxt;
    }

    set<string> terminal;
    string state;

    while (cin >> state) {
        if (state == "END") break;
        terminal.insert(state);
    }

    string start, word;
    cin >> start >> word;

    string current = start;
    int readCount = 0;

    for (char c : word) {
        auto it = go.find({current, c});

        if (it == go.end()) {
            break;
        }

        current = it->second;
        readCount++;
    }

    cout << (terminal.count(current) ? 1 : 0) << '\n';
    cout << readCount << '\n';
    cout << current << '\n';

    return 0;
}
