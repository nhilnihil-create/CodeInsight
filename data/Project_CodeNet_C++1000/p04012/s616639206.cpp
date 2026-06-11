#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    map <char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }

    for (auto pp : mp) {
        if (pp.second & 1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}