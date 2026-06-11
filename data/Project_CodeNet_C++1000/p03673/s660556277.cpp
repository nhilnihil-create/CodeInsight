
//#pragma GCC target("avx2")
#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

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
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (ll i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (ll i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
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

    int n; cin >> n;

    vi v1, v2;
    v1.reserve(n);
    v2.reserve(n);

    vi a(n);
    REP(i, n) cin >> a[i];

    REP(i, n) {
        if (i & 1) {
            v1.pb(a[i]);
        } else {
            v2.pb(a[i]);
        }
    }

    if (n & 1) {
        swap(v1, v2);
    }
    reverse(ALL(v1));
    REP(i, v1.size()) {
        if (i > 0) cout << " ";
        cout << v1[i];
    }

    REP(i, v2.size()) {
        cout << " " << v2[i];
    }

    print("");
}
