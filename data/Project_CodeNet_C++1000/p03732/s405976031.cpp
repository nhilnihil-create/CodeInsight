#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll w;
    cin >> n >> w;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    map<ll, ll> dp[2];
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(const auto &p : dp[i & 1]) {
            ll j = p.first;
            chmax(dp[(i + 1) & 1][j], p.second);
            if(j + a[i] <= w) {
                chmax(dp[(i + 1) & 1][j + a[i]], dp[i & 1][j] + b[i]);
            }
        }
        dp[i & 1].clear();
    }
    ll ans = -LLINF;
    for(const auto &p : dp[n & 1]) {
        if(p.first <= w) {
            chmax(ans, p.second);
        }
    }
    print(ans);
}