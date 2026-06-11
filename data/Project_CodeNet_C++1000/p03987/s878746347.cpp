#include <bits/stdc++.h>
using namespace std;
#define INF_LL 1LL << 40;
#define INF 1 << 31;
#define MOD 1000000007;
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define prique priority_queue
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
    int n, tmp;
    cin >> n;
    vl a(n + 2);
    set<ll> s = {-1, n};
    rep(i, n) {
        cin >> tmp;
        a[tmp - 1] = i;
    }
    ll ans = 0;
    rep(i, n) {
        auto it = s.lower_bound(a[i]);
        ans += (*it - a[i]) * (a[i] - *--it) * (i + 1);
        s.emplace(a[i]);
    }
    cout << ans << endl;
}
