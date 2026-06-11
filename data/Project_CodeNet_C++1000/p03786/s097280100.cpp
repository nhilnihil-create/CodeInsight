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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));
    vector<ll> sum(n+1, 0);
    rep(i, n) sum[i+1] = sum[i] + a[i];

    int ans = 1;
    int i = n - 1;
    while (i >= 0) {
        if (a[i] <= 2 * sum[i]) {
            i--;
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
}
