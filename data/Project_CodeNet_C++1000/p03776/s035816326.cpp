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
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
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
    int n, a, b;
    cin >> n >> a >> b;
    double ans = 0.0;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(RALL(v));
    for(int i = 0; i < a; i++) {
        ans += v[i];
    }
    ans /= a;
    vector<vector<ll>> dp(60, vector<ll>(60, 0));
    {
        for(int i = 0; i < 60; i++) {
            dp[i][0] = dp[i][i] = 1;
        }
        for(int i = 2; i < 60; i++) {
            for(int j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    int N = count(ALL(v), v[a - 1]);
    ll cnt = 0;
    if(v[0] == v[a - 1]) {
        for(int i = a; i <= b; i++) {
            cnt += dp[N][i];
        }
    } else {
        int cnt2 = 0;
        for(int i = 0; i < a; i++) {
            cnt2 += (v[i] == v[a - 1]);
        }
        cnt += dp[N][cnt2];
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
    cout << cnt << endl;
}