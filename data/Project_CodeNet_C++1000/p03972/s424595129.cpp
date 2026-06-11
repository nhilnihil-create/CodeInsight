#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

const int MAX = 1e5+10;

int W, H;
vii lines;

ll solve() {
    sort(ALL(lines));
    ll ans = 0;
    int h = H+1, w = W+1;
    FORE (line, lines) {
        ll val = line.first, is_vertical = line.second;

        if (is_vertical) {
            ans += val * h;
            w--;
        } else {
            ans += val * w;
            h--;
        }
    }
    return ans;
}

int main() {
    cin >> W >> H;
    REP (i, W) {
        int p; cin >> p;
        lines.push_back(make_pair(p, 1));
    }
    REP (i, H) {
        int q; cin >> q;
        lines.push_back(make_pair(q, 0));
    }
    cout << solve() << endl;
}