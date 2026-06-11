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
const int BIT = 32;

ll N, K, A[MAX], B[MAX];

ll solve() {
    ll ans = 0;
    REP (i, N) if ((K | A[i]) == K) ans += B[i];
    REP (b, BIT) if ((K>>b)&1) {
        ll res = 0;
        ll accept = K & (~(1<<b)) | ((1<<b) - 1);
        REP (i, N) if ((accept | A[i]) == accept) res += B[i];
        CHMAX(ans, res);
    }
    return ans;
}

int main() {
    cin >> N >> K;
    REP (i, N) cin >> A[i] >> B[i];
    cout << solve() << endl;
}