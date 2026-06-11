#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> ans(n * n, 0);
    vector<pair<int, int>> p;
    rep(i, n) {
        int x;
        cin >> x;
        x--;
        ans[x] = i + 1;
        p.push_back({x, i + 1});
    }
    sort(ALL(p));
    int x = 0;
    for(auto q : p) {
        rep(i, q.second - 1) {
            while(ans[x])
                x++;
            if(x > q.first) {
                cout << "No" << endl;
                return 0;
            }
            ans[x] = q.second;
        }
    }
    sort(ALL(p), greater<pair<int, int>>());
    x = n * n - 1;
    for(auto q : p) {
        rep(i, n - q.second) {
            while(ans[x])
                x--;
            if(x < q.first) {
                cout << "No" << endl;
                return 0;
            }
            ans[x] = q.second;
        }
    }
    cout << "Yes" << endl;
    rep(i, n * n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}