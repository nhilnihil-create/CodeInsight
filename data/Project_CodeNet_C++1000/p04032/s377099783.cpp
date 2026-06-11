#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }

vector<pair<int, int>> runLengthEncoding(string s) {
    int n = s.size();
    vector<pair<int, int>> res;
    int pre = s[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (pre != s[i]) {
            res.pb({pre, cnt});
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }
    res.pb({pre, cnt});
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<P> ns = runLengthEncoding(s);
    int cnt = 0;
    rep(i, ns.size()) {
        if (ns[i].se >= 2) {
            cout << cnt + 1 << ' ' << cnt + 2 << endl;
            return 0;
        }
        cnt += ns[i].se;
    }
    rep(i, s.size()-2) {
        if (s[i] == s[i+2]) {
            cout << i + 1 << ' ' << i + 3 << endl;
            return 0;
        }
    }
    cout << -1 << ' ' << -1 << endl;
    return 0;
}