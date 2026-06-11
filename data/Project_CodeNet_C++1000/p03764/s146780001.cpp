#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    ll n, m;
    cin >> n >> m;
    ll x[100060];
    ll y[100060];
    ll X = 0;
    ll Y = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> y[i];
    }
    ll dx[100060];
    ll dy[100060];
    for(ll i = 1; i < n; i++) {
        dx[i] = x[i + 1] - x[i];
        X = (X + dx[i] * i * (n - i)) % mod;
    }
    for(ll i = 1; i < m; i++) {
        dy[i] = y[i + 1] - y[i];
        Y = (Y + dy[i] * i * (m - i)) % mod;
    }
    cout << X * Y % mod << endl;
    return 0;
}
