#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair <int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const char nl = '\n';

void solve() {
    ll n, x, ans(0);
    cin >> n >> x;
    vl a(10000000);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; ++i){
        if((a[i] + a[i + 1]) > x){
            ans += (a[i] + a[i + 1] - x);
            a[i + 1] = a[i + 1] - (a[i] + a[i + 1] - x);
            if(a[i + 1] < 0){
                a[i] += a[i + 1];
                a[i + 1] = 0;
            }
        }
    }
    cout << ans << nl;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}