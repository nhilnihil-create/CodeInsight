#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    rep(i, (s.size() + 1) / 2) {
        cout << s[i * 2];
    }
    cout << "\n";
}