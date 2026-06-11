#include<bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define rep(i, n) for(int i=0;i<(n);++i)
#define INF (1ll<<60)
#define FI first
#define SE second
typedef pair<int, int> pii;
#define l_b lower_bound
#define u_b upper_bound

int N, M;
int x[100100], y[100100];
const int mod = 1000000007;

signed main() {
    cin >> N >> M;
    int sx = 0, sy = 0;
    for (int k = 1; k <= N; ++k) {
        cin >> x[k];
        x[k] = x[k] * (k - 1) - x[k] * (N - k);
        x[k] %= mod;
        sx += x[k];
        sx %= mod;
    }
    for (int k = 1; k <= M; ++k) {
        cin >> y[k];
        y[k] = y[k] * (k - 1) - y[k] * (M - k);
        y[k] %= mod;
        sy += y[k];
        sy %= mod;
    }
    cout << sx * sy % mod << endl;
}