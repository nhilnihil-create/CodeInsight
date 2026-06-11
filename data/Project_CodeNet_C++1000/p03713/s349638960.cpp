
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    ll H, W;
    cin >> H >> W;

    ll a1 = ll(H % 3 > 0) * W;

    ll a2 = ll(W % 3 > 0) * H;

    ll ans = min(a1, a2);

    ll a3 = INF;
    vector<ll> v(3);
    FOR(h, 1, H) {
        v[0] = h * W;
        v[1] = (H - h) * (W / 2);
        v[2] = (H - h) * (W / 2 + int(W & 1));
        sort(ALL(v));
        a3 = min(a3, v[2] - v[0]);
    }


    FOR(w, 1, W) {
        v[0] = w * H;
        v[1] = (W - w) * (H / 2);
        v[2] = (W - w) * (H / 2 + int(H & 1));
        sort(ALL(v));
        a3 = min(a3, v[2] - v[0]);
    }

    print(min(ans, a3));
    
}
