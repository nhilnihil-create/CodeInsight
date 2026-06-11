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
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()

const int MAX = 555;
const string COLORS = "RYGB";

int H, W, D;

void solveOdd() {
    REP (h, H) {
        REP (w, W) {
            cout << COLORS[(w+h)%2];
        }
        cout << "\n";
    }
}

inline int diff(int h, int w, int ch, int cw) {
    return abs(h-ch) + abs(w-cw);
}

void solveEven() {
    int ch = D/2-1;
    int cw = D/2-1;
    REP (h, H) {
        REP (w, W) {
            int k = (w/D+h/D)%2;
            int hh = h-h/D*D;
            int ww = w-w/D*D;
            if (diff(hh,ww,ch,cw)<D/2 || diff(hh,ww,ch,cw+1)<D/2) {
                cout << COLORS[k];
            } else if ((hh-ch)*(ww-cw) > 0) {
                cout << COLORS[2+k];
            } else {
                cout << COLORS[3-k];
            }
        }
        cout << "\n";
    }
}

void solve() {
    if (D%2 == 1) {
        solveOdd();
    } else {
        solveEven();
    }
}

int main() {
    cin >> H >> W >> D;
    solve();
}