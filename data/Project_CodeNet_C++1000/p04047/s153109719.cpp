#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int ll
#define pw(x) (1LL<<(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define SZ(a) ((int)(a).size())
#define dbg(a) cerr << #a << " = " << a << '\n'

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

void open(string file) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

signed main() {
    //open("cbarn");
    fast_io();
    int n;
    cin >> n;
    vi l(2 * n);
    for (auto& i : l) cin >> i;
    sort(rall(l));
    int ans = 0;
    for (int i = 1; i < 2 * n; i += 2) ans += l[i];
    cout << ans;
    return 0;
}
