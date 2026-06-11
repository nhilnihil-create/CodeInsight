#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll ans = 0;
    rep(i,n-1){
        ans += min(a * (x[i + 1] - x[i]), b);
    }
    cout << ans << "\n";
    return 0;
}