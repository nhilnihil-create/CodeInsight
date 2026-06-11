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

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int m = 0;
    rep(i, n){
        m += a[i];
    }

    m = round(1.0 * m / n);

    int ans = 0;
    rep(i, n) {
        ans += (a[i] - m) * (a[i] - m);
    }
    cout << ans << endl;
}