#include <bits/stdc++.h>
using namespace std;

int main() {
    string w;
    map<char, int> num;
    bool b = true;

    cin >> w;
    for (int i=0; i < w.length(); i++) {
        if (num.count(w[i])) {
            num[w[i]]++;
        } else {
            num[w[i]] = 1;
        }
    }

    for (auto p : num) {
        auto v = p.second;
        if (v % 2 == 1) {
            b = false;
            break;
        }
    }

    if (b) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}