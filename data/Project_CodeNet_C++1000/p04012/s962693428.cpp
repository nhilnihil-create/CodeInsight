#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> m;

    rep(i, s.size()) m[s[i]]++;
    for (auto e : m) {
        if (e.second % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
