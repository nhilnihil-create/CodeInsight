#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int long long

template <class T>
bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

struct comb {
    vvi v_set;

    void recursive_comb(int s, int rest, vi v) {
        if (rest == 0) {
            v_set.emplace_back(v);
        } else {
            if (s < 0) return;
            recursive_comb(s - 1, rest, v);
            v[rest - 1] = s;
            recursive_comb(s - 1, rest - 1, v);
        }
    }

    // nCkの組み合わせに対して処理を実行する
    void foreach_comb(int n, int k) {
        vi v(k);
        recursive_comb(n - 1, k, v);
    }

    vvi c(int n, int k) {
        v_set.clear();
        foreach_comb(n, k);
        return this->v_set;
    }
};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vi a(n);
    REP(i, n) cin >> a[i];
    
    vvi v = comb().c(n-1, n-k);
    ll ans = -1;
    for (vi vec : v) {
        vector<bool> use(n, true);
        for (int n : vec) use[n+1] = false;
        int tmp = 0;
        ll pre;
        REP(i, n) {
            if (i == 0) pre = a[i];
            else {
                if (use[i]) {
                    int dif = max(pre - a[i] + 1, 0LL);
                    tmp += dif;
                    if (dif == 0) pre = a[i];
                    else pre++;
                }else {
                    pre = max(pre, a[i]);
                }
            }
        }

        if (ans == -1) ans = tmp;
        ans = min(ans, tmp);

    }

    cout << ans << endl;

    return 0;
}
