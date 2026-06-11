#include <bits/stdc++.h>
using namespace std;
#define INF_LL 1LL << 40
#define INF 2000000000
#define MOD 1000000007
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define prique priority_queue
#define double float
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vector<int>> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
struct edge {
    int to, cost;
};

int main() {
    int n;
    cin >> n;
    vi t(n + 2, 0), a(n + 2, 0);
    rep(i, n) cin >> t[i + 1];
    rep(i, n) cin >> a[i + 1];
    ll ans = 1;
    rep(i, n) {
        if(t[i] == t[i + 1] && a[i + 2] == a[i + 1]) {
            ans *= min(t[i + 1], a[i + 1]);
        } else {
            if(a[i + 2] == a[i + 1] && t[i + 1] > a[i + 1]) {
                ans = 0;
            } else if(t[i] == t[i + 1] && a[i + 1] > t[i + 1]) {
                ans = 0;
            } else if(a[i + 2] != a[i + 1] && t[i] != t[i + 1] &&
                      a[i + 1] != t[i + 1]) {
                ans = 0;
            }
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
