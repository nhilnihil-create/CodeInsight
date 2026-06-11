#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 2147483647;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    int MAX = 0, MIN = INF;
    rep(i, n) {
        int a;
        cin >> a;
        cnt[a]++;
        chmax(MAX, a);
        chmin(MIN, a);
    }
    bool ok = 1;
    for (int i = MIN + 1; i <= MAX; i++) {
        ok &= cnt[i] >= 2;
    }
    ok &= cnt[MIN] == (MAX % 2 == 0 ? 1 : 2);
    ok &= MIN == (MAX + 1) / 2;
    cout << (ok ? "Possible" : "Impossible") << endl;
}