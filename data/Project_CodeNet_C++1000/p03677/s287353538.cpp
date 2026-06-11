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

const int MAX = 1e5+10;

ll N, M;
ll A[MAX];

ll solve() {
    vi s(M), t(M+1);
    REP (i, N-1) s[A[i+1]] += (A[i+1] - A[i] + M) % M - 1;
    REP (i, N-1) {
        t[A[i]+1] += 1;
        if (A[i+1] < A[i]) t[0] += 1;
        t[A[i+1]] -= 1;
    }
    REP (m, M-1) t[m+1] += t[m];

    // f0
    ll f = 0;
    REP (i, N-1) {
        if (A[i+1] > A[i]) f += A[i+1] - A[i];
        else f += A[i+1] + 1;
    }

    ll ret = f;
    // f1, f2, ...
    REP (x, M-1) {
        f += s[x] - t[x];
        CHMIN(ret, f);
    }
    return ret;
}

int main() {
    cin >> N >> M;
    REP (i, N) {
        cin >> A[i];
        A[i]--;
    }
    cout << solve() << endl;
}