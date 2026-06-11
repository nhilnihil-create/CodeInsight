#include<bits/stdc++.h>
 
#define fi first
#define se second
 
#define mp make_pair
#define pb push_back
 
#define all(x) (x).begin(), (x).end()
 
#define F return
#define skip continue

#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=a;i>=n;i--)

typedef long long ll;

using namespace std;                             

typedef pair<int, int> pii;
typedef pair<ll, ll> pll; 

 
const int MAXN = 3e5 + 500;
const int INF = 1e9 + 23;
const int MOD = 1e9 + 7;

ll n, k, a[MAXN], pr[MAXN];
ll t[MAXN * 4];

int get(int v, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    return get(v + v, tl, tm, l, r) + get(v + v + 1, tm + 1, tr, l, r);
}                                         

void upd(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v]++;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        upd(v + v, tl, tm, pos);
    }
    else {
        upd(v + v + 1, tm + 1, tr, pos);
    }
    t[v] = t[v + v] + t[v + v + 1];
}

pair<ll, int> p[MAXN];

void solve() {
    cin >> n >> k;

    rep(i, 1, n) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    rep(i, 1, n) {
        a[i] -= k * i;
    }

    ll ans = 0;

    for (int i = 0; i <= n; i++) {
        p[i] = mp(a[i], i);
    }

    sort(p, p + n + 1);

    for (int i = 0; i <= n; i++) {
        a[p[i].se] = i;
    }
                         
    rep(i, 0, n) {
        upd(1, 0, n + 1, a[i]);
        ans += get(1, 0, n + 1, 0, a[i] - 1);
    }
    cout << ans;
}

int main() {                
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;
     
    while (tt--) {
        solve();
        cout << '\n';
    }
 
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
*/