#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll t = max(m - 2 * n, 0LL);

    if (t == 0) {
        cout << m / 2 << endl;
    } else {
        cout << n + t / 4 << endl;
    }
}