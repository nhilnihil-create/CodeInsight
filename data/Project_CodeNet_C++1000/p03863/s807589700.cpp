#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    bool a = s[0] != s[n - 1];
    bool b = n & 1;
    if (a == b) {
        cout << "First" << '\n';
    } else {
        cout << "Second" << '\n';
    }
    return 0;
}
