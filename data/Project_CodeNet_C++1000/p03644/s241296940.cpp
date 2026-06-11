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
    int n;
    cin >> n;
    int mx = 0;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        int tmp = i;
        while(tmp % 2 == 0) {
            cnt++;
            tmp /= 2;
        }
        if(chmax(mx, cnt)) {
            ans = i;
        }
    }
    cout << ans << endl;
}