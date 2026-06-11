#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

signed main() {
    cin >> N;
    vector<ll> a(3 * N);
    cin >> a;
    priority_queue<int, vector<int>, greater<int>> fpq;
    priority_queue<int, vector<int>, greater<int>> bpq;
    ll fs = 0, bs = 0;
    REP(i, N) {
        fpq.push(a[i]);
        fs += a[i];
    }
    vector<int> v(2 * N);
    FOR(i, N, 3 * N) {
        v[i - N] = a[i];
    }
    sort(ALL(v));
    multiset<int> st;
    multiset<int> bst;
    REP(i, 2 * N) {
        if (i < N) {
            st.insert(v[i]);
            bs += v[i];
        } else {
            bst.insert(v[i]);
        }
    }
    ans = fs - bs;
    FOR(i, N, 2 * N) {
        dump(fs, bs);
        dump(st);
        int ft = fpq.top();
        if (ft < a[i]) {
            fpq.pop();
            fpq.push(a[i]);
            fs += a[i] - ft;
        }
        auto itr = st.find(a[i]);
        if (itr != st.end()) {
            st.erase(itr);
            int bt = *bst.begin();
            bst.erase(bst.begin());
            st.insert(bt);
            bs += bt - a[i];
        } else {
            bst.erase(bst.find(a[i]));
        }
        ans = max(fs - bs, ans);
    }
    cout << ans << endl;
}