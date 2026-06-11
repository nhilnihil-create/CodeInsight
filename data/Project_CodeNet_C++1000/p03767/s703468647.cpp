#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, ans;
    ans = 0;
    cin >> n;
    vll a(3*n+1, 0);
    FOR(i, 1, 3*n) cin >> a[i];
    sort(a.begin(), a.end());
    for(ll i = 3*n-1; i > n; i -= 2){
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
