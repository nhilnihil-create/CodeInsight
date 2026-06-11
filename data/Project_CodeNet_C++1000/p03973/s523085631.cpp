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

int N, A[MAX];

ll solve() {
    int s = 0;
    ll ans = 0;
    REP (i, N) {
        if (A[i] > s) {
            int n = A[i] / (s+1);
            if (A[i] % (s+1) == 0) n--;
            ans += n;
            if (n > 0) A[i] = 1;
        }
        s = max(s, A[i]);
    }
    return ans;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    cout << solve() << endl;
}