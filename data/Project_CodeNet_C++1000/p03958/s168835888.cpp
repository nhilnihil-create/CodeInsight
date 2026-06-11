#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    int K, N;
    cin >> K >> N;

    int ma = 0, a;
    rep(i, N) {
        cin >> a;
        ma = max(ma, a);
    }

    cout << max(2 * ma - 1 - K, 0) << endl;

    return 0;
}
