#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N, M;
    cin >> N >> M;
    ll x[N], y[M], dx[N-1], dy[M-1];
    rep(i, N) cin >> x[i];
    rep(i, M) cin >> y[i];
    rep(i, N-1) dx[i] = x[i+1] - x[i];
    rep(i, M-1) dy[i] = y[i+1] - y[i];
    ll sumx = 0, sumy = 0;
    rep(i, N-1){
        ll j = min(i, N-2-i);
        ll tmp = j*(j+1) + (j+1)*(N-1-2*j);
        tmp %= MOD;
        sumx += dx[i]*tmp%MOD, sumx %= MOD;
    }
    rep(i, M-1){
        ll j = min(i, M-2-i);
        ll tmp = j*(j+1) + (j+1)*(M-1-2*j);
        tmp %= MOD;
        sumy += dy[i]*tmp%MOD, sumy %= MOD;
    }
    cout << sumx*sumy%MOD << endl;
}