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
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define DOUBLE(d) cout << fixed << setprecision(15) << (d) << endl

const int MAX = 2e5+10;
const int ALPHA = 26;

string S;

vvii nxt;

string solve() {
    int sz = S.size();
    nxt = vvii(sz+1, vii(ALPHA));
    vii state(ALPHA+1, ii(-1, 0));

    REPR (i, sz) {
        ll mn = MAX;
        REP (a, ALPHA) { 
            nxt[i+1][a] = state[a];
            CHMIN(mn, state[a].second);
        }
        int al = S[i] - 'a';
        state[al].first = i;
        state[al].second = mn+1;
    }
    nxt[0] = vii(26);
    REP (a, ALPHA) nxt[0][a] = state[a];

    int idx = 0;
    string ans = "";
    while (1) {
        ii n(-1, MAX);
        int c = 0;
        REP (a, ALPHA) {
            if (nxt[idx][a].second < n.second) {
                n = nxt[idx][a];
                c = a;
            }
        }
        ans += c + 'a';
        if (n.first == -1) return ans;
        idx = n.first + 1;
    }
}

int main() {
    cin >> S;
    cout << solve() << endl;
}