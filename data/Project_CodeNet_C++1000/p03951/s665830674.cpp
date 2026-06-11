#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    rep(i, n) {
        bool flag = true;
        for (int j = i; j < n; ++j) {
            if (s[j] != t[j - i])
                flag = false;
        }
        if (flag) {
            cout << n + i << endl;
            return 0;
        }
    }

    cout << n * 2 << endl;

    return 0;
}
