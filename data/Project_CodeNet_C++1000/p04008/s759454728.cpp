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
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 1e5+10;

int N, K, A[MAX];
vi child[MAX];

ii dnf(int n) {
    if (child[n].size() == 0) return ii(1, 0);
    ll d = 0, r = 0;

    FORE (c, child[n]) {
        ii res = dnf(c);
        if (res.first == K && n != 0) {
            r++;
            res.first = 0;
        }
        CHMAX(d, res.first);
        r += res.second; 
    }
    return ii(d+1, r);
}

ll solve() {
    FOR (i, 1, N) child[A[i]].push_back(i);
    return dnf(0).second + (A[0] > 0);
}

int main() {
    cin >> N >> K;
    REP (i, N) {
        cin >> A[i];
        A[i]--;
    }
    cout << solve() << endl;
}