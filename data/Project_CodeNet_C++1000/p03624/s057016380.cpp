#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    set<char> a;

    rep(i, s.size()) a.insert(s[i]);

    for (char c = 'a'; c <= 'z'; c++) {
        bool ok = true;
        for (auto e : a)
            if (c == e) ok = false;
        if (ok) {
            cout << c << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    return 0;
}
