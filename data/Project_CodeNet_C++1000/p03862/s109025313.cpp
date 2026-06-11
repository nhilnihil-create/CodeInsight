#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, x;
    cin >> n >> x;
    ll a[n], b[n], sum1 = 0, sum2 = 0;
    rep (i, n) cin >> a[i];
    rep (i, n) b[i] = a[i];
    //貪欲法
    if (a[0] > x) {
        sum1 += a[0] - x;
        a[0] = x;
    }
    rep (i, n - 1) {
        if (a[i] + a[i + 1] > x) {
            sum1 += a[i + 1] + a[i] - x;
            a[i + 1] = x - a[i];
        }
    }
    if (b[n - 1] > x) {
        sum2 += b[n - 1] - x;
        b[n - 1] = x;
    }
    for (int i = n - 1; i > 0; i--) {
        if (b[i] + b[i - 1] > x) {
            sum2 += b[i] + b[i - 1] - x;
            b[i - 1] = x - b[i];
        }
    }
    ll ans = min (sum1, sum2);

    cout << ans << "\n";
}