#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    bool flag = false;
    rep(i, n + 1) {
        rep(j, m + 1) {
            if (j * (n - i) + i * (m - j) == k)
                flag = true;
        }
    }

    flag ? cout << "Yes" : cout << "No";
    cout << endl;

    return 0;
}