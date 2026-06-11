#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll n; vector<ll> a(4, 0);
    rep(i, 4) cin >> a[i];
    cin >> n;

    vector<ll> l1(3), l2(4);
    l1[0] = 4 * a[0];
    l1[1] = 2 * a[1];
    l1[2] = a[2];
    l2[0] = 8 * a[0];
    l2[1] = 4 * a[1];
    l2[2] = 2 * a[2];
    l2[3] = a[3];
    sort(all(l1)); sort(all(l2));
    n *= 4;

    ll ans = 0;
    ans += l2[0] * (n / 8);
    if (n % 8 != 0) ans += l1[0];
    cout << ans << endl;
}
