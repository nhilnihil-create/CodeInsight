#include <bits/stdc++.h>

#define TYPE(c)   remove_reference_t<decltype(c)>
#define REP(i, n) for(TYPE(n) i = 0; i < n; i++)
#define FOR(v, c) for(TYPE(c.begin()) v = c.begin(); v != c.end(); v++)
#define ALL(c)    c.begin(), c.end()
#define SORT(c)   sort(ALL(c))
#define RSORT(c)  sort(ALL(c), greater<TYPE(c)::value_type>())
#define UNIQUE(c) c.erase(unique(ALL(c)), c.end())

using namespace std;
using ll = long long;

constexpr int MOD  = (int)1e9 + 7;
constexpr int INF  = (int)1e9 + 1;
constexpr ll  LINF = (ll)1e18 + 1;
template<typename T> constexpr bool chmax(T& a, const T& b)
{ if(a < b) { a = b; return true; } else { return false; } }
template<typename T> constexpr bool chmin(T& a, const T& b)
{ if(b < a) { a = b; return true; } else { return false; } }
template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T>& p)
{ return os << "(" << p.first << "," << p.second << ")"; }
template<typename T> auto operator<<(ostream& os, const T& t)
    -> typename conditional<true, ostream&, decltype(*t.begin())>::type
{ os << "["; FOR(v, t) { if(v != t.begin()) os << ","; os << *v; } os << "]"; return os; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, W;
    cin >> N >> W;

    vector<vector<ll>> A(4);
    ll w1 = 0;
    REP(i, N) {
        ll w, v;
        cin >> w >> v;
        if(i == 0) w1 = w;
        A[w - w1].push_back(v);
    }

    vector<vector<ll>> accsum_A(4, vector<ll>(1, 0));
    REP(i, 4) {
        RSORT(A[i]);
        REP(j, A[i].size()) {
            accsum_A[i].push_back(accsum_A[i].back() + A[i][j]);
        }
    }

    ll ans = 0;
    for(size_t i0 = 0; i0 <= 100; i0++) {
        if(A[0].size() < i0) continue;
        for(size_t i1 = 0; i1 <= 100 - i0; i1++) {
            if(A[1].size() < i1) continue;
            for(size_t i2 = 0; i2 <= 100 - i0 - i1; i2++) {
                if(A[2].size() < i2) continue;
                for(size_t i3 = 0; i3 <= 100 - i0 - i1 - i2; i3++) {
                    if(A[3].size() < i3) continue;
                    if(i0 * w1 + i1 * (w1 + 1) + i2 * (w1 + 2) + i3 * (w1 + 3) <= (size_t)W) {
                        chmax(ans, accsum_A[0][i0] + accsum_A[1][i1] + accsum_A[2][i2] + accsum_A[3][i3]);
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
